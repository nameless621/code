const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');
const startButton = document.getElementById('startBtn');
const stopButton = document.getElementById('stopBtn');
const resetButton = document.getElementById('resetBtn');
const antCountInput = document.getElementById('antCount');
const speedInput = document.getElementById('speed');

let intervalID = null;
const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];
let cellsize = 2;
let W = canvas.width / cellsize;
let H = canvas.height / cellsize;
let board = Array.from({ length: W }, () => Array(H).fill(0));
let ants = [];

function setColor() {
  let r = Math.floor(Math.random() * 255);
  let g = Math.floor(Math.random() * 255);
  let b = Math.floor(Math.random() * 255);
  return `rgb(${r},${g},${b})`;
}

function initAnts(count) {
  for(let i = 0; i < count; i++) {
    let x = Math.floor(Math.random() * W);
    let y = Math.floor(Math.random() * H);
    let d = Math.floor(Math.random() * 4);
    let c = setColor();
    
    let antObject = {
      x : x,
      y : y,
      direction: d,
      color: c,
    }

    ants.push(antObject);
  }
}

startButton.addEventListener('click', () => {
  if(intervalID !== null) return;

  const count = parseInt(antCountInput.value, 10);
  const speed = parseInt(speedInput.value, 10);
  initAnts(count);

  intervalID = setInterval(() => {
    for(let step = 0; step < speed; step++) {
      for(let i = 0; i < count; i++) {
        let currentColor = board[ants[i].x][ants[i].y];
        if(currentColor === 0) {
          ants[i].direction = (ants[i].direction + 3) % 4;
        }
        else {
          ants[i].direction = (ants[i].direction + 1) % 4;
        }
        board[ants[i].x][ants[i].y] = 1 - currentColor;
        ants[i].x = (ants[i].x + dx[ants[i].direction] + W) % W;
        ants[i].y = (ants[i].y + dy[ants[i].direction] + H) % H;
        if(board[ants[i].x][ants[i].y] === 0) {
          ctx.fillStyle = ants[i].color;
          ctx.fillRect(ants[i].x * cellsize, ants[i].y * cellsize, cellsize, cellsize);
        }
        else {
          ctx.clearRect(ants[i].x * cellsize, ants[i].y * cellsize, cellsize, cellsize)
        }
      }
    }
  }, 0);
});


stopButton.addEventListener('click', () => {
  if (intervalID !== null) {
    clearInterval(intervalID);
    intervalID = null;
  }
});


resetButton.addEventListener('click', () => {
  if(intervalID !== null) {
    clearInterval(intervalID);
    intervalID = null;
  }
  board = Array.from({ length: W }, () => Array(H).fill(0));
  ants = [];
  ctx.clearRect(0, 0, canvas.width, canvas.height);
});