class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1){
            arr[0]=1;
        }
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(abs(arr[i-1]-arr[i])>1){
                arr[i]=arr[i-1]+1;
            }
        }
        int maxi=*max_element(arr.begin(),arr.end());
        return maxi;
    }
};