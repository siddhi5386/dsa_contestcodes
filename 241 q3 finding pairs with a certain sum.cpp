class FindSumPairs {
public:
    unordered_map<int,int> m;
    vector<int> ok1,ok2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        ok1=nums1,ok2=nums2;
        for(int i=0;i<ok2.size();i++){  // frequency map for ok2
            m[ok2[i]]++;
        }
    }
    
    void add(int index, int val) {
        m[ok2[index]]--;   // decrementing the frequency of old value 
        ok2[index]+=val;  // updating the value of ok2[index](originally nums2) 
        m[ok2[index]]++; // incrementing the freq of new value
    }
    
    int count(int tot) {
        int res=0;
        for(int i=0;i<ok1.size();i++) res+=m[tot-ok1[i]];  // checking how many times tot-ok1[i] occurs in ok2 & updating res
        return res;
    }
};