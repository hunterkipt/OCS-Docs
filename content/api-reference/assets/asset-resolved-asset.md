---
uid: AssetResolvedAsset
---

# Resolved Asset

The resolved asset describes the consumption-oriented aspects of an OCS resource rather than describing how the resource is configured. 

The resolved asset corresponds to its metadata and referenced stream which define how the data is interpreted (that is, SdsTypeCode, InterpolationMode, and UOM).

***

## `Get Resolved Asset`

Returns the resolved asset.

## Resolved Asset Metadata Value Rules

When an asset references an asset type, the following rules explain how the values are derived for a given `Metadata` value on the resolved asset.

- If a `Metadata` value with the same `Id` exists on the asset type and asset, the `Metadata` value properties, `Name`, `UOM`, and `SdsTypeCode`, of the asset type take precedence over the asset properties.
- If the `Metadata` value with the same `Id` exists on the asset type and asset, the `Value` property on the asset takes precedence (Example 3) if its value is not null.  
- If the `Value` property on the asset is null, then the `Value` property of the asset type's `Metadata` value is used (Example 2) unless that value is also null. In this instance, the `Value` property on the resolved asset is zero for metadata whose `SdsTypeCode` is a numeric type, and it is an empty string for metadata whose `SdsTypeCode` is string. (Example 1).
- If the `SdsTypeCode` on the asset and asset type do not match, then the `Value` property of the `Metadata` value on the resolved asset will be coerced to the `SdsTypeCode` property of the asset type (Examples 7 and 8).
- If the `Metadata` value with the same `Id` exists on the asset and the resolved asset, but the `Metadata` value does not exist on the asset type, then the asset's `Metadata` value appears on the resolved asset (Example 4), unless the asset's `Name` property is null. In this instance, the `Metadata` value does not appear on the resolved asset (Example 5).

### Examples

The examples in the following table illustrate the resolved asset metadata value rules.

| Example | Metadata value on asset type                          | Metadata value on asset                                      | Metadata value on resolved asset                          | Details                                                      |
| ------- | ----------------------------------------------------- | ------------------------------------------------------------ | --------------------------------------------------------- | :----------------------------------------------------------- |
| 1       | `Id` ="md_id"<br/> `Name`="**m1**"<br/>  `Value`=null | `Id`="md_id"<br> `Name`=null<br>  `Value`=null               | `Id`="md_id"<br> `Name`="**m1**"<br> ` Value`=See Details | For a numeric `SdsTypeCode`, the value of the `Value` property for **m1** is 0. For a string `SdsTypeCode`, the value of the `Value` property for **m1** is an empty string. For both, the `Metadata` value is returned, along with the `UOM` and `SdsTypeCode`, for the asset type. |
| 2       | `Id`="md_id"<br/> `Name`="**m2**"<br/>  `Value`=10    | `Id`="md_id"<br/> `Name`=null<br/> `Value`=null              | `Id`="md_id"<br/> `Name`="**m2**"<br/>  `Value`=10        | **m2** appears on the resolved asset with `Value`=10, along with `UOM` and `SdsTypeCode` from the asset type. |
| 3       | `Id`="md_id"<br/> `Name`="**m3**"<br/>  `Value`=10    | `Id`="md_id"<br/> `Name`=null<br/>  `Value`=20               | `Id`="md_id"<br/> `Name`="**m3**"<br/>  `Value`=20        | **m3** appears on the resolved asset with `Value`=20, along with `UOM` and `SdsTypeCode` from the asset type. The `Value` property on the asset `Metadata` value always overrides the `Value` property on the asset type. |
| 4       | Not present                                           | `Id`="md_id"<br/> `Name`="**m4**"<br/>  `Value`=30           | `Id`="md_id"<br/> `Name`="**m4**"<br/>  `Value`=30        | m4 appears on the resolved asset with value =30, along with `UOM` and `SdsTypeCode` from the asset. Because this metadata value does not exist on the asset type, the metadata value on the resolved asset takes the value of the asset. |
| 5       | Not present                                           | `Id`="md_id"<br/> `Name`=null<br/>  `Value`=30               | Not present                                               | Because there is no `Metadata` value with `Id` = "md_id" on the asset type and the name of the `Metadata` value on the asset is null, then this `Metadata` value does not appear on the resolved asset. |
| 6       | `Id`="md_id"<br/> `Name`="**m6**"<br/>  `Value`=10    | `Id`="md_id"<br/> `Name`="anotherName"<br/>  `Value`="1234"  | `Id`="md_id"<br/> `Name`="**m6**"<br/>  `Value`=10        | The `Metadata` value `Name` with `Id`= "md_id" is not null on the asset. Therefore, the resolved asset's `Metadata` value takes the  asset type's `Metadata` value. |
| 7       | `Id`="md_id"<br/> `Name`="**m7**"<br/>  `Value`=10    | `Id`="md_id"<br/> `Name`=null<br/>  `Value`="a string value" | `Id`="md_id"<br/> `Name`="**m7**"<br/> ` Value`=0         | The `Metadata` value with `Id`="md_id" has a different `SdsTypeCode` on the asset and asset type. Therefore, the resolved asset's `Metadata` value coerces the overloaded `Value` from the asset to the `SdsTypecode` on the asset type.  It also takes the  `Metadata` value for `UOM` and `SdsTypeCode` from the asset type. |
| 8       | `Id`="md_id"<br/> `Name`="**m9**"<br/> ` Value`=10    | `Id`="md_id"<br/> `Name`=null<br/> ` Value`="1.23"           | `Id`="md_id"<br/> `Name`="**m9**"<br/>  `Value`=1         | The `Metadata` value with `Id`="md_id" has a different `SdsTypeCode` on the asset and asset type. Therefore, the resolved asset's `Metadata` value coerces the overloaded `Value` from the asset to the `SdsTypecode` on the asset type. It also takes the  `Metadata` value for `UOM` and `SdsTypeCode` from the asset type. |

