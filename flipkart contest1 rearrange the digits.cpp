class Solution
{
public:
    string smallestnum(string N)
    {
        int a[10]={0};
        int n=N.length();
        for(int i=0;i<n;i++)
        {
            a[N[i]-'0']++;
        }
        
        int i=1;
        while(a[i]==0)
            i++;
        
        string fans ="";
        fans+=i+'0';
        a[i]--;
       
        for(int i=0;i<10;i++)
        {
            if(a[i]>0)
            {
                while(a[i]>0)
                {
                    fans+=i+'0';
                    a[i]--;
                }
            }
        }
        return fans;
  }
};