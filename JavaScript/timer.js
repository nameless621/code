'use strict';

//    setInterval(関数, 時間)は一定周期ごとに処理を実行する
//    setTimeout(関数, 時間)は一定時間後に一度だけ処理を実行する
//    時間はミリ秒単位で指定する（1000ms = 1秒）

// --------------------例1: setInterval()の基本的な使い方--------------------

{
  console.log(new Date()); // 現在時刻を出力

  // 1秒（1000ms）ごとに現在時刻をコンソールに表示する
  setInterval(() => {
    console.log(new Date()); // 毎秒更新される時刻を出力
  }, 1000);
}

// --------------------例2: setInterval()とclearInterval()の利用--------------------

{
  let count = 3; // カウントダウンの初期値を設定

  // setIntervalのIDを保存する
  const intervalID = setInterval(() => {
    console.log(count); // 現在のカウントを表示
    count--; // カウントを1減らす
    if (count < 0) { // カウントが0未満になったら停止
      clearInterval(intervalID); // setIntervalを停止する
    }
  }, 1000);

  console.log(`ID: ${intervalID}`); // 生成されたintervalIDを表示（デバッグ用）
}

// --------------------例3: setTimeout()の利用--------------------

{
  setTimeout(() => {
    // 指定した時間後に実行される処理
    console.log("50% OFF!"); 
    // 下記のコードを有効化すると、特定のURLにリダイレクトできる
    // window.location.href = "https://github.com/nameless621";
  }, 3000); // ページ読み込み後、3秒後にメッセージを表示

  console.log("Page loaded"); // ページが読み込まれたタイミングで表示される
}

// --------------------例4: setTimeout()をsetInterval()のように使う--------------------

{
  //    この書き方のメリット:
  //    - setInterval()では指定した時間で処理を実行するが、
  //      処理時間が長い場合、指定時間をオーバーして重複実行のリスクがある。
  //    - setTimeout()を使うことで、処理完了後に次の指定時間を待って実行できる。
  //      （時間超過によるズレを防げる）

  const pElement = document.querySelector('p'); // 時刻を表示する<p>要素を取得
  const buttonElement = document.querySelector('button'); // 停止ボタンを取得
  let timeoutID; // 現在のタイマーIDを保持する

  // 時刻を表示する関数
  function showClock() {
    timeoutID = setTimeout(() => {
      pElement.textContent = new Date(); // 現在時刻を<p>に表示
      showClock(); // 再帰的に次のタイマーを設定
    }, 1000); // 1秒ごとに再実行
  }

  // ボタンをクリックした際、タイマーを停止
  buttonElement.addEventListener('click', () => {
    clearTimeout(timeoutID); // 現在のsetTimeoutを停止する
  });

  // 初回実行
  showClock();
}
