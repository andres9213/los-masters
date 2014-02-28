(function ($) {
	$(document).ready(function() {
		/*fadeout text inputs forms*/
		$.fn.hide_label = function(){
	        var complete_input = this;
	        if($(complete_input).find('input').val() != ''){
	          $(this).find('label').fadeOut();
	        }

	        $(complete_input).find('input').focus(function() {
	          complete_input.find("label").fadeOut();
	        });

	        $(complete_input).find('input').blur(function() {
	          console.log(this);
	          if($(this).val() === ''){
	            complete_input.find("label").fadeIn();
	          }
	        });
	      }
		$('#imocom-newsletter .form-type-textfield').each(function(){
			$(this).hide_label();
		})
		
	});
})(jQuery);
