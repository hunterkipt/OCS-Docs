---
uid: ccRoles
---
# Roles

Roles are used to manage access to assets, resources, and services in OSIsoft Cloud Services (OCS). Roles are assigned to identities, which includes users, groups, and client-credentials clients. When an identity tries to access a resource in OCS, OCS checks the assigned roles against the permissions on the resource to determine their access level.

There are five built-in roles which cannot be removed from a tenant:

- Tenant Administrator - OCS Administrator of OCS who is granted full permissions throughout OCS, by default. This is the highest privilege role, with the ability to create new and remove existing users, clients and secrets. OSIsoft recommends not assigning this role to clients.
- Tenant Contributor - Granted read and write permissions throughout OCS, by default.
- Tenant Data Steward - No specific permissions are granted to this role, by default.
- Tenant Viewer - No specific permissions are granted to this role, by default.
- Tenant Member - This role is assigned to all users or clients in OCS. Tenant members are granted read access throughout OCS, by default.

You can add roles to further control access. By default, added roles do not have any specific permissions. You must have the Tenant Administrator role to add and manage roles in a tenant. 

Assigning a role to a user or client does not determine access. For any resource in OCS, you set access on the resource for specific roles, rather than for specific users or clients. Manage access using Manage Permissions for the given resource. For each role, you set access to the following access types: Read, Write, Delete, and Manage Permissions.

## <a name="roles-pi-server"></a>PI Server counterpart

Roles in OCS are comparable to PI identities in PI Data Archive or identities in PI AF server. Throughout OCS, permissions are granted to roles instead of directly to individual users or clients. This is similar to how identities in PI Server are used to assign permissions for a set of users or clients.

## <a name="roles-bp"></a>Roles best practices

OSIsoft recommends the following best practices when you create and assign roles:

- Consider whether the read access granted by the Tenant Member role is acceptable for all users and clients in your tenant. Specifically, if you plan to invite users from outside your organization, you may want to limit their read access. One way to do this is to create a custom role for external users so that their permissions can be explicitly managed.

- Use caution when granting the Tenant Administrator role. OSIsoft recommends that you assign a different role to users and clients who should not manage permissions. OSIsoft recommends that you avoid assigning the Tenant Administrator role to client-credentials clients.

- Ensure that the roles assigned to client-credentials clients only grant the minimum set of permissions required by the application that uses these clients. This minimizes the potential damage in the event a client secret is compromised or a problem arises with the application.

- Use caution when denying permissions because this supersedes any allowed access to a role. For example, if a user is allowed write access through one role but is denied write access through another role, the user will not have write access. Because all users and clients are assigned the Tenant Member role, you cannot deny permissions to the Tenant Member role. Doing so would deny the given permission to every user in the tenant.
