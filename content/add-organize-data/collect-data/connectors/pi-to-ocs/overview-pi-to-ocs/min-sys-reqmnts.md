---
uid: min-sys-reqmnts
---

# PI to OCS minimum system requirements

The following minimum system requirements are needed to transfer data from an on-premises PI Server to OCS using the PI to OCS Agent.

| System component | Requirement |
| ------------- | ----------------- |
| PI Server | <ul><li>Minimum version: PI Data Archive 2016 R2; For full support of PI to OCS features, use PI Data Archive 2017 R2 or later.</li><li>See the PI Data Archive release notes for all other minimum system requirements.</li></ul> |
| PI to OCS Agent | <ul><li> Install on a different computer than the PI Data Archive deployment.</li>|
|Operating system |<ul><li>64-bit version of Windows (v. 1809) or 64-bit version of Windows Server 2016 Standard (v. 1803)<br>**Note:** 32-bit operating systems are not supported.</li><li>Processor: 1 gigahertz (GHz) or faster compatible processor or System on a Chip (SoC)</li><li>RAM: 2 gigabyte (GB for 64-bit)</li><li>Hard drive size: 32GB or larger hard disk</li><li>An Internet connection and a secure network connection to the PI Data Archive computer</li></ul> |
| Specific PI to OCS features | <ul><li>Transfer out of order (OOO) events to OCS: PI AF 2017 R2 or later |

## Access requirements

The PI to OCS Agent must be installed on a local machine by a user account with the following permissions: 

- Administrator privileges on the local machine
- Assigned to the OCS Tenant Administrator role

During the PI to OCS Agent installation, you need to log on to the OCS portal with the Tenant Administrator credentials. 

The PI to OCS Agent requires the Windows service to "run as user". You must have read access to the following data on PI Data Archive:

* Archive data (the PIARCDATA Security table)
* The PI points configuration table (PIPOINT Security table)
* The PI points and data to be transferred
