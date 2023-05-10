import { TOURS_API_KEY, API_KEY } from './export/ToursControll.js';

document.getElementById('tour-image').addEventListener('change', function () {
    let file = this.files[0];
    let url = URL.createObjectURL(file);

    document.querySelector('.admin-form > div img').src = url;
});

let loading = document.querySelector('.loading');

document.getElementById('add-btn').addEventListener('click', async () => {
    loading.style.display = 'block';
    let adminForm = document.querySelector('.admin-form');
    let tourData = {};

    new FormData(adminForm).forEach((value, key) => tourData[key] = value);

    tourData.imageSource = `../images/${tourData.imageSource.name}`;
    tourData.price = parseInt(tourData.price);

    tourData.tourInfo = [
        `${tourData.days} днів`,
        `${tourData.places} місць`,
        `${tourData.countries} країн`
    ];
    
    delete tourData.days;
    delete tourData.places;
    delete tourData.countries;

    tourData.country = tourData.country.split(',').map((val) => val.trim());
    tourData.quantity = 1;

    tourData.discount = (tourData.discount == 'on');

    let n = parseInt(tourData.stars);
    if (n > 5) n = 5;
    else if (n < 1) n = 1;

    tourData.stars =  '&#9733; '.repeat(n) + '&#9734; '.repeat(5 - n) + `${n}.0`;

    let response = await fetch(`https://api.jsonbin.io/v3/b/${TOURS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });

    let data = await response.json();
    let last = data.record.at(-1);

    tourData.id = last.id + 1;
    data.record.push(tourData);
    

    await fetch(`https://api.jsonbin.io/v3/b/${TOURS_API_KEY}`, {
        method: 'PUT',
        headers: {
            'Content-Type': 'application/json',
            'X-Master-Key': API_KEY
        },
        body: JSON.stringify(data.record)
    });

    localStorage.setItem('cardsObjArray', JSON.stringify(data.record));

    loading.style.display = 'none';

    // 


    console.log(tourData);

});
