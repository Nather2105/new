import { TOURS_API_KEY, API_KEY } from './export/ToursControll.js'

let cardsContainer = document.querySelector(".cards");
let moreCardsBtn = document.getElementById('get-more-cards');
let recentlyViewedContainer = document.getElementById('recently-viewed');
let pagination = document.querySelector('.pagination');
let paginationNumbers = document.querySelectorAll('.pagination > input');


// Get a string of 5 stars: n full stars and (5 - n) empty stars
function getStars(n) {
	n = (n > 5 ? 5 : Math.round(n));
	return '&#9733; '.repeat(n) + '&#9734; '.repeat(5 - n) + `${n}.0`;
}


// Get n random elements from array
function randomChoice(array, n) {
	let copy = [...array];
	let shuffled = copy.sort(() => 0.5 - Math.random());
	return shuffled.slice(0, n);
}


// Get an array of strings that represent cards in HTML markup
function getCardsArray(cardObjects) {
	let cards = []

	for (let element of cardObjects) {
		let isChecked;

		try {
			isChecked = JSON.parse(localStorage.getItem('addedTours')).includes(element.id.toString());
		} catch {
			isChecked = null;
		}

		cards.push(
			`<div class="card" data-discount="${element.discount}">
                <figure>
                    <img src=${element.imageSource}>
                    <figcaption>Від ${element.price.toLocaleString()}₴</figcaption>
                </figure>

                <div class="description">
                    <h3>${element.title}</h3>
                    <p class="stars">${element.stars}</p>
                    <div class="tour-info">
                        <img class="icons" src="../images/calendar-alt.svg" alt="Календар">
                        <a>${element.tourInfo[0]}</a>
                        <img class="icons" src="../images/map-pin.svg" alt="Карта">
                        <a>${element.tourInfo[1]}</a>
                        <img class="icons" src="../images/globe.svg" alt="Глобус">
                        <a>${element.tourInfo[2]}</a>
                    </div>
                    <p>${element.description}</p>

                    <details>
                        <summary>Детальніше</summary>
                        ${element.details}
                    </details>
                    <input type="checkbox" class="add-to-shopping" value="${element.id}" onclick="checkboxClickHandler(this)" ${isChecked ? 'checked' : ''}></input>
                </div>

                ${element.discount ? '<img class="discount" src="../images/discount.png"></img>' : ''}
            </div>`
		);
	}

	return cards;
}

// TODO: add countries and region
// let cardObjects = [
// 	{
// 		id: 1,
// 		title: "Скандинавія",
// 		imageSource: "../images/scandinavia.jpg",
// 		price: 19_000,
// 		tourInfo: ["12 днів", "9 місць", "4 країни"],
// 		stars: getStars(5),
// 		description: "Від розкішного Копенгагена до витонченого Стокгольма! Ми даруємо вам 12 днів чистої скандинавської магії",
// 		details: "Велична північна природа, тревел, звивисті фіорди, середньовічні міста і замки - ось що Ви побачите, подорожуючи по Скандинавії, батьківщині вікінгів. Тури по Норвегії, Фінляндії, Данії, Швеції принесуть Вам масу приємних сюрпризів і не залишать байдужим.",
// 		discount: true,
// 		region: 'Європа',
// 		country: ['Норвегія', 'Фінляндія', 'Данія', 'Швеція'],
// 		date: new Date(2023, 4, 7),
// 	},

// 	{
// 		id: 2,
// 		title: "Барселона",
// 		imageSource: "../images/barselona.jpg",
// 		price: 22_560,
// 		tourInfo: ["11 днів", "9 місць", "1 країна"],
// 		stars: getStars(4),
// 		description: "Той тур, який дарує вам найкраще з іспанської культури, від пляжів до палаців і місцевої кухні",
// 		details: "Барселону часто називають містом-музеєм Середземномор'я. Тут фантастичним чином поєднались спокійна та розмірена атмосфера з живим та бурхливим ритмом життя.В цьому казковому місті знайшли своє натхнення легендарний Пікассо та Жуан Міро. Барселона — це активний ритм життя, шумні вечірки, безкінечна сангрія, казкові пам’ятки в кожному закутку міста, вуличні музиканти та затишні кав’ярні.",
// 		discount: true,
// 		region: 'Європа',
// 		country: ['Іспанія'],
// 		date: new Date(2023, 6, 22),
// 	},

// 	{
// 		id: 3,
// 		title: "Єллоустоун і Ґранд-Тітонс",
// 		imageSource: "../images/yellowstone.jpg",
// 		price: 9_950,
// 		tourInfo: ["11 днів", "9 місць", "1 країна"],
// 		stars: getStars(5),
// 		description: "Від вершин Ґранд-Тітонс до Єллоустоуну, на 2 дні пригод у найстарішому національному парку світу",
// 		details: "Єллоустоун це неймовірно красивий американський національний парк, розташований значною мірою у штаті Вайомінг та простягається у Монтану та Айдахо. Парк розташований на вершині вулканічної гарячої точки.Національний парк є ідеальним місцем для вас, якщо ви любитель природи.",
// 		discount: false,
// 		region: 'Північна Америка',
// 		country: ['США'],
// 		date: new Date(2023, 5, 14),
// 	},

// 	{
// 		id: 4,
// 		title: "Іспанія та Португалія",
// 		imageSource: "../images/spain.jpg",
// 		price: 15_900,
// 		tourInfo: ["22 дні", "21 місце", "2 країни"],
// 		stars: getStars(4),
// 		description: "Хочете по-справжньому пізнати Іспанію та Португалію? У цій 22-денній подорожі ми зануримося у все іспанське та португальське",
// 		details: "Про Іспанію розповідають як про країну яскравого літнього сонця, неординарної культури, запальної музики та оригінальної вишуканої кухні.Кожен, хто хоча б раз побував тут, прагне повернутися, щоб знову зануритися в неповторну місцеву атмосферу, де хочеться насолоджуватися буквально кожною хвилиною життя.",
// 		discount: false,
// 		region: 'Європа',
// 		country: ['Іспанія', 'Португалія'],
// 		date: new Date(2023, 10, 2),
// 	},

// 	{
// 		id: 5,
// 		title: "Рим - Барселона поїздом",
// 		imageSource: "../images/rome.jpg",
// 		price: 7_600,
// 		tourInfo: ["9 днів", "6 місць", "4 країни"],
// 		stars: getStars(5),
// 		description: "Той, який дарує вам найкраще з італійської культури, від пляжів до палаців до пам'яток Стародавнього Риму",
// 		details: "Рим - перша любов людства і перша наддержав планети. Рим - єдине місто з тисяч існуючих отримав назву «Вічного»! Його наслідували, його боялися, їм захоплювалися! І почнемо з огляду пам'яток античного Риму, відчутно велич Римської імперії, прогуляємося по мощення вулички, по яких ступала сам Юлій Цезар, почуємо древні легенди про великих імператора.",
// 		discount: true,
// 		region: 'Європа',
// 		country: ['Італія', 'Іспанія', 'Португалія', 'Греція'],
// 		date: new Date(2023, 9, 10),
// 	},

// 	{
// 		id: 6,
// 		title: "Найкраще з Іспанії",
// 		imageSource: "../images/spain-castle.jpg",
// 		price: 12_000,
// 		tourInfo: ["12 днів", "11 місць", "1 країна"],
// 		stars: getStars(5),
// 		description: "Немає кращого шансу прожити найкраще іспанське життя, ніж 12 днів дрейфувати Іспанією",
// 		details: "Відвідати Іспанію варто не лише заради того, щоб побачити всесвітньо відомі історичні та культурні пам’ятки та острови, що зачаровують своєю красою.Кожен регіон цієї країни унікальний і має свої індивідуальні риси та властиву лише йому атмосферу, що буквально відчувається в повітрі.",
// 		discount: false,
// 		region: 'Європа',
// 		country: ['Іспанія'],
// 		date: new Date(2023, 8, 11),
// 	},

