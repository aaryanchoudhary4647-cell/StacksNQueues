class Solution {
public:
// This is the brute force approach with calculating every min and max
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            int minEl = nums[i];
            int maxEl = nums[i];
            for(int j=i;j<n;j++){
                minEl = min(minEl,nums[j]);
                maxEl = max(maxEl,nums[j]);
                ans += maxEl-minEl;
            }   
        }

        return ans;
    }
};