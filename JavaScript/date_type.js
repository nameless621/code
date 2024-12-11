'use strict';

{
  // 【真偽値について】
  // true は「真」、false は「偽」を意味する。
  // 変数の値に応じてプログラムの処理を分岐させることができる。

  let isDevMode = true; // 開発モードの状態を保持するフラグ
  const pElement = document.querySelector('p'); // ページ内の <p> 要素を取得
  const buttonElement = document.querySelector('button'); // ページ内の <button> 要素を取得

  buttonElement.addEventListener('click', () => {
    // confirm() はユーザーに確認ダイアログを表示し、true/false を返す。
    if (!confirm("Are you sure?")) {
      return; // ユーザーがキャンセルした場合は処理を終了する
    }

    if (isDevMode) {
      // 開発モードがオンの場合の処理
      pElement.textContent = "Dev Mode is Off."; // テキストを変更
    } else {
      // 開発モードがオフの場合の処理
      pElement.textContent = "Dev Mode is On";
    }
    isDevMode = !isDevMode; // 現在の値を反転してモードを切り替える
  });
}

{
  // 【数値や真偽値だけでなく文字列でも真偽値判定できる】
  // 空文字列は「偽」として扱われ、文字列が空でなければ「真」として扱われる。

  const name = prompt('Your name?'); // ユーザーに名前を入力させる

  if (name) {
    // name が空でない場合（真と評価される）
    console.log(`Hi, ${name}`);
  } else {
    // name が空の場合（偽と評価される）
    console.log('Hi, nobody!');
  }
}

{
  // 【undefinedについて】
  // 未定義の変数や存在しない要素/プロパティにアクセスすると undefined が返される。

  let x; // 初期化されていない変数
  console.log(x); // undefined

  const scores = [70, 90, 80];
  console.log(scores[100]); // 存在しないインデックスを指定すると undefined

  const score = {math: 80, english: 90};
  console.log(score.history); // 存在しないプロパティにアクセスすると undefined

  if (score.history === undefined) {
    console.log('History score not defined!'); // undefined の場合のエラーハンドリング
  }
}

{
  // 【nullについて】
  // null は「何もない」という状態を明示的に表現するために使用する。

  const score = {
    math: 80, 
    english: 90,
    physics: null, // 物理のスコアがまだ入力されていないことを明示
  };

  if (score.physics === null) {
    console.log('Physics score is null!');
  }
}

{
  // 【typeof演算子】
  // 変数や値のデータ型を調べることができる。

  console.log(typeof 5); // number（数値型）
  console.log(typeof 'Hello'); // string（文字列型）
  console.log(typeof [5, 2]); // object（配列もオブジェクトとして扱われる）
  console.log(typeof {math: 80, english: 90}); // object（オブジェクト型）
  console.log(typeof true); // boolean（真偽値型）
  console.log(typeof undefined); // undefined（未定義型）
  console.log(typeof null); // object（歴史的な理由で null は object と表示される）
}
