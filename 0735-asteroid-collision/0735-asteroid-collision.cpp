class Solution {
public:
// same optimal approach but with forward traversal
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n = asteroids.size();

        for(int i=0;i<n;i++){
            if(asteroids[i]>0){s.push(asteroids[i]);}
            else{

                while(!s.empty() && s.top()>0 && s.top()<abs(asteroids[i])){
                    s.pop();
                }

                if(!s.empty() && s.top() == abs(asteroids[i])){
                    s.pop();
                }
                else if(s.empty() || s.top()<0){s.push(asteroids[i]);}
                
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        

        return ans;
    }
};