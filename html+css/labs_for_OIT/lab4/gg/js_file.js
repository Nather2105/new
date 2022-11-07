$(document).ready(function () {
    $('.header__burger').click(function (event) {
        $('.header__burger,.header_menu,.nav').toggleClass('active');
        $('body').toggleClass('lock');
    });
    // $('.trainers').slick();


    // ---------------- Slider ------------------------

    // var getProductHeight = $('.product.active').height();

    $('.products').css({
        height: 483.109
    });

    // function calcProductHeight() {
    //     getProductHeight = $('.product.active').height();
    //
    //     $('.products').css({
    //         height: getProductHeight
    //     });
    // }

    // function animateContentColor() {
    //   var getProductColor = $('.product.active').attr('product-color');
    //
    //   $('body').css({
    //     background: getProductColor
    //   });
    //
    //   $('.title').css({
    //     color: getProductColor
    //   });
    //
    //   $('.btn').css({
    //     color: getProductColor
    //   });
    // }

    var productItem = $('.product'),
        productCurrentItem = productItem.filter('.active');

    $('#next').on('click', function (e) {
        e.preventDefault();

        var nextItem = productCurrentItem.next();

        productCurrentItem.removeClass('active');

        if (nextItem.length) {

            productCurrentItem = nextItem.addClass('active');
        } else {
            productCurrentItem = productItem.first().addClass('active');
        }

        // calcProductHeight();
        // animateContentColor();
    });

    $('#prev').on('click', function (e) {
        e.preventDefault();

        var prevItem = productCurrentItem.prev();

        productCurrentItem.removeClass('active');

        if (prevItem.length) {
            productCurrentItem = prevItem.addClass('active');
        } else {
            productCurrentItem = productItem.last().addClass('active');
        }
        //
        // calcProductHeight();
        // animateContentColor();
    });

    // Ripple

});


