package Tasks.total.算法与数据结构.算法;
//简单排序算法，异或运算，相同为0，不同为1
public class Class1 {
    public static void main(String[] args) {
        int a = 16;
        int b = 8;
        int c = 3;
        int d = 3;
        int [] arr = {1,2,3,4,5};
//交换a,b的值，ab可以相等
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        System.out.println(a);
        System.out.println(b);
        
        fun(arr, c, d);

        for(int i : arr){
            System.out.println(i);
        }//数组遍历
    }


    public static void fun(int [] arr,int a,int b){
        arr[a] = arr[a] ^ arr[b];
        arr[b] = arr[a] ^ arr[b];
        arr[a] = arr[a] ^ arr[b];
    }//交换数组中两个位置的值,但此时a,b不能相等,因为地址相同，异或时变成0了
        
    
}

