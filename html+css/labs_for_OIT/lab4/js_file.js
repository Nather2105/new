$(document).ready(function() {
  $('.header__burger').click(function(event) {
    $('.header__burger,.header_menu,.nav').toggleClass('active');
    $('body').toggleClass('lock');
  });
  // $('.trainers').slick();
});


