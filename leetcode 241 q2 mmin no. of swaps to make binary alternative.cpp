class Solution {
public:
    int minSwaps(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int n=s.size();
        if(n%2!=0){
            if(m['0']>(n/2+1) || m['1']>(n/2+1)) return -1;
        }
        else{
            if(m['0']>(n/2) || m['1']>n/2) return -1;
        }

        int c=0;
        int c1=0;
        int index=-1;
        string s1=s;
        for(int i=0;i<n;i++){
            
                if(i%2==0){
                    if(s[i]=='1') continue;
                    else{
                        if(index==-1){
                            index=i;
                        }
                        else{
                            swap(s[i],s[index]);
                            c++;
                            // cout<<i<<endl;
                            index=-1;
                        }
                    }
                }
                else{
                    if(s[i]=='0') continue;
                    else{
                        if(index==-1){
                            index=i;
                        }
                        else{
                            swap(s[i],s[index]);
                            c++;
                            // cout<<i<<endl;
                            index=-1;
                        }
                    }
                }
             }  
        if(index!=-1){
            c=1e7;
        }
        index=-1;
        s=s1;
        // cout<<"l"<<endl;
        for(int i=0;i<n;i++){
            
                if(i%2==0){
                    if(s[i]=='0') continue;
                    else{
                        if(index==-1){
                            index=i;
                        }
                        else{
                            swap(s[i],s[index]);
                            c1++;
                            // cout<<i<<endl;
                            index=-1;
                        }
                    }
                }
                else{
                    if(s[i]=='1') continue;
                    else{
                        if(index==-1){
                            index=i;
                        }
                        else{
                            swap(s[i],s[index]);
                            c1++;
                            // cout<<i<<endl;
                            index=-1;
                        }
                    }
                }
             }
        
        if(index!=-1){
            c1=1e7;
        }
        return min(c,c1);
    }
};


// class Solution {
// public:
//     int minSwaps(string s) {
//         int ones = 0, zeros = 0;
//         for (auto c : s) {
//             if (c == '1') ones++;
//             else zeros++;
//         }
        
//         if (abs(zeros - ones) > 1) return -1;
        
//         if (zeros < ones) return helper(s, '1');
//         if (zeros > ones) return helper(s, '0');
//         return min(helper(s, '1'), helper(s, '0'));       
//     }
    
//     int helper(string s, char st) {
//         int swaps = 0;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == st && i % 2 != 0) swaps++;
//         }
//         return swaps;
//     }
// };