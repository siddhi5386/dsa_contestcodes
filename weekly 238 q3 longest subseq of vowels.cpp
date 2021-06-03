class Solution {
public:
    int longestBeautifulSubstring(string word) {
        
        string vow="aeiou";
        int i=0;
        int end=0;
        int n=word.size();
        int count=0;
        int max_size=0;
        cout<<word.size();
        if(n<5) return 0;
        
        for(end=0;end!=n;end++){
            char t=word[end];
            if(i==(vow.size())){
                max_size=max(max_size,count);
            }
            if(t==vow[i]){
                if(i<=vow.size()) i++;
                count++;
            }
            else if(i>0 && t==vow[i-1]){
                count++;
            }
            else{
                start=end;
                count=0;
                i=0;
                if(t=='a'){
                   count=1;  
                   i=1;
                }
            }
        }
        if(i==(vow.size())){
                max_size=max(max_size,count);
            }
        return max_size;
    }
};




class Solution {
public:
    int longestBeautifulSubstring(string word) {
        const auto n = word.size();

        int cnt = 1;
        int len = 1;
        int max_len = 0;
        for (int i = 1; i != n; ++i) {
            if (word[i - 1] == word[i]) {
                ++len;
            } else if (word[i - 1] < word[i]) {
                ++len;
                ++cnt;
            } else {
                cnt = 1;
                len = 1;
            }
            
            if (cnt == 5) {
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};