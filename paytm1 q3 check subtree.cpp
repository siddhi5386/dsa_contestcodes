bool iss(Node* t,Node* s){
    if((t==nullptr && s!=nullptr) || (t!=nullptr && s==nullptr)) return false;
    if(t==nullptr && s==nullptr) return true;
    
    if(t->data != s->data) return false;
    
    bool a=iss(t->left,s->left);
    bool b=iss(t->right,s->right);
    
    return (a && b);
}

bool isSubtree(Node* T, Node* S) {
    // code here
    bool flag=false;
    Node *p=T;
    flag=iss(p,S);
    if(flag==1) return true;
    queue<Node*> q;
    q.push(p);
    while(q.empty()==0){
        Node* t=q.front();
        q.pop();
        if(t->left){
            flag=iss(t->left,S);
            if(flag==1) return true;
            else{
                q.push(t->left);
            }
        }
        if(t->right){
            flag=iss(t->right,S);
            if(flag==1) return true;
            else q.push(t->right);
        }
    }
    return false;
}