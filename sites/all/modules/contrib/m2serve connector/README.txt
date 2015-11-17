--------------------------------------------------------------------------------
                                 m2serve Connector
--------------------------------------------------------------------------------

The m2Serve Connector module supports integration with m2Serve Studio. It makes
Drupal features (nodes, users, etc.) and data (views) available in the m2Serve
Studio making it possible to build native, hybrid and mobile web apps very
rapidly for Drupal solutions.

m2Serve is a visual development platform to build applications on current and
future devices. Today you can build and deploy immersive and interactive
mobile applications.

These applications can be native, hybrid or web (HTML5) apps for smartphones
and tablets on iOS, Android, BlackBerry or Windows.

Sign-up now for a free account (limited availability): studio.m2serve.net or
learn more at m2serve.com

m2Serve Connector provides end points via Services and MASt modules.

Main Features
=============
- Connects your Drupal website to m2Serve Studio. It can also be used to
  provide these services to any remote application, for e.g. a mobile app.
- Makes all content types accessible via API's along with individual field
  details with the help of MASt module. In addition extends support for
  field_collection, node_reference and entity_reference.
- Creates a services resource which exposes views as webservices and
  provides the list of the views via web service.
- Provides a simplified interface for managing services.

NOTE
============
- IMPORTANT: Currently only 7.x-3.3 version of the services module is supported.

Installation
============
- Refer https://drupal.org/documentation/install/modules-themes/modules-7
  to read about module installation on Drupal.
- Enable the content types which you want to be accessible via API's.
  To enable it, edit the content type under the "Mobile App" section.
  Enable the checkbox "Allow submission through a mobile app". We
  recommend enabling all the content types so that they are available
  to use via web services.

Documentation
==============
- Services related documentation can be found at http://drupal.org/node/109782
- m2Serve Connector configuration is available at
  'admin/structure/m2serve-connector' and more webservices can be enabled or
  disabled from here.
- It also provides the cURL example to call the webservice.
- Resource named "m2serve_res" provides the API's for fetching the list of
  all the available services, pofile2_type list and content_type lists.
- "views_list" resource provides the list of the views which has a display
  of type "Services".
- On installing m2Serve Connector module for all the existing views,
  display of type "Services" will be created.
- If any view is created after the m2serve Connector module installation,
  a "Services" display has to be created manually so the views_list API
  can contain the result for that view as well.
