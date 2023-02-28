let a = '';
let b = '';
let sign = '';
let finish = false;
let fl = 0;
let past_key = '0';
let key = '0';

const digit = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'];

const action = ['-', '+', 'x', '/'];

const out = document.querySelector('.calc-screen p');

function clearAll() {
    a = '';
    b = '';
    sign = '';
    finish = false;
    out.textContent = 0;
};

document.querySelector('.ac').onclick = clearAll;

document.querySelector('.buttons').onclick = (event) => {
    // обробка кліку не по кнопці 
    if(!event.target.classList.contains('btn')) return;
    //обробка кліку ас
    if(event.target.classList.contains('ac')) return;
    out.textContent = '';
    past_key = key;
    key = event.target.textContent;
    // console.log(key)
    
    // обробка заміни знаку +/-
    if(key === '+/-' && a !== '' && sign === ''){
        a = "-" + a;
        console.log(a);
        out.textContent = a;
        return;
    }
    else if(key === '+/-' && a === '' && sign === ''){
        out.textContent = 0;
        return;
    }
    else if(key === '+/-' && a !== '' && sign !== '' && b === ''){
        a = a * -1;
        console.log(a);
        out.textContent = a;
        return;
    }
    else if(key === '+/-' && a !== '' && sign !== '' && b !== '' && finish === true){
        a = a * -1;
        console.log(a);
        out.textContent = a;
        b = '';
        return;
    }
    else if(key === '+/-' && a !== '' && sign !== '' && b !== '' && finish === false){
        b = "-" + b;
        console.log(b);
        out.textContent = b;
        return;
    }
    else if(key === '+/-' && a !== '' && sign !== '' && b === ''){
        out.textContent = sign;
        return;
    }
    if(key === '%' && a !== '' && sign === ''){
        a /= 100;
        console.log(a);
        out.textContent = a;
        return;
    }
    else if(key === '%' && a === '' && sign === ''){
        out.textContent = 0;
        return;
    }
    else if(key === '%' && a !== '' && sign !== '' && b === ''){
        b = (a / 100) * a;
        console.log(b);
        out.textContent = b;
        return;
    }
    else if(key === '%' && a !== '' && b !== '' && sign === '+' || sign === '-'){
        b =  (a / 100) * b;
        console.log(b);
        out.textContent = b;
        return;
    }
    
    else if(key === '%' && a !== '' && b !== '' && sign !== ''){
        b /= 100;
        console.log(b);
        out.textContent = b;
        return;
    }
    // else if(key === '%' && a !== '' && sign === '+' && b === ''){
    //     b = a / 100;
    //     console.log(b);
    //     a = a * b;
    //     b = a;
    //     out.textContent = a;
    //     return;
    // }
    // клік на 0-9 або .
    if(digit.includes(key)) {
        
        if(key === '.' && a.includes('.') && sign === '' ){
            out.textContent = a;
            return;
        }
        else if(key === '.' &&  b.includes('.')){
            out.textContent = b;
            return;
        }

        if(b === '' && sign ==='') {
            a += key;
            console.log(a, sign, b);
            out.textContent = a;
        }
        else if(a !== '' && b!== '' && finish){
            b = key;
            finish = false;
            out.textContent = b;
        }
        else {
            b += key;
            console.log(a, sign, b);
            out.textContent = b;
        }

    }

    if(action.includes(key) && sign !== '' && a !== '' && b !== '' && finish === false) {
        switch (sign) {
            case "+":
                a = (+a) +(+b);
                // b = '';
                // sign = '';
                break;
            case "-":
                a = a - b;
                break;
            case "x":
                a = a * b;
                break;
            case "/":
                if(b === '0'){
                    out.textContent = "Error";
                    a = '';
                    b = '';
                    sign = '';
                    return;
                }
                a = a / b;
                break;
            case "":
                console.log("123");
                out.textContent = 0;
                // return;
                break;

        }
        finish = true;
        out.textContent = a;
        console.log(a, sign, b);
        sign = key;
        // b = '';
        // out.textContent = 0;
        // return;
    }
    else if(action.includes(key) && a !== '') {
        sign = key;
        console.log(a, sign, b);
        out.textContent = sign;
        return;
    }
    else if(action.includes(key) && a === '') {
        out.textContent = 0;
        return;
    }

    if(key === '=') {
        if(a !== '' && sign === '' && b === '') {
            out.textContent = a;
            // fl = 1;
            return;
        }
        else if(b === '') b = a;
        switch (sign) {
            case "+":
                a = (+a) +(+b);
                // b = '';
                // sign = '';
                break;
            case "-":
                a = a - b;
                break;
            case "x":
                a = a * b;
                break;
            case "/":
                if(b === '0'){
                    out.textContent = "Error";
                    a = '';
                    b = '';
                    sign = '';
                    return;
                }
                a = a / b;
                break;
            case "":
                console.log("123");
                out.textContent = 0;
                // return;
                break;

        }
        finish = true;
        out.textContent = a;
        console.log(a, sign, b);
        // b = '';
    }
};