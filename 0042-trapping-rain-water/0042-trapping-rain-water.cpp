class Solution {
public:
// This is the optimal approach where we have optimised the calculation of leftMax and RightMax using 2-pointer approach
// The intution here is we only need min(rightMax,LeftMax) so we move according to that
    int trap(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n-1;
        int rightMax =0;
        int leftMax =0;
        int ans =0;
        while(l<r){
            rightMax = max(rightMax,height[r]);
            leftMax = max(leftMax,height[l]);

            if(rightMax<leftMax){
                ans += rightMax-height[r];
                r--;
            }
            else{
                ans += leftMax-height[l];
                l++;
            }
        }

        return ans;
    }
};