(function () {
    function showAd() {
      let ad = document.createElement("div");
      ad.id = "adv";
      ad.style.position = "fixed";
      ad.style.zIndex = "3";
      ad.style.left = "0px";
      ad.style.bottom = "0px";
      ad.style.height = "50%";
      let adImg = document.createElement("img");
      adImg.src =
        "http://usfa.gov.ua:8080/frontend/web/upload/media/2018/02/01/5a72cb0a082e7-7553-1451392486-teper.jpg";
      adImg.style.width = "100%";
      adImg.style.height = "100%";
      adImg.style.borderRadius = "6px";
      ad.appendChild(adImg);
  
      let closeButton = document.createElement("button");
      closeButton.className = "adv";
      closeButton.id = "adv1";
      closeButton.innerText = "3";
      closeButton.style.position = "absolute";
      closeButton.style.right = "0px";
      closeButton.style.top = "0px";
      closeButton.style.width = "20px";
      closeButton.style.height = "20px";
      closeButton.style.borderRadius = "6px";
    //   closeButton.addEventListener("click", function () {
    //     ad.remove();
    //   });
      ad.appendChild(closeButton);
      document.body.appendChild(ad);
    }
  
    function countdown(closeButton, count) {
      if (count === 0) {
        closeButton.innerText = "x";
        ad = document.getElementById("adv");
        closeButton.addEventListener("click", function () {
            ad.remove();
          });
        return;
      }
      closeButton.innerText = count.toString();
      setTimeout(function () {
        countdown(closeButton, count - 1);
      }, 1000);
    }
  
    setTimeout(function () {
      showAd();
      let closeButton = document.getElementById("adv1");
      countdown(closeButton, 3);
    }, 1500);
  })();