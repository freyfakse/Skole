/*jslint browser: true*/
/*global $, jQuery*/

// The above lines help the editor (Brackets etc.) validate our code

// Sets a function that is run when the document is ready
$(document).ready(function () {
  'use strict';

  // Set the initial value of the text span
  $('#textOutput').text('Initial value');
  
  // Hook up the button click handler using the button's id.
  // This is recommended as it keeps script stuff out of your HTML.
  $('#btnUpdate').click(buttonExternalJQuery);
});

function buttonExternalJQuery() {
  'use strict';

  $('#textOutput').text($('#textInput').val());
}
