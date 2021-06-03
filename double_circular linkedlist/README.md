# circular linnked list
## 1.display
```cpp
vector<int> displayList(Node *head)
{
    if(head==NULL)return {};
    vector<int>ans;
    Node *temp=head;
    while(1){
        ans.push_back(temp->data);
        if(temp->next==head)break;
        else temp=temp->next;
    }
    return ans;
}
```
## 2.insert at head
insert at 2ns pos swap data of 1st and 2nd return head;
```cpp
Node *insertInHead(Node * head, int data)
{
    Node *temp=new Node(data);
    if(!head){
        temp->next=temp;
        return temp;
    }
    else{ 
        temp->next=head->next;
        head->next=temp;
        swap(temp->data,head->data);
        return head;
    }
}
```
## 3.insert at tail
insert at 2nd pos and swap 1st and 2d value and return 2nd node;
```cpp
    Node *temp=new Node(data);
    if(!head){
        temp->next=temp;
        return temp;
    }
    temp->next=head->next;
    head->next=temp;
    swap(temp->data,head->data);
    return temp;
```
## 4.delete tail or head
```cpp
//tail
    if(!head)return NULL;
    if(head->next==head)return NULL;
    
    Node *temp=head;
    while(1){
        if(temp->next==head)break;
        temp=temp->next;
    }
    temp->data=head->data;
    Node *curr=head;
    temp->next=curr->next;
    delete curr;
    
    return temp;

// head
   if(head==NULL)return NULL;
   if(head->next==head)return NULL;
   head->data=head->next->data;
   Node *temp=head->next;
   head->next=temp->next;
   delete temp;
   return head;
```
# Double linked list

all operations are simmilar just prev and next id there 
## 1.reverse DLL
```cpp
     Node *pre=NULL,*curr=head,*nex;
     while(curr){
        nex=curr->next;
        curr->next=pre;
        curr->prev=nex;
        pre=curr;
        curr=nex;
    }
    return pre;

// another way
   Node *temp=head;
   if(head->next==NULL)return head;
   else{
       Node* pre=NULL;
       while(temp){
           temp->prev=temp->next;
           temp->next=pre;
           pre=temp;
           temp=temp->prev;
           
       }
       return pre;
```
