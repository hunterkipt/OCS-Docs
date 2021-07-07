---
uid: ccAssets
---

# Assets

An asset is a container for metadata, or static information about the asset (such as location or company), and properties which are references to streams in the Sequential Data Store. Assets allow you to retrieve all the stream values associated with an asset and to provide context to this dynamic data. 

## PI Server counterpart

Assets are comparable to elements in PI AF server. Like elements, OCS assets include both dynamic and static information associated with the asset. The static information provides context for the dynamic data. Assets in OCS appear as a flat list that you can search using metadata values. This contrasts with the elements in PI AF server which are organized in a hierarchy.

## Assets best practices

OSIsoft recommends the following best practices when you create assets:

- Use OCS assets to bring together in one place the data from multiple streams and the static data associated with a logical asset. OCS assets make it easier to visualize and contextualize the data for a given logical asset.
- Define the UOM on the type whenever possible. The UOM can also be defined on the stream, but if it is defined in multiple places, ensure that the UOMs match. If a different UOM is configured, there is no conversion between the UOMs.  
