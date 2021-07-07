---
uid: ccClients
---
# Clients

Clients allow applications to authenticate against OSIsoft Cloud Services (OCS) from outside the OCS portal. OCS supports the following types of clients, each of which support different types of applications:

- [Client-credentials clients](#client-credentials-client)
- [Authorization code clients](#authorization-code-client)
- [Hybrid clients](#hybrid-client) <!-- Josh Kim Mar19021: Similar to the comment as before where we should ask if Hybrid Clients are still worth mentioning?. -->

You must have the Tenant Administrator role to add and manage clients in a tenant.

## <a name="client-credentials-client"></a>Client-credentials clients

Use client-credentials clients for server-to-server communication that does not require user interaction. The client typically authenticates with the token endpoint using its client ID and secret. A secret is a unique key generated for each client to connect to OSIsoft assets, resources, and services for a time-limited period. Because secrets allow access to data, you need to keep them secure.

### <a name="client-credentials-pi-server"></a>Client-credentials client PI Server counterpart

Client-credentials clients are very similar to Microsoft Windows service accounts that applications can use to authenticate against PI Data Archive or PI AF server. 

### <a name="client-credentials-bp"></a>Client-credentials client best practices

Use following best practices with a client credentials client:

- Create a separate client-credentials client for each device or instance of an application that connects to OCS. This ensures that secrets can be discretely managed for individual applications and that you know which applications are connecting to OCS.

- Ensure that client secrets are stored securely where they are used.

- Use secrets that expire and rotate them on a schedule. When it is time to switch to a new secret, OSIsoft recommends that you create the new secret, redirect the application to use the new secret, and only delete the old secret from the client when it is no longer being used.

##  <a name="authorization-code-client"></a>Authorization code clients

Authorization code clients are used with customer web applications that use OCS as their backend. They provide a secure means of authenticating users of the website to view OCS assets. The authorization code client is paired with a client ID. The web application that is using the client to authenticate users must include the client ID in its code.

Authorization code clients are used to authenticate using any browser. Upon successful authentication, an authorization code is provided to the client. This authorization code is exchanged for an access token using PKCE (Proof Code for Code Exchange) which is a more secure authentication flow. No refresh token is provided.

### <a name="authorization-code-pi-server"></a>Authorization code client PI Server counterpart

Authorization code clients have no direct PI Server equivalent, but they are similar to the combined behavior of a trust and mappings in PI Data Archive. These clients are similar to trusts because they only allow users to access OCS if the application that uses them meets certain criteria, for example, the application must be served at a specific URL. However, like a mapping, authorization code clients require the user to authenticate as a known user account within the tenant.

### <a name="authorization-code-bp"></a>Authorization code client best practices

The following best practices are recommended when you use an authorization code client:

- Use authorization code clients in web applications or with services where users must be authenticated and it is not possible to store a client secret securely.

- Because refresh tokens are not generated in this flow, web applications should use an iframe to request a new token before the existing token expires. Otherwise, the user will have to explicitly log in again to get a new token once their token expires.

## <a name="hybrid-client"></a>Hybrid clients

Hybrid clients are used by native and server-side web applications. This client utilizes the user credentials to authenticate with the identity provider. Once the user is authenticated, then the server-side client steps in and server-to-server communication commences. Authentication can be performed using any browser. The server-side code retrieves an access token and a refresh token can also be provided.

### <a name="hybrid-client-pi-server"></a>Hybrid client PI Server counterpart

Hybrid clients have no direct PI Server equivalent, but they are similar to the combined behavior of a trust and mappings in PI Data Archive. These clients are similar to trusts because they only allow users to access OCS if the application that uses them meets certain criteria, for example, the application must be served at a specific URL. However, like a mapping, hybrid clients require the user to authenticate as a known user account within the tenant.

### <a name="hybrid-client-bp"></a>Hybrid client best practices

OSIsoft recommends the following best practices when you use a hybrid client:

- Use hybrid clients in web applications or services where users authenticate against OCS through a web browser, but a secure backend that stores the secrets performs the actual authentication.

- Use caution when deciding whether to allow refresh tokens for your hybrid client. Where possible, it is a more secure practice to use an iframe to request a new token before the old token expires rather than use a refresh token.
