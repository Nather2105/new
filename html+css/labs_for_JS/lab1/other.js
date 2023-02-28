const hover = document.querySelector('.hover-logo');
// const h = document.querySelector('.hover');
const h = document.getElementById('try1');

hover.addEventListener('mouseenter', (event) =>{

    console.log('123');
    h.style.display = "flex";

})
hover.addEventListener('mouseout', (event) =>{

    console.log('321');
    h.style.display = "none";
})