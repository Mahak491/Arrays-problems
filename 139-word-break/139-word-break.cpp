class Solution {
public:
    bool wb(string s,unordered_set<string> &st,int start, vector<int> &memo){
       if (start >= s.size()) 
            return true;
        if (memo[start] != -1) 
            return memo[start];
        for (int i = start + 1; i <= s.size(); ++i) {
            if (st.count(s.substr(start, i - start)) && wb(s, st, i, memo)) {
                memo[start] = 1;
                return memo[start];
            }
        }
        memo[start] = 0;
        return memo[start];
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        vector<int> dp(s.size(),-1);
        for(auto str : wordDict){
            st.insert(str);
        }
        return wb(s,st,0,dp);
    }
    
};