// 	{
// 		id: 7,
// 		title: "Європейський дослідник",
// 		imageSource: "../images/europe2.jpg",
// 		price: 57_000,
// 		tourInfo: ["29 днів", "44 місця", "18 країн"],
// 		stars: getStars(3),
// 		description: "Той, який відкриває 18 країн за 35 неймовірних днів, а завершується круїзом по грецькому острову",
// 		details: "Бажаєте залишитися наодинці з містом, побачити його без штучного лиску і мішури, перейнятися до глибини душі Монмартром, собором святого Сімейства або собором святого Віта? Тоді тур \"Європейський дослідник\" саме для вас!",
// 		discount: false,
// 		region: 'Європа',
// 		country: ['Норвегія', 'Фінляндія', 'Данія', 'Швеція', 'Франція', 'Іспанія',
// 			'Італія', 'Австрія', 'Німеччина', 'Швейцарія', 'Нідерланди', 'Хорватія',
// 			'Литва', 'Латвія', 'Естонія', 'Польща', 'Словаччина', 'Чехія'],
// 		date: new Date(2023, 3, 5),
// 	},

// 	{
// 		id: 8,
// 		title: "Європейський квест",
// 		imageSource: "../images/europe3.jpg",
// 		price: 31_000,
// 		tourInfo: ["25 днів", "30 місць", "12 країн"],
// 		stars: getStars(5),
// 		description: "Від узбережжя до узбережжя, від міста до міста, Європейський квест – це ідеальний! Збалансування всього, що нам подобається в Європі",
// 		details: "Європейці вміють жити спокійно, але водночас і цікаво. Вони відпустили літні натовпи туристів і, втомившись від метушні, ведуть розмірене життя, балуючи час від часу себе і нечисленних, але найдорожчих гостей концертами джазової та класичної музики, виставками сучасного мистецтва або колоритними місцевими святами вина і врожаю.",
// 		discount: false,
// 		region: 'Європа',
// 		country: ['Норвегія', 'Фінляндія', 'Данія', 'Швеція', 'Франція', 'Іспанія',
// 			'Італія', 'Австрія', 'Німеччина', 'Швейцарія', 'Нідерланди', 'Хорватія'],
// 		date: new Date(2023, 6, 29),
// 	},

// 	{
// 		id: 9,
// 		title: "Найкраще з Франції",
// 		imageSource: "../images/france.jpg",
// 		price: 31_000,
// 		tourInfo: ["12 днів", "11 місць", "1 країна"],
// 		stars: getStars(5),
// 		description: "Що може бути краще двотижневого відпочинку у Франції? Загадкові вулички Парижа і мальовничі поля Провансу чекають на вас!",
// 		details: "Франція - країна кави та круасанів, Ейфелевої вежі і Лувру, законодавиця моди і мистецтва... Франція - це вишукана французька кухня, тонкі вина, звабливі аромати духів і неповторний шарм, притаманний всьому французькому: француженкам і Парижу, і кухні, і мові, маленьким кафе, готелям і атмосфері французьких Альп!",
// 		discount: true,
// 		region: 'Європа',
// 		country: ['Франція'],
// 		date: new Date(2023, 10, 19),
// 	},

// 	{
// 		id: 10,
// 		title: "Весна біля Червоного моря",
// 		imageSource: "../images/red-sea.jpg",
// 		price: 8_000,
// 		tourInfo: ["7 днів", "4 місця", "1 країна"],
// 		stars: getStars(3),
// 		description: "Єгипет - однин із найпопулярніших напрямків відпочинку для українських туристів",
// 		details: "Цю країну дуже легко полюбити: вона приваблює чарівним підводним світом Червоного моря, унікальними древніми артефактами і чудесами, арабською гостинністю. Інші очевидні плюси країни: багата готельна база, помірні ціни на тури, недовгий переліт, відсутність візових формальностей.",
// 		discount: false,
// 		region: 'Африка',
// 		country: ['Єгипет'],
// 		date: new Date(2023, 3, 12),
// 	},

// 	{
// 		id: 11,
// 		title: "До Індії на аюверду",
// 		imageSource: "../images/india.jpg",
// 		price: 15_300,
// 		tourInfo: ["14 днів", "7 місць", "2 країни"],
// 		stars: getStars(2),
// 		description: "Аювердичні готелі в Індії та Китаї - це чудовий варіант відпочинку, який гарантує не тільки відновлення сил і чудові враження, а й комплексне оздоровлення організму.",
// 		details: "Час підтримати здоров'я, відновитися та збалансувати своє життя. \
//         Рекомендуємо для цього обрати Кералу - затишний і чистий південний штат Індії, всесвітньо відомий аюрведичним лікуванням. \
//         Якому б готелю Ви не віддали перевагу - це буде ідеальним варіантом для лікувально - оздоровчого відпочинку в будь - яку пору року. \
//         Після цього відвідайте Санью - чудовий пляжний курорт, «перлину Азії». Чудові готелі, прекрасна природа \
//         (згаслі вулкани, ліси, білосніжні пляжі, пишні сади), високий рівень сервісу – все що потрібно для чарівного відпочину.",
// 		discount: false,
// 		region: 'Азія',
// 		country: ['Індія', 'Китай'],
// 		date: new Date(2023, 5, 28),
// 	},

// 	{
// 		id: 12,
// 		title: "Багамські острови",
// 		imageSource: "../images/bahamas.jpg",
// 		price: 24_000,
// 		tourInfo: ["21 день", "10 місць", "1 країна"],
// 		stars: getStars(3),
// 		description: "Їх називають американською версією раю. Будь який місцевий житель скаже вам, що немає кращого місця на Землі, аніж Багамські острови - країна червоних пляжів та солоних морів",
// 		details: "Всього за рік на острови приїжджають до п’яти мільйонів туристів, більшість яких – \
//         дуже багаті люди з США і Великобританії. Одних притягують розкішні клуби і бари, інших – можливість \
//         зняти цілий пляж або зробити ставку в казино з видом на океан. І абсолютно всіх підкорюють пустельні \
//         пляжі з біло-рожевим піском, смачна острівна кухня, можливість вдосталь попірнати з аквалангом і зловити найбільшу в своєму житті рибу.",
// 		discount: true,
// 		region: 'Північна Америка',
// 		country: ['Багамські острови'],
// 		date: new Date(2023, 5, 28),
// 	}
// ];

let cardObjects;

let loaded = sessionStorage.getItem('loaded');
let loading = document.querySelector('.opaque-loading');

if (loaded == undefined || !JSON.parse(loaded)) {

	loading.style.display = 'block';

	await fetch(`https://api.jsonbin.io/v3/b/${TOURS_API_KEY}/latest`, {
		headers: { 'X-Master-Key': API_KEY }
	}).then((response) => response.json())
	  .then((data) => cardObjects = data.record);

	sessionStorage.setItem('loaded', true);

	loading.style.display = 'none';
} else {
	cardObjects = JSON.parse(localStorage.getItem('cardsObjArray'));
}
// console.log(cardObjects);

// let data = await response.json();
// data.record.users.push(record);

// cardObjects.forEach(card => card.quantity = 1)
localStorage.setItem('cardsObjArray', JSON.stringify(cardObjects));


// Show more cards
let cards = getCardsArray(cardObjects);
let numberOfCards = 3;
let idx = 0;

// Random cards in 'Recently viewed'
let chosen = randomChoice(cards, cards.length - 3);

recentlyViewedContainer.innerHTML += chosen.slice(idx, idx + numberOfCards).join(' ');
idx += numberOfCards;

moreCardsBtn.addEventListener('click', () => {
	recentlyViewedContainer.innerHTML += chosen.slice(idx, idx + numberOfCards).join(' ');

	if (idx + numberOfCards >= chosen.length) {
		moreCardsBtn.style.display = 'none';
		return;
	}

	idx += numberOfCards;
});


// ! Pagination ----------------------------------------------------------------

let numberOfPages = Math.ceil(cards.length / numberOfCards);

