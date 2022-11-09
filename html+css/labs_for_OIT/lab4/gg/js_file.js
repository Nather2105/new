$(document).ready(function () {
    $('.header__burger').click(function (event) {
        $('.header__burger,.header_menu,.nav,.card,.btn__reg_ent').toggleClass('active');
        $('body').toggleClass('lock');
    });
    // $('.trainers').slick();


    // ---------------- Slider ------------------------

    let height = $('.product.active').height();
    calcProductHeight(height);


    function calcProductHeight(height) {
        if (height == 0)
            getProductHeight = 490;
        else
            getProductHeight = height
        console.log(getProductHeight);

        $('.products').css({
            height: getProductHeight
        });
    }

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

        calcProductHeight();
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
        calcProductHeight();
        // animateContentColor();
    });

    // Ripple


    // $('.products').css({
    //     height: 453.109
    // });

    // var productItem = $('.product'),
    //     productCurrentItem = productItem.filter('.active');

    // $('#next').on('click', function (e) {
    //     e.preventDefault();

    //     var nextItem = productCurrentItem.next();

    //     productCurrentItem.removeClass('active');

    //     if (nextItem.length) {

    //         productCurrentItem = nextItem.addClass('active');
    //     } else {
    //         productCurrentItem = productItem.first().addClass('active');
    //     }

    // });

    // $('#prev').on('click', function (e) {
    //     e.preventDefault();

    //     var prevItem = productCurrentItem.prev();

    //     productCurrentItem.removeClass('active');

    //     if (prevItem.length) {
    //         productCurrentItem = prevItem.addClass('active');
    //     } else {
    //         productCurrentItem = productItem.last().addClass('active');
    //     }
    // });

    // Ripple

});


