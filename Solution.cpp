
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    inline static int MAX_INPUT_VALUE = pow(10, 4);
    
public:
    vector<int> sortByBits(vector<int>& input) {
        const size_t size = input.size();
        for (int i = 0; i < size; i++) {
            input[i] = input[i] + (MAX_INPUT_VALUE + 1) * countBitsOfOne(input[i]);
        }
        sort(input.begin(), input.end());

        for (int i = 0; i < size; i++) {
            input[i] = input[i] % (MAX_INPUT_VALUE + 1);
        }
        return input;
    }

    int countBitsOfOne(int number) {
        int totalBitsOfOne = 0;
        while (number > 0) {
            totalBitsOfOne += number & 1;
            number >>= 1;
        }
        return totalBitsOfOne;
    }
};
