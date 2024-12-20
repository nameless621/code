import java.util.Scanner; // 標準入力から読み込むためのクラス

// 基本的な制御構造（if, switch, for, while, do-whileなど）
// および三項演算子、論理演算子の使い方まとめ
public class ControlStructure {
  public static void main(String[] args) {
    // 【整数の入力】
    System.out.print("Number? "); // printlnではなくprintなので改行しない
    int num = new Scanner(System.in).nextInt(); // 標準入力から整数を取得

    // 【文字列の入力】
    System.out.print("Signal? ");
    String signal = new Scanner(System.in).next();
    // Javaでは文字列比較にequalsを使用（"=="は参照比較）
    if (signal.equals("red") == true) {
      System.out.println("Stop");
    }

    // 【switch文】
    // switchで文字列の値を判定する例
    switch (signal) {
      case "red":
        System.out.println("Stop");
        break;
      case "yellow":
        System.out.println("Slow down");
        break;
      case "blue":
        System.out.println("Go");
        break;
      default:
        System.out.println("Wrong signal");
        break;
    }

    // 【for文による繰り返し】
    int[] scores = { 70, -10, 90, 80 };
    // 古典的forループ
    for (int i = 0; i < scores.length; i++) {
      System.out.println(scores[i]);
    }
    // 拡張for文（C++の範囲forに類似）
    for (int score : scores) {
      // continueは次の反復へスキップ
      if (score < 0) {
        continue;
      }
      System.out.println(score);
    }

    // 【while文】
    double money = 500.0;
    while (money < 1000.0) {
      money *= 1.1;
      System.out.println(money);
    }

    // 【do-while文】
    // do-whileは条件判定が後なので、少なくとも1回は実行される
    String password;
    do {
      System.out.print("Password? ");
      password = new Scanner(System.in).next();
    } while (password.equals("d0t1nsta11") == false);
    System.out.println("Password matched");

    // 【三項演算子】
    // (条件) ? (真のときの値) : (偽のときの値)
    int x = new Scanner(System.in).nextInt();
    String result = x >= 90 ? "A!" : "B!";
    System.out.println(result);

    // 【論理演算子】
    // &&, ||, ! を用いて条件を組み合わせられる
    System.out.print("English? ");
    int english = new Scanner(System.in).nextInt();
    System.out.print("Math? ");
    int math = new Scanner(System.in).nextInt();
    if (english >= 80 && math >= 80) {
      System.out.println("A!");
    } else {
      System.out.println("B!");
    }
  }
}
