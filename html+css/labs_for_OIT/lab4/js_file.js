$(document).ready(function () {
    $('.header__burger').click(function (event) {
        $('.header__burger,.header_menu,.nav,.card,.card2,.btn__reg_ent,.btn_ivts_mobile,.btn,.input_reg_ent').toggleClass('active');
        $('body').toggleClass('lock');
    });
    // $('.trainers').slick();


    // ---------------- Slider ------------------------

    let height = $('.product.active').height();
    let height1 = $('.product1.active').height();
    calcProductHeight(height);
    calcProductHeight(height1);


    function calcProductHeight(height) {
        
        getProductHeight = 490;
        $('.products').css({
            height: getProductHeight
        });
        
        $('.products1').css({
            height: 430
        });
        $('.products2').css({
            height: 300
        });
    }

    var productItem = $('.product'),
        productCurrentItem = productItem.filter('.active');
    var productItem1 = $('.product1'),
        productCurrentItem1 = productItem1.filter('.active');
    var productItem2 = $('.product2'),
        productCurrentItem2 = productItem2.filter('.active');

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

    $('#next').on('click', function (e) {
        e.preventDefault();

        var nextItem1 = productCurrentItem1.next();

        productCurrentItem1.removeClass('active');

        if (nextItem1.length) {

            productCurrentItem1 = nextItem1.addClass('active');
        } else {
            productCurrentItem1 = productItem1.first().addClass('active');
        }

        calcProductHeight();
        // animateContentColor();
    });

    $('#prev').on('click', function (e) {
        e.preventDefault();

        var prevItem1 = productCurrentItem1.prev();

        productCurrentItem1.removeClass('active');

        if (prevItem1.length) {
            productCurrentItem1 = prevItem1.addClass('active');
        } else {
            productCurrentItem1 = productItem1.last().addClass('active');
        }
        calcProductHeight();
    });

    $('#next').on('click', function (e) {
        e.preventDefault();

        var nextItem2 = productCurrentItem2.next();

        productCurrentItem2.removeClass('active');

        if (nextItem2.length) {

            productCurrentItem2 = nextItem2.addClass('active');
        } else {
            productCurrentItem2 = productItem2.first().addClass('active');
        }

        calcProductHeight();
        // animateContentColor();
    });

    $('#prev').on('click', function (e) {
        e.preventDefault();

        var prevItem2 = productCurrentItem2.prev();

        productCurrentItem2.removeClass('active');

        if (prevItem2.length) {
            productCurrentItem2 = prevItem2.addClass('active');
        } else {
            productCurrentItem2 = productItem2.last().addClass('active');
        }
        calcProductHeight();
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


