public class pattern1 {
    public static void main(String arg[]){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5+1-i;j++){
                System.out.print(j);
            }System.out.print("\n");
        }
    }
}

// 12345
// 1234
// 123
// 12
// 1
