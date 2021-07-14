---
uid: AssetCentricDataAPI
---

# Assets Data API

<!-- Chris Manhard asked that the TOC heading be changed from "Asset centric data" to "Assets data". So I changed the title of this topic so it would match the TOC. -->

The asset centric data API provides a quick way to retrieve data stored in an asset's referenced streams. 

In order to retrieve stream data from an asset, you must first set up stream references for a given asset. The data that is retrieved is based on the resolved asset. By default, data calls return data for all stream references. 

If you are only interested in data from a subset of streams, you must specify the streams encoded as a URL parameter. The format is to add `stream={streamName}` for each stream you are interested in.

For example, if a given asset has the following definition and you are only interested in HeaterA and PressureB for the last data call, you would send:

```text 
GET ...Namespaces/{namespaceId}/Assets/AssetStreamFilter/Data/Last?Stream={HeaterA},Stream={PressureB}
```

**Note:** Asset stream references can contain commas. In this case, the comma must be properly escaped.

```
{
    "Id": "AssetStreamFilter",
    "Name": "Demo",
    "Description": "Only for demoing stream filtering",
    "StreamReferences": 
    [
        {
            "Id": "StreamReferenceId1",
            "Name": "StreamReferenceWithEventsName"
            "StreamId": "PI_buildingMachine"
        },
        {
            "Id": "HeaterId1",
            "Name": "HeaterA"
            "StreamId": "PI_HeaterA"
        },
        {
            "Id": "PressureId1",
            "Name": "PressureB"
            "StreamId": "PI_PressureB"
        }
    ]
}
```
### Example Asset
The following asset is used in all of the sample output in the output below.
```
{
    "Id": "Idsample",
    "Name": "SampleForDemo",
    "Description": "This is a demo asset.",
    "Metadata": [
        {
            "Id": "b47c9529-7fbf-4b2d-810b-fe79d7fdb2b0",
            "Name": "RoomLocation",
            "Description": "This is what room number the asset is located.",
            "SdsTypeCode": "Double",
            "Value": 1.0
        }
    ],
    "StreamReferences": 
    [
        {
            "Id": "StreamReferenceId1",
            "Name": "StreamReferenceWithEventsName"
            "StreamId": "PI_buildingMachine_1112"
        }
    ]
}
```
***

## `Get Asset Last Data` 
Returns the last stored value for SDS streams in the resolved asset.

### Request 
```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Data/Last?stream={stream 1}[,stream={stream n}]
```

### Parameters  
`string tenantId`   
Tenant identifier

`string namespaceId`   
Namespace identifier

`string assetId`  
Asset identifier

[optional] `string[] stream`
Optional parameter consisting of a comma-separated list of stream reference names that you are interested in. By default, all data calls return data for all stream references.

### Response 
The response includes a status code and a response body.

| Status Code | Body Type | Description |
|--|--|--|
| 200 OK | OK | Array of last values for all references. |
| 207 Multi-Status | partial success | Array of last values for references. Look at child errors for those that are unsuccessful. |
| 400 Bad Request | error | The request is not valid. See the response body for additional details. |
| 403 Forbidden | error | You are not authorized to view the requested asset. |
| 404 Not Found | error | The specified asset is not found. |

#### Example response body
```json 
HTTP 200 OK
Content-Type: application/json
{
    "Results": {
        "StreamReferenceWithEventsName": [
            {
                "Timestamp": "2019-01-02T01:00:00Z",
                "Temp": 155.5,
                "Pres": 1
            }
        ],
    },
    "Errors": null
}
```

***

## `Get Asset Sampled Data` 
Returns sampled data for referenced streams. 

**Note:** The inputs to this API matches the SDS stream Get sampled values data call.  

