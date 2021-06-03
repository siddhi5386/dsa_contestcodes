class Solution {
public:
    int converttok(int n,int k){
        int sum=0;
        int x=n;
        while(x!=0){
            sum=sum+(x%k);
            x=x/k;
        }
        return sum;
    }
    int sumBase(int n, int k) {
        
        return converttok(n,k);
    }
};