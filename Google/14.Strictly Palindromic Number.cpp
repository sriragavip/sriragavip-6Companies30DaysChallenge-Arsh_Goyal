class Solution {
public:
    bool isStrictlyPalindromic(int n) 
    {
        int tmp;                    
        string base;                 
        for(int i=2;i<=n-2;i++)
        {
            tmp=n;
            
            while(tmp)                                    
            {
                base = base + to_string(tmp%i);
                tmp = tmp/i;
            }
            
            int st=0;
            int en=base.size()-1;
            while(st<en)                                
            {
                if(base[st++]!=base[en--]) return false;
            }
            
            base.clear();                         
        }
        return true;
    }
};