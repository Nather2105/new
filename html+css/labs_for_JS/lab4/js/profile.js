USERS_API_KEY = '645ae22c9d312622a35b1e39';
API_KEY = '$2b$10$umJB4mIwAFndHNVZfAth6u8Ol8k7YDBUtLsk5Teodo3G.dj0F2hSC';

current_user = JSON.parse(localStorage.currentUser);
passwordRequirements = document.querySelector(".password-requirements");
passwordRequirements.style.display = "none";
change_nickname_btn = document.getElementById("change_nickname_btn_for_profile");
conf_nickname_btn = document.getElementById("conf_nickname_btn_for_profile");
input_for_nickname = document.getElementById("input_for_nickname");
input_for_nickname.value = current_user.nickname;
input_for_nickname.disabled = true;
input_for_nickname.style.textAlign = "center";


email_for_profile = document.getElementById("email_for_profile");
email_for_profile.disabled = true;
email_for_profile.value = current_user.login;
email_for_profile.style.textAlign = "center";
change_pass_btn = document.getElementById("change_pass_btn_for_profile");
conf_pass_btn = document.getElementById("conf_pass_btn_for_profile");
old_pass = document.querySelector(".old_password");
new_pass = document.querySelector(".new_password");

input_old_pass = document.getElementById("old_pass");
input_new_pass = document.getElementById("new_pass");

old_pass.style.display = "none";
new_pass.style.display = "none";
conf_nickname_btn.style.display = "none";
conf_pass_btn.style.display = "none";

change_pass_btn.addEventListener('click', async (event) => {

    change_pass_btn.style.display = "none";
    old_pass.style.display = "block";
    new_pass.style.display = "block";
    passwordRequirements.style.display = "block";
    input_new_pass.addEventListener('keyup', function () {
        let child = (numberOfChild) => {
            return passwordRequirements.querySelector(`li:nth-child(${numberOfChild})`);
        };

        if (this.value.match(/[a-z]/g) && this.value.match(/[A-Z]/g)) {

            child(1).classList.add('display_none');
        }
        else {

            child(1).classList.remove('display_none');
        }

        if (this.value.match(/[0-9]/g)) {

            child(2).classList.add('display_none');
        }
        else {

            child(2).classList.remove('display_none');
        }

        if (this.value.length >= 8) {

            child(3).classList.add('display_none');
        }
        else {

            child(3).classList.remove('display_none');
        }
    });

    conf_pass_btn.style.display = "initial";
    conf_pass_btn.addEventListener('click', async (event) => {
        let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
            headers: { 'X-Master-Key': API_KEY }
        });

        let data = await response.json();
        console.log(data.record);
        data.record.users.forEach((item) => {
            if (item.nickname === current_user.nickname) {
                if (item.password === input_old_pass.value) {
                    console.log(item.password);
                    console.log(input_old_pass.value);
                    if (input_new_pass.value.length >= 8 && input_new_pass.value.match(/[0-9]/g) && input_new_pass.value.match(/[a-z]/g) && input_new_pass.value.match(/[A-Z]/g)) {
                        item.password = input_new_pass.value;
                        console.log(input_new_pass.value);
                        return;
                    }
                    else {
                        alert("not all requirements are satisfied");
                        return;
                    }
                }
            }
        });
        await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}`, {
            method: 'PUT',
            headers: {
                'content-type': 'application/json',
                'X-Master-Key': API_KEY
            },
            body: JSON.stringify(data.record)
        });
        conf_pass_btn.style.display = "none";
        change_pass_btn.style.display = "initial";
        old_pass.style.display = "none";
        new_pass.style.display = "none";
        passwordRequirements.style.display = "none";
        alert("Your password is changed");
        // window.location.replace('./index.html');

    })
})

change_nickname_btn.addEventListener('click', async (event) => {
    change_nickname_btn.style.display = "none";
    conf_nickname_btn.style.display = "initial";
    input_for_nickname.disabled = false;

})

conf_nickname_btn.addEventListener('click', change_nickname);

async function change_nickname() {
    console.log("!23");

    fl = 1;
    let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });

    let data = await response.json();
    console.log(data.record);
    data.record.users.forEach((item) => {
        if (item.nickname === input_for_nickname.value) {
            fl = 0;
            return;
        }
    });

    if (fl) {
        data.record.users.forEach((item) => {
            if (item.nickname === current_user.nickname) {
                item.nickname = input_for_nickname.value;
                index = data.record.users.indexOf(item);
                console.log(index);
                return;
            }
        });

        await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}`, {
            method: 'PUT',
            headers: {
                'content-type': 'application/json',
                'X-Master-Key': API_KEY
            },
            body: JSON.stringify(data.record)
        });
        localStorage.setItem('currentUser', JSON.stringify(data.record.users[index]));
        conf_nickname_btn.style.display = "none";
        change_nickname_btn.style.display = "initial";
        input_for_nickname.disabled = true;
        alert("your nickname is changed");
        window.location.replace('./profile.html');

    }
    else {
        conf_nickname_btn.style.display = "none";
        change_nickname_btn.style.display = "initial";
        input_for_nickname.disabled = true;
        alert("this nickname took someone else or it is already yours!")
        return 0;
    }
}

delete_acc = document.querySelector(".delete_acc");
del_acc = document.getElementById("del_acc");
delete_acc.style.display = "none";
console.log(del_acc);
delete_the_account = document.getElementById("delete_the_account");
console.log(delete_the_account);
fl = 0;
delete_the_account.addEventListener('click', async (event) => {

    if (fl === 0) {
        delete_acc.style.display = "block";
        fl = 1;
        return;
    }
    else {
        let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
            headers: { 'X-Master-Key': API_KEY }
        });

        let data = await response.json();
        console.log(data.record);
        index = -1;
        data.record.users.forEach((item) => {
            
                if (item.nickname === current_user.nickname) {
                    if (item.password === del_acc.value) {
                        index = data.record.users.indexOf(item);
                        return;
                    }
                }
        });
        data.record.users = data.record.users.filter(function(item){
            return item.password !== del_acc.value;
         });
        // console.log(delete(data.record.users[index]));
        console.log(data.record.users);
        console.log(data.record);
        // return;
        await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}`, {
            method: 'PUT',
            headers: {
                'content-type': 'application/json',
                'X-Master-Key': API_KEY
            },
            body: JSON.stringify(data.record)
        });
        localStorage.removeItem('currentUser');
        localStorage.removeItem('isAdmin');
        alert("Your account has been deleted");
        window.location.replace('./index.html');

    }
})