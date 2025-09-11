public class arrSum{
    public static int sumarArreglo(int[] arr){
        int suma = 0;
        for(int i = 0; i < arr.length; i++){
            suma += arr[i];
        }
        return suma;
    }
    
    public static void main(String[] args){
        int[] myArr = {1, 2, 3, 4, 5};
        int res = sumarArreglo(myArr);
        System.out.println("La suma es: " + res);
    }
}