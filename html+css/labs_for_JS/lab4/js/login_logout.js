const USERS_API_KEY = '645ae22c9d312622a35b1e39';
const API_KEY = '$2b$10$umJB4mIwAFndHNVZfAth6u8Ol8k7YDBUtLsk5Teodo3G.dj0F2hSC';

async function isAdmin(user, criteria = ['login']) {
    let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });

    let adminData = (await response.json()).record.admin[0];

    return criteria.every((crt) => user[crt] == adminData[crt]);
}


let logined = localStorage.getItem('currentUser');
console.log(logined);
let profile_icon = document.querySelector('.profile');
let new_on_nav = document.querySelector('.new_on_nav');
let backet_icon = document.querySelector('.backet');
let signup_icon = document.querySelector('.signup');
let login_icon = document.querySelector('.login');
let logout_icon = document.querySelector('.logout');
let add_icon = document.querySelector('.add');
console.log(add_icon);
let place_for_nick = document.querySelector(".place_for_nickname");

new_on_nav.style.display = "initial";
add_icon.style.display = "none";
if(logined != null) {
    profile_icon.style.display = "initial";
    backet_icon.style.display = "initial";
    logout_icon.style.display = "initial";
   
    login_icon.style.display = "none";
    signup_icon.style.display = "none";
    inf = JSON.parse(logined);
    if(inf.nickname === undefined){
        place_for_nick.textContent = "admin's account";
        admin_btn = document.querySelector('.admin_btn');
        console.log(admin_btn);
        add_icon.style.display = "initial"; 
        profile_icon.style.display = "none";
        backet_icon.style.display = "none";
        new_on_nav.style.display = "none";
    }
    else{
        place_for_nick.textContent = inf.nickname + "'s account";
    }
}
else {
    console.log(logined);
    profile_icon.style.display = "none";
    backet_icon.style.display = "none";
    logout_icon.style.display = "none";
   
    login_icon.style.display = "initial";
    signup_icon.style.display = "initial";
    
    localStorage.removeItem('isAdmin');
    // place_for_nick.textContent = '';
}

let login_btn = document.getElementById('sub_btn_for_log');
let login_input = document.getElementById("login_for_log");
let pass_input = document.getElementById("pass_for_log");

console.log(place_for_nick);
logout_icon = document.getElementById("logout");
console.log(logout_icon);
logout_icon.addEventListener('click', event => {
    localStorage.removeItem("currentUser");
    window.location.replace('./index.html');  
})
if(login_btn !== null){

    login_btn.addEventListener('click', async (event) =>{
        current_user = 0;
        console.log("123");
        let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
            headers: { 'X-Master-Key': API_KEY }
        });
        let data = await response.json();
        if(data.record.admin[0].login === login_input.value && data.record.admin[0].password === pass_input.value){
            current_user = data.record.admin[0];
        }
        else{
            data.record.users.forEach((item) => {
                if(item.login == login_input.value && item.password == pass_input.value){
                    current_user = item;
                    return;
                }
            })
        }
        if(current_user == 0){
            alert("Incorrect data");
            return;
        }
        delete(current_user.password);
        
        localStorage.setItem('currentUser', JSON.stringify(current_user));
        
        isAdmin(current_user).then(answer => localStorage.setItem('isAdmin', answer));
        
        alert('Your are logined!');
        window.location.replace('./index.html');
        
    })
}
    
    