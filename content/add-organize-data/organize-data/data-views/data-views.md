---
uid: Dataviews1
---

# Create a data view

Data views are subsets of data from one or more streams. You create a data view by defining the target namespace, and then specifying the source stream or streams, selected data fields, time period, and interpolation interval. 

## Procedure

1. In the OCS Portal, click the menu icon and select **Data Views** under Analytics.
2. In the `Data Views` pane of the OCS Portal, click **Add Data View**.
3. Enter the data view name and description in the `Data View Information` pane.
4. Click **Standard** or **Narrow** to specify the general shape of the data display.
5. In the `Query ID` field in the center pane, enter a name for *Query1* in the **Query ID** field, or accept the default name. 
6. In the `Query Type` section, select **Streams** or **Assets** to indicate which objects you want this query to search.

   **Note**: Assets are available for use through specific licensing only. If you are interested in using Assets, contact your account team for more details. 
   
6. In the `Search` field of the `Query Value` section, type a portion of the name of any known stream or asset (preceded/followed by the * wildcard symbol). The query results populate and the `Index Configuration` pane displays.

   **Note**: If you have created a metadata rule in the same namespace, you can enter a selected metadata key instead of a stream name in the `Search` field to select a more specific set of streams.
   
7. Select any stream in the query results to display the individual data fields of the stream in the `Data Item Details` pane.

   **Note**: Click the **Add Query** button to create as many additional queries as you want.

8. Click **Save** to accept the query results as the basis of the new data view. The `Field filter` pane displays. 
9. The **Index field** and **Grouping fields** selections are set by default. In the **Identifying field** section of the `Field filter` pane, select each data field you want to use as an identifying field.
10. In the `Generate Preview` pane, click the **Auto Refresh** toggle button to enable or disable auto refresh. With auto refresh enabled, changes to any of the streams included in the data view will be immediately reflected in the data view.
11. OPTIONAL: Click the **Generate preview** button to generate a preview of the data view with the selected settings.
12. Click the **Items per page** droplist to select the number of items to be displayed per page in the data view.
13. Click the date and time display to set the **Start Index** and **End Index** to specify the time period of the data to include in the data view.
14. Click the **Interpolated/Stored** droplist and select **Interpolated** or **Stored** for the data view. 
15. Click the **View in API Console** button to display basic parameters of the data view in the API console.
16. Click **Apply** to create the data view with the settings you have selected.
17. Click **Save** to save the data view and continue working, or click **Save and Close** to exit.


## Related links

To define a data view using the OCS API, see [Define a data view](xref:DataViewsQuickStartDefine).





