class StockPrice {
public:
    unordered_map<int,int> rem;
    priority_queue<pair<int,int>> pq_max;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq_min;
    int curr;
    StockPrice() {
        curr = 0;    
    }
    void update(int timestamp, int price) {
        curr = max(curr,timestamp);
        rem[timestamp] = price;
        pq_max.push({price,timestamp});
        pq_min.push({price,timestamp});
        
    }
    int current() {
        
        return rem[curr];
    }
    int maximum() {
        pair<int,int> temp;
        while(!pq_max.empty()) {
            temp = pq_max.top();
            if(rem[temp.second] == temp.first)
                return temp.first;
            else
                pq_max.pop();
            
        }
        return -1;
    }
    int minimum() {
        pair<int,int> temp;
        while(!pq_min.empty()) {
            temp = pq_min.top();
            if(rem[temp.second] == temp.first)
                return temp.first;
            else
                pq_min.pop();
        }
        
        return -1;
    }
};