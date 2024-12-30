
import java.util.Scanner;

public class calM {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter value for P: ");
        Double P = scanner.nextDouble();

        System.out.print("Enter value for V: ");
        Double V = scanner.nextDouble();

        System.out.print("Enter value for T: ");
        Double T = scanner.nextDouble();

        Double M = P * V / (0.37 * (T + 460));
        System.out.println("Value of M: " + M);

        scanner.close();
    }
}
