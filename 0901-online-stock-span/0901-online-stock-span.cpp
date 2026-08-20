class StockSpanner {
public:
// the intuition is that while pushing an element we will see that how much span it has becoz if there will be any element in future who will be greater than this then the previous span can be used
    StockSpanner() {
        
    }
    stack<pair<int,int>> s;
    int next(int price) {
        int span =1;
        while(!s.empty() && s.top().first<=price){
            span += s.top().second;
            s.pop();
        }
        s.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */