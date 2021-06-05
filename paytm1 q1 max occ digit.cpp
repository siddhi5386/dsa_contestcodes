class Solution
{

public:
    int maxoccourence(int arr[], int n, int k)
    {
        // code here
        char ke=(char)k+'0';
        string t;
        int count=0;
        int num;
        int maxc=0;
        for(int i=0;i<n;i++){
            t=to_string(arr[i]);
            count=0;
            for(int j=0;j<t.size();j++){
                if(t[j]==ke){
                    count++;
                }
            }
            if(count>maxc){
                maxc=count;
                num=arr[i];
            }
            else if(count==maxc){
                if(arr[i]<num){
                    num=arr[i];
                }
            }
        }
        return num;
    }
};
