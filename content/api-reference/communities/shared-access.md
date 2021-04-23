---
uid: shared-access-routes
---

***

## Shared Access

This service brokers all requests for a shared resource in a community. Currently, streams are the only shared resources.

When a resource is shared in a community, users with the **Community Member** role will be able to access metadata and data for that resource. Community members are limited to read-only access.

### Request

> [!IMPORTANT]
>
> All routes use the standard SDS service. Please see [Streams](xref:sdsStreams) and [API calls for reading data](xref:sdsReadingDataApi) in the [Sequential Data Store](xref:sds) section for specific request and response information.

***

> [!NOTE]
>
> Any routes that modify a shared resource will be unavailable.

#### Available Shared Stream Endpoints

```text

GET  api/v1-preview/communities/{communityId}/tenants/{tenantId}/namespaces/{namespaceId}/streams/{streamId}

```

```text

GET  api/v1-preview/communities/{communityId}/tenants/{tenantId}/namespaces/{namespaceId}/streams/{streamId}/data/{*more} 

```

```text

POST api/v1-preview/communities/{communityId}/tenants/{tenantId}/namespaces/{namespaceId}/streams/{streamId}/data/Transform/{*more} 

```

```text

POST api/v1-preview/communities/{communityId}/tenants/{tenantId}/namespaces/{namespaceId}/streams/{streamId}/data/Join/{*more} 

```

```text

GET  api/v1-preview/communities/{communityId}/tenants/{tenantId}/namespaces/{namespaceId}/streams/{streamId}/metadata

```

```text

POST api/v1-preview/communities/{communityId}/tenants/{tenantId}/namespaces/{namespaceId}/streams/{streamId}/metadata/{key}

```

```text

POST api/v1-preview/communities/{communityId}/tenants/{tenantId}/namespaces/{namespaceId}/streams/{streamId}/tags

```

#### Parameters

`string communityId`
Community identifier - validated to be a `Guid`

`string tenantId`
Tenant identifier - validated to be a `Guid`

`string namespaceId`
Namespace identifier

`string streamId`
Stream identifier

[Optional] `string key`  
[Optional] The key specifying the metadata value of interest  

### Response

> [!IMPORTANT]
>
> All routes use the standard SDS service. See [Streams](xref:sdsStreams) and [API calls for reading data](xref:sdsReadingDataApi) in the [Sequential Data Store](xref:sds) section for specific request and response information.

| Status Code               | Response Type | Description                                                     |
|---------------------------|---------------|-----------------------------------------------------------------|
| 200 OK                    | Multiple      | See [Sequential Data Store](xref:sds) for specific information. |
| 400 Bad Request           | error         | Missing or invalid inputs                                       |
| 401 Unauthorized          | error         | You are not authorized for this operation                       |
| 403 Forbidden             | error         | You are not authorized for this operation                       |
| 404 Not Found             | error         | The data view or query does not exist                           |
| 500 Internal Server Error | error         | An error occurred while processing the request.                 |

### Authorization

Allowed for specific **Community Member** role for community where the stream is shared. Having the **Community Member** role indicates you are a member of the community.

> [!IMPORTANT]
>
> Both the user's tenant and the tenant of the shared resource must be a part of the community in the route.

### Example

Responses will be identical to those from the SDS service. Here are a couple of examples (Source:[Read data API](xref:sdsReadingDataApi))

#### Example 1 request

```text
GET api/v1-preview/communities/{communityId}/Tenants/{tenantId}/Namespaces/{namespaceId}/Streams/Simple/Data?index=2017-11-23T13:00:00Z&searchMode=Next
```

The request has an index that matches the index of an existing event, but since a `SdsSearchMode` of ``next`` was specified, the response contains the next event in the stream after the specified index:

#### Example 1 response body

```text
HTTP/1.1 200
Content-Type: application/json
```

```json
[
    {
        "Time": "2017-11-23T14:00:00Z",
        "State": 0,
        "Measurement": 20
    }
]
```

#### Example 2 request

```text
GET api/v1-preview/communities/{communityId}/Tenants/{tenantId}/Namespaces/{namespaceId}/Streams/Simple/Data?index=2017-11-23T13:30:00Z&searchMode=Next
```

The request specifies an index that does not match an index of an existing event. The next event in the stream is retrieved.

#### Example response body

```text
HTTP/1.1 200
Content-Type: application/json
```

```json
[
    {
        "Time": "2017-11-23T14:00:00Z",
        "State": 0,
        "Measurement": 20
    }
]
```
