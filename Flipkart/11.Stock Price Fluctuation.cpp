class StockPrice {
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        if (stock.find(timestamp) != stock.end())
            prices.erase(prices.find(stock[timestamp]));
        
        stock[timestamp] = price;
        prices.insert(price);
        
        latest = max(latest, timestamp);
    }
    
    int current() {
        return stock[latest];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
    
private:
    map<int, int> stock;
    multiset<int> prices;
    int latest = 0;
};