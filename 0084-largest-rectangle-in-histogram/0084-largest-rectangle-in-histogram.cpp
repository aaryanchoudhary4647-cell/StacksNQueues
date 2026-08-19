class Solution {
public:
    // optimal soln using the concept of nse and pse
    // we have to find the max width of the rectangle we can make assuming the
    // current heights[i] is max for that rectangle
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> s1;

        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && heights[i] <= heights[s1.top()]) {
                s1.pop();
            }

            if (s1.empty()) {
                nse[i] = -1;
            } else {
                nse[i] = s1.top();
            }

            s1.push(i);
        }
        vector<int> pse(n);
        stack<int> s2;

        for (int i = 0; i < n; i++) {
            while (!s2.empty() && heights[i] <= heights[s2.top()]) {
                s2.pop();
            }

            if (s2.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = s2.top();
            }

            s2.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int leftBound = pse[i];
            int rightBound = (nse[i] == -1) ? n : nse[i];
            int width = rightBound - leftBound - 1;
            ans = max(ans, heights[i] * width);
        }

        return ans;
    }
};