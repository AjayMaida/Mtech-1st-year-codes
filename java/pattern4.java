public class pattern4 {
    public static void main(String arg[]){
        for(int i=0;i<5;i++){
            for(int j=4-i;j>=1;j--){
                System.out.print(" ");
            }
            for(int j=5;j>=1;j--){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
