
import java.util.Arrays;

public class Solution {

    static final int MAX_INPUT_VALUE = (int) Math.pow(10, 4);

    public int[] sortByBits(int[] input) {
        final int size = input.length;
        for (int i = 0; i < size; i++) {
            input[i] = input[i] + (MAX_INPUT_VALUE + 1) * countBitsOfOne(input[i]);
        }
        Arrays.sort(input);

        for (int i = 0; i < size; i++) {
            input[i] = input[i] % (MAX_INPUT_VALUE + 1);
        }
        return input;
    }

    public int countBitsOfOne(int number) {
        int totalBitsOfOne = 0;
        while (number > 0) {
            totalBitsOfOne += number & 1;
            number >>= 1;
        }
        return totalBitsOfOne;
    }
}
