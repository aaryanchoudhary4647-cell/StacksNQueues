class Solution {
public:
    // The intuition is to check that how many times every nums[i] contributes
    // to min and max for ex min = 1*3 + 2*2 + 3*1 = 10 and max = 3*3 + 2*2 +
    // 1*1 = 14 so ans = 14-10 = 4 to do that we will require pse and nse and
    // pge and nge
    // TC -> O(4N) + O(N)
    // SC -> O(8N)
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> s1;

        for (int i = n - 1; i >= 0; i--) {
            while (!s1.empty() && nums[i]>nums[s1.top()]){
                s1.pop();
            }

            if(s1.empty()){nge[i]=-1;}
            else{
                nge[i] = s1.top();
            }

            s1.push(i);
        }
        vector<int> nse(n);
        stack<int> s2;

        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && nums[i]<nums[s2.top()]){
                s2.pop();
            }

            if(s2.empty()){nse[i]=-1;}
            else{
                nse[i] = s2.top();
            }

            s2.push(i);
        }
        vector<int> pge(n);
        stack<int> s3;

        for (int i = 0; i<n; i++) {
            while (!s3.empty() && nums[i]>=nums[s3.top()]){
                s3.pop();
            }

            if(s3.empty()){pge[i]=-1;}
            else{
                pge[i] = s3.top();
            }

            s3.push(i);
        }
        vector<int> pse(n);
        stack<int> s4;

        for (int i = 0; i <n; i++) {
            while (!s4.empty() && nums[i]<=nums[s4.top()]){
                s4.pop();
            }

            if(s4.empty()){pse[i]=-1;}
            else{
                pse[i] = s4.top();
            }

            s4.push(i);
        }

        long long ans=0;

        for(int i=0;i<n;i++){
            int l1 = (pse[i]==-1) ? i+1 : i-pse[i];
            int l2 = (pge[i]==-1) ? i+1 : i-pge[i];
            int r1 = (nse[i]==-1) ? n-i : nse[i]-i; 
            int r2 = (nge[i]==-1) ? n-i : nge[i]-i; 

            long long totalMin = (1LL*nums[i]*l1*r1);
            long long totalMax = 1LL*nums[i]*l2*r2;

            ans += totalMax-totalMin;
        }

        return ans;
        
    }
};