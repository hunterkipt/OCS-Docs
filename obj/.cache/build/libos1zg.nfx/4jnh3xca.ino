<!DOCTYPE html>
<!--[if IE]><![endif]-->
<html>
  
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
    <title>Namespace Tier </title>
    <meta name="viewport" content="width=device-width">
    <meta name="title" content="Namespace Tier ">
    <meta name="generator" content="docfx 2.39.2.0">
    
    <link rel="shortcut icon" href="../../favicon.ico">
    <link rel="stylesheet" href="../../styles/docfx.vendor.css">
    <link rel="stylesheet" href="../../styles/docfx.css">
    <link rel="stylesheet" href="../../styles/main.css">
    <meta property="docfx:navrel" content="../../toc.html">
    <meta property="docfx:tocrel" content="../toc.html">
    
    <meta property="docfx:rel" content="../../">
    
  </head>
  <body data-spy="scroll" data-target="#affix" data-offset="120">
    <div id="wrapper">
      <header>
        
        <nav id="autocollapse" class="navbar navbar-inverse ng-scope" role="navigation">
          <div class="container">
            <div class="navbar-header">
              <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navbar">
                <span class="sr-only">Toggle navigation</span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
              </button>
              <a class="navbar-brand" href="../../index.html" width="46">
                <img id="logo" src="../../Documentation/images/atlas_icon.png" height="46" width="46" alt="OSIsoft Cloud Serices"> 
              </a>
            </div>
            <div class="collapse navbar-collapse" id="navbar">
              <form class="navbar-form navbar-right" role="search" id="search">
                <div class="form-group">
                  <input type="text" class="form-control" id="search-query" placeholder="Search" autocomplete="off">
                </div>
              </form>
            </div>
          </div>
        </nav>
        
        <div class="subnav navbar navbar-default">
          <div class="container hide-when-search" id="breadcrumb">
            <ul class="breadcrumb">
              <li></li>
            </ul>
          </div>
        </div>
      </header>
      <div class="container body-content">
        
        <div id="search-results">
          <div class="search-list"></div>
          <div class="sr-items">
            <p><i class="glyphicon glyphicon-refresh index-loading"></i></p>
          </div>
          <ul id="pagination"></ul>
        </div>
      </div>
      <div role="main" class="container body-content hide-when-search">
        
        <div class="sidenav hide-when-search">
          <a class="btn toc-toggle collapse" data-toggle="collapse" href="#sidetoggle" aria-expanded="false" aria-controls="sidetoggle">Show / Hide Table of Contents</a>
          <div class="sidetoggle collapse" id="sidetoggle">
            <div id="sidetoc"></div>
          </div>
        </div>
        <div class="article row grid-right">
          <div class="col-md-10">
            <article class="content wrap" id="_content" data-uid="AccountNamespaceTier">
<h1 id="namespace-tier" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="5" sourceendlinenumber="5">Namespace Tier</h1>

