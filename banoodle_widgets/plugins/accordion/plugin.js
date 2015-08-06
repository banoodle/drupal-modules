(function($){

CKEDITOR.plugins.add('accordion', {
  requires: 'widget',
  init: function(editor) {
    // Register the toolbar buttons for the CKEditor editor instance.
    editor.ui.addButton('accordion',
    {
      label : 'Insert Accordion',
      icon : this.path + 'icon-accordion.png',
      command: 'accordionDialog'
    });

    // Add our plugin-specific CSS to style the widget within CKEditor.
    editor.addContentsCss( this.path + 'editor-accordion.css' );
	
	editor.addCommand( 'accordionDialog', new CKEDITOR.dialogCommand( 'accordionDialog' ) );
	CKEDITOR.dialog.add( 'accordionDialog', this.path + 'dialogs/accordion.js' );
  }

});


})(jQuery);
