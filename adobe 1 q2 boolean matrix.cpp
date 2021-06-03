class Solution
{

public:
    int mindistinct(int Arr[], int N, int K)
    {
	    // code here
	    unordered_map<int,int> m;
	    for(int i=0;i<N;i++){
	        m[Arr[i]]++;
	    }
	    
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	    for(auto x:m){
	        pq.push({x.second,x.first});
	    }

	    int s=K;
	    while(s!=0){
	        pair<int,int> q=pq.top();
	        pq.pop();
	        if(q.first>=s){
	            q.first=q.first-s;
	            s=0;
	            if(q.first!=0) pq.push(q);
	        }
	        else if(q.first<s){
	            s=s-q.first;
	        }
	    }
	    return pq.size();
    }
};