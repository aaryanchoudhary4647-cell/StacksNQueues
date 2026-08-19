class Solution {
public:
// This is the optimal approach using stacks 
// the intuiton is to delete a digit if it is greater than the digit next to it

    string removeKdigits(string num, int k) {
        if(num.size()==k){return "0";}
        int n = num.size();
        stack<char> s;
        for(char c : num){

            while(!s.empty() && s.top()>c && k>0){
                s.pop();
                k--;
            }
            s.push(c);
        }

        // if still k exists then we have to remove the unit place digits
        while(k>0){
            s.pop();
            k--;
        }

        string ans(s.size(),' ');
        for(int i=s.size()-1;i>=0;i--){
            ans[i] = s.top();
            s.pop();
        }
        // removing the leading zeros
        while(ans.size()>1 && ans[0]=='0'){
            ans.erase(ans.begin());
        }


        return ans;
    }
};