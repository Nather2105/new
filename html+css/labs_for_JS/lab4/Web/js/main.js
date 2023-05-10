(function() {
    // Shopping Bag Icon
    let count = document.querySelector('.counter');
    let addedTours = JSON.parse(localStorage.getItem('addedTours'));

    let currentUser = localStorage.getItem('currentUser');
    if (currentUser == undefined) {
        currentUser = null;
        localStorage.setItem('currentUser', null);
    } else {
        currentUser = JSON.parse(currentUser)
    }

    // TODO: send this to local storage
    if (currentUser != null) {
        let openProfile = document.getElementById('open-profile');
        openProfile.href = '../pages/user-cabinet.html';
        openProfile.innerHTML = `<img class="icons big-icon profile" src="${currentUser.profileImage}">`
    }


    if (addedTours.length != 0) {
        count.style.display = 'block';
        count.textContent = addedTours.length;
    } else {
        count.style.display = 'none';
    }

    let upButton = document.querySelector('.up-btn');

    upButton.addEventListener('click', () => {
        window.scrollTo({
            top: 0,
            left: 0,
            behavior: 'smooth'
        });
    });

    function scrollHandler() {
        if (window.scrollY / document.scrollingElement.scrollHeight >= 0.5) {
            upButton.style.display = 'block';
        } else {
            upButton.style.display = 'none';
        }
    }

    window.addEventListener('scroll', scrollHandler);
}());
