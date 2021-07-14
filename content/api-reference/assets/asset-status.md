---
uid: AssetStatus
---

# Asset and Asset Type Status

Status is a property of an asset or asset type that defines the simple status of an asset or asset type. There is one status property for each asset or asset type.

If an asset references an existing asset type and the asset type has a corresponding type reference, then the status mapping on the asset is ignored.

Create, read, update, and delete of an asset status mapping is done through the asset or asset type itself.

## Status table

The following table lists the most common fields in a status mapping.

| Property       | Type       | Required? | Searchable? | Description                                                  |
| -------------- | ---------- | --------- | ----------- | ------------------------------------------------------------ |
| DefinitionType | String     | Required  | No          | At this moment, only the value "StreamPropertyMapping" is supported. |
| Definition     | Definition | Required  | No          | Status definition.                                           |

## Status definition table

The following table lists the most common fields in a status mapping.

| Property            | Type                     | Required? | Searchable? | Description                                                  |
| ------------------- | ------------------------ | --------- | ----------- | ------------------------------------------------------------ |
| StreamReferenceId   | String                   | Required  | No          | `Id` for the asset's StreamReferences property. The stream reference must exist before the status mapping can be created. |
| StreamPropertyId    | String                   | Required  | No          | SDS stream property that status uses for calculations. It must be present on the StreamId property on the asset StreamReference.  The SDS stream property must be a numeric enumeration, character, or string type. |
| ValueStatusMappings | List<ValueStatusMapping> | Required  | No          | The value status mapping maps values to a given status. See [Value status mapping properties table](xref:AssetStatus#value-status-mapping-properties-table) |
## Value status mapping properties table

The following table lists the most common fields in a value status mapping. A single value status mapping corresponds to a single status. If you want additional statuses in your asset status mapping, add additional elements in the `ValueStatusMappings` list.

| Property    | Type               | Required? | Searchable? | Description                                                  |
| ----------- | ------------------ | --------- | ----------- | ------------------------------------------------------------ |
| Value       | Object             | Required  | No          | Value of the value status mapping. The values in a status mapping should be unique. |
| Status      | Status Enumeration | Required  | No          | Description of the value status mapping.                     |
| DisplayName | String             | Optional  | No          | Display name for this value status mapping.                  |

## Status enumerations

The following are valid status enumerations: 

- Unknown = 0
- Good = 1
- Warning = 2
- Bad = 3

## Example status mapping

The following is an example of a status property which is on the asset or asset type.

```
"Status": {
  "DefinitionType": "StreamPropertyMapping",
  "Definition": {
    "StreamReferenceId": "AssetStreamReferenceId1",
    "StreamPropertyId": "Value",
    "ValueStatusMappings": [
      {
        "Value": 3,
        "Status": "Bad",
        "DisplayName": "Bad"
      },
      {
        "Value": 1,
        "Status": "Good",
        "DisplayName": "Good"
      }
    ]
  }
}
```
The asset or asset type's `StreamReferences` field has an `Id` property. To assign a status mapping to an asset or asset type, the value assigned to the `Id` property must match the `StreamReferenceId` of the status mapping object. Using the status mapping example above, AssetStreamReferenceId1 is assigned to the asset in the following example. 
```
{
  "Id": "ChargingStationAsset", 
   "AssetTypeId": null,
  "Metadata": [{ 
      "Name": "Location",  "Value": "Houston", "SdsTypeCode": "String", "Uom": null​ 
    }], 
    "StreamReferences": [{ 
      "Id": "AssetStreamReferenceId1", 
      "StreamId": "pi2ocs_stream1_inputpower", 
    }] 
} 
```

## `Get Asset Status`

Returns the status of an asset. 

The status of an asset is determined by an exact match of the SDS stream property value to the value of the `ValueStatusMappings`. If there are no exact matches, the status is a 0 (Unknown).


### Request

```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Status/Last
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
| Status Code       | Body Type    | Description                                                  |
| ----------------- | ------------ | ------------------------------------------------------------ |
| 200 OK            | Asset status | The asset status is returned.                                |
| 400 Bad Request   | error        | The request is not valid. See the response body for additional details. |
| 403 Forbidden     | error        | You are not authorized to view the requested asset.          |
| 404 Not Found     | error        | The specified asset with identifier is not found.            |
| 422 Invalid State | error        | See the response body for details.                           |

#### Example response body

```
HTTP 200 OK
Content-Type: application/json
{
	"AssetId": "TemperatureSensorAsset",
	"Status": 1,
	"Value": "85",
    "DisplayName": "TemperatureSensorBuild1InF",
    "DataRetrievalTime": "2020-05-04T16:55:26.3732693Z"
}
```

***

## `Asset Status Range Summary`

Returns the status summary of an asset.

### Request

```text 
POST api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Status/Summary
?startIndex={startIndex}&endIndex={endIndex}&intervals={intervals}
```

### Parameters

`string tenantId`  
Tenant identifier

`string namespaceId`  
Namespace identifier

`string assetId`  
Asset identifier

`string startIndex`  
Start index

`string endIndex`  
End index

`string intervals`  
Number of intervals

### Response

The response includes a status code and a response body.

| Status Code       | Body Type    | Description                                                  |
| ----------------- | ------------ | ------------------------------------------------------------ |
| 200 OK            | Asset status summary | The asset status summary is returned.                                |
| 400 Bad Request   | error        | The request is not valid. See the response body for additional details. |
| 403 Forbidden     | error        | You are not authorized to view the requested asset.          |
| 404 Not Found     | error        | The specified asset with identifier is not found.            |
| 422 Invalid State | error        | See the response body for details.                           |

#### Example response body

```
HTTP 200 OK
Content-Type: application/json
{
  "RangeValues": [
    {
      "Index": "2019-01-02T00:00:00Z",
      "Status": "Warning",
      "Value": 2,
      "DisplayName": "AssetInWarning"
    },
    {
      "Index": "2019-01-02T00:30:00Z",
      "Status": "Bad",
      "Value": 4,
      "DisplayName": "AssetInBadState"
    }
  ],
  "Statistics": [
    {
      "Status": "Warning",
      "TotalInterval": "00:30:00",
      "Values": [
        {
          "Value": 2,
          "Interval": "00:30:00"
        }
      ]
    },
    {
      "Status": "Bad",
      "TotalInterval": "1246.06:30:00",
      "Values": [
        {
          "Value": 4,
          "Interval": "1246.06:30:00"
        }
      ]
    }
  ]
}
```


***

## `Bulk Asset Status`

Returns the status of multiple assets.

### Request

```text 
POST api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Bulk/Assets/Status/Last
```

### Parameters

`string tenantId`  
Tenant identifier

`string namespaceId`  
Namespace identifier

`string assetId`  
Asset identifier

#### Example POST body

Lists the asset identifiers whose status you are interested in.

```
Content-Type: application/json
[
   "AssetId-1",
   "AssetId-2",
   "AssetId-3"
]
```

### Response

The response includes a status code and a response body.

| Status Code      | Body Type         | Description                                                  |
| ---------------- | ----------------- | ------------------------------------------------------------ |
| 200 OK           | Asset status list | Returns the status of multiple assets. |
| 207 Multi Status | Multi Status      | Partial success. Not all assets were able to be resolved. See response body for additional details. |

#### Example response body

```
HTTP 200 OK
Content-Type: application/json
{
   [
      {
         "AssetId": "AssetId-1",
         "Status": 1, 
         "Value": "85",
         "DisplayName": "TemperatureSensorBuild1InF",
         "DataRetrievalTime": "2020-05-04T16:55:26.3732693Z"
      },
      {
         "AssetId": "AssetId-2",
         "Status": 2, 
         "Value": "185",
         "DisplayName": "DeviceMeasurement",
         "DataRetrievalTime": "2020-05-04T16:55:26.3732693Z"
      },
      {
         "AssetId": "AssetId-3",
         "Status": 1, 
         "Value": "75",
         "DisplayName": "TemperatureSensorBuild5450InF",
         "DataRetrievalTime": "2020-05-04T16:55:26.3732693Z"
      }
   ]
}
```
