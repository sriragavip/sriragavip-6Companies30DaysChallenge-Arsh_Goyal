class Solution {
public:
    string longestPrefix(string s) {
        int l=0,i=1,n=size(s),mx=0;
        vector<int>lps(n);
        while(i<n){            
            if(s[i]==s[l]) lps[i++]=++l;
            else{
                if(l)l=lps[l-1];
                else i++;
            }
        } 
        return s.substr(0,l);
    }
};