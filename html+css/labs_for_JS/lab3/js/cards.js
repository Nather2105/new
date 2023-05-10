// Массив объектов с данными для карточек
const cardsData = [
    {
        imgSrc: 'imgs/ragdoll.jpeg',
        title: 'Ragdoll',
        price: 2500,
        description: "Lifespan: 12-17 years"
    },
    {
        imgSrc: 'imgs/exotic-shorthair.jpeg',
        title: 'Exotic Shorthair',
        price: 2200,
        description: 'Lifespan: 12-15 years'
    },
    {
        imgSrc: 'imgs/british-shorthair.jpeg',
        title: 'British Shorthair',
        price: 2300,
        description: 'Lifespan: 12-17 years'
    },
    {
        imgSrc: 'imgs/persian-cat.jpeg',
        title: 'Persian',
        price: 1670,
        description: 'Lifespan: 14-15 years'
    },
    {
        imgSrc: 'imgs/maine-coon.jpeg',
        title: 'Maine Coon',
        price: 999,
        description: 'Lifespan: 12-15 years'
    },
    {
        imgSrc: 'imgs/american-shorthair.jpeg',
        title: 'American Shorthair',
        price: 199,
        description: 'Lifespan: 15-17 years'
    },
    {
        imgSrc: 'imgs/devon-rex.jpeg',
        title: 'Devon Rex',
        price: 299,
        description: 'Lifespan: 10-15 years'
    },
    {
        imgSrc: 'imgs/sphynx.jpeg',
        title: 'Sphynx',
        price: 399,
        description: 'Lifespan: 12-14 years'
    },
    {
        imgSrc: 'imgs/scottish-fold.jpeg',
        title: 'Scottish Fold',
        price: 499,
        description: 'Lifespan: 11-14 years'
    },
    {
        imgSrc: 'imgs/abyssinian.jpeg',
        title: 'Abyssinian',
        price: 599,
        description: 'Lifespan: 14-15 years'
    },
    {
        imgSrc: 'imgs/oriental-shorthair.jpeg',
        title: 'Oriental',
        price: 699,
        description: 'Lifespan: 12-14 years'
    },
    {
        imgSrc: 'imgs/siamese.jpeg',
        title: 'Siamese',
        price: 799,
        description: 'Lifespan: 12-15 years'
    },
    {
        imgSrc: 'imgs/norwegian-forest-cat.jpeg',
        title: 'Norwegian Forest Cat',
        price: 899,
        description: 'Lifespan: 12-16 years'
    },
    {
        imgSrc: 'imgs/cornish-rex.jpeg',
        title: 'Cornish Rex',
        price: 1099,
        description: 'Lifespan: 11-14 years'
    },
    {
        imgSrc: 'imgs/bengal.jpeg',
        title: 'Bengal',
        price: 1199,
        description: 'Lifespan: 12-16 years'
    },
    {
        imgSrc: 'imgs/russian-blue.jpeg',
        title: 'Russian Blue',
        price: 1299,
        description: 'Lifespan: 10-16 years'
    },
    {
        imgSrc: 'imgs/siberian.jpeg',
        title: 'Siberian',
        price: 1399,
        description: 'Lifespan: 12-15 years'
    },
    {
        imgSrc: 'imgs/burmese.jpeg',
        title: 'Burmese',
        price: 1499,
        description: 'Lifespan: 15-16 years'
    },
    {
        imgSrc: 'imgs/birman.jpeg',
        title: 'Birman',
        price: 1599,
        description: 'Lifespan: 14-15 years'
    },
    {
        imgSrc: 'imgs/tonkinese.jpeg',
        title: 'Tonkinese',
        price: 1699,
        description: 'Lifespan: 14-16 years'
    },
    {
        imgSrc: 'imgs/ocicat.jpeg',
        title: 'Ocicat',
        price: 1799,
        description: 'Lifespan: 12-14 years'
    },
    {
        imgSrc: 'imgs/selkirk-rex.jpeg',
        title: 'Selkirk Rex',
        price: 1899,
        description: 'Lifespan: 14-15 years'
    },
    {
        imgSrc: 'imgs/ragamuffin-cat.jpeg',
        title: 'Ragamuffin',
        price: 1999,
        description: 'Lifespan: 12-16 years'
    },
    {
        imgSrc: 'imgs/american-curl.jpeg',
        title: 'American Curl',
        price: 2099,
        description: 'Lifespan: 12-16 years'
    },
    {
        imgSrc: 'imgs/japanese-bobtail.jpeg',
        title: 'Japanese Bobtail',
        price: 2199,
        description: 'Lifespan: 14-16 years'
    },
    {
        imgSrc: 'imgs/manx.jpeg',
        title: 'Manx',
        price: 2299,
        description: 'Lifespan: 12-14 years'
    },
    {
        imgSrc: 'imgs/egyptian-mau.jpeg',
        title: 'Egyptian Mau',
        price: 2399,
        description: 'Lifespan: 18-20 years'
    },
    {
        imgSrc: 'imgs/somali.jpeg',
        title: 'Somali',
        price: 2499,
        description: 'Lifespan: 12-16 years'
    },
    {
        imgSrc: 'imgs/balinese.jpeg',
        title: 'Balinese',
        price: 2599,
        description: 'Lifespan: 10-15 years'
    },
    {
        imgSrc: 'imgs/singapura.jpeg',
        title: 'Singapura',
        price: 2699,
        description: 'Lifespan: 12-15 years'
    },
    {
        imgSrc: 'imgs/colorpoint-shorthair.jpeg',
        title: 'Colorpoint Shorthair',
        price: 2799,
        description: 'Lifespan: 12-16 years'
    },
    {
        imgSrc: 'imgs/lykoi.jpeg',
        title: 'Lykoi',
        price: 2899,
        description: 'Lifespan: 12-16 years'
    }
];
cart={};