<!--Anthony, should "Get samples values" be "Get Sampled Values" (https://osisoft-dev.zoominsoftware.io/bundle/ocs/page/api-reference/sequential-data-store/sds-read-data-api.html#get-sampled-values) -->

### Request 
```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Data/Sampled?startIndex={startIndex}&endIndex={endIndex}&intervals={intervals}&stream={stream 1}[,stream={stream n}]
```

### Parameters  
`string tenantId`   
Tenant identifier 

`string namespaceId`   
Namespace identifier

`string assetId`  
Asset identifier

`string startIndex`   
Start index for the intervals

`string endIndex`   
End index for the intervals

`int intervals`  
Number of requested intervals

[optional] `string[] stream`
Optional parameter consisting of a comma-separated list of stream reference names that you are interested in. By default, all data calls return data for all stream references.

### Response 
The response includes a status code and a response body.

| Status Code | Body Type | Description |
|--|--|--|
| 200 OK | OK | Array of sampled values for all references. |
| 207 Multi-Status | partial success | Array of sampled values for  references. Look at child errors for those that are unsuccessful. |
| 400 Bad Request | error | The request is not valid. See the response body for additional details. |
| 403 Forbidden | error | You are not authorized to view the requested asset. |
| 404 Not Found | error | The specified asset with identifier is not found. |

```json 
HTTP 200 OK
Content-Type: application/json
{
    "Results": {
        "StreamReferenceWithEventsName": [
            {
                "Timestamp": "2019-01-02T00:00:00Z",
                "Temp": 0.044,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:16:38Z",
                "Temp": 998.046,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T01:00:00Z",
                "Temp": 155.5,
                "Pres": 1
            }
        ],
    },
    "Errors": null
}
```

***

## `Get Asset Summary Data` 
Returns summary data for referenced SDS streams. 

### Request 
```text 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Data/Summaries?startIndex={startIndex}&endIndex={endIndex}&count={count}&stream={stream 1}[,stream={stream n}]
```

###  Parameters  
`string tenantId`   
Tenant identifier 

`string namespaceId`   
Namespace identifier

`string assetId`  
Asset identifier

`string startIndex`   
Start index for the intervals

`string endIndex`   
End index for the intervals

`int count`   
Number of requested intervals

[optional] `string[] stream`
Optional parameter consisting of a comma-separated list of stream reference names that you are interested in. By default, all data calls return data for all stream references.

### Response 
The response includes a status code and a response body.

| Status Code | Body Type | Description |
|--|--|--|
| 200 OK | OK | Array of summary values for all references. |
| 207 Multi-Status | partial success | Array of summary values for  references. Look at child errors for those that are unsuccessful. |
| 400 Bad Request | error | The request is not valid. See the response body for additional details. |
| 403 Forbidden | error | You are not authorized to view the requested asset. |
| 404 Not Found | error | The specified asset with identifier is not found. |

```json 
HTTP 200 OK
Content-Type: application/json
{
    "Results": {
        "StreamReferenceWithEventsName": [
            {
                "Start": {
                    "Timestamp": "2019-01-01T08:00:00Z",
                    "Temp": 0.044,
                    "Pres": 1
                },
                "End": {
                    "Timestamp": "2019-02-06T20:00:00Z",
                    "Temp": 155.5,
                    "Pres": 1
                },
                "Summaries": {
                    "Count": {
                        "Timestamp": 1000,
                        "Temp": 1000,
                        "Pres": 1000
                    },
                    "Minimum": {
                        "Temp": 0.044,
                        "Pres": 1.0
                    },
                    "Maximum": {
                        "Temp": 998.046,
                        "Pres": 1.0
                    },
                    "Range": {
                        "Temp": 998.0020000000001,
                        "Pres": 0.0
                    },
                    "Total": {
                        "Temp": 498779.61199999356,
                        "Pres": 1001.0
                    },
                    "Mean": {
                        "Temp": 498.28133066933077,
                        "Pres": 1.0
                    },
                    "StandardDeviation": {
                        "Temp": 288.4561823749973,
                        "Pres": 0.0
                    },
                    "PopulationStandardDeviation": {
                        "Temp": 288.31206236481444,
                        "Pres": 0.0
                    },
                    "WeightedMean": {
                        "Temp": 153.11692828545156,
                        "Pres": 1.0
                    },
                    "WeightedStandardDeviation": {
                        "Temp": 25.424619899757136,
                        "Pres": 0.0
                    },
                    "WeightedPopulationStandardDeviation": {
                        "Temp": 25.411917116101474,
                        "Pres": 0.0
                    },
                    "Skewness": {
                        "Temp": 0.0011013861675857883,
                        "Pres": "NaN"
                    },
                    "Kurtosis": {
                        "Temp": -1.19976760290962,
                        "Pres": "NaN"
                    }
                }
            },
            {
                "Start": {
                    "Timestamp": "2019-03-15T08:00:00Z",
                    "Temp": 155.5,
                    "Pres": 1
                },
                "End": {
                    "Timestamp": "2019-04-20T20:00:00Z",
                    "Temp": 155.5,
                    "Pres": 1
                },
                "Summaries": {
                    "Count": {
                        "Timestamp": 0,
                        "Temp": 0,
                        "Pres": 0
                    },
                    "Minimum": {
                        "Temp": 155.5,
                        "Pres": 1.0
                    },
                    "Maximum": {
                        "Temp": 155.5,
                        "Pres": 1.0
                    },
                    "Range": {
                        "Temp": 0.0,
                        "Pres": 0.0
                    },
                    "Total": {
                        "Temp": 155.5,
                        "Pres": 1.0
                    },
                    "Mean": {
                        "Temp": 155.5,
                        "Pres": 1.0
                    },
                    "StandardDeviation": {
                        "Temp": "NaN",
                        "Pres": "NaN"
                    },
                    "PopulationStandardDeviation": {
                        "Temp": 0.0,
                        "Pres": 0.0
                    },
                    "WeightedMean": {
                        "Temp": 155.5,
                        "Pres": 1.0
                    },
                    "WeightedStandardDeviation": {
                        "Temp": "NaN",
                        "Pres": "NaN"
                    },
                    "WeightedPopulationStandardDeviation": {
                        "Temp": 0.0,
                        "Pres": 0.0
                    },
                    "Skewness": {
                        "Temp": "NaN",
                        "Pres": "NaN"
                    },
                    "Kurtosis": {
                        "Temp": "NaN",
                        "Pres": "NaN"
                    }
                }
            }
        ],
    "Errors": null
   }
}
```

***

## `Get Asset Window Data`
Returns window data for referenced SDS streams.

### Request

```
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Data?startIndex={startIndex}&endIndex={endIndex}&stream={stream 1}[,stream={stream n}]
```

### Parameters
`string tenantId`  
Tenant identifier

`string namespaceId`   
Namespace identifier

`string assetId`  
Asset identifier

`string startIndex`   
Start index for the intervals

`string endIndex`   
End index for the intervals

[optional] `string[] stream`
Optional parameter consisting of a comma-separated list of stream reference names that you are interested in. By default, all data calls return data for all stream references.

### Response
The response includes a status code and a response body.

| Status Code | Body Type | Description |
|--|--|--|
| 200 OK | OK | Array of window values for all references. |
| 207 Multi-Status | partial success | Array of window values for  references. Look at child errors for unsuccessful values. |
| 400 Bad Request | error | The request is not valid. See the response body for additional details. |
| 403 Forbidden | error | You are not authorized to view the requested asset. |
| 404 Not Found | error | The specified asset with identifier is not found. |

```json 
HTTP 200 OK
Content-Type: application/json
{
    "Results": {
        "StreamReferenceWithEventsName": [
            {
                "Timestamp": "2019-01-02T00:00:00Z",
                "Temp": 0.044,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:01Z",
                "Temp": 1.045,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:02Z",
                "Temp": 2.045,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:03Z",
                "Temp": 3.045,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:04Z",
                "Temp": 4.045,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:05Z",
                "Temp": 5.045,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:06Z",
                "Temp": 6.045,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:07Z",
                "Temp": 7.045,
                "Pres": 1
            },
            {
                "Timestamp": "2019-01-02T00:00:08Z",
                "Temp": 8.045,
                "Pres": 1
            },       ],
    },
    "Errors": null
}

```
***

## `Get Asset Interpolated Data` 
Returns interpolated data for referenced SDS streams. 

### Request 
``` 
GET api/v1-preview/Tenants/{tenantId}/Namespaces/{namespaceId}/Assets/{assetId}/Data/Interpolated?startIndex={startIndex}&endIndex={endIndex}&count={count}&stream={stream 1}[,stream={stream n}]
```

###  Parameters  
`string tenantId`   
Tenant identifier 

`string namespaceId`   
Namespace identifier

`string assetId`  
Asset identifier

`string startIndex`   
Start index for the intervals

`string endIndex`   
End index for the intervals

`int count`   
The number of requested intervals

[optional] `string[] stream`
Optional parameter consisting of a comma-separated list of stream reference names that you are interested in. By default, all data calls return data for all stream references.

### Response 
The response includes a status code and a response body.

| Status Code | Body Type | Description |
|--|--|--|
| 200 OK | OK | Array of summary values for all references. |
| 207 Multi-Status | partial success | Array of summary values for  references. Look at child errors for those that are unsuccessful. |
| 400 Bad Request | error | The request is not valid. See the response body for additional details. |
| 403 Forbidden | error | You are not authorized to view the requested asset. |
| 404 Not Found | error | The specified asset with identifier is not found. |

```json 
HTTP 200 OK
Content-Type: application/json
{
	"Results": {
		"StreamReferenceWithEventsName": [
			{
                "Timestamp": "2019-01-02T00:00:05Z",
                "Temp": 5.045,
                "Pres": 1
			},
			{
				"Timestamp": "2020-04-12T08:00:00Z",
                "Temp": 3.045,
                "Pres": 11
			},
			{
				"Timestamp": "2020-06-29T05:20:00Z",
                "Temp": 54.045,
                "Pres": 11
			}]
	},
	"Errors": null
}

```
