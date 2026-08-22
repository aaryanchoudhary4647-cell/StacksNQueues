class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int a = *max_element(nums.begin(), nums.end());

        int n = 0;
        while (a > 0) {
            a = a / 2;
            n++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int ct = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & (1 << i)) != 0) {
                    ct++;
                }
            }

            if (ct >= k) {
                ans += pow(2, i);
            }
        }

        return ans;
    }
};