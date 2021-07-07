---
uid: lpstoredata
---

# Store data

Use the Sequential Data Store (SDS) to store, retrieve, and organize any type of streaming data in OCS. <!-- Angela Flores 6/10/21 - There is a logic jump from this sentence to the next sentence. There should be a connecting sentence that connects Types and Streams to SDS. Also what does "streaming data" or "data stream"? Suggested:  The Sequential Data Store (SDS) is streaming data storage that is optimized for storing sequential data, usually time-series, but can store anything that is indexed by an ordered sequence. Use the Sequential Data Store (SDS) to store, retrieve, and organize any type of streaming data in OCS. An SDS type defines the shape of a single measured event or object. A type gives structure to the data. For example, if you measure three things from a device at the same time such as longitute, latitude, and speed, then those three properties need to be included in the type. An SDS stream is a collection of ordered events, or a series of events, where each event is an instance of the type. -->

SDS types define the structure of data to be collected. A type is analogous to a template that defines each instance in a stream of data.

SDS stream data contains values or events of the same SDS type and is ordered (indexed) by one or more properties defined by the stream's SDS type, usually a timestamp.
<!-- Angela Flores 6/10/21 The sentence above still has multiple instances of passive voice and is very difficult to understand. -->