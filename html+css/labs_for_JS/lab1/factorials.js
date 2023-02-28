const input_how_much_factorial = document.querySelector('.input-how-much-factorial');
const btn_result_factorial = document.querySelector('.btn-result-factorial');
const output_factorial = document.querySelector('.output-factorials');

btn_result_factorial.addEventListener('click', function () {

    let how_factorial = input_how_much_factorial.value;
    if (how_factorial >= 0) {
        let fact = 1;
        console.log(how_factorial);
        for (let j = 1; j <= how_factorial; j++) {
            fact *= j;
        }
        output_factorial.textContent = 'factorial is ' + fact;
        
        fact = 1;
        for (j = how_factorial; j > 1; j -= 2) {
            fact *= j;
        }
        output_factorial.textContent += ' double factorial is ' + fact;
    }
    else {
        output_factorial.textContent = 'Error';
    }
});