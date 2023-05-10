(async function create() {

    fl = 0;
    current_user = JSON.parse(localStorage.currentUser);
    cart1 = current_user.cart;
    console.log(cart1);
    current_arr = cart1;
    lastBtn = 0;
    cardGridCart = document.getElementById('cards_for_cart');
    cardsHTMLCart = [];
    for (let i = 0; i < 32; i++) {
        if (cart1[i] !== undefined) {
            cart1[i]['articul'] = i;
            cardsHTMLCart.push(`<div class="card"> <img src="${cart1[i].imgSrc}" alt="${cart1[i].title}"> <h2 style="margin: 0">${cart1[i].title}</h2> <h3>${cart1[i].price} $</h3> <div class="amount"><button class="minus" data-articul="${i}">-</button> <input class="how_much" data-articul="${i}" placeholder="${cart1[i].count}"> <button class="plus" data-articul="${i}">+</button> </div></div>`);
        }
    }
    const total = document.getElementById('total');
    total.style.border = "3px solid black";
    total.style.borderRadius = "50px";
    total.style.height = "40px";
    total.style.marginTop = "20px";
    total.style.backgroundColor = "orange";
    total.style.textAlign = "center";
    total.style.fontSize = "30px";
    cardGridCart.innerHTML = cardsHTMLCart.slice(0, 32).join(' ');
    recalculate();

    // Фільтр по ключовому слову.
    const filterButton = document.getElementById('filter');
    filterButton.addEventListener('click', filterCards);


    // фільтр по прайсу
    const byPriceButton = document.getElementById('by_price');
    byPriceButton.addEventListener('click', byprice);


    // Кнопка сбросу.
    const resetButton = document.getElementById('reset');
    resetButton.addEventListener('click', resetCards);




})();

function recalculate() {
    sum = 0;
    for (let i = 0; i < 32; i++) {
        if (cart1[i] !== undefined) {
            sum += (cart1[i].price * cart1[i].count);
        }
    }
    total.innerText = "Total: " + sum + " $";
}

document.querySelector('.cards_for_cart').addEventListener('click', async event => {
    if (event.target.classList.contains('minus')) {
        let articul = event.target.dataset['articul'];
        if (cart1[articul].count !== 0) {
            cart1[articul].count -= 1;
        }

        if (cart1[articul].count === 0) {
            let conf = confirm("are you sure to delete this item from cart?");
            if (conf === true) {
                delete (cart1[articul]);
                console.log(cart1);
                turnRightFunc();
            }
            else {
                cart1[articul].count += 1;
            }
        }
        let all_how_much = document.querySelectorAll('.how_much');
        all_how_much.forEach(item => {
            if (articul === item.dataset['articul']) {
                console.log(item.dataset['articul']);
                item.placeholder = cart1[articul].count;
                return;
            }
        });
        let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
            headers: { 'X-Master-Key': API_KEY }
        });
        
        let data = await response.json();
        data.record.users.forEach((item) => {
        if(item.login === current_user.login){
                index = data.record.users.indexOf(item);
                console.log(index);
                return;
        } 
        });
        data.record.users[index].cart = cart1;
        await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}`, {
            method: 'PUT',
            headers: {
                'content-type': 'application/json',
                'X-Master-Key': API_KEY
            },
            body: JSON.stringify(data.record)
        });
        localStorage.setItem('currentUser', JSON.stringify(data.record.users[index]));
        recalculate();
    }

    if (event.target.classList.contains('plus')) {
        let articul = event.target.dataset['articul'];
        cart1[articul].count += 1;
        let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
            headers: { 'X-Master-Key': API_KEY }
        });
        
        let data = await response.json();
        data.record.users.forEach((item) => {
        if(item.login === current_user.login){
                index = data.record.users.indexOf(item);
                console.log(index);
                return;
        } 
        });
        data.record.users[index].cart = cart1;
        await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}`, {
            method: 'PUT',
            headers: {
                'content-type': 'application/json',
                'X-Master-Key': API_KEY
            },
            body: JSON.stringify(data.record)
        });
        localStorage.setItem('currentUser', JSON.stringify(data.record.users[index]));
        let all_how_much = document.querySelectorAll('.how_much');
        console.log(cart1[articul].count);
        all_how_much.forEach(item => {
            if (articul === item.dataset['articul']) {
                console.log(item.dataset['articul']);
                item.placeholder = cart1[articul].count;
                return;
            }
        });
        
        recalculate();
    }

})

