class Solution {
public:
    string sortSentence(string s) {
        int index=0;
        unordered_map<int,string> m;
        // replace(s.begin(),s.end()," ","_");
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                int a=(s[i-1]-'0');
                int dist=(i-1)-index;
                m[a]=s.substr(index,dist);
                index=i+1;
            }
        }
        int a=s[s.size()-1]-'0';
        int dist=(s.size()-1)-index;
        m[a]=s.substr(index,dist);
        vector<pair<int,string>> v;
        for(auto x:m){
            v.push_back(x);
        }
        
        sort(v.begin(),v.end());
        
        string ans="";
        
        for(int i=0;i<v.size();i++){
            ans=ans+v[i].second+" ";
        }
        
        return ans.substr(0,ans.size()-1);
    }
};