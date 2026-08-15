class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            int index = (i+1)%nums.size();

            while(nums[index]<=nums[i] && index!=i){
                index = (index+1)%nums.size();
            }

            if(index==i){
                ans.push_back(-1);
            }
            else{ans.push_back(nums[index]);}
        }

        return ans;
    }
};