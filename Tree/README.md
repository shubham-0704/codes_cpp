# Tree
*  hierarchical DS
* Tree --> Binary Tree --> Binary search tree 
```cpp
struct Node{
    int data;
    Node * left,*right;
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

// in above while loop this code is also can be used
        if(root==NULL)return v;
        Node *curr=root;
          while(st.size() || curr){
            v.push_back(curr->data);
            
            if(curr->right)st.push(curr->right);
            curr=curr->left;
            
            if(curr==NULL && st.size()){
                curr=st.top();
                st.pop();
            }
        }
```
## Iterative post order
```cpp
// using two stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>s1,s2;
        
        TreeNode *curr=root;
        s1.push(root);
        while(s1.size()){
            curr=s1.top();s1.pop();
            if(curr->left)s1.push(curr->left);
            if(curr->right)s1.push(curr->right);
            s2.push(curr);
        }
        
        while(s2.size()){
            ans.push_back(s2.top()->val);s2.pop();
        }
        return ans;
    }
    
 // using one stack
         vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        TreeNode * curr= root;
        while(st.size() || curr){
            while(curr){
                st.push(curr);curr=curr->left;
            }
            curr=st.top();
            if(st.top()->right==NULL){
                st.pop();ans.push_back(curr->val);curr=NULL;
            }else{
                if(ans.size() && ans.back()==curr->right->val){
                                ans.push_back(curr->val);curr=NULL;st.pop();
                }
                else{
                    curr=curr->right;
                }
            }
        }
        
        return ans;
    }
```
## 9.Insertion in BT
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
// O(3n) and space O(N)
bool findPath(Node* root, vector<int>& path, int k)
{
    // base case
    if (root == NULL)
        return false;

    // Store this node in path vector.
    // The node will be removed if
    // not in path from root to k
    path.push_back(root->key);

    // See if the k is same as root's key
    if (root->key == k)
        return true;

    // Check if k is found in left or right sub-tree
    if ((root->left && findPath(root->left, path, k)) || 
        (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root,
    // remove root from path[] and return false
    path.pop_back();

    return false;
}

// Function to return LCA if node n1, n2 are
// present in the given binary tree, otherwise
// return -1
int findLCA(Node* root, int n1, int n2)
{
    // to store paths to n1 and n2 from the root
    vector<int> path1, path2;

    // Find paths from root to n1 and root to n1.
    // If either n1 or n2 is not present, return -1
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;

    // Compare the paths to get the first
    // different value
    int i;

    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;

    return path1[i - 1];
}
****************************************
// if all elelemts are diffenrent and present in BT then otimised solution
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    // Base case
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->key == n1 || root->key == n2)
        return root;

    // Look for keys in left and right subtrees
    Node* left_lca = findLCA(root->left, n1, n2);
    Node* right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL,
    // then one key is present in once subtree and
    // other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)
        return root;

    // Otherwise check if left subtree or
    // right subtree is LCA
    return (left_lca != NULL) ? left_lca : right_lca;
}

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
## 13.1 left  view
```cpp
// recursive
// k=0 initially 
void solve(struct node *root,map<int,int>&mp,int k){
    if(root==NULL)return ;

    mp[k]=root->data;
    solve(root->right,mp,k+1);
    solve(root->left,mp,k+1);

}
// my solution
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>v;
   if(root==NULL)return v;
   queue<Node *>q;
   q.push(root);
   q.push(NULL);
   Node *curr;
   while(q.size()>0 ){
       while(q.front()){
           curr=q.front();
           
           if(curr->right)q.push(curr->right);
           if(curr->left)q.push(curr->left);
           q.pop();
       }
       v.push_back(curr->data);
       q.pop();
       if(q.size()==0)break;
       q.push(NULL);
   }
   return v;
}

// BFS
void leftViewUtil(Node root) 
{ 
      // Declare a queue for Level order Traversal
      queue<Node*> q;
  
    if (root == NULL) 
        return; 

    // Push root 
    q.push(root); 

    // Delimiter 
    q.push(NULL); 

    while (!q.empty()) { 
        Node* temp = q.front(); 

        if (temp) { 

            // Prints first node 
            // of each level 
            print temp->data;

            // Push children of all nodes at 
            // current level 
            while (q.front() != NULL) { 

                // If left child is present 
                // push into queue 
                if (temp->left) 
                    q.push(temp->left); 

                // If right child is present 
                // push into queue 
                if (temp->right) 
                    q.push(temp->right); 

                // Pop the current node 
                q.pop(); 

                temp = q.front(); 
            } 

            // Push delimiter 
            // for the next level 
            q.push(NULL); 
        } 

        // Pop the delimiter of 
        // the previous level 
        q.pop(); 
    } 
} 

```
## 13.2 Right view
```cpp
// recursive
// k=0 initially 
void solve(struct node *root,map<int,int>&mp,int k){
    if(root==NULL)return ;

    mp[k]=root->data;
    solve(root->left,mp,k+1);
    solve(root->right,mp,k+1);

   
}
// BFS 
same as above just print element present at last of that level
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>v;
       queue<Node *>q;
       if(root==NULL)return v;
       q.push(root);q.push(NULL);
       Node * curr;
       while(q.size()>0){
           while(q.front()){
               curr=q.front();
               q.pop();
               if(curr->left)q.push(curr->left);
               if(curr->right)q.push(curr->right);
           }
           v.push_back(curr->data);
           q.pop();
          if( q.size()==0)break;
          q.push(NULL);
       }
       return v;
    }
```
## 13.3 top  view
```cpp
    vector<int> topView(Node *root)
    {
        //Your code here
        if(root==NULL)return {};
        vector<int>v;
        map<int,int>mp;
        queue<pair<Node *,int>>q;
        q.push({root,0});
        Node *curr;
        pair<Node *,int>tp;
        while(q.size()>0){
           tp= q.front();
           curr=tp.first;
           if(mp.find(tp.second)==mp.end())mp[tp.second]=curr->data;
           if(curr->left)q.push({curr->left,tp.second-1});
           if(curr->right)q.push({curr->right,tp.second+1});
           q.pop();
        }
        for(auto i:mp)v.push_back(i.second);
        
        return v;
        
    }
```
## 13.4 bottom  view
```cpp
same as top view
vector <int> bottomView(Node *root)
{
   // Your Code Here
   if(root==NULL)return {};
   vector<int>v;
   map<int,int>mp;
   queue<pair<Node *,int>>q;
   q.push({root,0});
   pair<Node*,int>tp;
   Node *curr;
   while(q.size()>0){
       tp=q.front();q.pop();
       curr=tp.first;
       mp[tp.second]=curr->data;
       
       if(curr->left)q.push({curr->left,tp.second-1});
       if(curr->right)q.push({curr->right,tp.second+1});
       
   }
   for(auto i:mp)v.push_back(i.second);
   return v;
}
```

## 14.Convert a Binary Tree into its Mirror Tree
mirror image of binary tree
```cpp
void mirror(struct Node* node) 
{
    if (node == NULL) 
        return
    else
    {
        struct Node* temp
         
        /* Recur for subtrees */
        mirror(node->left)
        mirror(node->right)
     
        /* swap the pointers in this node */
        temp     = node->left
        node->left = node->right
        node->right = temp
    }
}
```

## 15.Convert a given Binary Tree to Doubly Linked List
```cpp
// A simple recursive function to convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head --> Pointer to head node of created doubly linked list
void BinaryTree2DoubleLinkedList(node *root, node **head)
{
    // Base case
    if (root == NULL) 
        return
 
    // Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static node* prev = NULL
 
    // Recursively convert left subtree
    BinaryTree2DoubleLinkedList(root->left, head)
 
    // Now convert this node
    if (prev == NULL)
        *head = root
    else
    {
        root->left = prev
        prev->right = root
    }
    prev = root
 
    // Finally convert right subtree
    BinaryTree2DoubleLinkedList(root->right, head)
}
```
