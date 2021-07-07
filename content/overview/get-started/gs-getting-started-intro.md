---
uid: gsGetStartedOCS
---

# Get started with OSIsoft Cloud Services 

This is an introduction to the main features of OSIsoft Cloud Services (OCS) using the OCS portal. Each section includes a tutorial with step-by-step procedures with links to basic concepts and best practices.

## Before you begin

Before you begin the get started exercises, obtain the following:

- Request a tenant from your OSIsoft account manager. 
- You must have Tenant Administrator privileges. 

## Log into the OCS Portal

Once you have completed the pre-requisites, log into the OCS portal. 

1. In the web browser, enter the following URL: https://cloud.osisoft.com to open the OSIsoft Cloud Services web site. 

   **Note:** The latest versions of Microsoft Edge, Google Chrome, and Firefox are supported.

3. In the toolbar, click **Sign In**.

4. In the Specify Tenant Id or Company Alias window, enter the tenant ID or the company alias for your tenant, and click **Continue**. 

   <!-- I'm guessing there are additional next steps that depend on the Identity Provider they are using? --> 

## OCS portal

The OCS portal is a web-based application through which you can perform many of the tasks you need to perform. Alternatively, you can accomplish the same tasks through the OCS REST-based API. This introduction to OCS uses the portal functionality. Before you start the exercises, see [Introduction to the OCS portal](xref:introPortalInterface) to get an overview of the user interface.
## Get started goals

In this get started exercise, you will do the following:

1. Create a namespace that will contain all of your OCS resources, including an instance of the Sequential Data Store and the data streams.

2. Create two connection types, one that brings in PI Data Archive data and another that brings in data using an OMF application.

3. Create a type that defines the data you want to store.

3. Create a stream container to store that data.

4. Create clients for different types of applications.

1. Invite a user to your tenant.

7. Create a role that defines permissions for users.

   **Note:** Each exercise is built upon the previous one; therefore, complete the exercises in the order shown. At the end of each exercise, you will be directed to the next exercise.  

## Next step

Start with [Get started with namespaces](xref:gsNamespaces).