### Resolved Asset Stream Reference Rules

The following example illustrates the resolved asset reference rules. If an asset references an asset type, the the following rules apply for a given reference:

Assume that the following is true for the asset and asset type:

- `Id`="reference1" is defined for both the asset and the asset type. The asset type has measurement mappings for "Temperature" and "Pressure".
- `Id`="reference2" is defined only on the asset, with one measurement mapping for "Temperature".
- `Id`="reference3" is defined only on the asset, but its `StreamReferenceName` is null, with one measurement mapping for "Pressure".

In this scenario, the default reference rules resolve as follows: 

- Measurement mappings for "reference1" are determined by the asset type. Any measurement mappings for "reference1" on the asset are ignored.
- The "Temperature" measurement mapping for "reference2" on the asset overrides the "Temperature" measurement mappings from "reference1".
- Any measurement mappings for "reference3" are ignored because Name on the asset is null. Note: `StreamReferenceName` on the asset type cannot be null. 

### Request

```text
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Resolved
```

### Parameters

`string tenantId`    
Tenant identifier

`string namespaceId`  
Namespace identifier

`string assetId`  
Asset identifier

### Response

The response includes a status code and a response body.

| Status Code     | Body Type        | Description                                                  |
| --------------- | ---------------- | ------------------------------------------------------------ |
| 200 OK          | `Resolved Asset` | The resolved asset.                                          |
| 400 Bad Request | error            | The request is not valid. See the response body for additional details. |
| 403 Forbidden   | error            | You are not authorized to view the requested asset.          |
| 404 Not Found   | error            | The asset with the specified identifier is not found.        |

#### Example response body

```
HTTP 200 OK
Content-Type: application/json
{
  "Id": "Heater-8911ee90-467b-4a3f-bc7b-3b3512c23dfc",
  "Name": "Heater Asset",
  "Resolved": true,
  "Description": "Heater Asset on the first floor.",
  "AssetTypeId": "Heater_AssetType-6f53c911-f5de-4b7f-981f-d6f0ec139d9f",
  "AssetTypeName": "Heater_AssetType",
  "Metadata": [
    {
      "Id": "fbd82b97-d29e-4022-968e-f8492cf86644",
      "Name": "ModelNumber",
      "Description": "This is a static attribute on the asset which represents the model number.",
      "SdsTypeCode": "Double",
      "Value": 0.01
    }
  ],
  "Streams": [
    {
      "Name": "ResolvedReferenceName1",
      "Type": {
        "Id": "SdsType-ffdf2227-50e8-4196-b828-f1bd2b3689c8",
        "SdsTypeCode": "Object",
        "Properties": [
          {
            "Id": "Timestamp",
            "IsKey": true,
            "SdsType": {
              "Id": "0573b425-368a-369b-95d9-71c863df45a5",
              "SdsTypeCode": "DateTime"
            },
            "InterpolationMode": "Continuous"
          },
          {
            "Id": "Pressure",
            "SdsType": {
              "Id": "9144b7d6-3d5f-3b29-8131-ff0db551e17c",
              "SdsTypeCode": "Double"
            },
            "Uom": "bar",
            "InterpolationMode": "Continuous"
          }
        ]
      },
      "StreamReferenceName": "ResolvedReferenceName1",
      "StreamId": "Stream-b3c7a344-ce8a-4578-b4cd-1a6d78ca0610",
      "PropertyMaps": [
        {
          "Id": "Timestamp",
          "SourcePropertyId": "Timestamp"
        },
        {
          "Id": "Pressure",
          "SourcePropertyId": "Pressure"
        }
      ]
    }
  ],
  "UnresolvedStreams": [ 
        { 
            "Name": "OutputFlow",
            "Reason": "SDS Stream 'PI_Outflow' not found"
        }]
  "UnresolvedMetadata": [],
  "StatusDefinitionType": "StreamPropertyMapping",
  "Status": {
    "StreamId": "SdsStream_id_1",
    "SourcePropertyId": "Count"
  }
}
```

## `Get Resolved Asset (Bulk)`

Returns multiple resolved assets in one call.

### Request
```text
POST api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/bBlk/Assets/Resolved
```

### Parameters

`string tenantId`    
Tenant identifier

`string namespaceId`  
Namespace identifier

#### Request body 

A list of asset `Id`s.

#### Example request body 
Requesting resolved assets for assets with the following `Id`s: **Asset1**, **Asset2**, and **Asset3**.

```json
[
   "Asset1",
   "Asset2",
   "Asset3"
]
```

### Response

The response includes a list of resolved assets, a status code and a response body.

| Status Code     | Body Type        | Description                                                  |
| --------------- | ---------------- | ------------------------------------------------------------ |
| 200 OK          | `Resolved Asset` List | The resolved assets.                                          |
| 207 Multi-status| `Resolved Asset` List and Error List | The resolved assets and errors for assets which could not be resolved.  |
| 400 Bad Request | error            | The request is not valid. See the response body for additional details. |
