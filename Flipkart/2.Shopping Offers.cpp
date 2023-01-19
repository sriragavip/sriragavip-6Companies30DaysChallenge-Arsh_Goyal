class Solution {
    map<vector<int>,int>mymap;
    int find(vector<int>&price,vector<vector<int>>&special,vector<int>needs){
        if(mymap.find(needs)!=mymap.end())
            return mymap[needs];
        int p=0;
        for(int i=0;i<needs.size();i++)
            p+=(needs[i]*price[i]);
        if(p==0)
            return 0;
        
        for(int i=0;i<special.size();i++){
            bool x=true;
            for(int j=0;j<special[i].size()-1;j++){
                if(special[i][j]>needs[j]){
                    x=false;
                }
            }
            if(x==false)
                continue;
            vector<int>temp;
            for(int j=0;j<special[i].size()-1;j++){
                temp.push_back(needs[j]-special[i][j]);
            }
            p=min(special[i][special[i].size()-1]+find(price,special,temp),p);
        }
        mymap[needs]=p;
        return p;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return find(price,special,needs);
    }
};