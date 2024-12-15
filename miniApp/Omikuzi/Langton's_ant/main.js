
const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');
ctx.fillStyle = 'White';

const startButton = document.getElementById('startBtn');
const stopButton = document.getElementById('stopBtn');

const dx = [0, 1, 0, -1];
const dy = [-1, 0, 1, 0];

let cellsize = 2;
let W = canvas.width / cellsize;
let H = canvas.height / cellsize;
let posX = W / 2;
let posY = H / 2;
let antDirection = 0;
let intervalID = null;

let board = Array.from({ length: W }, () => Array(H).fill(0));


startButton.addEventListener('click', () => {
  if(intervalID !== null) return;

  intervalID = setInterval(() => {
    let currentColor = board[posX][posY];
    if(currentColor === 0) {
      antDirection = (antDirection + 3) % 4;
    }
    else {
      antDirection = (antDirection + 1) % 4;
    }

    board[posX][posY] = 1 - currentColor;
    posX += dx[antDirection];
    posY += dy[antDirection];
    posX = (posX + W) % W;
    posY = (posY + H) % H;

    if(board[posX][posY] === 0) ctx.fillRect(posX * cellsize, posY * cellsize, cellsize, cellsize);
    else ctx.clearRect(posX * cellsize, posY * cellsize, cellsize, cellsize);
  }, 0);
});

stopButton.addEventListener('click', () => {
  if(intervalID !== null) {
    clearInterval(intervalID);
    intervalID = null;
  }
});

