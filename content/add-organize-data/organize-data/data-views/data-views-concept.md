---
uid: ccDataViews
---

# Data views

Use data views to specify the OSIsoft Cloud Services (OCS) data to use in external applications for visualization, data science, and analytics. Data views group related streams and retrieve tabular time-series data for those streams. The table of data includes data fields from the selected streams for a time period and an interpolation interval. 

## <a name="data-views-pi-integrators"></a>PI Integrators counterpart

Data views in OCS are comparable to asset, event, and streaming views in PI Integrators. Like PI Integrator views, data views shape complex data into a consistent tabular format so it can be used more easily with external tools.

## <a name="data-views-bp"></a>Data views best practices

Follow these best practices when creating data views:

- Use the Identify By or Group By features of data views to identify which columns and rows correspond to which streams. Use Identify By to associate columns, and use Group By to associate rows. Generally, you use only one method in a single data view. 

- Consider the data shape that your application requires in order to accomplish your goals before you start building a data view. Consider how the columns should be organized and labeled.

- Remove any default fields from your data views that will not be used in the data analysis to improve overall performance.
