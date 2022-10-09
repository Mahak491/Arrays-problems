class Solution {
public:
    
    vector<string> res;
    unordered_map<string,int> mp;
    
    int getMinInValid(string s){
        stack<char> st;
        int i=0;
        
        while(i < s.size()){
            if(s[i] == '('){
                st.push('(');
            }
            else if(s[i] == ')'){
                if(st.size() > 0 && st.top() == '(')
                    st.pop();
                else
                    st.push(')');
            }
            i++;
        }
        return st.size();
    }
    
    void solve(string s,int minInv){
        if(mp[s] != 0)
            return;
        else
            mp[s]++;
        
        if(minInv < 0)
            return;
        
        if(minInv == 0){
            if(getMinInValid(s) == 0)
                res.push_back(s);
            return;
        }
        
        for(int i=0;i<s.size();i++){
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right,minInv-1);
        }
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) {
       solve(s,getMinInValid(s));
        return res;
    }
};