function showPagination(numberOfPages) {
	let paginationStr = '<button id="backward"></button>';

	for (let i = 1; i <= numberOfPages; i++) {
		paginationStr += `<input type="radio" name="pages" id="page${i}" value="${i}" ${i == 1 ? 'checked' : ''}>`;
	}

	paginationStr += '<button id="forward"></button>';

	pagination.style.display = 'flex';
	pagination.innerHTML = paginationStr;
}

showPagination(numberOfPages);

let currentPage = 0;

function setCurrentPage(cards) {
	cardsContainer.innerHTML = cards.slice(currentPage * numberOfCards, (currentPage + 1) * numberOfCards).join(' ');
	document.getElementById(`page${currentPage + 1}`).checked = true;
}

setCurrentPage(cards)

pagination.addEventListener('click', (event) => {
	if (event.target.id == 'backward') {
		currentPage--;
		if (currentPage <= 0) currentPage = 0;
	}
	else if (event.target.id == 'forward') {
		currentPage++;
		if (currentPage > numberOfPages - 1) currentPage = numberOfPages - 1;
	}
	else {
		let page = event.target.value - 1;
		if (!isNaN(page)) currentPage = page;
	}

	setCurrentPage(cards);
	cardsContainer.scrollIntoView({ behavior: 'smooth' });
});


// ! Create an AD banner

const bannerObj = {
	text: 'Унікальна пропозиція, знижка 30% на найпопулярніші тури!',
	startDate: new Date(),
	duration: 7
};

let adBanner = document.createElement('section');
adBanner.classList.add('ad-banner');

let endDate = new Date(bannerObj.startDate);
endDate.setDate(endDate.getDate() + bannerObj.duration);

adBanner.innerHTML = `<div>
                         <h2>${bannerObj.text}</h2>
                         <p id="small-text">Пропозиція діє з ${bannerObj.startDate.toLocaleDateString()} по ${endDate.toLocaleDateString()} включно</p>
                      </div>
                      <img src="../images/tourists.png">`

document.querySelector('.search-result').after(adBanner);


// Added tours
let addedToursId = (localStorage.getItem('addedTours') == null) ? [] : JSON.parse(localStorage.getItem('addedTours'));
let counter = document.querySelector('.counter');

function checkboxClickHandler(checkbox) {
	if (checkbox.checked) {
		addedToursId.push(checkbox.value);
	} else {
		addedToursId = addedToursId.filter((e) => e != checkbox.value);
	}

	localStorage.setItem('addedTours', JSON.stringify(addedToursId));

	if (addedToursId.length != 0) {
		counter.style.display = 'block';
		counter.textContent = addedToursId.length;
	} else {
		counter.style.display = 'none';
	}
}


// Country options
function setCountriesByRegion(region = 'Усі') {
	let options = '<option value="Усі">Усі</option>';
	let countriesSet = new Set();

	for (const card of cardObjects) {
		if (card.region != region && region != 'Усі') continue;

		for (const countryName of card.country) {
			countriesSet.add(countryName);
		}
	}

	for (const countryName of countriesSet) {
		options += `<option value="${countryName}">${countryName}</option>`;
	}

	document.getElementById('country').innerHTML = options;
}

setCountriesByRegion('Усі');


document.getElementById('region').addEventListener('change', function () {
	setCountriesByRegion(this.value);
});


// ----------------------------------------------------------------------------

// ! Searching
let selectedCards = [...cardObjects];

