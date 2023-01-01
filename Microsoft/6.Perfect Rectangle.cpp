class Solution {

public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        auto comp = [] (const vector<int> &a, const vector<int> &b)
        {
            if (a[0] != b[0]) return (a[0] > b[0]);
            return (a[1] > b[1]);
        };

        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> pq(comp);
        for (auto &r : rectangles) pq.push(r);
        int x1 = INT_MIN;
        int y1 = INT_MIN;
        int x2 = INT_MIN;
        int y2 = INT_MIN;
        int sx1 = INT_MIN;
        int sy1 = INT_MIN;
        int sx2 = INT_MIN;
        int sy2 = INT_MIN;
        while(!pq.empty())
        {
           
            auto r = pq.top();
            pq.pop();
            if (x1== INT_MIN)
            {   
                x1 = r[0];
                y1 = r[1];
                x2 = r[2];
                y2 = r[3];
                sx1 = x1;   
                sy1 = y1;
            }
            else if (r[0] == x1)
            {   
                if (r[1] != y2) return false;
                if (r[2] > x2)
                {   
                    pq.push({x2,y2,r[2],r[3]});
                }
                else if (r[2] < x2)
                {  
                    pq.push({r[2],y1,x2,y2});
                    x2 = r[2];  
                }
                y2 = r[3];    
            }
            else
            {  
                if (r[0] != x2) return false;  
                if (r[1] != y1) return false;   
                if (sy2 == INT_MIN)  sy2 = y2;  
                else if (y2 != sy2) return false;  
                x1 = r[0];    
                y1 = r[1];
                x2 = r[2];
                y2 = r[3];
            }
        }
        if (sy2 == INT_MIN)  sy2 = y2;
        else if (y2 != sy2) return false;
        sx2 = x2;
        return true;
        
    }
};