<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="7" sourceendlinenumber="7">An attribute that specifies <code>Namespace</code> performance.</p>
<h2 id="properties" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="9" sourceendlinenumber="9">Properties</h2>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="11" sourceendlinenumber="11">For HTTP requests and responses, the NamespaceTier object has the following properties and JSON-serialized body: </p>
<table sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="13" sourceendlinenumber="18">
<thead>
<tr>
<th>Property</th>
<th>Type</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td>Id</td>
<td>string</td>
<td>GUID for this Namespace Tier.</td>
</tr>
<tr>
<td>Description</td>
<td>string</td>
<td>Description of this Tier.</td>
</tr>
<tr>
<td>ThroughputUnits</td>
<td>int32</td>
<td>The number of throughput units associated with this Tier.</td>
</tr>
<tr>
<td>StorageUnits</td>
<td>int32</td>
<td>The number of Storage units associated with this Tier.</td>
</tr>
</tbody>
</table>
<pre sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="21" sourceendlinenumber="28"><code class="lang-json">{
    &quot;Id&quot;: &quot;id&quot;,
    &quot;Description&quot;: &quot;description&quot;,
    &quot;ThroughputUnits&quot;: 0,
    &quot;StorageUnits&quot;: 0
}
</code></pre><hr>
<h2 id="getnamespacetier" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="31" sourceendlinenumber="31"><code>GetNamespaceTier()</code></h2>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="33" sourceendlinenumber="33">Retrieves a Namespace tier associated with a specified id.</p>
<h3 id="http" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="35" sourceendlinenumber="35">Http</h3>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="37" sourceendlinenumber="37"><code>GET api/v1-preview/NamespaceTiers/{namespaceTierId}</code></p>
<h3 id="parameters" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="39" sourceendlinenumber="39">Parameters</h3>
<pre sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="41" sourceendlinenumber="44"><code class="lang-csharp">[Required]
string namespaceTierId
</code></pre><p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="46" sourceendlinenumber="46">The tier identifier for this request.</p>
<h3 id="security" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="49" sourceendlinenumber="49">Security</h3>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="51" sourceendlinenumber="51">A <code>NamespaceTier</code> can be retrieved by an Account Member.</p>
<h3 id="returns" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="53" sourceendlinenumber="53">Returns</h3>
<table sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="55" sourceendlinenumber="58">
<thead>
<tr>
<th>Status Code</th>
<th>Return Type</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td>200</td>
<td>NamespaceTier</td>
<td>A <code>NamespaceTier</code> object with the specified namespaceTierId.</td>
</tr>
<tr>
<td>400</td>
<td>Nothing is returned</td>
<td>Could not retrieve the specified <code>NamespaceTier</code> due to missing or invalid input.</td>
</tr>
</tbody>
</table>
<hr>
<h2 id="getallnamespacetiers" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="62" sourceendlinenumber="62"><code>GetAllNamespaceTiers()</code></h2>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="64" sourceendlinenumber="64">Retrieves a list of all available namespace tiers.</p>
<h3 id="http-1" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="66" sourceendlinenumber="66">Http</h3>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="68" sourceendlinenumber="68"><code>GET api/v1-preview/NamespaceTiers</code></p>
<h3 id="parameters-1" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="70" sourceendlinenumber="70">Parameters</h3>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="72" sourceendlinenumber="72">This API call does not have any parameters.</p>
<h3 id="security-1" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="74" sourceendlinenumber="74">Security</h3>
<p sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="76" sourceendlinenumber="76"><code>NamespaceTiers</code> can be retrieved by an Account Member.</p>
<h3 id="returns-1" sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="78" sourceendlinenumber="78">Returns</h3>
<table sourcefile="Documentation/Management/Account_NamespaceTier.md" sourcestartlinenumber="80" sourceendlinenumber="82">
<thead>
<tr>
<th>Status Code</th>
<th>Return Type</th>
<th>Description</th>
</tr>
</thead>
<tbody>
<tr>
<td>200</td>
<td>[NamespaceTier]</td>
<td>Returns a list of <code>NamespaceTier</code> objects.</td>
</tr>
</tbody>
</table>
<hr>
</article>
          </div>
          
          <div class="hidden-sm col-md-2" role="complementary">
            <div class="sideaffix">
              <div class="contribution">
                <ul class="nav">
                  <li>
                    <a href="https://github.com/osisoft/OCS-Docs/blob/master/Documentation/Management/Account_NamespaceTier.md/#L1" class="contribution-link">Improve this Doc</a>
                  </li>
                </ul>
              </div>
              <nav class="bs-docs-sidebar hidden-print hidden-xs hidden-sm affix" id="affix">
              <!-- <p><a class="back-to-top" href="#top">Back to top</a><p> -->
              </nav>
            </div>
          </div>
        </div>
      </div>
      
      <footer>
        <div class="grad-bottom"></div>
        <div class="footer">
            <span id='copyright-text'>© 2019 - OSIsoft, LLC.<span>
        </span></span></div>
      </footer>
    </div>
    
    <script type="text/javascript" src="../../styles/docfx.vendor.js"></script>
    <script type="text/javascript" src="../../styles/docfx.js"></script>
    <script type="text/javascript" src="../../styles/main.js"></script>
  </body>
</html>
