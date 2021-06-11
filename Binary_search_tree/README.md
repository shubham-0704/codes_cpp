## binary search tree
* inorder tranversal is sorted
* tansversing with key can be done by while loop
```cpp
    TreeNode* searchBST(TreeNode* root, int val) {
       
        TreeNode *curr=root;
        while(curr){
            if(curr->val==val)return curr;
            else if(curr->val>val)curr=curr->left;
            else curr= curr->right;
        }
        return NULL;
    }
```
## 1.insert in BST
```cpp
Node* insert(Node* root, int key)
{
    // Your code here
    if(root==NULL)return new Node(key);
    if(root->data==key)return root;
    if(root->data>key)root->left=insert(root->left,key);
    else root->right=insert(root->right,key);
    return root;
}

//itertive
Node* insert(Node* root, int key)
{   
    Node *temp=new Node(key);
    if(root==NULL)return temp;
    Node *prev,*curr;
    prev=NULL;curr=root;
    while(curr){
        prev=curr;
        if(curr->data==key)return root;
        else if(curr->data>key)
            curr=curr->left;
        else
            curr=curr->right;  
    }

    if(prev->data>key)prev->left=temp;
    else prev->right=temp; 
    return root;
}
```

## 2 delete element in BST
```cpp
Node *succ(Node *root){
    root=root->right;
    while(root && root->left)root=root->left;
    
    return root;
}


//Function to delete a node from BST.
Node *deleteNode(Node *root,  int X)
{
    // your code goes here
    if(root==NULL)return root;
    
    if(root->data>X){
        root->left=deleteNode(root->left,X);
    }else if(root->data<X){
        root->right=deleteNode(root->right,X);
    }else{
        if(root->left==NULL){
            return root->right;
        }else if(root->right==NULL)return root->left;
        else{
            Node *temp= succ(root);
            root->data=temp->data;
             root->right=deleteNode(root->right,temp->data);
            
        }
    }
    return root;
    
    
}
```

## 3 floor in BST
```cpp
Node *floor(Node *root, int x){
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key>x)
            root=root->left;
        else{
            res=root;
            root=root->right;
        }
    }
    return res;
} 
```

## 4 ceil in BST
```cpp
Node *ceil(Node *root, int x){
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key<x)
            root=root->right;
        else{
            res=root;
            root=root->left;
        }
    }
    return res;
} 
```

## 5. LCA lowest common ancector
```cpp
node *lca(node* root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 

    // If both n1 and n2 are smaller
    // than root, then LCA lies in left 
    if (root->data > n1 && root->data > n2) 
        return lca(root->left, n1, n2); 

    // If both n1 and n2 are greater than 
    // root, then LCA lies in right 
    if (root->data < n1 && root->data < n2) 
        return lca(root->right, n1, n2); 

    return root; 
} 
```