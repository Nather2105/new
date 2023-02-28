const TYPES = [
    'bytes',
    'kilobytes',
    'megabytes',
    'gigabytes',
    'terabytes'
]
let answer;
const kef = 1024;
const input_how_much = document.querySelector('.input-how-much');
const btn_result = document.querySelector('.btn-result');
const output = document.querySelector('.output');
const type_from = document.querySelector('.type-from');
const type_to = document.querySelector('.type-to');

btn_result.addEventListener('click', function () {
    const how = input_how_much.value;
    const what = type_from.value;
    const into = type_to.value;
    const index_of_what = TYPES.indexOf(what);
    const index_of_into = TYPES.indexOf(into);
    console.log(how);
    console.log(what);
    console.log(into);

    console.log(index_of_into);
    console.log(index_of_what);
    const index_of_convert = index_of_into - index_of_what;
    console.log(index_of_convert);
    if (index_of_convert < 0) {
        answer = how;
        for (let i = 0; i < -index_of_convert; i++) {
            answer *= kef;
        }
        // answer = how * ( kef ** (index_of_convert));
    }
    else {
        answer = how;
        for (let i = 0; i < index_of_convert; i++) {
            answer /= kef;
        }
        // answer = how / ( kef ** (index_of_convert));
    }
    console.log(answer);
    if (how !== '') {
        output.innerHTML = "answer is " + answer;
    }
    else {
        output.innerHTML = '';
    }
});