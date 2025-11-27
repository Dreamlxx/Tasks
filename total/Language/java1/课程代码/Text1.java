public class Text1{
    int a=10;//声明在类内部，方法体外部叫成员变量
    static String s1 ="你好";

    public static void main(String[] args) {
        char a = 'a';
        int b=5;//声明在类内部叫局部变量
        System.out.println(b);//println这个ln是他妈换行的意思
        // System.out.println(a);//错误，静态方法中不能访问非静态的成员变量
        System.out.println(s1);//正确，静态方法中可以访问静态的成员变量
        System.out.println(a);
    }

    public void fun (){

    }
}