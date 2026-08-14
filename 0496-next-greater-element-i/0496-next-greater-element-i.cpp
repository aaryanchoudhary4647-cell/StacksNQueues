class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;i++){
            int el = nums1[i];
            for(int j=0;j<m;j++){
                bool exists = false;
                if(el==nums2[j]){
                    for(int k=j;k<m;k++){
                        if(nums2[k]>el){
                            ans.push_back(nums2[k]);
                            exists = true;
                            break;
                        }
                    }
                    if(!exists){ans.push_back(-1);}
                    
                    break;
                }
            }
        }

        return ans;
    }
};