---
uid: identityConsent
---

# Consent

There are three possible consent paths when integrating your OCS tenant with your AAD tenant. The different paths depend on if you wish to use Advanced Integration and whether you are provisioning a new OCS tenant or modifying an existing OCS tenant. The consent paths are as follows:

* Path 1: Add AAD as an identity provider to an OCS tenant without Advanced Integration. Advanced Integration can be added later.
* Path 2: Add AAD as an identity provider to an OCS tenant with Advanced Integration at the same time.
* Path 3: Add Advanced Integration to an OCS tenant which is already configured with AAD as an identity provider.

## Consent path 1: Adding an AAD identity provider to your OCS tenant with basic-level integration only

In order to add your AAD tenant as an identity provider for your OCS tenant, your AAD administrator must agree to only one consent. This consent grants permission for your AAD tenant to be an identity provider for your OCS tenant (basic-level integration).

1. For a new tenant, an email will be sent to your AAD administrator who has the privileges with a link to grant OCS access to your AAD.
2. Your AAD administrator will click on the link provided in the email which will bring them to a login page. Your administrator will need to log in as a user with the Global Administrator role on your AAD.
3. Upon successful login, your administrator will be prompted to grant consent for a single application: OCS Identity.
4. Your administrator should click Accept in the Permissions requested prompt window to grant consent.
5. OSIsoft will get a confirmation that the consent process has been completed.
6. A final email will be sent to the initial user who either signed up for the account (if this is a new account being provisioned), or who requested that AAD be added as an identity provider (if AAD is being added to an existing account), informing them that the consent has been granted.
7. At that point, this initial user will be able to use the link provided to activate his profile and sign in to your OCS account (if this is a new account being provisioned), and other users can now be added using credentials from AAD.

## Consent path 2: Adding an AAD identity provider to your OCS tenant with advanced integration at the same time

In order to integrate your AAD tenant with OCS using Advanced Integration, your AAD administrator must agree to two separate consents. These two consents are to grant the following:

1. Consent 1: Granting permission for your AAD tenant to be an identity provider for your OCS tenant (basic-level integration)
2. Consent 2: Granting permission for OCS Identity to sign in and read all users' full profiles and all group memberships. (Advanced Integration).
Note that this is a two-step consent process. You must first grant consent for basic-level integration. If you do not wish to use Advanced Integration, you can skip the second consent. However, in order to use Advanced Integration, the second consent must be granted.

1. An email will be sent to your AAD administrator who has the privileges with a link to grant OCS access to your AAD. This email contains two links: the first link to consent to AAD as an identity provider for OCS, and the second link to consent to Advanced Integration. For a new tenant being provisioned with both AAD and Advanced Integration, no users will be able to sign in to the account until both consents are given.
2. Your AAD administrator will click on the first link provided in the email which will bring them to a login page. Your administrator will need to log in as a user with the Global Administrator role on your AAD.
3. Upon successful login, your administrator will be prompted to grant consent for a single application: OCS Identity.
4. Your administrator should click Accept in the Permissions requested prompt window to grant consent.
5. OSIsoft will get a confirmation that the consent process has been completed.
6. Your AAD administrator will then click on the second link in the original email to grant permission for OCS Identity to sign in and read all users' full profiles and all group memberships.
7. Your administrator should agree to the advanced integration by clicking the consent button.
8. A final email will be sent to the initial user who signed up for the account, informing them that they can sign in with their AAD account.
9. At that point, this initial user will be able to use the link provided to activate his profile and sign in to your OCS account.

## Consent path 3: Adding advanced integration to an existing OCS tenant configured with AAD as an identity provider

In order to enable Advanced Integration on an OCS tenant that is already provisioned with AAD, your AAD administrator must agree to a single consent granting permission for OCS Identity to sign in and read all users' full profiles and all group memberships.

1. Your AAD administrator will then click on the second link in the original email to grant permission for OCS Identity to sign in and read all users' full profiles and all group memberships.
2. Your administrator should agree to the advanced integration by clicking the consent button.
3. A final email will be sent to the initial user who signed up for the account, informing them that they can sign in with their AAD account.
4. At that point, this initial user will be able to use the link provided to activate his profile and sign in to your OCS account.

Note that until this consent for Advanced Integration has been granted, the AAD identity provider will be in a partially-consented state. In this partially-consented state, pre-existing users can still access the account, and new users can also still be added for the AAD identity provider, but without the features of Advanced Integration (by search).

1. An email will be sent to your AAD administrator who has the privileges to grant OCS access to your AAD. This email contains two links: the first link to consent to AAD as an identity provider for OCS, and the second link to consent to Advanced Integration. For a new tenant being provisioned with both AAD and Advanced Integration, no users will be able to sign in to the account until both consents are given.
2. Your AAD administrator will click on the first link provided in the email which will bring them to a login page. Your administrator will need to log in as a user with the Global Administrator role on your AAD.
3. Upon successful login, your administrator will be prompted to grant consent for a single application: OCS Identity.
4. Your administrator should click Accept in the Permissions requested prompt window to grant consent.
5. OSIsoft will get a confirmation that the consent process has been completed.
6. Your AAD administrator will then click on the second link in the original email to grant permission for OCS Identity to sign in and read all users' full profiles and all group memberships.
7. Your administrator should agree to the advanced integration by clicking the consent button.
8. A final email will be sent to the initial user who either signed up for the account (if this is a new account being provisioned), or who requested that AAD be added as an identity provider (if AAD is being added to an existing account), informing them that the consent has been granted.
9. At that point, this initial user will be able to use the link provided to activate his profile and sign in to your OCS account (if this is a new account being provisioned), and other users can now be added using credentials from AAD.
