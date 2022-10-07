class MyCalendarThree {
public:
    map<int,int> m;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
       int res = 0;
       int maxi = INT_MIN;
       m[start]++;
       m[end]--;
       for(auto i : m){
           res += i.second;
           maxi = max(maxi,res);
       }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */