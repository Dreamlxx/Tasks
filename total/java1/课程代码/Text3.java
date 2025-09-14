public class Text3{

    public static void main(String[] args) {
        byte c1=17;
        //byte c2=128;//错误，超出范围
        int c3=128;
        //long c4=12312312312312312// 错误，超出范围
        long c4=12312312312312312L;//正确，后面加个L
        
        System.out.println(c1);
        System.out.println(c3);
        System.out.println(c4);
    }
}

