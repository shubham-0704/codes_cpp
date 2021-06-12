# Heap 
* indentifiction - kth + smallest/larget
* min heap /max heap  (nlogk)
* k +smaller == max heap
* k + larger == min heap
```cpp
priority_queue<int>maxh;
priority_queue<int,vector<int>,greater<int> >minh;

.top(),.push().pop().size(),.empty(),swap()

maxh(arr,arr+n) == this is done in O(N) 
```

## 1. kth samllest in array
```cpp
int solve(int arr[],int n,int k){
  priority_queue<int>pq;
  for(int i=0;i<n;i++){
      pq.push(arr[i]);
      if(pq.size()>k)pq.pop();
  }
  return pq.top();
}
```
## 2.Kth largest in array
```cpp
int solve(int arr[],int n,int k){
  priority_queue<int,vector<int>,greater<int>>pq;
  for(int i=0;i<n;i++){
      pq.push(arr[i]);
      if(pq.size()>k)pq.pop();
  }
  return pq.top();
}
```
## 3.sort a k sorted array
```cpp
solve(int arr,int k,int n){
   priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>ans;
   for(int i=0;i<n;i++ ){
       pq.push(arr[i]);

       if(pq.size()>k){
           ans.push_back(pq.top());
           pq.pop();
       }
   }  
   while(pq.size()>0){
        ans.push_back(pq.top());
        pq.pop();
   }
   return ans;
}
```
## 4. k closest number
```cpp
arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3
find k nearest to 5 

make max heap with elememnt as pair<diff,element>
for(i in arr){
    maxh.push({abs(x-arr[i]),arr[i]});
    if(maxh.size()>k)maxh.pop();
}
return k elelmnt present in maxh;
```
## 5. top k frequent number
```cpp
make map and store elemtn with there frequency

insert map element in min heap of pair type  and makin k size conststant and  
return elememnt in min heap
```
## 6.frequency sort
```cpp
make map to store frequency and insert all elemnt in heap 
to sort and return elemnt 

```
## 7.k closest point to origin
```cpp
make mp<int,pair<int>>;
store x^2 + y^2;
make max heap and do as usual as above logics
```
## 8. connect ropes to minmize the cost
```cpp
always select min two ropes and add 
in min heap and repeat the process till size ==1;
```
## 9.sum of element 
```cpp
k1 th samllest and k2 the smallest number sum
sum of elemnt  between them ;

```
## 10.median of running integer
```cpp
// function to calculate median of stream
void printMedian(double arr[], int n)
{
    // max heap to store the smaller half elements
    priority_queue s;
    // min heap to store the greater half elements
    priority_queue,greater > g;
    double med = arr[0];
    s.push(arr[0]);
 
    print(med)
    // reading elements of stream one by one
    /*  At any time we try to make heaps balanced and
        their sizes differ by at-most 1. If heaps are
        balanced,then we declare median as average of
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined
        as the top element of heap of larger size  */
    for (int i=1; i < n; i++)
    {
        double x = arr[i];
 
        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
 
            med = (s.top() + g.top())/2.0;
        }
 
        // case2(both heaps are balanced)
        else if (s.size()==g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
            }
            else
            {
                g.push(x);
                med = (double)g.top();
            }
        }
 
        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
 
            med = (s.top() + g.top())/2.0;
        }
 
        print(med)
    }
}
```


# implemenation 
```cpp
heap is complete binary tree 
array represention ar[n]==heap
left (i)= 2*i +1;
right(i)= 2*i+2;
parent(i)=[(i-1)/2]
```

```cpp
// implemenation 
class MinHeap{
    int *arr;
    int size;
    int capacity;
    
    public:
    // constrctor with arguemnt  minheap h1(100);
    MinHeap(int c){
    size = 0; 
    capacity = c; 
    arr = new int[c];
    }

    int left(int i) { return (2*i + 1); } 
    int right(int i) { return (2*i + 2); } 
    int parent(int i) { return (i-1)/2; } 
    
    // insert in array then check for parent that it
    // is smaller or not till parent become smaller or reached
    // root of tree
    void insert(int x) { 
    if (size == capacity)return;
    size++; 
    arr[size-1]=x; 
        for (int i=size-1;i!=0 && arr[parent(i)]>arr[i];){ 
            swap(arr[i], arr[parent(i)]); 
            i = parent(i); 
        } 
    }

    // top and pop
    int extractMin(){ 
        if (size <= 0) 
            return INT_MAX; 
        if (size == 1){ 
            size--; 
            return arr[0]; 
        }  
        swap(arr[0],arr[size-1]);
        size--; 
        minHeapify(0); 
        return arr[size]; 
    } 
    // heapfy
    void minHeapify(int i){ 
        int lt = left(i); 
        int rt = right(i); 
        int smallest = i; 
        if (lt < size && arr[lt] < arr[i]) 
            smallest = lt; 
        if (rt < size && arr[rt] < arr[smallest]) 
            smallest = rt; 
        if (smallest != i) 
        { 
            swap(arr[i],arr[smallest]); 
            minHeapify(smallest); 
        } 
    }

    void decreaseKey(int i, int x) 
    { 
    arr[i] = x; 
    while (i != 0 && arr[parent(i)] > arr[i]) 
    { 
       swap(arr[i], arr[parent(i)]); 
       i = parent(i); 
    } 
    }
    
    void deleteKey(int i){ 
        decreaseKey(i, INT_MIN); 
        extractMin(); 
    }

    void buildHeap(){
        for(int i=(size-2)/2;i>=0;i--)
            minHeapify(i);
    }
};
```

## heap sort
```cpp
// using max heap
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int l=2*i+1;
      int r=2*i+2;
      int large=i;
      if(l<n && arr[l]>arr[i])large=l;
      if(r<n && arr[r]>arr[large])large=r;
      
      if(large!=i){
          swap(arr[i],arr[large]);
          heapify(arr,n,large);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=n/2-1;i>=0;i--){
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        
        for(int i=n-1;i>=0;i--){
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
        }
        
    }
```