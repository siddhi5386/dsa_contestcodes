class Solution {
    public:
    void burn(Node* root,map<int,vector<int>> &m){
        
        if(root){
        burn(root->left,m);
        if(root->left){
            m[root->data].push_back(root->left->data);
            m[root->left->data].push_back(root->data);
            
        }
        if(root->right){
            m[root->data].push_back(root->right->data);
            m[root->right->data].push_back(root->data);
            
        }
        burn(root->right,m);
        }
    }
    int minTime(Node* root, int start) 
    {
        // Your code goes here
        map<int,vector<int>> m;
        burn(root,m);
        queue<int> q;
        q.push(start);
        int count=0;
        map<int,bool> visited;
        visited[start]=1;
        while(!q.empty()){
            int size=q.size();
            count++;
            
            for(int i=0;i<size;i++){
                int node=q.front();
                cout<<node<<" ";
                q.pop();
                for(int i:m[node]){
                    if(visited[i]==0){
                        visited[i]=1;
                        q.push(i);
                    }
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return count-1;
        
    }
};
