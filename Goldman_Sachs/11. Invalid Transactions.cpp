class tr{
        public:
        string name;
        int time;
        int amount;
        string city;
    };
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& traj) {
        int sz=traj.size();
        vector<tr> v(sz);
        vector<string> ans;
        
        for(int i=0;i<sz;i++)
        {
            string s=traj[i];
            int l=0;
            string temp;
            while(isalpha(s[l]))
                temp.push_back(s[l++]);
            v[i].name=temp;;
            l++;
            temp="";
            while(isdigit(s[l]))
                temp.push_back(s[l++]);
            v[i].time=stoi(temp);
            l++;
            temp="";
            while(isdigit(s[l]))
                temp.push_back(s[l++]);
            v[i].amount=stoi(temp);
            l++;
            temp="";
            while(isalpha(s[l]))
                temp.push_back(s[l++]);
            v[i].city=temp;
        }
        for(int i=0;i<sz;i++)
        {
            if(v[i].amount>1000)
            {
                ans.push_back(traj[i]);
                continue;
            }   
            int j=0;
            while(j<sz)
            {
                if(j!=i)
                {
                   if(v[i].name==v[j].name and v[i].city!=v[j].city and abs(v[i].time-v[j].time)<=60) {
                      ans.push_back(traj[i]); 
                       break;
                   }
                       
                }
                j++;
            }
        }
       return ans;
    }
};