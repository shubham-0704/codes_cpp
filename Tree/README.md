# Tree
*  hierarchical DS
* Tree --> Binary Tree --> Binary search tree 
```cpp
struct Node{
    int data;
    Node * left,right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
}
int main(){
    Node* root=new Node(1); // if empty tree then root= NULL;
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(4);
}
```

## 1.height of binary tree

```cpp
int height(Node *root){
    if(root==NULL)return 0/-1;
    return 1+max(height(root->left),height(root->right));
}
```
## 2. size of binary tree (no of nodes)
```cpp
int solve(Node *root){
    if(root==NULL)return 0;
    return 1+solve(root->left)+solve(root->right);
}
```
## 3. min/max in binary tree
transverse and update the value for min max ( any type of transversal);
```cpp
int getMax(Node *root){
    if(root==NULL)
        return INT_MIN;
    else
        return max(root->key,max(getMax(root->left),getMax(root->right)));
} 
```
## 4. print Node at distance k
```cpp
void solve(Node *root ,k){
    if(root==NULL)return;
    if(k==0)cout<<root->data;
    else{
        solve(root->left,k-1);
        solve(root->right,k-1);
    }
}
```

## Tree transversal
* breadth first search (level order)
* depth first search (subtree)
    * preorder (root ,left ,right)
    * inorder  (left ,root,right)
    * postorder (left ,right ,root)

## 5. breadth first search
time O(n)  space O(width)
```cpp
void solve(Node *root){
    if(root==NULL)return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node* temp= q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left!=NULL)q.push(temp->left);
        if(temp->right!=NULL)q.push(temp->right);
    }
}
```
## 6.preorder search (recursive)
```cpp
// O(N) space : O(height of tree)
void solve(Node *root){
    if(root!=NULL){
        // rearrange to form other two
        cout<<root->data<<endl; //root 
        solve(root->left);  //left 
        solve(root->right);  //right
    }
}
```
## 7. iterative inorder
```cpp
    vector<int> inOrder(Node* root)
    {
            vector<int>ans;
            if(root==NULL)return ans;
            stack<Node *>st;
            Node * curr=root;
            while(curr!=NULL || !st.empty()){
                while(curr!=NULL){
                    st.push(curr);
                    curr=curr->left;
                }
                ans.push_back(st.top()->data);
                curr=st.top()->right;
                st.pop();
            }
            
            return ans;
    }
```
## 8. iterative preorder

```cpp
void solve(Node *root){
    if(root==NULL)return;
    stack<Node* >s;
    s.push(root);
    while(!s.empty()){
        cout<<s.top()->data;
        Node* curr=s.top();s.pop();
        if(curr->right!=NULL)s.push(curr->right);
        if(curr->left!=NULL)s.push(curr->left);
    }
}

// optimised
void solve(Node *root){
    if(root==NULL)return;
    stack<Node* >s;
    Node* curr=root;
    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            cout<<curr->data;
            if(curr->right!=NULL)s.push(curr->right);

            curr=curr->left;
        }
        if(s.empty()==false){
            curr=s.top();
            s.pop();
        }
    }
}
```
## 9.INsertion in BT
BFS when u find null push and break;
```cpp
void insert(struct Node* temp, int key) 
{ 
    queue<struct Node*> q; 
    q.push(temp); 

    while (!q.empty()) { 
        struct Node* temp = q.front(); 
        q.pop(); 

        if (!temp->left) { 
            temp->left = newNode(key); 
            break; 
        } else
            q.push(temp->left); 

        if (!temp->right) { 
            temp->right = newNode(key); 
            break; 
        } else
            q.push(temp->right); 
    } 
} 
```

## 10. deletion in BS
```cpp
// Function to delete the given deepest node 
// (d_node) in binary tree 
void deletDeepest(struct Node *root, struct Node *d_node) 
{ 
    queue<struct Node*> q; 
    q.push(root); 

    // Do level order traversal until last node 
    struct Node* temp; 
    while(!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 

        if (temp->right) 
        { 
            if (temp->right == d_node) 
            { 
                temp->right = NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 

        if (temp->left) 
        { 
            if (temp->left == d_node) 
            { 
                temp->left=NULL; 
                delete(d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 

// Function to delete element in binary tree 
void deletion(struct Node* root, int key) 
{ 
    queue<struct Node*> q; 
    q.push(root); 

    struct Node *temp; 
    struct Node *key_node = NULL; 

    // Do level order traversal to find deepest 
    // node(temp) and node to be deleted (key_node) 
    while (!q.empty()) 
    { 
        temp = q.front(); 
        q.pop(); 

        if (temp->key == key) 
            key_node = temp; 

        if (temp->left) 
            q.push(temp->left); 

        if (temp->right) 
            q.push(temp->right); 
    } 

    int x = temp->key; 
    deletDeepest(root, temp); 
    key_node->key = x; 
} 
```
## 11. LCA or Lowest Common Ancestor 
```cpp

```
## 12. diameter of bt
```cpp
    int solve(Node *root ,int &ans){
        if(root==NULL)return 0;
        int l=solve(root->left,ans);
       int r = solve(root->right,ans);
       ans=max(ans,l+r+1);
       return max(l,r)+1;
    }
    //Function to return the diameter of a Binary Tree.
    int diameter(Node* root)
    {
      int ans=INT_MIN;
      
      return max(ans,solve(root,ans));
    }
```