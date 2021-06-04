class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<int,int> m;
        
        for(int i=0;i<sentence.size();i++){
            m[sentence[i]]++;
        }
        if(m.size()==26) return true;
        return false;
    }
};