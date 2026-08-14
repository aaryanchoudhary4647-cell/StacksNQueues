class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2==1){return false;}
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){return false;} // becoz we got a closing before any opening bracket

                char c = st.top();
                st.pop();
                if(c=='(' && s[i]!=')' || 
                c=='{' && s[i]!='}' || c=='[' && s[i]!=']'){return false;}
            }
        }

        if(st.empty()){return true;}

        return false;
    }
};