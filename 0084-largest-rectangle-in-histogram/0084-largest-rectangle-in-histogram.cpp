class Solution {
public:
// This is the optimal approach for this question 
// the intution is similar to the brute where we calculated max(ans,nse-pse-1)
// so in this approach while traversal from left to right we will get pse easily , so all comes down to nse which will be nothing but the element on the top of the stack when we will remove it while calculating pse 
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int ans = 0;
        for(int i=0;i<n;i++){

            while(!s.empty() && heights[i]<heights[s.top()]){
                int el = s.top();
                s.pop();
                int pse = s.empty() ? -1 : s.top();
                ans = max(ans,heights[el]*(i-pse-1)); // here nse is i and pse is s.top() after we removed the current element el
            }

            s.push(i);

        }

        while(!s.empty()){
            int el = s.top();
            s.pop();
            int pse = s.empty() ? -1 : s.top();
            
            ans = max(ans,heights[el]*(n-pse-1));
        }

        return ans;
    }
};