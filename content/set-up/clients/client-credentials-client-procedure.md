---
uid: gpClientCredentialsClient
---
# Add a client-credentials client

Client-credentials clients are used for server-to-server communication where no user interaction is required. See the following topics for more information about client-credentials clients:

- [Introduction to client-credentials clients](xref:ccClients#client-credentials-client)
- [Client-credentials client PI Server counterpart](xref:ccClients#client-credentials-pi-server)
- [Client-credentials client best practices](xref:ccClients#client-credentials-bp)

## Procedure

1. Click the ![Menu icon](../images/menu-icon.png) icon and click **Clients** (under Security).

1. From the **Client Type** drop-down list, select **Client-Credentials**. (This is the option that is displayed, by default.)

1. In the toolbar, click **Add Client**.

1. Enter a name for the client.  
   Use this name to identify the device or application that will use this client.

1. Select the roles that are appropriate for the client.  
   By default, the client has the Account Member role which cannot be removed. Roles can be modified after the client is created.

1. (Optional) Set the **Token Lifetime**.  
   Token Lifetime represents the length of time (in seconds) the access token functions before it expires. The default, 3600 seconds (one hour), is the maximum length of time. The minimum value is 60 seconds.

1. Click **Continue**.

1. In the `Add Secret` window, enter a description for the client secret.

1. Enter a date that the secret expires.  
   Ensure that the expiration date is valid for the secret. By default, the secret is set to expire one year after creation. You may specify that the secret does not expire by selecting the **Never Expires** checkbox. Secrets can be deleted later, including secrets that are set to never expire.

1. Click **Add**.  
   A window opens with the `Client Id` and `Client Secret`.  
   **IMPORTANT**:  Click the **Copy** buttons to the right of these fields to save the client secret and client Id. You will need to reference these in your applications. Once the window is closed, the client secret cannot be accessed or retrieved.
   
1. Click **Close**.  
   **Note:** In the list of secrets, the Client Id is still visible. If you did not save the client secret, select the client in the list and use the `Details` pane to remove the old secret and add a new secret.

## Related links

- [Client Credential Clients](xref:identityClientCredentialClient) API