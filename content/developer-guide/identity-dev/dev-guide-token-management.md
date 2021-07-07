---
uid: TokenManagement
---

# Token management

A successful authentication process creates a token that grants access to protected resources. A valid access token is as critical as passwords and secrets and should be protected the same way.

A token is sent as part of the Authorization header with all requests to OSIsoft resources and services. Clients can be configured to generate access tokens with varying expiration between 60 seconds and one hour. The default access token lifespan is one hour. There is no limit on the number of access tokens a client can be issued at any given time. <!--Angela Flores 6/23/21 Why mention the predefined fields in the token if there is no further explanation of them?-->

## Token management with client credential clients

For applications using client credential client authorization, the application must be running in a secured device/virtual machine that you either own or have provisioned. Only authorized persons should have access to the application and its associated secrets.

## Token management with authorization code clients

For applications using authorization code clients and running in a browser, the OWASP foundation suggests storing the access token in the browser session Storage container.<!--Angela Flores 6/23/21 What is The OWASP foundation?-->
