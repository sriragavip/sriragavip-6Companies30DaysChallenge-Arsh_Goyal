class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<long long> s;
        for(int i = 0 ; i < t.size() ; i++){
            if(t[i]  == "+" || t[i] =="-" || t[i] == "*" || t[i] =="/"){
                long long a = s.top();
                s.pop();
                long long b = s.top();
                s.pop();
                if(t[i] == "+"){
                    long long p = a+b;
                    s.push(p);
                }
                if(t[i] == "-"){
                    long long p = b - a;
                    s.push(p);
                }
                if(t[i] == "*"){
                    long long p = a * b;
                    s.push(p);
                }
                if(t[i] == "/"){
                    long long p = b/a;
                    s.push(p);
                }
            }else{
                long long z = stoi(t[i]);
                s.push(z);
            }
        }
        return (int)s.top();
    }
};