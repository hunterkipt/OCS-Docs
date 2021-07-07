---
uid: bpNamespaces
---

# Namespaces best practices

OSIsoft recommends using one of the following strategies when creating namespaces:

- Strategy 1 &ndash; Create a separate namespace for each environment. For example, Production, Development, Staging, and so on.
- Strategy 2 &ndash; Create a separate namespace for each of your customers.

Use the first strategy for tenants where all the data belongs to one organization. Keep in mind, if you need to use the data together, you should store it together in one namespace.

Use the second strategy if you are providing a service to customers that uses OSIsoft Cloud Services as a backend. This strategy makes it easier to avoid naming conflicts and to manage security and assign permissions. Note that objects and collections do not automatically inherit security from their namespace. If your organization has internal data that does not belong to a customer, consider combining both strategies. Create separate namespaces for each customer and create another namespace for internal use that includes your Production, Development, and Staging environments.
