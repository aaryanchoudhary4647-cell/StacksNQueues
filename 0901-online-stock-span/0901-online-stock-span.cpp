class StockSpanner {
public:
// in this the logic of PGE or previousGreaterElement is used as we have did in the above approach as well , but in this instead of storing previous span and just add it , here we will store the element and its index and use span = 1 + (ct-pge-1)
    StockSpanner() {
        
    }
    stack<pair<int,int>> s;
    int ct=0;
    int next(int price) {
        while(!s.empty() && s.top().first<=price){
            s.pop();
        }
        int ngeInd = s.empty() ? -1 : s.top().second ; 
        int span = ct-ngeInd;
        s.push({price,ct});
        ct++;   
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */