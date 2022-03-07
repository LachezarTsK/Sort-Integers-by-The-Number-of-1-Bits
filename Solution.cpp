
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    inline static int MAX_INPUT_VALUE = pow(10, 4);
public:
    vector<int> sortByBits(vector<int>& input) {
        for (auto& num : input) {
            num = num + (MAX_INPUT_VALUE + 1) * countBitsOfOne(num);
        }
        sort(input.begin(), input.end());

        for (auto& num : input) {
            num = num % (MAX_INPUT_VALUE + 1);
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
