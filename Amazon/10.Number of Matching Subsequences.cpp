class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int m=s.size(),n=words.size(),cnt=0;
        vector<vector<int>>pos(26);
        for(int i=0;i<m;i++)
            pos[s[i]-'a'].push_back(i);
        bool flag;
        for(auto &word:words)
        {
            int prevPosition=-1;
            flag=true;
            for(auto & character:word)
            {
                auto it=upper_bound(pos[character-'a'].begin(),pos[character-'a'].end(),prevPosition);
                if(it==pos[character-'a'].end())
                { 
                    flag=false;
                    break;
                }
                else
                    prevPosition=*it;
            }
            if(flag)
                cnt++;
        }
        return cnt;
    }
};