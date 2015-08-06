// Register our custom "callout" widget plugin with CKEditor.
CKEDITOR.plugins.add('callout', {
  requires: 'widget',
  init: function(editor) {
    // Register the toolbar buttons for the CKEditor editor instance.
    editor.ui.addButton( 'callout', {
      label : 'Insert callout box',
      icon : this.path + 'icon-callout.png',
      command : 'callout'
    });
    // Register the widget.
    editor.widgets.add('callout', {
      template: '<div class="callout">Callout box contents here.</div>',
      allowedContent: 'div(!callout)',
      editables: {
        contents: {
          selector: '.callout'
        }
      },
      upcast: function(element) {
        if (element.name == 'div' && element.hasClass('callout')) {
          return true;
        }
        else {
          return false;
        }
      }
    });
  }
});
