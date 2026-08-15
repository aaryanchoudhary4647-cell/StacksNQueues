class Solution {
public:
    // as we have already done with the brute force approach , now we will use monotonic stack , where monotonic means that we are storing data in stack in a particular order.

    // the intuition is that we will store the elements of nums2 from last and simultaneously we will store their next max in a map

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mpp;
        vector<int> ans;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            if(s.empty()){
                mpp[nums2[i]] = -1;
                s.push(nums2[i]);
            }
            else{
                while(!s.empty()){
                    if(s.top()>nums2[i]){
                        mpp[nums2[i]] = s.top();
                        s.push(nums2[i]);
                        break;
                    }
                    else{s.pop();}
                }
                if(s.empty()){
                    mpp[nums2[i]] = -1;
                    s.push(nums2[i]);
                }
            }
        }

        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]); 
        }

        return ans;

    }
};