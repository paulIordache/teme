import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Number of elements: ");
        int numberOfElements = scan.nextInt();
        int[] array = new int[numberOfElements];

        InputOutput input = new InputOutput();
        isMajority majority = new isMajority();

        System.out.println("Array elements: ");
        input.read_array(array, numberOfElements);

        System.out.println("Choose element: ");
        int x = scan.nextInt();

        if (majority.Majority(array, numberOfElements, x))
            System.out.println(x + " is the majority element");
        else
            System.out.println(x + " is not the majority element");

    }
}