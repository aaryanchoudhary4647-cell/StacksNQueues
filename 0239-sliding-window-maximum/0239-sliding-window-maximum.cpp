class Solution {
public:
// this is the optimal soln using a dequeue which is a data structure which allows operations like push in front or back and pop from front or back OR we can say that it is open from both the sides
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            // to maintain the window of size k
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }

            // to maintain a decreasing dq
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i); 
            // start pushing values when i>=k-1
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};