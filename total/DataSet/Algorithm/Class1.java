package Tasks.total.DataSet.Algorithm;
public class Class1 {
    public static void main(String[] args) {
        Integer e = 16;
        int a = 16;
        int b = 8;
        int c = 3;
        int d = 3;
        int[] arr = { 1, 2, 3, 4, 5 };
        // 交换a,b的值，ab可以相等
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        System.out.println(a);
        System.out.println(b);
        System.out.println(e);

        fun(arr, c, d);

        for (int i : arr) {
            System.out.println(i);
        } // 数组遍历
    }

    public static void fun(int[] arr, int a, int b) {
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];
    }
}