(function createCards() {

    act_filter = 0;
    act_byprice = 0;
    current_arr = cardsData;
    render_graphic();
    // console.log(localStorage.getItem('cart'));
    // Підвантаження перших 12 карток.
    const cardGrid = document.getElementById('cards');
    const cardsHTML = cardsData.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}">to the cart</button></div>`).slice(0, 12).join(' ');
    cardGrid.innerHTML = cardsHTML;
    // console.log(heightOfMain);


    column = document.querySelector(".column");
    pie = document.querySelector(".pie");
    linear = document.querySelector(".linear");

    column.addEventListener("click", ()=>{
        chart.data[0].set("type", "column");
        column.style.background = "wheat";
        linear.style.background = "orange";
        pie.style.background = "orange";
        chart.render();
    })
    pie.addEventListener("click", ()=>{
        chart.data[0].set("type", "pie");
        pie.style.background = "wheat";
        linear.style.background = "orange";
        column.style.background = "orange";
        chart.render();
    })
    linear.addEventListener("click", ()=>{
        chart.data[0].set("type", "line");
        linear.style.background = "wheat";
        pie.style.background = "orange";
        column.style.background = "orange";
        chart.render();
    })
    // Довантаження ще +4 картки.
    const loadMoreButton = document.getElementById('show-more-btn');

    loadMoreButton.addEventListener('click', loadMoreCards);
    function loadMoreCards() {
        if(act_byprice === 1 || act_filter === 1){
            console.log('123');
        } 
        else {
            const newCardsHTML = cardsData.slice(cardGrid.children.length, cardGrid.children.length + 4).map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}">to the cart</button></div>`).join(' ');
            cardGrid.innerHTML += newCardsHTML;
        }
    }

    // Фільтр по ключовому слову.
    const filterButton = document.getElementById('filter');
    filterButton.addEventListener('click', filterCards);
    function filterCards() {
        const filterInput = document.getElementById('filter-input');
        const filterText = filterInput.value.toLowerCase();

        const filteredCardsHTML = cardsData.filter(item => item.title.toLowerCase().includes(filterText) || item.description.toLowerCase().includes(filterText));
        console.log(filteredCardsHTML);
        current_arr = filteredCardsHTML;
        filtered = filteredCardsHTML.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}">to the cart</button></div>`).join(' ');
        cardGrid.innerHTML = filtered;
        act_filter = 1;
        if(act_byprice === 1){
            byprice();
        }
        render_graphic();
    }

    const byPriceButton = document.getElementById('by_price');
    byPriceButton.addEventListener('click', byprice);
    fl = 0;
    function byprice() {
        cart2 = [];
        pricer = [];
        for (let i = 0; i < 32; i++) {
            if(current_arr[i] !== undefined){
                pricer.push(current_arr[i].price);
                // console.log(cardsData[i]);
            }
        }
        // console.log(cart1);
        // console.log(pricer.length);
        let swapper;
        let j;
        for (let i = 0; i < pricer.length; i++) {
            for (j = i + 1; j < pricer.length; j++) {
                if (pricer[i] < pricer[j]) {
                    swapper = pricer[i];
                    pricer[i] = pricer[j];
                    pricer[j] = swapper;
                }
            }
        }
        // console.log(pricer);
        for (let i = 0; i < pricer.length; i++) {
            for (j = 0; j < 32; j++) {
                if(current_arr[j] !== undefined){

                    if (pricer[i] === current_arr[j].price) {
                        cart2.push(current_arr[j]);
                        continue;
                    }
                }
            }
            console.log('1');
        }
        // cart2 = 0;
        console.log(cart2);
        if(fl === 0) {
            fl = 1;
        }
        else if(fl === 1){
            cart2.reverse();
            fl = 0;
        }
        // console.log(cart_reversed);
        let filteredCardsHTML1 = cart2.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}">  <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}")>to the cart</button></div>`);
        console.log(filteredCardsHTML1);
        cardGrid.innerHTML = filteredCardsHTML1.slice(0, 32).join(' ');
        // current_arr = cart2;
        act_byprice = 1;
        console.log(current_arr);
        // render_graphic();
    }

    // Кнопка сбросу.
    const resetButton = document.getElementById('reset');
    resetButton.addEventListener('click', resetCards);

    function resetCards() {
        const cardsHTML = cardsData.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}">  <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}")>to the cart</button></div>`).slice(0, 12).join(' ');
        cardGrid.innerHTML = cardsHTML;

        const filterInput = document.getElementById('filter');
        filterInput.value = '';
        filterInput.blur();
        act_byprice = 0;
        act_filter = 0;
        current_arr = cardsData;
        render_graphic();
    }


})();

