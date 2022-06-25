class Solution {
public:
    long long canfinishontime(vector<int>& piles,int k,int h){
        long long hours = 0;
        for(int p:piles){
            int div = p/k;
             hours += div;
            if(p % k > 0) {
                 hours++;
            }
        }
        return hours <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        long long r = 1000000000;
        while(l <= r){
            long long mid = l+(r-l)/2;
            if(canfinishontime(piles,mid,h)){
                 r = mid-1;
            }else{
               l = mid+1;
            }
        }
    return l;
    }
};