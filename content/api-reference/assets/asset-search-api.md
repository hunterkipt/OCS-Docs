---
uid: AssetsSearchAPI
---

# Assets search API
The assets search API allows you to search for your assets with search criteria.

***
## `Get Assets by Search Criteria` 
Returns an array of assets that meet the search criteria.

### Searchable Properties
Assets can be searched on the following asset properties:

- Asset Top-level Properties
  - Id, Name, Description, AssetTypeId, AssetTypeName

- Metadata Properties
  - Name, Description, Value

- Stream Reference Properties
  - StreamReferenceName - Stream Reference Name
  - StreamPropertyId - SDS Stream Property Ids, not including indices

Search criteria can be chained together using an **AND**. See examples below. 

## `Search Assets` 
Searches and returns assets matching the search criteria.

### Request 
```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets?skip={skip}&count={count}&orderby={orderby}&query={queryString}&{filterString}&pageSize={pageSize}&maxPages={maxPages}&continuationToken={continuationToken}
```

### Parameters  
`string tenantId`  
Tenant identifier

`string namespaceId`  
Namespace identifier

`string queryString`  
Asset query string. Search strings are not case sensitive.

`string filterString`  
String used to filter the asset search results. Filter strings are not case sensitive. The strings on which you can filter results are limited to the asset `AssetTypeName` property and the asset metadata properties (using the syntax filter[*property_name*]=*property_value*).

[optional] `int skip`   
Optional parameter representing the zero-based offset of the first asset to retrieve. If not specified, a default value of 0 is used.

[optional] `int count`   
Optional parameter, between 1 and 1000 (inclusive), that represents the maximum number of assets to retrieve. If not specified, the default is 100.

[optional] `[id|name] [asc|desc|] orderby`  
Optional parameter which returns assets ordered either by the asset `Id` or the asset `Name`. Specify `asc` or `desc` to return the results in ascending or descending order. If not specified, the default is ascending order.

### Response 
Returns an array of assets matching the search query and the total number of assets returned specified as `Total-Count` in the HTTP response header. 

| Status Code | Body Type | Description |
|--|--|--|
| 200 OK | Asset list | A list of assets matching the search criteria. An empty array is returned if there are no matching assets. |
| 204 OK | empty | No assets match your search criteria. |
| 400 Bad Request | error | The request is not valid. See the response body for additional details. |
| 403 Forbidden | error | You are not authorized to view the requested asset. |


## `Search Matched Fields Asset` 
Searches all assets and returns a list of asset identifiers and their matched fields. Use this API to identify the fields in the asset that match your query string.

### Request 
```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Search/Assets?skip={skip}&count={count}&orderby={orderby}&query={queryString}&{filterString}&pageSize={pageSize}&maxPages={maxPages}&continuationToken={continuationToken}
```

### Parameters  
`string tenantId`  
Tenant identifier

`string namespaceId`  
Namespace identifier

`string queryString`  
Asset query string. Search strings are not case-sensitive.

`string filterString`  
String used to filter the asset search results. Filter strings are not case sensitive. The strings on which you can filter results are limited to the asset `AssetTypeName` property and the asset metadata properties (using the syntax filter[*property_name*]=*property_value*).

[optional] `int skip`   
Optional parameter representing the zero-based offset of the first asset to retrieve. If not specified, a default value of 0 is used.

[optional] `int count`   
Optional parameter, between 1 and 1000 (inclusive), representing the maximum number of retrieved assets. If not specified, the default is 100.

[optional] `[id|name] [asc|desc|] orderby`  
Optional parameter which returns assets ordered either by the asset `Id` or the asset `Name`. Specify `asc` or `desc` to return the results in ascending or descending order. If not specified, the default is ascending order.

### Response 
A list of asset Ids and their matched fields.

| Status Code | Body Type | Description |
|--|--|--|
| 200 OK | Asset list | A list of assets matching the search criteria. An empty array is returned if there are no matching assets. |
| 204 OK | empty | No assets match your search criteria. |
| 400 Bad Request | error | The request is not valid. See the response body for additional details. |
| 403 Forbidden | error | You are not authorized to view the requested asset. |

#### Example response body
Below is a response when query string is "Name:Tracer".

- `Count` represents the number of matched assets in the given query.

 A list of results is returned. Each result contains:  
-  `MatchProperties` - a list of matched property objects. Each `MatchProperties` object contains the matched fields and their values.
- `Id` - Identifier of the matched asset.
- `TypeId` - asset type identifier of the asset. This is null if the asset does not reference an asset type.
- `Name` - asset name.
- `Description` - asset description.
- `ETag` - version tag.
- `CreatedDate` - asset creation date.
- `LastModifiedDate` - last modified date of the asset.

