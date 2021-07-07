---
uid: accessControl
---

# Role-based access control

Use an Access Control List (ACL) to manage role-based access control to entities such as namespaces and streams. ACLs control user access to entities based on their OCS roles. Each entity has an owner, who has access for all operations regardless of the contents of the ACL. Not all entities in the OCS system support role-based access control.  <!--Angela Flores 6/23/21 We should not talk about unreleased functionality or future functionality in the end-user documentation. Original text "Not all entities in the OCS system support role-based access control at this time, but the list will quickly grow and currently includes Namespaces and several unreleased entities." We should list all the entities that do support an ACL. How does access work for entities that don't support an ACL? -->

## Access Control Lists

Access Control Lists (ACLs) contain sets of Access Control Entries (ACEs), which contain the following information:

- TrusteeType - the role, user, or application for whom access is set 
- AccessType - the access permitted, either allowed or denied
- AccessRights - the 

A user or application that attempts to read, write, delete, or manage access control of an entity assigned an ACL must be assigned a trustee that has `AccessType` set to `Allowed` for the AccessRight corresponding to that operation.

### Notes

- If an operation requires more than one access right, then an identity obtains those rights from multiple ACL entries.
- `AccessType.Denied` takes precedence over `AccessType.Allowed`.
  - For example, a role that is assigned `AccessType.Denied` for `AccessRights.All` will receive a `forbidden` for all  requests unless they are the owner of the entity.
- Roles are the only TrusteeType supported for AccessControlList ACEs.
- At least one role must be given Manage Permission access.

The following table shows TrusteeTypes and the corresponding TypeIds.

| TrusteeType           | TypeId |
|-----------------------|--------|
| User                  | 1      |
| Application           | 2      |
| Role                  | 3      |

The following table shows AccessTypes and the corresponding TypeIds.

| AccessType            | TypeId |
|-----------------------|--------|
| Allowed               | 0      |
| Denied                | 1      |

### CommonAccessRightsEnum 
<!-- Angela Flores 6/23/21 why does this table get a heading, but the others don't? What does CommonAccessRightsEnum mean, it isn't mentioned anywhere else?-->
The following table shows AccessRights and the corresponding int and bitwise information.

| AccessRights          | int  | bitwise |
|-----------------------|------|---------|
| None                  | 0    |    0000 |
| Read                  | 1    |    0001 |
| Write                 | 2    |    0010 |
| Delete                | 4    |    0100 |
| ManageAccessControl   | 8    |    1000 |
| All                   | 15   |    1111 |

AccessRights are the bitwise union of all the access rights they encompass. For example, `AccessRights: 3` indicates that Read and Write access is permitted. <!--Angela Flores 6/23/21 - this bitwise union example needs more explanation. if Read is bitwise `0001` and Write is `0010`, wouldn't that be bitwise `0011`? It seems to be the sum of the assigned int-->

### Sample Access Control List

The following code sample shows the structure and format for an ACL that gives Role 1 `Read` access, Role 2 `All` access but denies Role 3 `ManageAccessControl` access:

**Body**

Sample  body:

```json
HTTP/1.1 200
Content-Type: application/json

{
  "RoleTrusteeAccessControlEntries": [
    {
    	"Trustee": {
    		"Type": 3,
    		"RoleId": "11111111-1111-1111-1111-111111111111"
    	},
    	"AccessType": 0,
    	"AccessRights": 1
    },
    {
		"Trustee": {
			"Type": 3,
    		"RoleId": "22222222-2222-2222-2222-222222222222"
    	},
    	"AccessType": 0,
    	"AccessRights": 15
    },
    {
		"Trustee": {
    		"Type": 3,
    		"RoleId": "33333333-3333-3333-3333-333333333333"
    	},
    	"AccessType": 1,
    	"AccessRights": 8
	}
],
}
```

## Owner

Set an owner on an entity to grant access for all operations on the entity regardless of the access set in the ACL. Only users and applications are valid owners for entities. Users are identified with their `ObjectId`, and applications are identified with the `ApplicationId`.

The following code samples shows the format and structure of an owner object.

**User Owner Body**

```json
"Owner": {
	"Type": 1,
	"TenantId": "55555555-5555-5555-5555-555555555555",
	"ObjectId": "44444444-4444-4444-4444-444444444444"
},
```

**Application Owner Body**

```json
"Owner": {
	"Type": 2,
	"TenantId": "55555555-5555-5555-5555-555555555555",
	"ApplicationId": "66666666-6666-6666-6666-666666666666"
},
```
