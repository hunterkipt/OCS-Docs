---
uid: log-messages
---

# Common Event Viewer log messages

The following table below summarizes the most common messages logged by the Event Viewer.

Message | ID   | Description
---------|----------|---------
 Started Agent | 0 | The PI to OCS Agent has been started.
 Stopped Agent | 2 | The PI to OCS Agent has been stopped.
 Connected To Data Archive | 18 | The PI to OCS Agent has connected to source PI Data Archive. PI Data Archive information will be printed in the message.
 Error Performing Point Query | 19 | The PI to OCS Agent has encountered an error querying for PI points in the source PI Data Archive. The exception reason and the query ID will be displayed.
Failed To Get Data Archive Info | 21 | The PI to OCS Agent has encountered an error while trying to get archive file information from the source PI Data Archive. The exception reason will be displayed. Depending on the exception, this call may or may not be automatically retried.
Data Archive Version Not Supported | 24 | The source PI Data Archive version is not supported. Currently, the PI to OCS Agent only supports PI Data Archive 2016 R2 (3.4.415.1188) and above. Please upgrade your PI Data Archive if you wish to use PI to OCS.
Failed To Perform Point Query - Element Invalid | 27 | One or more the query objects (Point Mask and/or Point Source Mask) is invalid. If this query is made via the OCS Portal, users should not get this error.
Agent Registration Completed | 30 | The PI to OCS Agent registration was successful
Agent Registration Failed | 33 | The PI to OCS Agent registration was not successful. The most frequent reasons why this would occur are as follows: 1) The source PI Data Archive was already tied to an existing Connection; and, 2) 	The Connection is already tied to another PI to OCS Agent.
Agent Received Unregister Request | 60 | The PI to OCS Agent received an unregister request from the OCS Portal. As a result, the PI to OCS Agent will unregister and shutdown.
Agent Unregistered | 62 | Confirmation message that the PI to OCS Agent is unregistered after receiving event ID 60.
Processing Transfer Job Request | 65 | The PI to OCS Agent has received the new transfer request. The message will contain information about the contents of the transfer such as the transfer historical start time and the number of involved points.
Done Transferring Data To OCS For Transfer Job | 70 | The PI to OCS Agent has completed the given transfer job. At this moment, the only transfer jobs which will complete are the historical and backfilling transfer jobs. By the very nature of streaming data, streaming transfer job will never complete.
Error Reading From Data Archive | 90 | The PI to OCS Agent was unable to read data from PI Data Archive. The event will contain the exception message.
Failed To Get Streaming Updates From Data Archive | 96 | The PI to OCS Agent was not unable to get streaming data from PI Data Archive. The message will contain the exception message.

If you have any issues, questions, or comments about deploying or using PI to OCS, please visit [my.osisoft.com](https://my.osisoft.com/) to open a new technical support case.