document.querySelector('.search-result').addEventListener('click', (event) => {
	let el = event.target;
	if (!el.hasAttribute('id')) return;
	let searchingOptions = [];

	for (let option of document.querySelectorAll('.result-item > input, .result-item > select')) {
		if (option.value == 'Усі') continue;

		switch (option.id) {
			case 'date':
				if (option.value != '') searchingOptions.push(`MONTH(date) = ${new Date(option.value).getMonth() + 1}`);
				break;
			case 'country':
				searchingOptions.push(`"${option.value}" IN country`);
				break;
			case 'region':
				searchingOptions.push(`region = "${option.value}"`);
				break;
		}
	}

	currentPage = 0;

	selectedCards = alasql('SELECT * FROM ? ' + (searchingOptions.length != 0 ? 'WHERE ' + searchingOptions.join(' AND ') : ''), [cardObjects])

	if (selectedCards.length == 0) {
		cardsContainer.innerHTML = '<h3 style="font-style: italic;">Вибачте, тури не було знайдено...</h3>';
		cardsContainer.style.textAlign = 'center';
		pagination.style.display = 'none';
	} else {
		cards = getCardsArray(selectedCards);

		numberOfPages = Math.ceil(cards.length / numberOfCards);
		showPagination(numberOfPages);
		setCurrentPage(cards);

		cardsContainer.style.textAlign = 'left';
		pagination.style.display = 'flex';
	}

	updateChartsData();
});

// ! Sorting
let sortingOptions = [];

const priceFrom = document.getElementById('price-from');
const priceTo = document.getElementById('price-to');

let sortByPrice = false;
let sortUpDown = document.getElementById('sort-up-down');


document.getElementById('sorting').addEventListener('click', (event) => {
	let el = event.target;

	if (el.tagName.toLowerCase() != 'button') return;

	if (el.id.startsWith('sort'))
		el.classList.toggle('is-checked');

	let toggleElement = (value) => {
		if (el.matches('.is-checked')) {
			sortingOptions.push(value);
		} else {
			var index = sortingOptions.indexOf(value);
			if (index > -1) sortingOptions.splice(index, 1);
		}
	};

	let order = (sortUpDown.checked) ? 'DESC' : 'ASC';

	switch (el.id) {
		case 'sort-name':
			toggleElement('LOWER(title)');
			break;

		case 'sort-price':
			sortByPrice = !sortByPrice;
			let priceRange = document.querySelector('.price-range');
			priceRange.style.display = el.matches('.is-checked') ? 'flex' : 'none';
			break;

		case 'sort-rating':
			toggleElement('stars');
			break;

		default:
			sortingOptions = [];
	};

	if (el.matches('.price-range > button') || sortByPrice)
		selectedCards = alasql(`SELECT * FROM ? WHERE price BETWEEN ${priceFrom.value} AND ${priceTo.value}` + (sortingOptions.length != 0 ? ` ORDER BY ${sortingOptions.join(', ')}` + order : ''), [cardObjects]);
	else if (sortingOptions.length == 0)
		selectedCards = [...cardObjects];
	else
		selectedCards = alasql(`SELECT * FROM ? ORDER BY ${sortingOptions.join(', ')} ` + order, [cardObjects]);


	if (selectedCards.length == 0) {
		cardsContainer.innerHTML = '<h3 style="font-style: italic;">Вибачте, тури не було знайдено...</h3>';
		cardsContainer.style.textAlign = 'center';
		pagination.style.display = 'none';
	} else {
		numberOfPages = Math.ceil(selectedCards.length / numberOfCards);
		cards = getCardsArray(selectedCards);

		showPagination(numberOfPages);
		setCurrentPage(cards);

		cardsContainer.style.textAlign = 'left';
		pagination.style.display = 'flex';
	}

	updateChartsData();
});


// TODO: Refactoring
sortUpDown.addEventListener('click', function () {
	let order = (sortUpDown.checked) ? 'DESC' : 'ASC';

	if (sortByPrice)
		selectedCards = alasql(`SELECT * FROM ? WHERE price BETWEEN ${priceFrom.value} AND ${priceTo.value}` + (sortingOptions.length != 0 ? ` ORDER BY ${sortingOptions.join(', ')} ` + order : ''), [cardObjects]);
	else if (sortingOptions.length == 0)
		selectedCards = [...cardObjects];
	else
		selectedCards = alasql(`SELECT * FROM ? ORDER BY ${sortingOptions.join(', ')} ` + order, [cardObjects]);

	numberOfPages = Math.ceil(selectedCards.length / numberOfCards);
	cards = getCardsArray(selectedCards);

	showPagination(numberOfPages);
	setCurrentPage(cards);

	updateChartsData();
});


