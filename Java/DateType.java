public class DateType {
  public static void main(String[] args) {
    // 【Javaにおける数値表現】
    // 整数同士の割り算は整数の商が求まる
    System.out.println(10 / 3);   // 結果: 3（小数点以下切り捨て）
    // 片方を小数にすると小数点以下まで計算される
    System.out.println(10.0 / 3); // 結果: 3.3333333...
    // 剰余（あまり）の計算
    System.out.println(10 % 3);   // 結果: 1
    // 小数の直接表記
    System.out.println(2.5);      // 結果: 2.5
    // 桁区切り（読みやすくするためのアンダースコア）
    System.out.println(1_000_000); // 結果: 1000000

    
    // 【eを使った指数表現】
    // 1.2e3は1.2 * 10^3
    System.out.println(1.2e3);    // 結果: 1200.0
    // 1.2e-3は1.2 * 10^-3
    System.out.println(1.2e-3);   // 結果: 0.0012


    // 【変数】
    // int型変数の宣言と代入
    int price = 150;
    // finalは定数を表す（C++のconstに相当）
    // 定数は大文字で書く慣習
    final double RATE = 1.1;
    // 計算結果（intとdoubleの混合計算も可）
    System.out.println(price * 120 * RATE); // price * 120 * 1.1 の計算結果を表示


    // 【文字列表現】
    System.out.println("Taro said hi.");
    // 文字列中でダブルクォートを表示するには \" を使う
    // \nは改行文字
    System.out.println("Taro said hi. \n\"Hi!\", he replied.");

    // 文字列の結合とフォーマット
    String fname = "Taro";
    String lname = "Yamada";
    System.out.println("I am Taro Yamada");
    // String.formatでフォーマット指定（%sに文字列が入る）
    System.out.println(String.format("I am %s %s.", fname, lname));


    // 【配列】
    // 配列の初期化方法1：直接要素を並べる
    int[] scores = {70, 90, 80};
    // 配列は参照型、scoresBackupはscoresと同じ配列を指す
    int[] scoresBackup = scores;
    // ここでscoresの要素を変更するとscoresBackup参照先も変わる（同じモノを指すため）
    scores[1] = 100;
    System.out.println(scores[1]);       // 結果: 100
    System.out.println(scoresBackup[1]); // 結果: 100（同じ配列参照）
    // 配列の長さは length プロパティで取得
    System.out.println(scores.length);   // 結果: 3


    // 【2次元配列】
    // 2次元配列は配列の配列
    int[][] scores2d = {
      {70, 90, 80}, // scores2d[0]
      {30, 40, 50}, // scores2d[1]
    };

    // 2次元配列へのアクセスは [行][列]
    System.out.println(scores2d[0][1]); // 結果: 90（1行目の2列目）
  }
}
