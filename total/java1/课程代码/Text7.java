import java.util.Scanner;

public class Text7 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        // System.out.println("请输入成绩");
        System.out.print("请输入成绩: ");
        double score = s.nextDouble();
        if (score >= 60) {
            System.out.println("成绩合格");
        } else {
            System.out.println("成绩不合格");
        }
        s.close();//不写这个会报错--s not closed.
    }
        
}