```json 
HTTP 200 OK 
Content-Type: application/json
{
    "Count": 2,
    "Results": [
        {
            "MatchedProperties": [
                {
                    "Field": "Name",
                    "Value": "Asset Tracer ced7ee16-984d-480f-8338-3055f7f39d8b"
                }
            ],
            "Id": "AssetId2b5f41ae-0929-4977-bfbd-1e046d8a66f4",
            "TypeId": "AssetTracerType",
            "Name": "Asset Tracer ced7ee16-984d-480f-8338-3055f7f39d8b",
            "Description": "First tracer device",
            "ETag": "1",
            "CreatedDate": "2021-05-26T19:05:33.8979442Z",
            "LastModifiedDate": "2021-05-26T19:05:33.8979442Z"
        },
        {
            "MatchedProperties": [
                {
                    "Field": "Name",
                    "Value": "Asset Tracer d6b984dd-b6da-4225-a2e0-59f781d065a4"
                }
            ],
            "Id": "AssetId3dbfd185-7c62-49ed-b875-7953cba07fc3",
            "TypeId": "AssetTracerType",
            "Name": "Asset Tracer d6b984dd-b6da-4225-a2e0-59f781d065a4",
            "Description": "Another tracer device",
            "ETag": "1",
            "CreatedDate": "2021-05-26T19:05:40.9043726Z",
            "LastModifiedDate": "2021-05-26T19:05:40.9043726Z"        
        }
    ]
}
```

### Examples of asset query strings

| Query String                 | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| Id:Id1                       | Returns the asset with `Id` equal to **Id1**.                |
| Id:Id1 Name desc             | Returns the asset with `Id` equal to **Id1** return results in descending order by Name. |
| Id:Id*                       | Returns all assets with `Id` matching **id*** wildcard.      |
| Name:Name1                   | Returns all asset with a friendly name equal to **Name1**.   |
| Id:Id AND Name:Name1         | Returns all assets with `Id` matching the **id** and with a friendly name equal to **Name1**. |
| Description:floor1*          | Returns all assets with a description that starts with **floor1**. |
| Metadata/Name:Building*      | Returns all assets with at least one metadata name whose description contains the string **Building**. |
| Metadata/Description:heater* | Returns all assets with at least one metadata whose description starts with **heater**. |
| Metadata/Value:123           | Returns all assets with at least one metadata whose Value property equals **123**. |
| Id:X* AND Metadata/Name:B*   | Returns all assets with `Id` starting with **X** and containing at least one metadata value with a name that starts with a **B**. |
| AssetTypeId:HeaterTypeId     | Returns all assets with `AssetTypeId` matching `HeaterTypeId` |
| AssetTypeName:HeaterTypeName | Returns all assets whose `Name` field of the asset type matches **HeaterTypeName** |
| StreamPropertyId:Pressure    | Returns all assets that have one or more stream references with the stream property ID **Pressure**. Note: This search only searches non-key Sds stream properties. |
| StreamReferenceName:Name1    | Returns all assets whose stream references contain a stream reference name that matches **Name1**. |

### Special characters in search queries

Add the backslash escape character ( \ ) before any special characters in search queries. The following special characters require an escape character:   " |  /  *  \  ( )  : 

The following are examples of using the escape character in query strings.

| Example Field Value                    | Query String                               |
| -------------------------------------- | ------------------------------------------ |
| Austin\Dallas\Fort Worth               | Austin\\\Dallas\\\Fort Worth               |
| 1:100                                  | 1\\:100                                    |

### Examples of asset filter strings

Filter strings are not case sensitive. Numeric types must be passed as strings according to English locale. For example, a double of 1.1 must be sent as **"1.1"**.

| Query String                                 | Description                                                  |
| -------------------------------------------- | ------------------------------------------------------------ |
| filter[location]=Earth                       | Filter that only returns assets that contain the metadata name = **location** with **Earth** as the metadata value. |
| filter[location]=Earth&filter[device]=tracer | Filter that only returns assets that contain both of the following metadata. The first metadata name = **location** with **Earth** as the metadata value, and the second metadata is name = **device** with **tracer** as the metadata value. |
| filter[AssetTypeName]=HeaterType             | Filter that only returns assets with an AssetTypeName of **HeaterType**. |
| filter[status]=Bad                           | Filter that returns only assets with a bad status. Status filters can have the values **Good**, **Bad**, **Warning**, and **Unknown**. |

## `Asset Faceted Search` 

Asset faceted search allows for searching using asset facets. Asset facets are not case sensitive.  Only asset metadata can be used in asset faceted searches.

### Request 

```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Search/Assets/Facets?name={category}&count={count}
```

### Parameters  

`string tenantId`  
Tenant identifier

`string namespaceId`  
Namespace identifier

`string category`  
Name of the asset metadata for which you want to retrieve the facet values.

