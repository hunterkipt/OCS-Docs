---
uid: remove-agent
---

# Filter, uninstall or repair an agent

You can search for PI to OCS Agents that have been installed on host machines at your organization.  The global filter feature allows you to search for Agents by name, status, version number, hostname, PI Data Archive or AF server name, region, and namespace.  

Use the global filter feature to filter down a large list of agents to only ones of interest.  For example, you may want to remove or uninstall older agents. This topic contains the following procedures:

* [Search for an agent](#search-for-an-agent)
* [Uninstall an agent](#uninstall-an-agent)
* [Repair an agent](#repair-an-agent)

## Search for an agent

1. Log on to the [OCS portal](https://cloud.osisoft.com).

2. Click the menu ![ ](../../images/waffle-button.png) icon, then click **Data Collection > PI to OCS Agents**.

   **Result:** The **PI to OCS Agents** window opens.

3. In the **Filter Agents** text box, enter the first few characters of the agent's name or version number.  

   **Result:** If there is a match, any agents that meet the filter criteria are displayed in the list of agents.

## Uninstall an agent

You may want to remove a PI to OCS Agent from a host machine. To uninstall an agent, open the **Apps & features** window and then follow the prompts in the `PI to OCS Agent` window.

#### Procedure

1. Click the Windows Start button, then click **Settings**.

   **Result:** The **Windows Settings** window opens.
2. Double-click **Apps**.

   **Result:** The **Apps & features** window opens.
3. Scroll to and click **PI to OCS Agent** in the list of installed apps.
4. Click **Uninstall** twice, then click **Yes** in the **User Account Control** window.

   **Result:** The **PI to OCS Agent (Administrator)** window opens.
5. Select the **Uninstall** option, then click **Next**.
6. Click the **Unregister agent from OCS** option, then click **Next**.

   **Result:** The agent's associated client and connection information is removed in OCS.
7. Select the user account you wish to use to log on to OCS.

   **Result:** You are returned to the **PI to OCS Agent** window.
8. Click **Uninstall**, then click **Close**.

   **Result:** The PI to OCS Agent is uninstalled and removed from the host machine.

## Repair an agent

An agent may need to be repaired from time to time.

#### Procedure

1. Click the Windows Start button, then click **Settings**.

   **Result:** The **Windows Settings** window opens.
2. Double-click **Apps**.

   **Result:** The **Apps & features** window opens.
3. Scroll to and click **PI to OCS Agent** in the list of installed apps, click **Modify**, then click **Yes**.
4. Make sure the **Repair** option is selected in the **PI to OCS Agent** dialog box, then click **Next** twice.

   **Result:** The **Installation** page opens and the repair process begins.
5. After the repair process is completed, click **Close** to exit.