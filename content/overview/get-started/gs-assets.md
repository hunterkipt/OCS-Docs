---
uid: gsAssets
---
# Get started with assets

An asset is a container that includes metadata and references to streams related to a logical asset. For more information about assets, see the following topics:

- [Assets](xref:ccAssets)
- [PI Server counterpart](xref:ccAssets#pi-server-counterpart)
- [Assets best practices](xref:ccAssets#assets-best-practices)

## Procedure

Follow the procedure to create an asset.

1. Click the ![Menu icon](images/menu-icon.png) icon and click **Asset Explorer** (under Visualization).

1. Click the **Change Namespace** dropdown list.  In the `Select a Namespace` window, click **MyOCS** or another namespace in which you created your stream. 

1. From the  **Asset/Asset Types Selector** drop-down list, ensure that **Assets** is selected.

1. In the toolbar, click **Add Asset**. 

1. In the `Select Type for New Asset` window, select **< None >** and click **Continue**.

1. A panel appears on the right. Enter the values in the fields:
   - `Asset`&ndash; **MyOCS.Tank**
   - `Description` &ndash; Optionally, add a description for this asset.
   
1. Click the **Metadata** tab, and click **Add Metadata**.

1. Enter the following:

   - `Metadata` &ndash; **Capacity**
   - `Value` &ndash; **200**
   - `Type` &ndash; **Double**
   - `UOM` &dash; **US gallon (Volume)**

1. Click the **Properties** tab, and click **Add Stream References**.

1. In the `Select Streams` window, enter **MyOCS.*** in the search box.

1. Select **MyOCS.NorthAmerica.SLTC.PumpA** from the list and click **Add**.

1. In the text box below the **Stream References** label, enter **Output Pump State**.  This is the user-friendly name for the stream reference.

1. Click **Configure UOMs** to open a window where you can assign a unit of measure (UoM) to the stream properties.  

   **Note:** If the properties already have UOMs assigned, the UOM you set here will override this. No data conversion occurs between the two UOMs.
   
1. Click the **Status** tab, and click **Add Status Configuration**.

   The `Select Property` window lists the properties whose values can be displayed as a status. Only properties with an enumerated state or that have a string value can be displayed.
   
1. Select the **Output Pump Status | Status** property, and then click **Continue**. 

   If there are no values in the stream, there will be no eligible values to choose from. If there are eligible values that can be mapped to different statuses, select the value that corresponds to the Good, Warning, and Bad statuses. 

1. When you are done, click **Save**. 

   This adds the asset to the left pane.

1. In the assets pane, use the icons in the upper right of the toolbar ![Card view/List view](images/card-list-view.png) to switch between the following:

   - ![Card view](images/card-view.png) &ndash; Card view displays the assets as a series of tiles 
   - ![Table view](images/table-view.png) &ndash; Table view displays the assets in a table format 

## Next step

Continue with [Get started with asset types](xref:gsAssetTypes).
