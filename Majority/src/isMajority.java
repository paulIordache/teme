
public class isMajority {
    public boolean Majority(int[] array, int numberOfElements, int x) {
        int last_index;

        if (numberOfElements % 2 == 0)
            last_index = (numberOfElements / 2) + 1;
        else
            last_index = (numberOfElements / 2);

        for(int i = 0; i < last_index; i++)
            if (array[i] == x && array[i + numberOfElements / 2] == x)
                return true;

        return false;
    }
}
