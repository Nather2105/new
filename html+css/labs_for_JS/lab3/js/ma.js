let itemsInCart = [];
let chart;


CanvasJS.addColorSet("whiteColorSet", [
    
    "#E5E5E5",
    "#CCCCCC",
    "#BFBFBF",
    "#A6A6A6",
    "#999999",
    "#8C8C8C",
   "#404040",
   "#363636",
   "#494949",
   "#5C5C5C",
   "#6F6F6F",
])


function renderCart(){

    let cart = document.querySelector(".cart");    
    
    let i = 0;
    let newCarts = '';

    

    while(itemsInCart.length > i){
        newCarts += `
        <div class = "cart-item" data-id = ${itemsInCart[i].id}>
            <div class = "leftSide">
                <p class = "cart-item-name">${itemsInCart[i].name}</p>
                <p class = "item-price">${itemsInCart[i].price}$</p>
            </div>

            <div class = "rightSide">
                <button class = "item-plus">+</button>
                <p class = "item-count">${itemsInCart[i].count}</p>
                <button class = "item-minus">-</button>
            </div>
            
        </div>
        `
        i++;
    }
    cart.innerHTML = newCarts;
    
    countTotal();
    
    
    
  
}



function addToCart(dataToCart) {
  
    let index = itemsInCart.findIndex(obj => obj.id === dataToCart.id);

    if (index === -1) {
      dataToCart.count = 1;
      itemsInCart.push(dataToCart)
    } else {
      itemsInCart[index].count += 1;
    }

     
  }

function clearCart(){
    itemsInCart =[];
    let cart_cont = document.querySelector(".cart-container");
    let emptyP = document.querySelector(".empty");

    cart_cont.classList.remove("show");
    emptyP.classList.add("show");
    
}

function renderGraphic(array){


    console.log(array);
    let dataSet = alasql('SELECT type as label, COUNT(*) as y FROM ? GROUP BY type', [array]);

    chart = new CanvasJS.Chart("chartContainer", {
        
        backgroundColor: "transparent",
  
        colorSet:"whiteColorSet",
        
        axisX: {
            labelFontColor: "white"
        },
        axisY: {
            labelFontColor: "white"
        },
        title:{
            text: "Items",
            fontColor:"white",
            fontFamily:"Helvetica"
        },
        toolTip:{ 
            fontColor:"Black",
            content: "{label} : {y}",
            //content: "",
            //backgroundColor: "transparent",
        
        },
        data: [{
            type: "pie",
            indexLabelFontColor: "white",
            toolTipContent:"{label}:{y}",
            indexLabel: "{label} {y}",
             
            // indexLabelLineThickness: 0,
            showInLegend: false,
            //legendText: "{label}",
            dataPoints: dataSet,
        }]
      });
    

    
    
    chart.render();

}


function addButtonsListeners(){
    
    let cart = document.querySelector(".cart");
    

    //плюс / мінус кнопки
    cart.addEventListener("click", (event)=>{
        
        
        if(event.target.classList.contains("item-plus") || event.target.classList.contains("item-minus")){

            
            let item = event.target.closest('.cart-item');

            let countP = item.querySelector('.item-count');
            let id = item.getAttribute("data-id"); // id товару

            let indexId = itemsInCart.findIndex(obj => obj.id === id); // індекс товару в масиві з індексом id

            if(event.target.classList.contains("item-plus")){
                itemsInCart[indexId].count++;                
                countP.innerHTML = itemsInCart[indexId].count;

            }

            if(event.target.classList.contains("item-minus")){

                itemsInCart[indexId].count--;
                countP.innerHTML = itemsInCart[indexId].count;

                //перевірка чи кілкість товару не 0 після зменшення кількості
                if(itemsInCart[indexId].count === 0){
                    event.target.closest(".cart-item").remove();
                    itemsInCart.splice(indexId, 1);

                } 
                //перевірка чи залишились товари в корзині
                if(itemsInCart.length === 0){
                    let cart = document.querySelector(".cart-container");
                    let emptyP = document.querySelector(".empty");
                    cart.classList.remove("show");
                    emptyP.classList.toggle("show");
                        
                }  
                
            } 
            countTotal();
        }
    })

    let column = document.querySelector(".Column");
    let pie = document.querySelector(".Pie");
    let linear = document.querySelector(".Linear");

    column.addEventListener("click", ()=>{
        chart.data[0].set("type", "column");
        chart.render();
    })
    pie.addEventListener("click", ()=>{
        chart.data[0].set("type", "pie");
        chart.render();
    })
    linear.addEventListener("click", ()=>{
        chart.data[0].set("type", "line");
        chart.render();
    })
}

function sortItems(itemsInCart){
    let NameValue = document.querySelector(".sortName").value;
    let PriceValue = document.querySelector(".sortPrice").value;
    if(NameValue === "1"){
        return itemsInCart.sort(function(a, b){
            let nameA=a.name.toLowerCase(),
             nameB=b.name.toLowerCase();
            if (nameA < nameB) return -1;
            })
    }

    
    if(PriceValue === "1"){
        return itemsInCart.sort((a, b) => a.price - b.price);
    }

    if(PriceValue === "1" && NameValue === "1"){
       return alasql(`SELECT *FROM ? ORDER BY price ASC, name ASC`, [itemsInCart]);
    }

    return itemsInCart;
}


function countTotal(){
    let totalP = document.querySelector(".totalMoney");
    let total = 0;
    itemsInCart.forEach((obj)=>{
        total += parseFloat(obj.price) * parseFloat(obj.count);
    })

    totalP.innerHTML = "Total: " + total + "$";
}
  