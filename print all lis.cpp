#include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<string> printLIS(vector<int> arr){

	vector<int> dp(arr.size(),1);
	int omax=0;
	int omi=0;
	for(int i=0;i<arr.size();i++){
		int maxi=0;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				if(dp[j]>maxi){
					maxi=dp[j];
				}
			}
		}
		dp[i]=maxi+1;
		if(dp[i]>omax){
			omax=dp[i];
			omi=i;
		}
	}
	cout<<omax<<endl;
	int count=0;
	vector<string> ans;
	queue<pair<pair<int,int>,string>> q;
	q.push({{omax,omi},to_string(arr[omi])+""});

	while(q.empty()==false){
		pair<pair<int,int>,string> temp=q.front();
		q.pop();
		if(temp.first.first==1){
			count++;
			ans.push_back(temp.second);
		}
		//if seq of print matters..then try j=temp.first.second-1 to 0
		for(int j=temp.first.second-1;j>=0;j--){
			if(dp[j]==(temp.first.first-1) && arr[j]<arr[temp.first.second]){
				q.push({{dp[j],j},to_string(arr[j])+" -> "+temp.second});
			}
		}
	}
	return ans;
}


int main()
{
//   vector<int> v= {10, 22, 9, 33, 21, 50, 41, 60, 80, 1};
   int N;
    cin>>N;
    vector<int> arr(N,0);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
   vector<string> ans=printLIS(arr);
   for(int i=0;i<ans.size();i++){
   	cout<<ans[i]<<endl;
   }
   return 0;
}