
class UndergroundSystem {
public:
    map<string,pair<int,int>> m;
    map<int,string> person;
    map<int,int>pt;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        person[id]=stationName;
        pt[id]=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        int val=0;
        string str=person[id]+" "+stationName;
        if(person.count(id)){
            val=t-pt[id];
        }
        m[str].first+=val;
        m[str].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string str=startStation+" "+endStation;
        double val=m[str].first/(1.0*m[str].second);
        return val;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */