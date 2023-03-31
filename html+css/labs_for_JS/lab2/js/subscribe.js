const isSubscribed = localStorage.getItem('isSubscribed');

if (!isSubscribed) {
    setTimeout(() => {
        const overlay = document.createElement('div');
        overlay.style.cssText = 'position: fixed; bottom: 0; left: 0; width: 100%; display: flex; flex-direction: column; z-index: 100; background: orange;';

        const modal = document.createElement('div');
        modal.style.cssText = 'padding: 20px; text-align: center;';

        const message = document.createElement('p');
        message.innerText = 'Input email to subscribe on our news:';
        message.style.margin = '0 0 10px';

        const alert_message = document.createElement('p');
        alert_message.innerText = 'Incorrect email';
        alert_message.style.display = 'none';
        alert_message.style.margin = '0';

        const input_line = document.createElement('input');
        input_line.type = 'email';
        input_line.placeholder = 'email';




        const validateEmail = (email) => {
            return email.match(
                /^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/
            );
        };


        const acceptButton = document.createElement('button');
        acceptButton.innerText = 'Підписатися';
        acceptButton.style.margin = "10px";
        acceptButton.style.borderRadius = "6px";
        acceptButton.addEventListener('click', () => {

            if (validateEmail(input_line.value)) {
                localStorage.setItem('isSubscribed', true);
                overlay.style.display = 'none';
                // var f = "email.txt";

                // function writeTextFile(afilename, output) {
                //     var txtFile = new File(afilename);
                //     txtFile.writeln(output);
                //     txtFile.close();
                // };
                // writeTextFile(f, "Spoon");
                // writeTextFile(f, "Cheese monkey");
                // writeTextFile(f, "Onion");


            } else {
                alert_message.style.display = 'block';
            };
        });

        const cancelButton = document.createElement('button');
        cancelButton.innerText = 'Не зараз';
        cancelButton.style.margin = "10px";
        cancelButton.style.borderRadius = "6px";
        cancelButton.addEventListener('click', () => {
            overlay.style.display = 'none';
        });


        modal.appendChild(message);
        modal.appendChild(alert_message);
        modal.appendChild(input_line);
        modal.appendChild(acceptButton);
        modal.appendChild(cancelButton);
        overlay.appendChild(modal);
        document.body.appendChild(overlay);
    }, 1000);
}
