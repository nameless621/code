'use strict';

//【classについて】
// アプリケーションに特化した独自のデータ型を作れる
// またそのデータ型に特化した独自の命令を自分で定義できる
// classで定義した独自のデータ型から作られる値を「そのclassのインスタンス」、
// そのデータ型に特化した独自の命令は「そのclassのメソッド」と呼ぶ

{
  class User {
    // コンストラクタ
    // new演算子でインスタンスが作られるときに自動的に実行される特殊なメソッド
    constructor(nameFromNew, scoreFromNew) {
      // classの定義内ではインスタンスは「this」と表現する
      this.name = nameFromNew; // インスタンスのnameプロパティを設定
      this.score = scoreFromNew; // インスタンスのscoreプロパティを設定
    }

    // メソッド
    // インスタンスのデータを操作・取得する命令を定義する
    getUserString() {
      return `${this.name} ${this.score}`; // nameとscoreを文字列として結合して返す
    }
  }

  // Userクラスのインスタンスを作成
  const user1 = new User("Taro", 70);
  const user2 = new User("Jiro", 80);

  // メソッドを呼び出してインスタンスの情報を取得
  console.log(user1.getUserString());
  console.log(user2.getUserString());
}

{
  // スコア情報に科目と判定を含めたクラスの例
  class Score {
    // 科目(subject)と点数(result)を保持するクラス
    constructor(subject, result) {
      this.subject = subject; // 科目名を保存
      this.result = result; // 点数を保存
    }

    // 点数に応じて評価を返すメソッド
    getGrade() {
      return this.result >= 80 ? 'A' : 'B'; // 三項演算子を使ってAまたはBを返す
    }

    // 点数情報をフォーマットして返すメソッド
    getScoreString() {
      // メソッド内から他のメソッドを呼び出す場合、this.を付ける必要がある
      return `${this.subject} ${this.result} ${this.getGrade()}`;
    }
  }

  // Scoreクラスを継承して数学専用のクラスを作成
  class MathScore extends Score {
    // 親クラスのコンストラクタを呼び出す
    constructor(result) {
      super('Math', result); // superで親クラスのコンストラクタを実行
    }

    // メソッドのオーバーライド
    // 親クラスと同じ名前のメソッドを上書きする
    getGrade() {
      return this.result >= 50 ? 'A' : 'B'; // 数学の判定基準は50点以上でA
    }
  }

  // 英語専用のクラス
  class EnglishScore extends Score {
    constructor(result) {
      super('English', result); // 英語科目名を親クラスに渡す
    }
  }

  // ユーザー情報を保持するクラス
  class User {
    constructor(name, score) {
      this.name = name; // ユーザー名を保存
      this.score = score; // スコアオブジェクトを保存
    }

    // ユーザー情報を文字列で返すメソッド
    getUserString() {
      // スコア情報のフォーマットはスコアクラスのメソッドに任せることで保守性を向上
      return `${this.name} ${this.score.getScoreString()}`;
    }
  }

  // MathScoreとEnglishScoreを使用してUserインスタンスを作成
  const user1 = new User('Taro', new MathScore(70));
  const user2 = new User('Jiro', new EnglishScore(80));

  // ユーザー情報を出力
  console.log(user1.getUserString());
  console.log(user2.getUserString());
}


// 【classのフィールドについて】
// フィールドは、class内で定義されるプロパティを指す。
// フィールドにはインスタンスプロパティと静的プロパティ(静的フィールド)がある。

{
  class User {
    // インスタンスごとに異なる値を持つプロパティ
    name; // ユーザー名
    score; // ユーザーのスコア

    // 静的プロパティ(静的フィールド)
    // 全てのインスタンスで共有されるプロパティ
    static count = 0; // 作成されたインスタンスの数を保持

    // コンストラクタ
    constructor(name, score) {
      this.name = name; // インスタンスの名前を設定
      this.score = score; // インスタンスのスコアを設定
      User.count++; // インスタンス生成時にカウントを増加
    }

    // インスタンスメソッド
    // 特定のインスタンスに対して呼び出す
    getUserString() {
      return `${this.name} ${this.score}`; // インスタンスの名前とスコアを文字列で返す
    }

    // 静的メソッド
    // インスタンスではなくクラス自体に紐づくメソッド
    static getUserCountString() {
      return `${User.count} instance(s) created.`; // 作成されたインスタンス数を文字列で返す
    }
  }

  // Userクラスのインスタンスを作成
  const user1 = new User('Taro', 70);
  const user2 = new User('Jiro', 80);

  // 静的メソッドを呼び出してインスタンスの数を確認
  console.log(User.getUserCountString());

  // 各インスタンスの情報を取得
  console.log(user1.getUserString());
  console.log(user2.getUserString());
}

// 【ゲッターとセッターについて】
// ゲッター(get)やセッター(set)を使うと、プロパティへのアクセスや値の変更を制御できる。
// 内部的に保持するプロパティは、一般的に「_」で始める名前をつける慣習がある。

{
  class User {
    // インスタンスプロパティ
    name; // ユーザー名
    _score; // スコア(内部的に管理)

    // コンストラクタ
    constructor(name, score) {
      this.name = name; // インスタンスの名前を設定
      this._score = score; // スコアを内部プロパティに設定
    }

    // ゲッター
    // プロパティの値を取得する際に使用
    get score() {
      return this._score; // 内部プロパティを返す
    }

    // セッター
    // プロパティの値を変更する際に使用
    set score(newValue) {
      // 値が不正な場合はエラーメッセージを表示して処理を終了
      if (newValue < 0 || newValue > 100) {
        console.log('Invalid value!');
        return;
      }
      this._score = newValue; // 値が有効な場合にのみ変更
    }
  }

  const user = new User('Taro', 70);

  // セッターを使用してスコアを設定
  user.score = 99999; // 無効な値なのでエラーメッセージが表示される
  console.log(user.score); // ゲッターを使用してスコアを取得
}

