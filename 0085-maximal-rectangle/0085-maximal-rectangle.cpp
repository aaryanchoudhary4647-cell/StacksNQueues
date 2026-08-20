class Solution {
public:
    // This question is nothing but an extension to the largest rectangle in histogram problem

    int callFunc(vector<int> arr) {
        int n = arr.size();
        stack<int> s; // this will be an increasing stack
        int ans = 0;
        for (int i = 0; i < n; i++) {
                while (!s.empty() && arr[s.top()] >= arr[i]) {
                    int elInd = s.top();
                    s.pop();
                    int pse = s.empty() ? -1 : s.top();
                    ans = max(ans, arr[elInd] * (i - pse - 1));
                }
                s.push(i);
        }

        while (!s.empty()) {
            int nse = n;
            int elInd = s.top();
            s.pop();
            int pse = s.empty() ? -1 : s.top();
            ans = max(ans, arr[elInd] * (nse - pse - 1));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> histogram(matrix[0].size());
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    histogram[j] = 0;
                } else {
                    histogram[j] += 1;
                }
            }

            ans = max(ans, callFunc(histogram));
        }

        return ans;
    }
};