---
uid: sdsQuickStart
---

# Quick Start: Sequential Data Store

Sequential Data Store (SDS) is a sophisticated data store. The steps described here show a very simple interaction with SDS.
To follow along with the steps in this section, you need a tenant, a user account and associated security credentials. 
Email [OCS support](mailto://cloudservices@osisoft.com) at OSIsoft Cloud Services to get access.

You will be mainly working on the [OSIsoft Cloud Services portal](https://cloud.osisoft.com/). Sign into the portal using the credentials associated with the tenant. You will also need a namespace and administrative client keys. 

## Before you get started 
To work with SDS, you must first acquire a client identity, secret and authentication token. 

### Acquire client identity and secret

The application acts as a confidential client – an application that is capable of securely maintaining a secret.
OSIsoft Cloud Services supports confidential client authentication flow with a client identifier (Client Id) and a client secret.

To acquire a client identity from the portal, open the navigation menu and select **Security** > **Clients**.

You can either select an existing client or create a new one. For a new client, select **Add Client** and follow the 
prompts for creating a client identity and client secret. Be sure to keep a record of the client secret.
For an existing client, highlight the desired client and select **Client Details** to see configuration information. 

You need the tenant identity, client identity, and client secret to proceed. 

The tenant identity, client identity, and client secret are used to acquire a security token from an identity 
provider, Azure Active Directory in this case.

### Acquire authentication token

You use the tenant identity, client identity, and client secret to acquire an access token 
from Azure Active Directory. Select one of the clients from the list to see configuration information 
and code samples in various languages which are shown on tabs in the right panel.

## Step 1: Acquire namespace

In the portal, open the navigation menu ![navigation menu](../images/icon-navigation.png) and select **Data Management** > **Namespaces**.
You can use an existing namespace or create a new one.

## Step 2: Create data types

A type describes the structure of a single measured event or object. A stream has an associated 
type and stores a stream of events or objects that take the shape of that type.

A type consists of one or more data properties, one of which must represent an index. Indexes can be 
simple (a single integer property, for example) or compound (represented by multiple properties). 
``DateTime`` is a common index for time-series stores. 

SDS supports a wide variety of property types, both simple (integers, strings and floats, for example) 
and complex (lists, arrays and enumerations, for example). Properties can be of any complex type. 
See [Types](xref:sdsTypes#sdstypecode) for a detailed list of supported data types.

The type is defined in JSON and is posted on OSIsoft Cloud Services (OCS) endpoint.

```json
POST /api/v1/Tenants/{tenantId}/Namespaces/{namespaceId}/Types/{typeId}  
HTTP/1.1
Authorization: Bearer <bearer-token>
Content-Length: 1562
Content-Type: application/json
Host: dat-b.osisoft.com
{
    "Id": "Simple",
    "Name": "Simple",
    "Description": null,
    "SdsTypeCode": 1,
    "IsGenericType": false,
    "IsReferenceType": false,
    "GenericArguments": null,
    "Properties": [
        {
            "Id": "Time",
            "Name": "Time",
            "Description": null,
            "Order": 0,
            "IsKey": true,
            "FixedSize": 0,
            "SdsType": {
                "Id": "19a87a76-614a-385b-ba48-6f8b30ff6ab2",
                "Name": "DateTime",
                "Description": null,
                "SdsTypeCode": 16,
                "IsGenericType": false,
                "IsReferenceType": false,
                "GenericArguments": null,
                "Properties": null,
                "BaseType": null,
                "DerivedTypes": null,
                "InterpolationMode": 0,
                "ExtrapolationMode": 0
            },
            "Value": null,
            "Uom": null,
            "InterpolationMode": null
        },
        {
            "Id": "State",
            "Name": "State",
            "Description": null,
            "Order": 0,
            "IsKey": false,
            "FixedSize": 0,
            "SdsType": {
                "Id": "e20bdd7e-590b-3372-ab39-ff61950fb4f3",
                "Name": "State",
                "Description": null,
                "SdsTypeCode": 609,
                "IsGenericType": false,
                "IsReferenceType": false,
                "GenericArguments": null,
                "Properties": [
                    {
                        "Id": "Ok",
                        "Name": null,
                        "Description": null,
                        "Order": 0,
                        "IsKey": false,
                        "FixedSize": 0,
                        "SdsType": null,
                        "Value": 0,
                        "Uom": null,
                        "InterpolationMode": null
                    },
                    {
                        "Id": "Warning",
                        "Name": null,
                        "Description": null,
                        "Order": 0,
                        "IsKey": false,
                        "FixedSize": 0,
                        "SdsType": null,
                        "Value": 1,
                        "Uom": null,
                        "InterpolationMode": null
                    },
                    {
                        "Id": "Alarm",
                        "Name": null,
                        "Description": null,
                        "Order": 0,
                        "IsKey": false,
                        "FixedSize": 0,
                        "SdsType": null,
                        "Value": 2,
                        "Uom": null,
                        "InterpolationMode": null
                    }
                ],
                "BaseType": null,
                "DerivedTypes": null,
                "InterpolationMode": 0,
                "ExtrapolationMode": 0
            },
            "Value": null,
            "Uom": null,
            "InterpolationMode": null
        },
        {
            "Id": "Measurement",
            "Name": "Measurement",
            "Description": null,
            "Order": 0,
            "IsKey": false,
            "FixedSize": 0,
            "SdsType": {
                "Id": "6fecef77-20b1-37ae-aa3b-e6bb838d5a86",
                "Name": "Double",
                "Description": null,
                "SdsTypeCode": 14,
                "IsGenericType": false,
                "IsReferenceType": false,
                "GenericArguments": null,
                "Properties": null,
                "BaseType": null,
                "DerivedTypes": null,
                "InterpolationMode": 0,
                "ExtrapolationMode": 0
            },
            "Value": null,
            "Uom": null,
            "InterpolationMode": null
        }
    ],
    "BaseType": null,
    "DerivedTypes": null,
    "InterpolationMode": 0,
    "ExtrapolationMode": 0
}
```
To help users develop .NET client applications for SDS, OSIsoft provides OCS client libraries through NuGet packages, 
[OCSClients](https://www.nuget.org/packages/OSIsoft.OCSClients/). OCSClients consists of necessary libraries
to connect to OCS and manage data. Note that SDS client libraries are only available in .NET.

You can use ``SdsTypeBuilder`` in .NET client libraries to create types:

```csharp
public enum State
{
    Ok,
    Warning,
    Alarm
}

public class Simple
{
    [SdsMember(IsKey = true, Order = 0)]
    public DateTime Time { get; set; }
    public State State { get; set; }
    public Double Measurement { get; set; }
}

SdsType simpleType = SdsTypeBuilder.CreateSdsType<Simple>();
simpleType.Id = "Simple";
simpleType.Name = "Simple";
simpleType.Description = "Basic sample type";
await config.CreateTypeAsync(simpleType);
```


## Step 3: Create stream

A stream has an associated type and stores a stream of events or objects that take the shape of that type. 
For more information, see [Streams](xref:sdsStreams).

Define and post a JSON representation of stream to OCS endpoint.

```json 
POST /api/v1/Tenants/{tenantId}/Namespaces/{namespaceId}/Streams/{streamId}  
HTTP/1.1
Authorization: Bearer <bearer-token>
Content-Length: 139
Content-Type: application/json
Host: dat-b.osisoft.com
{  
    "Id": "Simple",
    "Name": "Simple",
    "Description": null,
    "TypeId": "Simple",
    "Indexes": null,
    "InterpolationMode": null,
    "ExtrapolationMode": null,
    "PropertyOverrides": null 
}
```
You can create a stream for simple events also by using .NET client libraries method:

```csharp
SdsStream simpleStream = new SdsStream() 
{
    Id = "Simple",
    Name = "Simple",
    TypeId = simpleType.Id
};

simpleStream = config.CreateStreamAsync(simpleStream);
```

## Step 4: Write data

SDS supports a number of methods for adding and updating data. In this section, you will insert data. 
Inserts fail if events with the same index already exist in the database.
Update adds new events and replaces existing events.
For more information, see [Write data](xref:sdsWritingData).

Add data to SDS by posting a JSON serialized event to OCS endpoint:

```json
POST /api/v1/Tenants/{tenantId}/Namespaces/{namespaceId}/Streams/{streamId}/Data
HTTP/1.1
Authorization: Bearer <bearer-token>
Content-Length: 57
Content-Type: application/json
Host: dat-b.osisoft.com
[
    {  
       "Time":"2017-08-17T17:21:36.3494129Z",
       "State":0,
       "Measurement":123.45
    }
]
```
You can alternatively use .NET client libraries method ``InsertValueAsync``:

```csharp
Simple value = new Simple()
{
    Time = DateTime.UtcNow,
    State = State.Ok,
    Measurement = 123.45
};

await client.InsertValueAsync(simpleStream.Id, value);
```

## Step 5: Read data

SDS includes different read methods for retrieving data from streams. 
For more information, see [Read data](xref:sdsReadingData).
The examples below are of reading value that was recently written.
You need an index or indexes in a read data call, a timestamp of that value in this case.

Read a value from SDS at a distinct index by making a REST API call to OCS:

```json
GET api/v1/Tenants/{tenantId}/Namespaces/{namespaceId}/Streams/{streamId}/Data?index=2017-08-17T17:21:36.3494129Z 
HTTP/1.1 200
Content-Type: application/json
[
    {
        "Time": "2017-08-17T17:21:36.3494129Z",
        "State": 0,
        "Measurement": 20
    }
]
```

One or more indexes are needed in most read calls to determine which data to read. 
The simplest way to supply an index is as a string. A `DateTime` is used as an index below in .NET:

```csharp
string index = DateTime.Parse("2017-08-17T17:21:36.3494129Z")
               .ToUniversalTime().ToString("o"); 
```

To read a value at a distinct index, you can use the SDS .NET client libraries method.
`Time` is the index here, which is a property of a type named `Simple`: 

```csharp
value = await client.GetDistinctValueAsync<Simple>(simpleStream.Id, index); 
```

## Error handling 

Refer to the following sections to troubleshoot: 


### Handling transient service interruptions

All applications that communicate with remote systems must manage transient faults. 
Temporary service interruptions are a fact of life in real-world cloud applications. 

If you access SDS with .NET client libraries methods, transient fault handling is built in; 
the SDS client automatically retries error codes identified as transient.

If you are directly calling into the OCS through SDS REST APIs (not using .NET), you should 
consider creating your own retry logic to handle errors identified as transient.
In this case, we recommend a logic which returns HTTP status code ``503: Service Unavailable``:
an immediate first retry followed by an exponential backoff.


### SDS client error

If you access SDS using the .NET client libraries methods, note that any non-success
responses returned to the client are packaged in an ``SdsHttpClientException``,
which is an exception with the following additional properties:

```csharp
string ReasonPhrase
HttpStatusCode StatusCode
Dictionary<string, object> Errors 
```

* The StatusCode provides the ``HttpStatusCode`` from the response.
* The ``ReasonPhrase`` might provide additional information regarding the cause of the exception. 
  You should always evaluate the ``ReasonPhrase`` in addition to the ``StatusCode`` to determine the cause of the exception.
* The errors collection may provide additional specific error information based on the response. For example, 
  if an ``InsertValues`` call failed because it conflicted with an existing event in the stream, the index of the 
  conflicting event will be included in this dictionary.

### SDS timeout request header

Handling timeout issues can be difficult and confusing in a distributed programming environment. When a client 
times out, for example, the request is terminated before the client receives a response from the server. Meanwhile, the application is
unaware of the state of the server.

One solution is to use the ``Request-Timeout`` header, which is recognized by many services in OCS. Using the 
header, you can tell the server how long to spend on a particular request before timing out. If possible, the server 
terminates the request if the time it takes to process the request exceeds the timeout value set in the header.

To specify the request timeout value, include the Request-Timeout header and specify the value in seconds.

> [!NOTE]
>
> For write data requests, the `Request-Timeout` header may not be acknowledged by SDS.
> It is to allow ample time for a large amount of data to be written. 
> [Write data APIs](xref:sdsWritingDataApi) adhere to an internal timeout setting of 5 minutes (300 seconds.)