// Повернення на початок сторінки.
var backToTopBtn = document.getElementById("to-the-top-btn");
window.addEventListener("scroll", function () {
    if (window.pageYOffset > window.innerHeight / 2) {
        backToTopBtn.style.display = "block";
    } else {
        backToTopBtn.style.display = "none";
    }
});

function scrollToTheTop() {
    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });
};

document.querySelector('.cards').addEventListener('click', event => {
    // console.log('1');
    if(localStorage.getItem('cart') !== null) {
        cart = JSON.parse(localStorage.cart);
        // console.log(cart);
    }
    if(event.target.classList.contains('to_the_cart')) {
        console.log('2');
        let articul = event.target.dataset['articul'];
        console.log(articul);
        if(cart[articul] !== undefined){
            cart[articul]['count']++;
            console.log('3');
        }
        else {
            cart[articul] = cardsData[articul];
            console.log(cart[articul]);
            cart[articul]['count'] = 1; 
            console.log('4');
        }
        localStorage.setItem('cart', JSON.stringify(cart));
        console.log('5');
    }
});

function render_graphic() {
    twot = 0;
    onet = 0;
    zerot = 0;
    // CanvasJS.addColorSet("colors",
    // [//colorSet Array [
    //     "#020035",
    //     "#34414e",
    //     "#220a0a",
    //     "#280137"
    // ]);
    for(i = 0; i < current_arr.length; i++) {
        if(current_arr[i].price >= 2000) {
            twot++;
        }
        else if(current_arr[i].price < 2000 && current_arr[i].price >= 1000) {
            onet++;
        }
        else if(current_arr[i].price <= 999) {
            zerot++;
        }
    }


    chart = new CanvasJS.Chart("chartContainer", {
        // border: "10px solid black;",
		title:{
			text: "Money issue",
            fontColor: "Black"              
		},
        // colorSet: "colors",
        backgroundColor: "orange",
        // toolTip: {
        //     fontColor: "Black"
        // },
		data: [              
		{
            indexLabelFontColor: "Black",
			type: "pie",
			dataPoints: [
				{ label: "more than 2000 $",  y: twot },
				{ label: "1000-1999 $",  y: onet },
				{ label: "999 $ and less ",  y: zerot },
			]
            
		}
		]
	});
    chart.render();
    column = document.querySelector(".column");
    linear = document.querySelector(".linear");
    pie = document.querySelector(".pie");
    pie.style.background = "wheat";
    linear.style.background = "orange";
    column.style.background = "orange";

};

  