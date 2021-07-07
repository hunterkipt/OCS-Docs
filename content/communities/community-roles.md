---
uid: communityroles
---

# Community roles

When using Communities, you must [assign users to roles](xref:managecommunityusers#assign-user-roles) that grant permissions for certain types of actions.

Communities includes the following roles, ordered from least privileged to most privileged.

## Community Member

A role authorized to read any data shared in the community.

## Community Moderator

A role that manages the community for a tenant. Usually, a Community Moderator is the individual who accepted the invitation to join a community on behalf of a tenant. 

A Community Moderator's primary purpose is to specify which tenant's users have access to a community. Community Moderators have all privileges of a Community Member, plus the following abilities:  

- Add users from their tenant to the community.
- Remove their tenant's users from the community.
- Remove their tenant from the community.

Community Moderators can assign the following roles to users in their own tenant:

- Community Member
- Community Moderator

## Community Administrator

A role with full administrative rights. These rights include all the privileges of a Community Moderator plus the ability to take the following actions:

- Delete the community.
- Invite tenants to the community and confirm those invitations.
- Remove tenants from the community.

Community Administrators only exist in the [community owner's](#community-owner) tenant. Community Administrators can assign any role to users in their own tenant; they cannot assign roles to users in other tenants.

## Related roles and identities

In addition to the roles you can assign in Communities, be aware of the following related roles and identities.

### Tenant Administrator

A tenant-level role that allows users to administer their own tenant. The Tenant Administrator roles applies to all of OCS rather than just Communities. For more information about OCS roles, see [Roles](xref:ccRoles). In Communities, Tenant Administrators can create a community and accept invitations to join their tenant with other communities.

### Community owner

The community owner refers to the tenant that created a community. A community owner is not a role and is not granted any privileges. By default, Tenant Administrators have the privilege needed to create communities.
