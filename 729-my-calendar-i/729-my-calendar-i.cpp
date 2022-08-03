class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i< booked.size();i++){
            if(start >= booked[i].first && start < booked[i].second) return false;
            else if(end > booked[i].first && end < booked[i].second) return false;
            else if(start<booked[i].first && end>=booked[i].second) return false;
        }
        booked.push_back(make_pair(start,end));
        return true;
    }
private:
    vector<pair<int,int>> booked;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */