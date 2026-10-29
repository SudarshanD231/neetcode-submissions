class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;  // stores indices

        for (int i = 0; i < n; i++) {
            int t = temperatures[i];

            // Pop while current temperature is warmer
            while (!st.empty() && t > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                res[prevIndex] = i - prevIndex;
            }

            // Push current index
            st.push(i);
        }

        return res;
    }
};