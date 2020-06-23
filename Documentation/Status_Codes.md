# HTTP response status codes
You receive status and error codes for the HTTP request you make with the API.
The table below lists common codes in OSIsoft Cloud Services. 
For the meaning of specific response codes in context, refer to the API documentation.   

## Status codes table
|   Status Code |    Description                            |
|-------------- |------------------------------------------ |
|200            |   OK. The request was successful.         |
|201            |   Created. A resource was created as a result of a successful request.   |
|202            |   Accepted. The request has been accepted but not yet processed. |
|204            |   No content. The request was successful without changing the content the user sees. |
|207            |   Multi-status. The request was partially successful. |
|302            |   Found. Requested resource will be redirected.   |
|400            |   Bad request. The server does not understand the request because of the client error. |
|401            |   Unauthorized. Authentication has failed or not been provided.|
|403            |   Forbidden. Unauthorized.                 |
|404            |   Not found. The server cannot find the requested resource.|
|405!           |   Method not allowed. The resource does not allow the method in the request. |
|408            |   Operation timed out. The server timed out while waiting for the client request. |
|409            |   Conflict. The request conflicts with the current state of the server. |
|500            |   Internal server error. The server ran into an unexpected condition and failed to complete the request.  |
|503            |   Service unavailable.The server is not ready to handle the request. Retry later. |