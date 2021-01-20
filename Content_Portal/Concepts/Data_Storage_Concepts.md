---
uid: DataStorageConcepts
---

# Data Storage Concepts


## Sequential Data Store

Sequential Data Store (SDS) is a streaming database optimized for storing sequential data, typically time-series data. It can store any data that is indexed by an ordered sequence. For each namespace that is created, an SDS instance or SDS resources, is created. The services and storage are scoped to a particular region. Data is written into the SDS using REST APIs. 

## Types
Types define the datum stored by OCS. It is comparable to a type (class) in programming or a table definition in a database. Types contain:

* The composition of named properties with primitive types and other Types
* Arrays of primitive types and other Types
* Index *annotation*
* UOMs annotation

The term "Stream Type" is used when additional context is needed. Within the API itself, this type is frequently referred to as `SdsType`.

## Streams
Streams (SdsStream) are containers for sequential data of some **Type**. Streams are either a collection of ordered events stored in SDS or a series of events (instances of the defined SdsType) indexed by one or more properties.

Streams are defined to organize incoming data from a device into Osisoft Cloud Services (OCS). Metadata and tags can be used to omit stream data. Metadata is a key-value pair that allows you to add context to your data. Tags are string values that can be used to group streams by category.


<!---
(QUESTION: Does this mean that by assigning properties and other things, you are organizing the data? 
JL: Yes, just like with PI to OCS, you are essentially "shaping" the PI data to the OCS SDS format.) --->


Streams are scoped within a namespace. 


## Stream Views
Different persona in the customer's organization may be interested in different data contained in the stream. A process engineer and maintenance person rely on different data in the stream to do their job. SdsType objects are immutable, that is, once created, you cannot alter the data captured by them. However, stream views provide greater flexibility and allow different personas to view only the subset of the stream they are interested in. Stream views are a custom view or logical overlay over your stream data. They allow you to scope down the data that is viewed, to change non-intuitive labels to more user-friendly names, and create arbitrary mappings of data within a stream.
Stream views are a custom view or logical overlay for your stream data. They allow you to scope down the data that is viewed, to change non-intuitive labels to more user-friendly names, and create arbitrary mappings of data within a stream. Stream views can be used when changing the type of a stream to provide a mapping from the previously stored data to the new type.

