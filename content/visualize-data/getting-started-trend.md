---
uid: GettingStartedWithTrendData
---

Get started with trend data
=================================================

Use trace data in a trend to monitor assets, anticipate problems, and proactively perform preventative maintenance. The following procedure describes how to display traces in your trend and glean useful information from your data.

Procedure
---------

1. Log in to OSIsoft Cloud Services.

2. Click the navigation icon ![](images/icon_navigation_bigger.png) (upper left corner) and click **Trend** (under Visualization). 
    
3. In the Add Traces blade, click the **+** sign to add the trace to the trend. 

   Tip: 

   - Specify the stream name or description in the Search box to find the OCS streams you are interested in.

   - After you have finished adding the traces, click the **x** in the Add Traces blade to hide the blade and maximize the available area to display your trend.

    ![Search blade](images/Search_blade_75.png)
   
4. Click the ![Trend views icon](images/trend-views-icon.png)icon to choose one of the three views:

   | Trend View                               | Description                                     |
   | ---------------------------------------- | ----------------------------------------------- |
   | ![Single mode](images/Single_mode.png)   | Each trace is displayed in its own trend.       |
   | ![](images/Multiple_mode.png)            | All measurements are plotted on the same scale. |
   | ![Stacked mode](images/Stacked_mode.png) | All measurements are plotted on its own scale.  |
   
    The following screen capture shows the stacked view.
    ![Trend dislaying traces in stacked view](images/Traces_stacked_view.png)
   
5. Click the time picker and select the time range you want to view. If the desired time range does not appear in this list, click the **Custom Range** tab and specify your time range.<br>

    ![Time picker](images/Time-picker.png)
<br>

6. Click **Step backward** or **Step forward** to move the time range of the data displayed in the trend.

   The trace will move in time increments displayed in the time range picker. If the trend displays the last 8 hours, **Step backward** shows the previous 8-hour period. If it displays the last 30 days, **Step forward** shows the next 30-day period. Click the triangle to select another time range or specify a custom range.

   ![Step back and step forward](images/Step_back_forward.png)

   The Legend table displays the Trace view. It shows the legend for each trace, the last value, minimum, maximum, and average values in the displayed time range.

    ![Legend Table](images/Legend_Table.png)

7. Click on a trace to select it for further analysis.<br>The selected trace is highlighted, and two cursors automatically mark the minimum and maximum values for the displayed time range. These cursors, called *easy cursors,* remain as long as the trace is highlighted.<br>

    ![Maximum and minimum cursors](images/Max_min_cursors.png)
<br>

8. Click the plus sign (+) above the trace to lock the cursors in place.<br>
    The *+* turns into an *x*.  To unlock the cursor, click the *x*.
         <br>
         <br>
    Note: When two cursors are locked, the Legend table displays summary calculations for the values between the two cursors, known as the Cursor view.

    ![Cursor_view](images/Cursor_view.png)

9. Click the link icon ![Copy link icon](images/copy_url_link.png) in the menu bar to copy the URL of the workspace.  <br>

    This link, when shared with colleagues, gives them the same view of the trend that they can then use to troubleshoot problems.

