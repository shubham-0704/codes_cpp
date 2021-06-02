# Linked list
```cpp
void explainList() {
	// double linked list implemented
	list<int> ls;

	ls.push_back(2); // {2}
	ls.emplace_back(4); // {2, 4}

	ls.push_front(5); // {5, 2, 4};

	ls.emplace_front(); {2, 4};

	rest functions same as vector
	begin, end, rbegin, rend, clear, insert, size, swap
	front() – Returns the value of the first element in the list.
	back() – Returns the value of the last element in the list.
	push_front(g) – Adds a new element ‘g’ at the beginning of the list.
	push_back(g) – Adds a new element ‘g’ at the end of the list.
	pop_front() – Removes the first element of the list, and reduces the size of the list by 1.
	pop_back() – Removes the last element of the list, and reduces the size of the list by 1.
	begin() and end() – begin() function returns an iterator pointing to the first element of the list.
	empty() – Returns whether the list is empty(1) or not(0).
	insert() – Inserts new elements in the list before the element at a specified position.
	reverse() – Reverses the list.
	size() – Returns the number of elements in the list.
	sort() – Sorts the list in increasing order ls.sort();
}
```

```cpp
// simple implemenation
struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

// delete node --> delete the node
```
## 1. Transverse Linked List
```cpp
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
```
## 2.sorted insert 
 find the position greater than elemnt and insert 

## 3.Print middle 
```cpp
// slow and fast pointers 
void printMiddle(Node * head){
    if(head==NULL)return;
    Node *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}
```
## 4.finding the n-th node from the end of a given linked list
```cpp
 // method 1 find len of list then find (len-k+1)th element 

 // method 2 two pointers 
   1. move 1st pointer to n pos 
   2. 2nd pointer to head 
   3. transverse linked list 2nd pos will give nth node from last
   void printNthFromEnd(Node * head,int n){
        if(head==NULL)return;
        Node *first=head;
        for(int i=0;i<n;i++){
            if(first==NULL)return;
            first=first->next;
        }
        Node *second=head;
        while(first!=NULL){
            second=second->next;
            first=first->next;
        }
        cout<<(second->data);
}
```
## 5. reverse a linked list
```cpp
// iterative
Node *reverse(Node *head){
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
// recursive
Node *recRevL(Node *curr,Node *prev){
    if(curr==NULL)return prev;
    Node *next=curr->next;
    curr->next=prev;
    return recRevL(next,curr);
}

```

## 6.Detect Loop in a Linked List (Floyd’s Cycle-Finding Algorithm)
```cpp
//hash map to store and check if it comes again (another approach)
bool detectloop(Node* head) 
{
    Node *slow_p = head, *fast_p = head
  
    while (slow_p && fast_p && fast_p->next) 
    {
        slow_p = slow_p->next
        fast_p = fast_p->next->next
        if (slow_p == fast_p) 
            return true 
    }
    return false  
}
```
## 7.Find Intersection Point of Two Linked List  
```cpp
Node Count Difference Solution : Problem can be solved following these steps -
1.Get count of the nodes in the first list, let count be c1.
2.Get a count of the nodes in the second list, let count be c2.
3.Get the difference of counts d = abs(c1 – c2).
4.Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)

/* function to get the intersection point of two linked 
   lists head1 and head2 */
int getIntesectionNode( Node* head1, Node* head2) 
{
    c1 = getCount(head1)
    c2 = getCount(head2)
    d // difference 

    if(c1 > c2) 
        d = c1 - c2
        return utility(d, head1, head2)
    else :
        d = c2 - c1
        return utility(d, head2, head1)
}
/* function to get the intersection point of two linked 
   lists head1 and head2 where head1 has d more nodes than 
   head2 */
int utility(d, Node* head1, Node* head2) 
{
    Node* current1 = head1
    Node* current2 = head2
  
    for ( i = 0 to d-1 )
    {
        if(current1 == NULL) 
            return -1
        current1 = current1->next
    }

    while(current1 !=  NULL && current2 != NULL) 
    {
        if(current1 == current2) 
            return current1->data
        current1= current1->next
        current2= current2->next
    }
    return -1
}
```
## full implemenation
```cpp
class llist{

      //pointers maloc
      // code run in 4 areas(text,global declartion,stack,heap)
      //linked list implementaion
      private:
      struct node{
      int data;
      node* next;
      };
      node *head;
      node *tail;

      public:
      llist(){
      head=NULL;
      tail=NULL;
      }

      void insert(int data){
            node *temp=new node;
            temp->data=data;
            temp->next=NULL;
            if(head==NULL){
                  head=tail=temp;
            }
            else {
                  tail->next=temp;
                  tail=temp;
            }

      }
      void p(){
            node *ptr=head;
            while(ptr!=NULL){
                  cout<<ptr->data<<" ";

                  ptr=ptr->next;
            }
            cout<<endl;
      }
      void inserthead(int data){
             node *temp=new node;
            temp->data=data;
            temp->next=NULL;
            if(head==NULL){
                  head=tail=temp;
            }
            else {
                  temp->next=head;
                  head=temp;
            }
           
      }
      void dl(int n){
            node *temp=head;
            int cnt=0;
           for(int i=1;i<n-1;i++){
                 temp=temp->next;
           }
           if(temp==head){
                 head=head->next;
                 delete temp;
           }
           else {
                 node *temp2=temp->next;
                 temp->next=temp2->next;
                 delete temp2;
           }
      }
};

int main(){
  llist a,b;
  a.insert(2);
  a.insert(3);
  a.inserthead(293);
  a.insert(21);
  a.inserthead(100);
  a.p();
  a.dl(3);
  a.dl(1);
  a.p();
 

      return 0;
}
```