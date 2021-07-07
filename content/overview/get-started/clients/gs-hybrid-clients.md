---
uid: gsHybridClients
---
# Get started with hybrid clients

Hybrid clients are used by native and server-side web applications. Authentication can be performed using any browser. The server-side code retrieves an access token and a refresh token can also be provided. See the following topics for more information about hybrid clients:

- [Introduction to hybrid clients](xref:ccClients#hybrid-client)
- [Hybrid client PI Server counterpart](xref:ccClients#hybrid-client-pi-server)
- [Hybrid client best practices](xref:ccClients#hybrid-client-bp)

### Creating a hybrid client

1. Click the ![Menu icon](images/menu-icon.png) icon and click **Clients** (under Security).

1. From the **Client Type** drop-down list, select **Hybrid**.

1. In the toolbar, click **Add Client**.

1. Enter a name for the client.  
   Use this name to identify the application that will use this client.

1. (Optional) Select the **Allow Refresh Token** check box if the application uses refresh tokens to keep users logged in to OCS.

1. Enter the URLs in the **Allowed Redirect URL(s)** text box, and click **+** to add it to the list.  
   The application specifies one of the URLs in this list when it authenticates against OCS, and the OCS identity server returns the results of the authentication to this URL.

1. (Optional) Enter URLs in the **Allowed Logout Redirect URL(s)** text box, and click **+** to add it to the list.  
   This is similar to the **Allowed Redirect URL(s)**. The application specifies one of the URLs from this list when it logs a user out of OCS, and the OCS identity server sends the user to that URL after a successful log out.

1. (Optional) Set the **Token Lifetime**.  
   Token Lifetime represents the length of time (in seconds) the access token is valid before it expires. The default, 3600 seconds (one hour), is the maximum length of time. The minimum value is 60 seconds.

1. Click **Add**.  
   The `Client Successfully Created` window displays the client Id for the client. The application must specify this client Id when it makes an authentication request. You can copy the client Id by clicking the **Copy** icon. Alternatively, after you close the window, you can retrieve the client Id from the list of clients.

## Next step

Continue with either of the following topics: 

- [Get started with client-credentials clients](xref:gsClientCredentialsClients) 
- [Get started with authorization code clients](xref:gsAuthorizationCodeClients)