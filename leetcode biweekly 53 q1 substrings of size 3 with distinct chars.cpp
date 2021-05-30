class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0;
        if(s.size()<=2) return 0;
        for(int i=0;i<=s.size()-3;i++){
            string temp=s.substr(i,3);
            map<char,int> m;
            int j;
            for(j=0;j<temp.size();j++){
                if(m.find(temp[j])!=m.end()){
                    break;
                }
                m[temp[j]]++;
            }
            if(j==temp.size()) count++;
        }
        return count;
    }
};