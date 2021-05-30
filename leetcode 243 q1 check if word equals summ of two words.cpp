class Solution {
public:
    bool isSumEqual(string firstword, string secondword, string targetword) {
        map<char,char> m;
        m['a']='0';
        m['b']='1';
        m['c']='2';
        m['d']='3';
        m['e']='4';
        m['f']='5';
        m['g']='6';
        m['h']='7';
        m['i']='8';
        m['j']='9';
        string one="",two="",thre="";
        for(int i=0;i<firstword.size();i++){
            one=one+m[firstword[i]];
        }
        int onei=stoi(one);
        
        for(int i=0;i<secondword.size();i++){
            two=two+m[secondword[i]];
        }
        int twoi=stoi(two);
        for(int i=0;i<targetword.size();i++){
            thre=thre+m[targetword[i]];
        }
        int threi=stoi(thre);
        if((onei+twoi)==threi)
        return true;
        return false;
    }
};