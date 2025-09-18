import java.util.Scanner;

public class c01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String nom;
        System.out.print("Ingresa tu nombre: ");
        nom = sc.nextLine();
        System.out.println("Bienvenido a Java, " + nom + "!");
        sc.close();
    }
}