function turnRightFunc() {
    if (lastBtn === 0) {
        resetCards();
    }
    else if (lastBtn === 1) {
        filterCards();
    }
    else if (lastBtn === 2) {
        byprice();
    }
    else if (lastBtn === 3) {
        resetCards();
    }
}


function resetCards() {
    let cardsHTMLCart = [];
    // let sum = 0 
    for (let i = 0; i < 32; i++) {
        if (cart1[i] !== undefined) {
            cart1[i]['articul'] = i;
            cardsHTMLCart.push(`<div class="card"> <img src="${cart1[i].imgSrc}" alt="${cart1[i].title}"> <h2 style="margin: 0">${cart1[i].title}</h2> <h3>${cart1[i].price} $</h3> <div class="amount"><button class="minus" data-articul="${i}">-</button> <input class="how_much" data-articul="${i}" placeholder="${cart1[i].count}"> <button class="plus" data-articul="${i}">+</button> </div></div>`);
            // sum += (cart1[i].price * cart1[i].count);
        }
    }

    const filterInput = document.getElementById('filter-input');
    filterInput.textContent = '';
    filterInput.value = '';
    filterInput.blur();
    cardGridCart.innerHTML = cardsHTMLCart.slice(0, 32).join(' ');
    recalculate();
    lastBtn = 3;
    act_byprice = 0;
    act_filter = 0;
    current_arr = cart1;
}

function byprice() {
    console.log(cart1);

    cart2 = [];
    pricer = [];
    for (let i = 0; i < 32; i++) {
        if (current_arr[i] !== undefined) {
            pricer.push(current_arr[i].price);
            console.log(current_arr[i]);

        }
    }
    console.log(cart1);
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
    // console.log(cart2);
    if (fl === 0) {
        fl = 1;
    }
    else if (fl === 1) {
        cart2.reverse();
        fl = 0;
    }
    let filteredCardsHTML1 = cart2.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="amount"><button class="minus" data-articul="${item.articul}">-</button> <input class="how_much" data-articul="${item.articul}" placeholder="${item.count}"> <button class="plus" data-articul="${item.articul}">+</button> </div></div>`);
    console.log(filteredCardsHTML1);
    cardGridCart.innerHTML = filteredCardsHTML1.slice(0, 32).join(' ');
    lastBtn = 2;
    act_byprice = 1;
}

function filterCards() {
    const filterInput = document.getElementById('filter-input');
    const filterText = filterInput.value.toLowerCase();
    console.log(filterText);
    if (filterText !== '') {

        let cart2 = [];
        for (let i = 0; i < 32; i++) {
            if (cart1[i] !== undefined) {
                cart2.push(cart1[i]);
            }
        }
        console.log(cart2);
        let filteredCardsHTML1 = cart2.filter(item => item.title.toLowerCase().includes(filterText) || item.description.toLowerCase().includes(filterText));
        console.log(filteredCardsHTML1);
        current_arr = filteredCardsHTML1;
        filtered = filteredCardsHTML1.map(item => `<div class="card"> <img src="${item.imgSrc}" alt="${item.title}"> <h2 style="margin: 0">${item.title}</h2> <h3>${item.price} $</h3> <div class="amount"><button class="minus" data-articul="${item.articul}">-</button> <input class="how_much" data-articul="${item.articul}" placeholder="${item.count}"> <button class="plus" data-articul="${item.articul}">+</button> </div></div>`);
        cardGridCart.innerHTML = filtered.slice(0, 32).join(' ');
        lastBtn = 1;
    }
    act_filter = 1;
    if (act_byprice === 1) {
        if(fl === 1) fl = 0;
        else if(fl === 0) fl = 1;
        byprice();
    }
}
