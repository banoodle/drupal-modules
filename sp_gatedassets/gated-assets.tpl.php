<?php
/**
 *
 * Template for marketo form page.
 *
 */
?>
<?php
if (isset($_GET['ref'])) {
    $_SESSION['ref'] = htmlspecialchars(substr($_GET['ref'], 0, 100));
}
?>

<?php include_once $directory . '/templates/navigation.php'; ?>
<div class="clear"></div>

<div id="body-wrapper">
<div id="page">
  <div id="main">
    <div id="content" class="column clearfix" role="main">
      <?php print render($page['highlighted']); ?>
      <?php print $breadcrumb; ?>
      <a id="main-content"></a>
      <?php if ($title): ?>
        <hgroup class="head-box">
          <?php print render($title_prefix); ?>
          <h1 class="title" id="page-title"><?php print $title; ?></h1>
          <?php print render($title_suffix); ?>
          <?php if ($subtitle): ?>
            <h2><?php print $subtitle; ?></h2>
          <?php endif; ?>
        </hgroup>
        <?php print $head_box_suffix; /*see template.php*/ ?>
      <?php endif; ?>

      <div id="content-holder">
        <?php print $messages; ?>
        <?php print render($tabs); ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>
        <script src="//app-sji.marketo.com/js/forms2/js/forms2.min.js"></script>
        <form id="mktoForm_3673"></form>
        <script>MktoForms2.loadForm("//app-sji.marketo.com", "[marketo_key goes here]", [marketo formid goes here], function(form) {
            //Add an onSuccess handler
            form.onSuccess(function(values, followUpUrl) {
              // Get asset path from url 'Asset' query parameter
              function getParameterByName( name ){
                var regexS = "[\\?&]"+name+"=([^&#]*)",
                regex = new RegExp( regexS ),
                results = regex.exec( window.location.search );
                if( results == null ){
                  return "";
                } else{
                  return decodeURIComponent(results[1].replace(/\+/g, " "));
                }
              }
              var assetpath = getParameterByName('asset');
              // Take the lead to a different page on successful submit, ignoring the form's configured followUpUrl
              go_url = location.protocol + '//' + location.host + Drupal.settings.basePath + 'node/' + assetpath;
              location.href = go_url;
              // Return false to prevent the submission handler continuing with its own processing
              return false;
            });
        });
        </script>
        <div class="clearfix"></div>
        <?php print render($page['content_bottom']); ?>
        <?php print $feed_icons; ?>
      </div><!--/#content-holder-->

      <?php
      $sidebar_first = render($page['sidebar_first']);
      $sidebar_first_bottom = render($page['sidebar_first_bottom']);

      if ($sidebar_first || $sidebar_first_bottom) { ?>
        <aside id="sidebar-first" class="sidebar-wrapper">
          <?php if ($sidebar_first) { ?>
            <div id="sidebar-first-top">
              <?php print $sidebar_first; ?>
            </div>
          <?php } ?>
          <?php if ($sidebar_first_bottom) { ?>
            <div id="sidebar-first-bottom">
              <?php print $sidebar_first_bottom; ?>
            </div>
          <?php } ?>
        </aside>
      <?php } ?>

      <?php
      $sidebar_second = render($page['sidebar_second']);
      $sidebar_second_bottom = render($page['sidebar_second_bottom']);

      if ($sidebar_second || $sidebar_second_bottom) { ?>
        <aside id="sidebar-second" class="sidebar-wrapper">
          <?php if ($sidebar_second) { ?>
            <div id="sidebar-second-top">
              <?php print $sidebar_second; ?>
            </div>
          <?php } ?>
          <?php if ($sidebar_second_bottom) { ?>
            <div id="sidebar-second-bottom">
              <?php print $sidebar_second_bottom; ?>
            </div>
          <?php } ?>
        </aside>
      <?php } ?>

    </div><!-- /#content -->
  </div><!-- /#main -->

</div><!-- /#page -->
</div><!-- /#body-wrapper-->

<?php include_once $directory . '/templates/footer.php'; ?>
<?php print render($page['bottom']); ?>
