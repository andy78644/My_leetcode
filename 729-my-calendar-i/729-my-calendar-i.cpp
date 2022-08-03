class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i< booked.size();i++){
            if(max(booked[i].first, start) < min(booked[i].second, end)) return false;
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
/*

start min max end
min start end max
min start max end
start min end max

start end min max
min max start end



*/