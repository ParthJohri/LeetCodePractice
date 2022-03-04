class OrderedStream {
public:
    unordered_map<int,string> m;
    int ptr=1;
    OrderedStream(int n) {
        int x=0;
        for(int i=0;i<n;i++)
        m[x++]="";
    }
    
    vector<string> insert(int idKey, string value) {
        m[idKey]=value;
        vector<string> ans;
            while(m[ptr]!="")
                ans.push_back(m[ptr++]);
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */