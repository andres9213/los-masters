(function($) {
  Drupal.imSiteConfig = Drupal.imSiteConfig || {};
  Drupal.imSiteConfig.speed = 1;
  Drupal.imSiteConfig.logoWidth = 0;
  Drupal.imSiteConfig.logosQty = 0;
  Drupal.imSiteConfig.interval = '';
  Drupal.imSiteConfig.logosCarousel = function() {
    Drupal.imSiteConfig.interval = setInterval(function() {
      var contentLeft = parseInt($('.view-id-logos .view-content').css('left'));
      $('.view-id-logos .view-content').css('left', contentLeft - Drupal.imSiteConfig.speed);
      if ((contentLeft * -1) > Drupal.imSiteConfig.logoWidth) {
        $('.view-id-logos .views-row:first').appendTo('.view-id-logos .view-content');
        $('.view-id-logos .view-content').css('left', -Drupal.imSiteConfig.speed);  
      };
    }, 30);
  };
  Drupal.behaviors.imSiteConfigBehavior = {
    attach : function(context, settings) {
    	Drupal.imSiteConfig.logoWidth = $('.view-id-logos .views-row').width();
    	Drupal.imSiteConfig.logosQty = $('.view-id-logos .views-row').length;
    	var logosWidth = Drupal.imSiteConfig.logoWidth * Drupal.imSiteConfig.logosQty;
    	var viewWidth = $('.view-id-logos').width();
    	var diff = logosWidth - viewWidth;
    	$('.view-id-logos .view-content').width(logosWidth);
      Drupal.imSiteConfig.logosCarousel();
      $('.view-id-logos', context).mouseenter(function() {
        clearInterval(Drupal.imSiteConfig.interval);
      }).mouseleave(function() {
        Drupal.imSiteConfig.logosCarousel();
      });
    }
  };
})(jQuery);