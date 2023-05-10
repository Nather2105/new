// const USERS_API_KEY = '645832cb8e4aa6225e9878dd';
// const API_KEY = '$2b$10$umJB4mIwAFndHNVZfAth6u8Ol8k7YDBUtLsk5Teodo3G.dj0F2hSC';



async function isAdmin(user, criteria = ['login']) {
    let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });

    let adminData = (await response.json()).record.admin[0];

    return criteria.every((crt) => user[crt] == adminData[crt]);
}

async function findUser(record, findBy = ['nickname', 'login']) {
    let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });

    let data = await response.json();
    let usersArray = data.record.users;
    usersArray.push(data.record.admin);

    let isUsersSame = (firstUser, secondUser) => {
        return findBy.every((key) => firstUser[key] == secondUser[key]);
    };

    return usersArray.some((element) => isUsersSame(element, record));
}

async function getFullInfo(initUser, criteria = ['email', 'password']) {
    let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });

    let data = await response.json();
    let usersData = data.record.users;

    usersData.push(data.record.admin);

    for (const user of usersData) {
        if (criteria.every((crt) => user[crt] == initUser[crt]))
            return user;
    }

    return null;
}

async function addNewUser(record) {
    let isRegistered = await findUser(record, ['login', 'password']);
    if (isRegistered) return;

    let response = await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}/latest`, {
        headers: { 'X-Master-Key': API_KEY }
    });
    let data = await response.json();
    data.record.users.push(record);
    console.log(data.record);
    await fetch(`https://api.jsonbin.io/v3/b/${USERS_API_KEY}`, {
        method: 'PUT',
        headers: {
            'content-type': 'application/json',
            'X-Master-Key': API_KEY
        },
        body: JSON.stringify(data.record)
    });
}


nickname_of_user = document.getElementById('nick');
email_of_user = document.getElementById('login');
password_of_user = document.getElementById('pass');
repassword = document.getElementById('conf_pass');
passwordRequirements = document.querySelector('.password-requirements');


password_of_user.addEventListener('keyup', function () {
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

function validateRegForm() {
    console.log(email_of_user.value);

    if (email_of_user.value.trim().length == 0) {
        alert('Input login line');
        return false;
    } else if (!email_of_user.value.match(/\S+@\S+\.\S+/)) {
        alert('Your email is incorrect, try again');
        return false;
    } else if (!email_of_user.value.match(/^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/)) {
        alert('Not all requirements are satisfied for a password');
        return false;
    }

    return true;
}


document.getElementById('sign-up-submit').addEventListener('click', async (event) => {
    event.preventDefault();

    if (!validateRegForm()) return;
    if (password_of_user.value != repassword.value) {
        alert('Паролі не збігаються!');
    } else {

        let jsonUserData = {
            "login": email_of_user.value,
            "nickname": nickname_of_user.value,
            "password": password_of_user.value,
            "cart": {}
        };
        console.log(jsonUserData);

        findUser(jsonUserData).then(async (answer) => {
            if (answer)
                alert('Ви вже зареєстровані!');
            else {
                await addNewUser(jsonUserData);

                let copyData = { ...jsonUserData };
                delete copyData.password;

                localStorage.setItem('currentUser', JSON.stringify(copyData));
                isAdmin(jsonUserData).then(answer => localStorage.setItem('isAdmin', answer));

                alert('Успішно зареєстровано!');
                window.location.replace('./index.html');
            }
        });
    }
});


