---
uid: ccNamespaces
---


# Namespaces

A namespace is a logical unit of organization for data within a tenant. Each tenant may contain more than one namespace. Before OSIsoft Cloud Services (OCS) can receive data for a given tenant, a namespace must exist within the scope of that tenant. When you create a namespace, you specify the region for storing data within it; for example, West US.

When you create a namespace, OCS allocates data processing resources (for example, SDS and asset service) and the associated storage resources to support that namespace. Each namespace and its resources are distinct and separate from all other namespaces. The resources are scoped to the namespace. Which means, you can create an SdsType or an SdsStream object with the same name in two different namespaces.

Data stored within a namespace is tied to that namespace and its region, and you cannot directly transfer the data to any other namespace (or region). To move data between namespaces, you must export the data from the source namespace in OCS, then import it into the destination namespace.

## PI Server counterpart

A namespace is similar to a full PI Server. Much like a PI Server, a namespace has its own resources and it is not typical or easy to use data from multiple namespaces at the same time. It is reasonable for a tenant to use only one namespace.

## Namespace IDs

The namespace ID must be unique across the tenant and meet these requirements:

- Contains 100 or fewer characters
- Can include alphanumeric characters, underscores (\_), dashes (-), spaces, and periods
- May not contain two consecutive periods or two consecutive underscores
- May not begin or end with a period
- May not start with two consecutive underscores
- May not include leading or trailing white spaces

## Querying data across namespaces

When querying API endpoints, the namespace ID is part of the URL. The API URL takes the form `https://{server}/api/{version}/Tenants/{tenant id}/Namespaces/{namespace id}`, followed by the API path, such as `/Streams`.  Because the URL contains the namespace, it is not possible to make a single API request for data across multiple namespaces.
