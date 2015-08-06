CKEDITOR.dialog.add( 'accordionDialog', function ( editor ) {
    return {
        title: 'Configure Your Accordion',
        minWidth: 400,
        minHeight: 200,
        contents: [
            {
                id: 'tab-basic',
                label: 'Basic Settings',
                elements: [
                    {
                        type: 'text',
                        id: 'number',
                        label: 'Number of sections for your accordion',
                        validate: CKEDITOR.dialog.validate.notEmpty( "You must provide a number" )
                    }
                ]
            }
        ],
        onOk: function() {
            var dialog = this;
            var sections = parseInt(dialog.getValueOf('tab-basic','number')); //Number of sections for your accordion

            section = "<div class='accordion__title'>Accordion Header</div><div class='accordion__content'><p>Accordion Content</p></div>"
            intern = ""
            for (i=0;i<sections;i++){
                intern = intern + section
            }

            editor.insertHtml('<div class="accordion">'+ intern +'</div>');

        }
    };
});
