class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        vector<int> ans(barcodes.size());
        unordered_map<int,int> m;
        for(auto i : barcodes)
        {
            m[i]++;
        }
        
        int maxVal = -1;
        int maxCnt = -1;
        for(auto p : m)
        {
            if(p.second > maxCnt)
            {
                maxCnt = p.second;
                maxVal = p.first;
            }
        }
        
        m.erase(maxVal);
        
        int pos = 0;
        for(int i = 0 ; i < maxCnt ; i++)
        {
            ans[pos] = maxVal;
            pos += 2;
        }
        
        for(auto p : m)
        {
            for(int i = 0 ; i < p.second ; i++)
            {
                if(pos >= ans.size())
                {
                    pos = 1;
                }
                ans[pos] = p.first;
                pos+=2;
            }
        }
        return ans;
    }
};