class Solution {
public:
    
    void solve(int start,string s,unordered_set<string> &st,vector<string> &res,string cur){
        if(start == s.length()){
            cur.pop_back();
            res.push_back(cur);
        }
        
        string str = "";
        for(int i=start;i<s.length();i++){
            str.push_back(s[i]);
            
            if(st.count(str)){
                solve(i+1,s,st,res,cur+str+" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        vector<string> res;
        
        for(auto str : wordDict){
            set.insert(str);
        }
        
        string cur = "";
        solve(0,s,set,res,cur);
        return res;
    }
};