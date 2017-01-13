This module makes it possible to "gate" Info Center items -- i.e., require the
user to fill out a marketo form before they can access the item.

The module works by doing two things:

1. If a user goes to an Info Center item that has the field_infoctr_gate flag
set to 1, the module will check if the user is being referred from the form page
(info-center/register) and if not, redirect them there.

2. When the user requests a gated asset, a page is dynamically generated which
displays an embedded marketo form (info-center/register). The template
controlling the content and layout of this page is included in this module
(gated-assets.tpl.php). The requested asset is captured in variables taken from
the URL query parameter "asset" and is passed to the form's onSuccess handler,
overriding the form's default thank you page.

3. This works with marketo forms2 with or without progressive profiling enabled.

4. To configure, enable module and set marketo key and form id at admin/config/search/sp_gatedassets

Author: Anne ("Banoodle") Bonham abonham@mollyduggan.com
