class Solution {
public:
// This is the optimal soln for this problem 
// The intuition is that , to find the contribution of each element 
// we can find the contribution of each element using nse(next smaller element) and pse(previous smaller element) for ex in 3 1 2 4 if we see nse of 2 is -1 means no nse and pse of 2 1 which means 2 will be smaller element of only 2 subarray -> [2] and [2,4]

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1e9 + 7;
        // NEXT SMALLER ELEMENT
        vector<int> nse(n,0); // we will store index instead of val
        stack<int> s1;
        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && arr[s1.top()]>=arr[i]){
                s1.pop();
            }
            
            if(s1.empty()){
                nse[i] = -1;
            }
            else{
                nse[i] = s1.top();
            }

            s1.push(i);
        }

        // PREVOUS SMALLER ELEMENT
        vector<int> pse(n,0);
        stack<int> s2;
        for(int i=0;i<n;i++){
            while(!s2.empty() && arr[s2.top()]>arr[i]){
                s2.pop();
            }
            
            if(s2.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = s2.top();
            }

            s2.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int leftEls = (pse[i]==-1) ? i+1 : i-pse[i]; // No of left elements which can be used to make subarrays which have arr[i] as min

            int rightEls = (nse[i]==-1) ? n-i : nse[i]-i; // No of right elements which can be used to make subarrays which have arr[i] as min

            ans = (ans + (long long)arr[i] * (leftEls * rightEls)) % MOD;
            
        }

        return ans;
    }
};