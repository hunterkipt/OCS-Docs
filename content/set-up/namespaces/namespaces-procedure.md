---
uid: gpNamespaces
---

# Add a namespace

A namespace is a logical unit of organization for data within a tenant. Before any data can be put into OCS for a given tenant, a namespace must be created within the scope of the tenant. See the following topics for more information about namespaces:

- [Namespaces](xref:ccNamespaces)
- [Namespaces best practices](xref:bpNamespaces)

## Procedure

1. Click the ![Menu icon](../images/menu-icon.png) icon and click **Namespaces** (under Data Management).


2. In the `Manage Namespaces` pane, click **Add Namespace**. 

3. In the `Namespace Id` field, enter your namespace Id, enter a description, and select a region. 

   **Note:** Once the namespace is created, the `Namespace Id` and `Region` fields cannot be changed.

4. Click **Add**.

   **Note:**  Click **Display Details** in the menu bar to see the following information about your namespace:
   
- The window shows your tenant Id, namespace Id, description, and region of your namespace. It also displays zero (0) in the `Type Count` and `Stream Count` fields.  
- The details window shows the `State` field, which indicates the status of the namespace. Once the process of creating a namespace and bringing it online is complete, the value of the `State` field changes to *Active*. If the status does not display as *Active*, close the window and refresh the page. 

## Related links

- [Namespaces](xref:AccountNamespace_1) API

