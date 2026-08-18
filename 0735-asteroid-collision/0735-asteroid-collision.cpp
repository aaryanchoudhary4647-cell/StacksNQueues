class Solution {
public:
// This is the optimal soln as if we encounter a -ve value in stack there will be 4 cases in reverse traversal
// 1- its next element will bigger and +ve
// 2- its next element will be smaller and +ve
// 3- its next element will be equal and +ve
// 4- its next element will be -ve
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int n = asteroids.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--){
                
            if(asteroids[i]>0){
                    while(!s.empty() && s.top()<0 && asteroids[i]>abs(s.top())){
                        s.pop();
                    }

                    if(!s.empty() && s.top()<0 ){
                        if(abs(s.top())==asteroids[i]){s.pop();}
                        else{continue;}
                    }
                    else{s.push(asteroids[i]);}
            }
            else{s.push(asteroids[i]);}
        }

        vector<int> ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};