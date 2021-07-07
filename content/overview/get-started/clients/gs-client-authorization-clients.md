---
uid: gsAuthorizationCodeClients
---
# Get started with authorization code clients

Authorization code clients are used with customer web applications that use OCS as their backend. They provide a secure means of authenticating users of the website to view OCS assets. See the following topics for more information about authorization code clients:

- [Introduction to authorization code clients](xref:ccClients#authorization-code-client)
- [Authorization code client PI Server counterpart](xref:ccClients#authorization-code-pi-server)
- [Authorization code best practices](xref:ccClients#authorization-code-bp)

### Creating an authorization code client

1. Click the ![Menu icon](images/menu-icon.png) icon and click **Clients** (under Security).

1. From the **Client Type** drop-down list, select **Authorization Code**.

1. In the toolbar, click **Add Client**.

1. Enter a name for the client. 
   Use this name to identify the device or application that will use this client.

1. Enter the URLs in the **Allowed Redirect URL(s)** text box, and click  **+**  to add it to the list.  
   The application specifies one of the URLs in this list when it authenticates against OCS, and the OCS identity server returns the results of the authentication to this URL.

1. (Optional) Enter URLs in the **Allowed Logout Redirect URL(s)** text box, and click **+**  to add it to the list. 
   This is similar to **Allowed Redirect URL(s)**. The application specifies a URL from this list when it logs out of OCS, and the OCS identity server sends the user to this URL after a successful log out.

1. (Optional) Enter URLs in the **Allowed CORS Origin(s)** text box, and click  **+**  to add it to the list.  
   This can be used to designate other URLs from which the application is allowed to make requests against OCS. For example, this may be necessary if the user authenticates from an application running at `https://authenticate.com`, but the result of the authentication is sent to an application running at a different URL, for example, `https://application.com`.
   
1. (Optional) Set the **Token Lifetime**.  
   Token Lifetime represents the length of time (in seconds) the access token is valid before it expires. The default, 3600 seconds (one hour), is the maximum length of time. The minimum value is 60 seconds.

1. Click **Add**.  
   The `Client Successfully Created` window displays the client Id for the client. The application must specify this client Id when it makes an authentication request. After you close this window, you can also retrieve the client Id from the list of clients.

## Next step

Continue with either of the following topics:

- [Get started with client-credentials clients](xref:gsClientCredentialsClients) 
- [Get started with hybrid clients](xref:gsHybridClients)