import java.util.Scanner;

public class InputOutput {
    Scanner scan = new Scanner(System.in);
    public void read_array(int[] array, int numberOfElements) {
          for(int i = 0; i < numberOfElements; i++)
              array[i] = scan.nextInt();

    }
}
