# Queue
FIFO 
easy to implement with circular linked list pointing node at the last node;
```cpp
void explainQueue() {
	queue<int> q;
	q.push(1); // {1}
	q.push(2); // {1, 2}
	q.emplace(4); // {1, 2, 4}

	q.back() += 5

	cout << q.back(); // prints 9

	// Q is {1, 2, 9}
	cout << q.front(); // prints 1

	q.pop(); // {2, 9}

	cout << q.front(); // prints 2

	.size() .swap() .empty() same as stack
}

void explainPQ() {
	priority_queue<int>pq;

	pq.push(5); // {5}
	pq.push(2); // {5, 2}
	pq.push(8); // {8, 5, 2}
	pq.emplace(10); // {10, 8, 5, 2}

	cout << pq.top(); // prints 10

	pq.pop(); // {8, 5, 2}

	cout << pq.top(); // prints 8

	// size swap empty function same as others

	// Minimum Heap
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5); // {5}
	pq.push(2); // {2, 5}
	pq.push(8); // {2, 5, 8}
	pq.emplace(10); // {2, 5, 8, 10}

	cout << pq.top(); // prints 2

}
```

## 1.Reverse the first K elements of the Queue
```cpp
/* Function to reverse the first K elements of the Queue */
void reverseQueueFirstKElements(k, Queue) 
{ 
    if (Queue.empty() == true || k > Queue.size()) 
        return
    if (k <= 0) 
        return
    stack  Stack 
    /* Push the first K elements into a Stack*/
    for ( i = 1 to k) { 
        Stack.push(Queue.front())
        Queue.pop()
    } 
    /* Enqueue the contents of stack 
       at the back of the queue*/
    while (!Stack.empty()) { 
        Queue.push(Stack.top())
        Stack.pop()
    } 
    /* Remove the remaining elements and  
       enqueue them at the end of the Queue*/
    for (int i = 0 to i < Queue.size() - k) { 
        Queue.push(Queue.front())
        Queue.pop()
    } 
} 
```

## max in window size k
```cpp
int main() {
 int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
 int k=3;
 int max_index=0;
 int i=0;int j=0;
for(j=0;j<k;j++){
    if(arr[j]>arr[max_index])max_index=j;
}
j--;
while(j<9){
    if(arr[j]>arr[max_index])max_index=j;
    cout<<arr[max_index]<<" ";

    if(max_index==i){
        for(int z=i+1;z<j;z++){
            if(arr[z]>arr[max_index])max_index=z;
        }
    }
    i++;j++;

}

}
```