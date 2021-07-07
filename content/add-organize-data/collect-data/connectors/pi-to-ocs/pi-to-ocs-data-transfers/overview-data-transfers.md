---
uid: overview-data-transfers
---

# Overview of data transfers

To transfer PI System data to OCS, you must first create a transfer list by setting filter criteria and choosing PI points for the transfer. Then, stream the selected PI points from your on-premises PI System to OCS.

The following tasks must be performed before you can complete a data transfer:

1. Install the PI to OCS agent setup kit.
2. Configure the PI System data source connection.
3. Create a transfer.
4. Set historical start and end time if desired.

**Note:** If you have PI points that do not update often, you might want the data in OCS before it is archived on PI Data Archive. To accomplish this task, turn off compression for these PI points to ensure snapshot data is collected.  

OSIsoft recommends turning off compression only for PI points that do not update often. In general, this practice is not required for most tags and can cause unnecessary overhead and data collection.

## Historical transfer

During the creation of a transfer, you have the option of including historical data. You specify the start and end times for a historical data transfer. When the start time is in the past, that is before `*` in PI terminology, the PI to OCS Agent asks PI Data Archive for past data. The PI to OCS Agent retrieves the data between the start time and the time when the transfer started. The data it collects is referred to as the historical transfer.

## Backfilling

Backfilling is the process of transferring missing data. It happens when a PI to OCS Agent shuts down while it is transferring data. When the PI to OCS Agent is stopped or the PI to OCS Agent Windows service shuts down, it loses its update signup. For example, if the service shuts down for two hours, it will have to re-signup for updates when it becomes available; however, the PI to OCS Agent cannot use updates to retrieve the data for those two hours it was down. In this example, the backfill transfer job fills the gap for those two hours.

## Historical transfer versus backfilling

Historical transfer fills the gap between a configured, past start time and the time the transfer started. Backfilling fills the data for the time period that a configured transfer stopped up until the time the transfer resumed again.
