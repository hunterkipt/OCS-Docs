---	
uid: omfIngressSpecification
---

# Use OSIsoft Message Format with OSIsoft Cloud Services

[The OSIsoft Message Format (OMF) specification](http://omf-docs.osisoft.com) is generic in that it does not specify a particular back-end system. This topic is a companion to the OMF specification which describes how OMF is interpreted by OSIsoft Cloud Services back-end system. 

## Headers
For a description of each of the headers, see [OMF specification](http://omf-docs.osisoft.com). Note that rather than using a ``producertoken``, data collection calls to OCS require a bearer token to be attached in the header, as documented in the [OCS Quick Start](xref:sdsQuickStart) documentation. The bearer token is used to authenticate the sender and to authorize the sender for use with a particular tenant. The client ID associated with this token is used to route messages to a particular [topic](xref:omfIngressTopics) that it is mapped to.

The ``omfversion`` header must match the version of the OMF spec used to construct the message.
Versions 1.0, 1.1, and 1.2 of the spec are currently supported. 

## Message types

OMF message types fall into three categories: *type*, *container*, and *data*, which are described below. 

## Type messages

A *type* message is interpreted by OSIsoft Cloud Services as an SdsType in the Sequential Data Store. 

Because SdsTypes are immutable, update operations are not supported. The keywords in the type definition, by OMF version, are interpreted as follows:

### OMF 1.0 and 1.1

  + ``id``: Corresponds to the SdsType Id field. It must conform to the rules defined for a 
    typeId specified here: [types](xref:sdsTypes)
  + ``classification``: Only the ``dynamic`` classification is currently supported.
  + ``version``: Versioning of SdsTypes is not supported.
  + ``name``: Corresponds to the SdsType Name field. This is the friendly name for the type.
  + ``description``: Corresponds to the SdsType Description field. 
  + ``properties``: Key-value pairs defining the properties of a type
  + ``type``: Inherited from JSON Schema. Must be set to object. 

### OMF 1.1

  + ``id``: Corresponds to the SdsType Id field. It must conform to the rules defined for a 
    typeId specified here: [types](xref:sdsTypes)
  + ``classification``: Only the ``dynamic`` classification is currently supported.
  + ``version``: Versioning of SdsTypes is not supported.
  + ``name``: Corresponds to the SdsType Name field. This is the friendly name for the type.
  + ``description``: Corresponds to the SdsType Description field. 
  + ``properties``: Key-value pairs defining the properties of a type
  
      **Note**: A `uom` keyword for type properties was added with OMF 1.1.
      
  + ``type``: Inherited from JSON Schema. Must be set to object.
  
      **Note**: Nullable type properties were added with OMF 1.1.
      
  
### OMF 1.2

  OMF 1.2 type messages contain the same keywords as OMF 1.0 and 1.1, plus the following:

  + ``enum``: Optional array of name/value pairs used to define an allowed set of values. Classification should not be set when defining an enum type.

  **Note**: OMF 1.2 adds support for [enum](https://omf-docs.osisoft.com/documentation_v12/Types/Enum_Type.html) and [flag](https://omf-docs.osisoft.com/documentation_v12/Types/Type_Properties_and_Formats.html) type messages. These types can be created and used in object types using the "reftypeid" keyword. 
  
  The ``isindex`` keyword corresponds to the ``iskey`` attribute of an SdsTypeProperty. SdsTypes support clustered indexes which can be specified with multiple properties marked with the ``isindex`` keyword with a value of ``true``. For compound indexes, the index property order within the message corresponds to the ``Order`` field of an SdsTypeProperty. The ``isname`` keyword is not supported.

### Link type

Link types are not supported in Sequential Data Store, and will be ignored.

<!--deleting per Chris feedback
### Span type
  Span types are not supported in Sequential Data Store.
-->

### Property types and formats
OMF supports setting the ``format`` keyword to specify how a particular JSON type should be interpreted. The following is a mapping for the Sequential Data Store supported 
types (see [types](xref:sdsTypes)):


Type     | Format   | SdsTypeCode
-------- | -------- | -----------
array		 |          | IEnumerable
boolean  |          | boolean
integer	 | int64    | Int64
integer  | int32    | Int32
integer  | int16    | Int16
integer  | uint64   | Uint64
integer  | uint32   | Uint32
number   | uint16   | Uint16
number   | float64  | Double
number   | float32  | Single
number   | float16  | Single
object   | dictionary | Idictionary
string   |          | String
string   | date-time | DateTime

## Container messages

A *container* message is interpreted as an SdsStream in the Sequential Data Store. The keywords 
in the *container* definition are interpreted as follows:

### OMF 1.0

* ``id``: Corresponds to the SdsStream Id field. It must conform to the rules defined for
    an SdsStream Id specified here: [Streams](xref:sdsStreams#streams).
* ``typeid``: Corresponds to the SdsStream TypeId field.
* ``typeversion``: Versioning of SdsTypes is not supported.
* ``name``: Corresponds to the SdsStream Name field. This is a friendly name for the stream.
* ``description``: Corresponds to the SdsStream Description field.
* ``tags``: Corresponds to the SdsStream Tag field. 
* ``metadata``: Corresponds to the SdsStream Metadata field.        

### OMF 1.1

 OMF 1.1 container messages contain the same keywords as OMF 1.0 plus the following:

* ``indexes``: Optional array of type property ids to be used as secondary indexes for the container.

### OMF 1.2

OMF 1.2 container messages contain the same keywords as OMF 1.0 and 1.1, plus the following:

* ``datasource``: Optional string used to specify the source of a stream of data.
* ``propertyoverrides``: Optional key-value pairs used to override properties on a type definition. `Uom` is the only property for which override is supported by OMF 1.2.

## Data messages

A *data* message is mapped to generic Sds values in the Sequential Data Store. The keywords in the 
*data* definitions are interpreted as follows:

### OMF 1.0/OMF 1.1

* ``typeid``: Data that is not grouped by containerId is not supported.
* ``typeversion``: Versioning of SdsTypes is not supported.
* ``containerid``: Stream Id for the associated Sds Stream.
* ``values``: An array of the generic Sds values.

### OMF 1.2

* ``typeid``: Data that is not grouped by containerId is not supported.
* ``containerid``: Stream Id for the associated Sds Stream.
* ``properties``:	Optional key-value pairs defining the properties of the type. Used to support sending type-less static data values.
* ``values``: An array of the generic Sds values.
