class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        if (digits[n - 1] != 9) {
            digits[n - 1]++;
            return digits;
        }

        int i = n - 1;

        while (i >= 0 && digits[i] == 9) {
            digits[i] = 0;
            i--;
        }

        if (i >= 0) {
            digits[i]++;
            return digits;
        }

        vector<int> newDigits(n + 1, 0);
        newDigits[0] = 1;
        return newDigits;
    }
};