---
uid: WhatIsOCS
---

# What is OSIsoft Cloud Services?

OSIsoft Cloud Services (OCS) is a cloud data platform for storing, retrieving, and analyzing sequentially indexed data. OCS creates a seamless, trustworthy data infrastructure to incorporate information from sensors, plants, enterprises, and communities of interested users. This infrastructure enables data sharing and usage within your organization, across locations, and even with external partners.

OCS offers the following capabilities: 

* [Easy data collection](#easy-data-collection)
* [Integration with external tools and applications](#integration-with-external-tools-and-applications) 
* [Secure and robust data infrastructure](#secure-and-robust-data-infrastructure) 
* [Elastic resource allocation](#elastic-resource-allocation) 
* [Interruption resilience](#interruption-resilience) 
* [Easy management and maintenance](#easy-management-and-maintenance )

## Easy data collection

OCS provides a variety of methods to collect data into the system. You can ingress data from an external application or from PI Server directly to OCS using any of the following methods: 

- PI to OCS Agent
- OSIsoft Message Format
- Edge Data Store
- PI Adapters
- REST API

### PI to OCS Agent

The PI to OCS Agent transfers PI time-series data from an on-premises PI Server into OCS. PI to OCS maps PI Data Archive PI points to SDS types and streams. 

### OSIsoft Message Format

OSIsoft Message Format (OMF) is a platform-independent format for passing JSON messages to OCS using an HTTP client. Use OMF to achieve a high-throughput data feed into OCS. 

### Edge Data Store

Edge Data Store (EDS) uses OMF messages to send data into OCS from edge devices.

### PI Adapters 

PI Adapters use OMF messaging to send data into OCS from a variety of data collection devices. 

### REST API 

Developer-friendly REST APIs provide programmatic access to read and write sequential data into OCS. 

## Integration with external tools and applications

OCS allows you to integrate data with many different partner applications, data pipelines and workflows, collaboration tools, business intelligence (BI) and data exploration tools, and custom applications. A few examples include these tools: 

- Power BI 
- Grafana 

You can integrate and view OCS data in the following ways: 

- Build applications with OCS client libraries to read and write data to OCS 
- Use the OCS REST API to read and write data to OCS 
- Retrieve tabular data with OCS data views 

OCS also offers opportunities for many new types of data consumers. For example, you could integrate OCS with applications that perform machine learning or AI functions. 

## Secure and robust data infrastructure

OCS is built from the ground up to ensure security. The OCS platform is based on industry standard techniques to ensure the strongest possible data integrity. All users authenticate through trusted identity providers, such as Google, Microsoft, and Azure Active Directory. Authenticated users can only perform actions for which their role is authorized. Machine access to OCS is controlled through a variety of defensive strategies. All data in OCS is fully encrypted in transit to OCS and at rest. 

OCS is designed to prevent your data from being accessible to others. Each organization using OCS, known as a tenant, sets up one or more logical units of work called a namespace. Each namespace is distinct. When a tenant requests a new namespace, OCS automatically allocates the resources needed to support data infrastructure needs. The storage and backend services for each namespace are logically separated from all other namespaces. 

## Elastic resource allocation

Due to its microservice-based architecture, OCS dynamically adapts to workload changes by automatically provisioning and de-provisioning resources. Each microservice performs a subset of the system’s overall capabilities, and when orchestrated together, they function as a complete platform. 

When a tenant requests a new namespace, OCS provisions a new set of microservices and all necessary data storage. As the tenant’s needs for the namespace grow, OCS automatically provisions additional microservices and storage so the namespace can expand horizontally. Similarly, if requirements shrink, OCS can reduce the number of required microservices and de-allocate storage. 

## Interruption resilience

To prevent data interruptions or loss, OCS incorporates many safeguards. By design, OCS is built for high availability. You are not required to perform any specific actions to ensure continuous access to reliable, distributed data storage.

OSIsoft continuously tests OCS to ensure the platform is performing reliably. Both the platform and the underlying operating systems are updated regularly. In addition, OSIsoft conducts frequent threat analyses to thwart potential exploitations. Load balancing precludes distributed denial of service attacks. A gateway prevents unauthorized access to resources.

## Easy management and maintenance

OSIsoft manages, operates, and maintains all aspects of the OCS platform. OCS is built and deployed on Microsoft Azure and operates outside the OSIsoft corporate firewall. Currently, OCS runs in two Azure regions: West US and West Europe. By housing the platform in multiple regions, OCS accommodates regulations that mandate where data must be stored.

Access your data infrastructure through the OCS web-based portal or by using modern, secure, developer-friendly REST APIs.
