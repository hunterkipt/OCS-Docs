---
uid: CredentialManagement
---

# Credential management

All connections to OCS are made using secure credentials, which are either user credentials or client secrets.

## User credentials and authentication

The management of user credentials and authentication is delegated to external identity providers.

## Client secrets and authentication

Client applications can authenticate a connection to OCS using a client Id and client secret pair. The client Id is the public identifier of the application. Client Ids are valid GUIDs that are randomly generated or provided by the caller upon creation. The client Id does not need to be protected the same way as a client secret.<!-- Angela Flores 6/18/21 What does "provided by the caller upon create" mean? -->

A client secret is a unique key that OCS generates for each client credential client to authenticate a connection to OCS for a limited period of time. Each client can have a maximum of 10 secrets at a time. Client secrets have a description, which contains information about their purpose and usage, and an expiration date. <!-- Angela Flores 6/18/21 This would be a good place to link to the task topic for creating client credential clients. Also, why isn't this entire topic in that section of the documentation? It really seems to be about how client credentials work. -->

**Caution:** As a security best practice, always create client secrets that expire. 

OCS generates the secret value using a cryptographically secure, random number generator. The secret value is available only upon creation. OCS does not maintain the actual value of the secret. If a secret value were ever lost, delete the secret and create a new one. 

### Client secret security

Keep client secrets secure. Do not store client secrets in text or transfer them through insecure channels. OSIsoft recommends developing a strategy for managing and securing client secrets. Consider the following options while developing your security strategy:

- Use a cloud key management service, such as Azure Key Vault, Windows Credential Manager, Amazon Key Management Service, and Google Cloud Key Management, to persist and access the client secret for the environment where the client application is running.
- Refer to the Microsoft instructions on how to handle secrets and passwords in applications in the article [Handling Passwords](https://docs.microsoft.com/en-us/windows/win32/secbp/handling-passwords). 
- Refer to the documentation from the programing language or framework you use to develop applications to determine what secret management security features they provide. 
- Use the hardware security module on the device where your application runs.

### Client secret rotation

OSIsoft recommends using a secret rotation pattern to change secrets before they expire. Generate a new secret before the current secret expires and provide it to the client. The client should have logic to start using the new secret. Once the client is using the new secret, delete the old secret. 

**Caution:** Do not extend and reuse client secrets that are close to their expiration date. 
