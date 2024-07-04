package javaProgram;

public class multiArray {
    public static void main(String[] args){
        int arr[][] = {{1,2,3},{2,4,5},{5,6,8}};
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}
