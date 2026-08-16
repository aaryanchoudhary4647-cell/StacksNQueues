class Solution {
public:
    // this is the optimal approach using stacks
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            s.push(nums[i]);
        }

        vector<int> ans(n,0);
        int ind = n-1;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            if(s.empty()){ans[ind]=-1;}
            else{ans[ind] = s.top();}
            ind--;
            s.push(nums[i]);
        }

        return ans;
    }
};