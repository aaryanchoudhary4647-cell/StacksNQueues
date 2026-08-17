class Solution {
public:
    // This is the brute force approach TC -> O(3N) and SC -> O(2N) 
    // The intution is that->
    // 1-  at every step it will only store water if its right and left steps are higher than the current step
    // 2- they will store water units = min(leftMax,rightMax) - height of current step
    
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int total = 0;
        int maxH =0;
        for(int i=0;i<height.size();i++){
            maxH = max(maxH,height[i]);
            prefix[i] = maxH;
        }

        int maxH2 = 0;
        for(int i=n-1;i>=0;i--){
            maxH2 = max(maxH2,height[i]);
            suffix[i] = maxH2;
        }

        for(int i=0;i<n;i++){
            int leftMax = prefix[i];
            int rightMax = suffix[i];

            if(height[i]<leftMax && height[i]<rightMax){
                total += min(leftMax,rightMax) - height[i];
            }
        }

        return total;

    }
};