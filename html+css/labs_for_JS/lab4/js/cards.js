// зробити профіль 
// зробити вкладку для адміна для додавання нових предметів у  джейсон файл
key_for_cards = "645a63919d312622a35adaa6";
security_key = "$2b$10$umJB4mIwAFndHNVZfAth6u8Ol8k7YDBUtLsk5Teodo3G.dj0F2hSC";
cart = {};

(async function createCards() {

    let response = await fetch(`https://api.jsonbin.io/v3/b/${key_for_cards}/latest`, {
        headers: { 'X-Master-Key': security_key }
    });

    let data = await response.json();
    cardsData = data.record.cardsData;

    act_filter = 0;
    act_byprice = 0;
    current_arr = cardsData;
    render_graphic();
    // console.log(localStorage.getItem('cart'));
    // Підвантаження перших 12 карток.
    const cardGrid = document.getElementById('cards');
    const cardsHTML = cardsData.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}">to the cart</button> <button class="admin_btn" data-articul="${cardsData.indexOf(item)}">delete</button></div>`).slice(0, 12).join(' ');
    cardGrid.innerHTML = cardsHTML;
    // console.log(heightOfMain);


    async function check_func_for_btns() {
        if (logined == null) {

            none_display_for_add_to_cart_btn = document.querySelectorAll('.to_the_cart');
            console.log(none_display_for_add_to_cart_btn);
            none_display_for_add_to_cart_btn.forEach((item) => {
                item.style.display = "none";
            })
            admin_btn = document.querySelectorAll('.admin_btn');
            admin_btn.forEach(item => {
                item.style.display = "none";
            })
    
            
        }
        if (inf.nickname === undefined) {
            admin_btn = document.querySelectorAll('.admin_btn');
            to_the_cart_admin = document.querySelectorAll('.to_the_cart');
            to_the_cart_admin.forEach(item => {
                item.style.display = "none";
            })
            console.log(admin_btn);
            admin_btn.forEach(async item => {
    
                item.addEventListener('click', async event => {
                    let response = await fetch(`https://api.jsonbin.io/v3/b/${key_for_cards}/latest`, {
                        headers: { 'X-Master-Key': security_key }
                    });
                    let data = await response.json();
                    articul = event.target.dataset['articul'];
                    data.record.cardsData = data.record.cardsData.filter(function(item){
                        if(data.record.cardsData.indexOf(item) !== Number(articul)){
                            return item;
                        }
                     });
                     await fetch(`https://api.jsonbin.io/v3/b/${key_for_cards}`, {
                        method: 'PUT',
                        headers: {
                            'content-type': 'application/json',
                            'X-Master-Key': security_key
                        },
                        body: JSON.stringify(data.record)
                    });
                    alert("Card has been deleted");
                    window.location.replace('./index.html');     
                })
            })
        }
        if(logined !== null && inf.nickname !== undefined) {
            admin_btn = document.querySelectorAll('.admin_btn');
            admin_btn.forEach(item => {
                item.style.display = "none";
            })
            to_the_cart_admin = document.querySelectorAll('.to_the_cart');
            to_the_cart_admin.forEach(item => {
                item.style.display = "block";
            })
        }
    }
    check_func_for_btns();
    column = document.querySelector(".column");
    pie = document.querySelector(".pie");
    linear = document.querySelector(".linear");

    column.addEventListener("click", () => {
        chart.data[0].set("type", "column");
        column.style.background = "wheat";
        linear.style.background = "orange";
        pie.style.background = "orange";
        chart.render();
    })
    pie.addEventListener("click", () => {
        chart.data[0].set("type", "pie");
        pie.style.background = "wheat";
        linear.style.background = "orange";
        column.style.background = "orange";
        chart.render();
    })
    linear.addEventListener("click", () => {
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
        if (act_byprice === 1 || act_filter === 1) {
            console.log('123');
        }
        else {
            const newCardsHTML = cardsData.slice(cardGrid.children.length, cardGrid.children.length + 4).map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}">to the cart</button> <button class="admin_btn" data-articul="${cardsData.indexOf(item)}">delete</button></div>`).join(' ');
            cardGrid.innerHTML += newCardsHTML;
            check_func_for_btns();
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
        filtered = filteredCardsHTML.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}">to the cart</button> <button class="admin_btn" data-articul="${cardsData.indexOf(item)}">delete</button></div>`).join(' ');
        cardGrid.innerHTML = filtered;
        check_func_for_btns();
        act_filter = 1;
        if (act_byprice === 1) {
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
            if (current_arr[i] !== undefined) {
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
                if (current_arr[j] !== undefined) {

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
        if (fl === 0) {
            fl = 1;
        }
        else if (fl === 1) {
            cart2.reverse();
            fl = 0;
        }
        // console.log(cart_reversed);
        let filteredCardsHTML1 = cart2.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}">  <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}")>to the cart</button> <button class="admin_btn" data-articul="${cardsData.indexOf(item)}">delete</button></div>`);
        console.log(filteredCardsHTML1);
        cardGrid.innerHTML = filteredCardsHTML1.slice(0, 32).join(' ');
        check_func_for_btns();
        // current_arr = cart2;
        act_byprice = 1;
        console.log(current_arr);
        // render_graphic();
    }

    // Кнопка сбросу.
    const resetButton = document.getElementById('reset');
    resetButton.addEventListener('click', resetCards);

    function resetCards() {
        const cardsHTML = cardsData.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}">  <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="text-container"><p class="description">${item.description}</p></div><button class="to_the_cart" data-articul="${cardsData.indexOf(item)}")>to the cart</button> <button class="admin_btn" data-articul="${cardsData.indexOf(item)}">delete</button></div>`).slice(0, 12).join(' ');
        cardGrid.innerHTML = cardsHTML;
        check_func_for_btns();
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


document.querySelector('.cards').addEventListener('click', async event => {
    // console.log('1');
    // if(localStorage.getItem('cart') !== null) {
    //     cart = JSON.parse(localStorage.cart);
    //     // console.log(cart);
    // }
    let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });

    let data = await response.json();
    current_user = JSON.parse(localStorage.currentUser);
    data.record.users.forEach((item) => {
        if (item.login === current_user.login) {
            index = data.record.users.indexOf(item);
            console.log(index);
            return;
        }
    });
    cart = data.record;
    if (event.target.classList.contains('to_the_cart')) {
        console.log('2');
        let articul = event.target.dataset['articul'];
        console.log(articul);

        if (cart.users[index].cart[articul] !== undefined) {
            cart.users[index].cart[articul]['count']++;
            console.log('3');
        }
        else {
            cart.users[index].cart[articul] = cardsData[articul];
            console.log(cart.users[index].cart[articul]);
            cart.users[index].cart[articul]['count'] = 1;
            console.log('4');
        }
        await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}`, {
            method: 'PUT',
            headers: {
                'content-type': 'application/json',
                'X-Master-Key': API_KEY
            },
            body: JSON.stringify(cart)
        });
        localStorage.setItem('currentUser', JSON.stringify(cart.users[index]));
    }
});

function render_graphic() {
    twot = 0;
    onet = 0;
    zerot = 0;
    for (i = 0; i < current_arr.length; i++) {
        if (current_arr[i].price >= 2000) {
            twot++;
        }
        else if (current_arr[i].price < 2000 && current_arr[i].price >= 1000) {
            onet++;
        }
        else if (current_arr[i].price <= 999) {
            zerot++;
        }
    }


    chart = new CanvasJS.Chart("chartContainer", {
        // border: "10px solid black;",
        title: {
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
                    { label: "more than 2000 $", y: twot },
                    { label: "1000-1999 $", y: onet },
                    { label: "999 $ and less ", y: zerot },
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