[optional] `int count`   
Optional parameter, between 1 and 1000 (inclusive), representing the maximum number of retrieved assets. If not specified, the default is 100.

### Response 

A list of asset Ids and their matched fields.

| Status Code     | Body Type        | Description                                                  |
| --------------- | ---------------- | ------------------------------------------------------------ |
| 200 OK          | Asset facet list | A list of asset facet values that match the search criteria. An empty array is returned if there are no matching asset metadata with the supplied category. |
| 204 OK          | empty            | No assets match your search criteria.                        |
| 400 Bad Request | error            | The request is not valid. See the response body for additional details. |

### Example 

If you have the following assets in your system:

| Assets in System                                             |
| ------------------------------------------------------------ |
| "Id": "CaliforniaAsset",    "Metadata": [      { "Name": "Manufacturer", "Value": "GE", "SdsTypeCode": "String" },      { "Name": "Location", "Value": "California", "SdsTypeCode": "String" },    ] |
| "Id": "CaliforniaAsset1",    "Metadata": [      { "Name": "Manufacturer", "Value": "Rockwell", "SdsTypeCode": "String" },      { "Name": "Location", "Value": "California", "SdsTypeCode": "String" },    ] |
| "Id": "PhillyAsset",    "Metadata": [      { "Name": "Manufacturer", "Value": "GE", "SdsTypeCode": "String" },      { "Name": "Location", "Value": "Philly", "SdsTypeCode": "String" },    ] |


Performing a `GET search/assets/facets?Name=Location` returns the following response. 


```json 
HTTP 200 OK 
Content-Type: application/json
[
    {
        "Name": "Location",
        "FacetValues": [
            {
                "Value": "California",
                "DocumentCount": 2
            },
            {
                "Value": "Philly",
                "DocumentCount": 1
            }
        ]
    }
]
```

## `Asset Autocomplete` 

Asset autocomplete allows you to query assets and retrieve a list of suggested assets based on your search criteria. The autocomplete feature can be used with the following asset properties:

-  Name
-  Description
-  AssetTypeName
-  Metadata

### Request 

```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Search/Assets/Autocomplete?term={term}&facetCount={facetCount}&termCount={termCount}
```

### Parameters  

`string tenantId`  
Tenant identifier

`string namespaceId`  
Namespace identifier

`string term`  
Search term that you want to search for.

[optional] `int facetCount`  
Maximum number of facet autocompleted items to return. The default is 0 which means you will not get any facet suggestions.

[optional] `int termCount`  
Maximum number of token autocompleted items to return. The default is 0 which means you will not get any token suggestions.

### Example 

Assume you have the following assets in your system.

| Assets in System                                             |
| ------------------------------------------------------------ |
| "Id": "AutoCompletedAsset_1", "Name": "tracerRound", "Description": "Traced Asset 1", "Metadata": [{ "Id": "1", "Name": "tractorNumber", "Value": "t100", "SdsTypeCode": "String:}] |
| "Id": "AutoCompletedAsset_2", "Name": "tracerRound", "Description": "None", "Metadata": [{ "Id": "2", "Name": "tractorNumber", "Value": "tractor3",        "SdsTypeCode": "String"}] |
| "Id": "AutoCompletedAsset_3", "Name": "tracerRound_Type2", "Description": "None", "Metadata": {"Id": "17", "Name": "track", "SdsTypeCode": "String", "Value": "100"}] |

Performing a `GET Search/Assets/Autocomplete?term=t&termcount=10&facetcount=10` returns the following response. 


```json 
{
    "Facets": [
        {
            "Value": "trackUnit1",
            "FacetCategories": [
                {
                    "Name": "track",
                    "DocumentCount": 1
                }
            ]
        },
        {
            "Value": "t1000",
            "FacetCategories": [
                {
                    "Name": "tractorNumber",
                    "DocumentCount": 1
                }
            ]
        }
    ],
    "Tokens": [
        {
            "Value": "tracerround",
            "DocumentCount": 2
        },
        {
            "Value": "tractornumber",
            "DocumentCount": 2
        },
        {
            "Value": "tracerround_type2",
            "DocumentCount": 1
        },
        {
            "Value": "track",
            "DocumentCount": 1
        },
        {
            "Value": "t1000",
            "DocumentCount": 1
        }
    ]
}
```

Performing a `GET Search/Assets/Autocomplete?term=t&facetcount=10` returns the following response. 


```json 
{
    "Facets": [
        {
            "Value": "trackUnit1",
            "FacetCategories": [
                {
                    "Name": "track",
                    "DocumentCount": 1
                }
            ]
        },
        {
            "Value": "t1000",
            "FacetCategories": [
                {
                    "Name": "tractorNumber",
                    "DocumentCount": 1
                }
            ]
        }
    ],
    "Tokens": []
}
```
