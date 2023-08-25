import java.util.Scanner;

class first{
    public static void  main(String arg[]){
        System.out.print("hello world\n");
        try (Scanner sc = new Scanner(System.in)) {
            String name=sc.nextLine();
            System.out.println(name);
        }
    }
};