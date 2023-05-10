// {
//     "imgSrc": "imgs/ragdoll.jpeg",
//     "title": "Ragdoll",
//     "price": 2500,
//     "description": "Lifespan: 12-17 years"
//   },
//   {
//     "imgSrc": "imgs/exotic-shorthair.jpeg",
//     "title": "Exotic Shorthair",
//     "price": 2200,
//     "description": "Lifespan: 12-15 years"
//   },
// two cards just for play with them

key_for_cards = "645a63919d312622a35adaa6";
security_key = "$2b$10$umJB4mIwAFndHNVZfAth6u8Ol8k7YDBUtLsk5Teodo3G.dj0F2hSC";

path = document.getElementById("path_of_new_product");
title = document.getElementById("title_of_new_product");
price = document.getElementById("price_of_new_product");
description = document.getElementById("description_of_new_product");

create_new_card_btn = document.getElementById("create_new_card");

create_new_card_btn.addEventListener('click', async event => {
    console.log(path.value);
    console.log(title.value);
    console.log(price.value);
    console.log(description.value);
    // return;
    let response = await fetch(`https://api.jsonbin.io/v3/b/${key_for_cards}/latest`, {
        headers: { 'X-Master-Key': security_key }
    });
    hash_of_new_card = {
        "imgSrc": path.value,
        "title": title.value,
        "price": Number(price.value),
        "description": description.value
    };
    let data = await response.json();
    fl = 1;
    data.record.cardsData.forEach(async item => {
        if(item.imgSrc === path.value && item.title === title.value && item.price === price.value && item.description === description.value){
            alert("This product already exist");
            fl1 = 0;
            return;
        }
    });
    if(fl){
        data.record.cardsData.push(hash_of_new_card);
        console.log(data.record.cardsData);
        await fetch(`https://api.jsonbin.io/v3/b/${key_for_cards}`, {
            method: 'PUT',
            headers: {
                'content-type': 'application/json',
                'X-Master-Key': security_key
            },
            body: JSON.stringify(data.record)
        });
        alert("Card has been added");
    }
})