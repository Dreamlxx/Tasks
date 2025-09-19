public class Text8 {
    public static void fun() {
        int a = 1;
        int b = 1;

        for (; a <= 9; a++) {
             for (b = 1; b <= a; b++) {
                int i = a * b;
                System.out.print(b + "*" + a + "=" + i + "\t");
            }
            System.out.println();
        }
    }//方法，对内隐藏细节，对外暴露接口。

    public static void main(String[] args) {
        fun();
    }
}