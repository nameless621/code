public class method {
    // メソッド(関数)についての基本まとめ

    // メソッドは特定の処理をまとめた再利用可能なブロック
    // メソッド定義時の引数を「仮引数」、呼び出し時に渡す値を「実引数」という
    // 仮引数はそのメソッド内でのみ有効（スコープ内）となる
    
    // 【メソッドのシグネチャー】
    // メソッド名 + 引数の数 + 引数の型 + 引数の順序 の組み合わせをシグネチャーと呼ぶ
    // 同一クラス内でシグネチャーが同一のメソッドは定義できない
    
    // 【オーバーロード】
    // 引数や戻り値の型が異なるなど、シグネチャーが異なれば、同じ名前でも複数のメソッドを定義できる
    // これをオーバーロードという
    
    // intを受け取って3倍した値を返すメソッド
    private static int triple(int num) {
        return num * 3;
    }

    // doubleを受け取って3倍した値を返すメソッド（オーバーロード例）
    private static double triple(double num) {
        return num * 3;
    }

    // 引数2つを受け取って、その和を表示するメソッド
    private static void sum(int a, int b) {
        System.out.println(a + b);
    }

    // 割り算が割り切れるかを判定するメソッド
    // aがbで割り切れるならtrue、そうでないか、またはbが0ならfalseを返す
    private static boolean isDividable(int a, int b) {
        if(b != 0 && a % b == 0) return true;
        else return false;
    }

    public static void main(String[] args) {
        // 【メソッド呼び出し例】
        // triple(int num)呼び出し
        System.out.println(triple(10)); // 10を3倍→30
        // 結果にさらに *3
        System.out.println(triple(4) * 3); // 4を3倍→12、その後12*3→36
        
        // sum(int a, int b)呼び出し
        sum(10, 15); // 10+15=25を表示
        
        // isDividable(int a, int b)呼び出し
        // 10は2で割り切れるか？ (10%2==0なのでtrue)
        System.out.println(isDividable(10,2)); // true
        // 10は3で割り切れるか？ (10%3==1なのでfalse)
        System.out.println(isDividable(10,3)); // false
        // 10は0で割り切れるか？ (0で割ることは不可、false)
        System.out.println(isDividable(10,0)); // false
    }
}
