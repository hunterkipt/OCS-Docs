---
uid: pi-point-change
---

# Point type change

When the source PI Data Archive tag changes point type, PI to OCS Services detects this change and sets the transfer status to `PI Point Type Change Detected`. The SDS stream affected is noted in the log files. You must manually decide what to do with the destination SDS stream as well as data that has already been transferred. The PI to OCS service cannot determine why a point changed and how to resolve the issue. A point change could occur for the following reasons:

* The source tag had an incorrect configuration of data and type. The data and tag must be deleted and recreated.
* The source tag was misconfigured initially. For example, the tag updated from a `Float32` to a `Float64`. The data is still relevant and should be kept.
* Other reasons.
<!--Angela Flores 6/28/21 This list is oddly specific. Also, what is PI to OCS Services? And PI to OCS service? This topic still needs work. -->

Once an SDS stream is created, its underlying SdsType cannot change. As a result, new data from a tag that is assigned a different type cannot be stored in the same stream, and you must decide what to do with the existing SDS stream and data. You can choose from the following corrective actions:

* To maintain the data and continue streaming data for that particular tag, create a new SDS stream and copy the data to that new stream. Then, delete the SDS stream in question and restart the transfer.
* To maintain the data, but not the streaming data for that particular tag, create a new transfer without the tag in question and start the transfer. 
* To stream data for that particular tag, but not maintain previously transferred data, delete the SDS stream in question and restart the transfer.

To see what types of point coercions are supported in PI Data Archive, please refer to the ["Allowable point type coercions"](https://docs.osisoft.com/bundle/pi-server/page/allowable-point-type-coercions.html) topic.<!--Angela Flores 6/28/21 should that be "coercions" or "conversions"? -->
