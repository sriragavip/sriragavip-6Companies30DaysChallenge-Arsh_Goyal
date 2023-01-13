class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        set<string>s(bank.begin(),bank.end());
        if(s.find(end)==s.end())
        {
            return -1;
        }
        set<string>visited;
        queue<string>q;
        q.push(start);
        vector<char>v={'A','C','G','T'};
        int level=0;
        visited.insert(start);
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                if(temp==end)
                {
                    return level;
                }
                for(int i=0;i<temp.size();i++)
                {
                    char ch=temp[i];
                    for(auto it:v)
                    {
                        temp[i]=it;
                        if(s.count(temp)&&visited.count(temp)==0)
                        {
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                    temp[i]=ch;
                }
            }
            level++;
        }
        return -1;
    }
};