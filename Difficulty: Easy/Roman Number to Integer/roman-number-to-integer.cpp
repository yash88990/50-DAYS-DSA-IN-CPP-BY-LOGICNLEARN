//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevValue = 0; // Store the value of the previous symbol

    // Iterate through the string from right to left
    for (int i = str.length() - 1; i >= 0; i--) {
        int value = romanValues[str[i]];

        // If the value of the current symbol is less than the previous one, subtract it
        if (value < prevValue) {
            result -= value;
        }
        // Otherwise, add it to the result
        else {
            result += value;
        }

        // Update the previous value for the next iteration
        prevValue = value;
    }

    return result;
    }
};