let maxPrice = alasql('VALUE OF SELECT MAX(price) FROM ?', [cardObjects]);
priceFrom.max = priceTo.max = priceTo.value = maxPrice;


// ! Count functions

function countPrices() {
	const prices = [0, 10_000, 25_000, 50_000, 75_000];

	let res = [];
	for (let i = 0; i < prices.length - 1; i++) {
		let count = alasql(`VALUE OF SELECT COUNT(*) FROM ? WHERE price BETWEEN ${prices[i]} AND ${prices[i + 1]}`, [selectedCards]);
		res.push(count);
	}

	return res;
}

function countRegions() {
	let res = [];
	for (let reg of regions) {
		let count = alasql(`VALUE OF SELECT COUNT(*) FROM ? WHERE region = "${reg}"`, [selectedCards]);
		res.push(count);
	}

	return res;
}

alasql.fn.getRating = function (rateString) {
	return rateString.split(' ').at(-1);
}

function countStars() {
	let res = [];
	for (let s = 1; s <= 5; s++) {
		let count = alasql(`VALUE OF SELECT COUNT(*) FROM ? WHERE getRating(stars) = "${s}.0"`, [selectedCards]);
		res.push(count);
	}

	return res;
}

// ! Charts
const canvas = document.getElementById('charts');
const ctx = canvas.getContext('2d');

function updateChartsData() {
	pricesChartData.data.datasets[0].data = countPrices();
	regionsChartData.data.datasets[0].data = countRegions();
	ratingChartData.data.datasets[0].data = countStars();

	currentChart.update();
}

let pricesChartData = {
	type: 'bar',
	data: {
		labels: ['0-10 000₴', '10 000₴-25 000₴', '25 000₴-50 000₴', '50 000₴-75 000₴'],
		datasets: [{
			label: 'Кількість турів по цінових діапазонах',
			data: countPrices(),
			backgroundColor: [
				'rgba(54, 162, 235, 0.5)',
				'rgba(153, 102, 255, 0.5)',
				'rgba(69, 255, 87, 0.5)',
				'rgba(255, 128, 128, 0.5)'
			],
			borderRadius: 10,
		}]
	},
	options: {
		responsive: true,
		scales: {
			y: {
				beginAtZero: true,
				max: Math.max(...countPrices()) + 2,
			}
		}
	}
};

const regions = [
	'Європа',
	'Азія',
	'Африка',
	'Північна Америка',
	'Південна Америка',
	'Австралія'
];

let regionsChartData = {
	type: 'pie',
	data: {
		labels: regions,
		datasets: [{
			label: 'Кількість турів по регіону',
			data: countRegions(),
		}]
	},
	options: {
		responsive: true,
		plugins: {
			legend: {
				position: 'bottom',
			}
		}
	}
};

let ratingChartData = {
	type: 'line',
	data: {
		labels: ['1 зірка', '2 зірки', '3 зірки', '4 зірки', '5 зірок'],
		datasets: [{
			label: 'Кількість турів по рейтингах',
			data: countStars(),
			backgroundColor: 'rgba(255, 18, 121, 0.5)',
			cubicInterpolationMode: 'monotone',
			pointStyle: 'circle',
			pointRadius: 5,
			pointHoverRadius: 7,
			borderColor: 'rgb(255, 82, 79)'
		}]
	},
	options: {
		responsive: true,
	}
};

let currentData = Object.assign({}, pricesChartData);
let currentChart = new Chart(ctx, currentData);

document.querySelector('#statistic > div').addEventListener('click', (event) => {
	if (event.target.id == 'chart1') {
		currentChart.destroy();
		currentData = Object.assign({}, pricesChartData);
	} else if (event.target.id == 'chart2') {
		currentChart.destroy();
		currentData = Object.assign({}, regionsChartData);
	} else if (event.target.id == 'chart3') {
		currentChart.destroy();
		currentData = Object.assign({}, ratingChartData);
	} else {
		return;
	}

	currentChart = new Chart(ctx, currentData);
})
