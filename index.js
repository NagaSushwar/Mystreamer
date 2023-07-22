let movies =[
    {
        name: "falcon and the wiunter solider",
        des : "eefhw",
        image:"images/slider 2.png"
    },
    {
        name: "loki",
        des : "eefhw",
        image:"images/slider 1.png"
    },
    {
        name: "wanda wision",
        des : "eefhw",
        image:"images/slider 3.png"
    },
    {
        name: "raya an d teh last dragon",
        des : "eefhw",
        image:"images/slider 4.png"
    },
    {
        name: "luca",
        des : "eefhw",
        image:"images/slider 5.png"
    },
];
const carousel = document.querySelector('.carousel');
let sliders =[];
let slideIndex =0; //counter of the current slide

const createSlide = () => {
  if (slideIndex >= movies.length) {
    slideIndex = 0;
  }

  // create DOM elements
  let slide = document.createElement('div');
  let imgElement = document.createElement('img');
  let content = document.createElement('div');
  let h1 = document.createElement('h1');
  let p = document.createElement('p');

  // attach DOM elements
  h1.appendChild(document.createTextNode(movies[slideIndex].name));
  p.appendChild(document.createTextNode(movies[slideIndex].des));
  content.appendChild(h1);
  content.appendChild(p);
  slide.appendChild(imgElement);
  slide.appendChild(content);
  carousel.appendChild(slide);

  // set image and class names
  imgElement.src = movies[slideIndex].image;
  slideIndex++;
  slide.classList.add('slider');
  content.classList.add('slide-content');
  h1.classList.add('movie-title');
  p.classList.add('movie-des');

  sliders.push(slide);

  if (sliders.length) {
    sliders[0].style.marginLeft = `calc(-${100 * (sliders.length - 2)}% - ${30 * (sliders.length - 2)}px)`;
  }
};

for (let i = 0; i < 3; i++) {
  createSlide();
}

setInterval(() => {
  createSlide();
}, 3000);
//video cards
const videoCards = [...document.querySelectorAll('.video-card')];
videoCards.forEach(item =>{
    item.addEventListener('mouseover',()=>{
        let video = item.children[1];
        video.play();
    })
    item.addEventListener('mouseleave',()=>{
        let video = item.children[1];
        video.pause();
    });
});
//card sliders

let cardContainers =[...document.querySelectorAll(".card-container")];
let preBtns = [...document.querySelectorAll(".pre-btn")];
let nxtBtns = [...document.querySelectorAll(".nxt-btn")];
cardContainers.forEach((items,i)=>{
    let containerDimensions = item.getBoundingClientRect();
    let containerWidth = containerDimensions.width;

    nxtBtns[i].addEventListener('click',()=>{
       item.scrollLeft += containerWidth - 200; 
    })
    preBtns[i].addEventListener('click',()=>{
        item.scrollLeft -= containerWidth + 200; 
    });
});
