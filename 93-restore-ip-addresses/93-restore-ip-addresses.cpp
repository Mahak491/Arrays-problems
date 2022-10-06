class Solution {
public:

    void dfs(string s,int idx,string currentIp,int cnt,vector<string> &res)
    {
        if(cnt > 4)
        return;
        
        
        if(cnt == 4 && idx == s.size())
        {
            res.push_back(currentIp);
        }
        
        for(int i=1;i<4;i++)
        {
            if(idx+i > s.size())
                break;
            string str = s.substr(idx,i);
            if((str[0] == '0' && str.size() > 1) || (i == 3 && stoi(str) > 255))
                continue;
            dfs(s,idx+i,currentIp+str+(cnt == 3?"":"."),cnt+1,res);
        }
    }
    
    
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        dfs(s,0,"",0,res);
        return res; 
    }
};