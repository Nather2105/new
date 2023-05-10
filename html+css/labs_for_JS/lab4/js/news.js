

const cardGrid = document.getElementById('news');

let trying = 0;
fetch("./js/news.JSON").then(response => response.json()).then(data => {
    data.info = data.info.sort(function (a, b) {
        let dateA = moment(a.date);
        let dateB = moment(b.date);
        return dateA - dateB;
    })
    let nowdate = moment();
    let news = '';
    data.info.forEach(item => {
        if(moment(item.date).isBefore(nowdate)) {
            news += `<div class="new">
            <h2 class="title_for_new" data-articul="${data.info.indexOf(item)}">${item.title}</h2> 
            <h3 class="text_for_new"  data-articul="${data.info.indexOf(item)}">${item.text}</h3>
            <h3 class="date_for_new"  data-articul="${data.info.indexOf(item)}">${item.date}</h3>
            </div>`;
        }
    });
    cardGrid.innerHTML = news;
     
});

const changer = document.getElementById('news');

changer.addEventListener(('click'), event => {
    const text = document.querySelectorAll('.text_for_new');

    if (event.target.classList.contains('title_for_new')) {
        let articul = event.target.dataset['articul'];
        console.log(articul);
        console.log(text);
        text[articul].classList.toggle("display_block");

    }
}
);

