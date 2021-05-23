## Binary Search 
sorted is given in question then think of BS 

```cpp
binary_search(start_ptr, end_ptr, ele)  // return true or false
upper_bound(first_itr, last_itr, ele) // return greater value or not present then end
lower_bound(first_itr, last_itr, ele)  //return pointer to equal or greater
find (InputIterator first, InputIterator last, val) // o(n) linear search
```

# 1. Binary search
```cpp
//recursive 
int solve(int a[],int start,int end ,int comp){

   if (start>end)return -1;
   int mid = (end-start)/2 + start;

   if(a[mid]==comp)return mid;
   else if (a[mid]>comp){
       end=mid-1;
   }
   else {
       start =mid +1;
   }
   return solve(a,start,end,comp);
}

//iterative approch
int solve(int a[],int start,int end ,int comp){

   while(start<=end){
   int mid = (end-start)/2 + start;
   if(a[mid]==comp)return mid;
      else if (a[mid]>comp){
       end=mid-1;
   }
   else {
       start =mid +1;
   }
   }
   return -1;
}
```
# 2. order agnostic search (order is not known  ascending or descending)
* make code for both check ascending or descending a[0]<a[1] and call  corresponding function
# 3. 1st occurance or last occurence in sorted array
```cpp
// 1st occurence eg 1,2,3,3,4,4,4,5,6  1st 4 comes at 4th position

int solve(int a[],int start,int end ,int comp){

   int oc1=-1;
   int oc_last= -1;

   while(start<=end){
   int mid = (end-start)/2 + start;
   if(a[mid]==comp){
       oc1= mid;
       end=mid-1;
       }
      else if (a[mid]>comp){
       end=mid-1;
   }
   else {
       start =mid +1;
   }
   }
   return oc1;
}
```
# 4. count of element in sorted array  find 1st occurence and last occurence 
solve as above problme and find last and 1st and then (last-first +1) will be ans
# 5. how many times a sorted array is rotated 
https://practice.geeksforgeeks.org/problems/rotation4723/1 
>find by bs and then go to unsorted side // same code for find minimum in sorted rotated array
```cpp
	int findKRotation(int arr[], int n) {

	    int i=0,j=n-1;
	    int mid;
	    while(i<=j){
	        if(arr[i]<=arr[j])return i;
	        mid=(j-i)/2+i;
	        int next=(mid+1)%n;
	        int pre=(mid-1+n)%n;
	        if(arr[mid]<arr[next] && arr[mid]<arr[pre])return mid;
	        else if(arr[i]<=arr[mid])i=mid+1;
	        else j=mid-1;
	    }
	}
// another way
	int findKRotation(int arr[], int n) {
	   int i=0,j=n-1;
	   if(arr[i]<=arr[j])return 0;
	   int mid,prev,next;
	   while(i<=j){
	       mid= (j-i)/2+i;
	       prev=(mid-1+n)%n;
	       next=(mid+1)%n;
	       
	       if(arr[mid]<arr[next]&& arr[mid]<arr[prev])return mid;
	       else if( arr[mid]>arr[j])i=mid+1;
	       else j= mid-1;
	   }
	}

    //another way best and easy
    Simple and StraightForward 
        int strt=0, end=n-1;
        int mid, index;
        while(strt<end)
        {
            mid=strt+(end-strt)/2;
            if(nums[mid] > nums[end])
                strt = mid+1;
            else
                end = mid;
        }
        return strt;
```
# 6.Find an Element in a Rotated Sorted Array
> find the min elemnt as above approach and from that divide the array into two parts and BS in both arrays

# 7.Searching in a Nearly Sorted Array
https://www.geeksforgeeks.org/search-almost-sorted-array/
```cpp
// use same logic for itterative code
int binarySearch(int arr[], int l, int r, int x)
{
if (r >= l)
{
        int mid = l + (r - l) / 2;
  
        // If the element is present at 
        // one of the middle 3 positions
        if (arr[mid] == x) 
            return mid;
        if (mid > l && arr[mid - 1] == x)
            return (mid - 1);
        if (mid < r && arr[mid + 1] == x) 
            return (mid + 1);
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 2, x);
  
        // Else the element can only be present 
        // in right subarray
        return binarySearch(arr, mid + 2, r, x);
}
  
// We reach here when element is not present in array
return -1;
}
```

# 8.FIND FLOOR OF AN ELEMENT IN A SORTED ARRAY
https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1#
```cpp
    int findFloor(vector<long long> v, long long n, long long x){
        long long i=0,j=n-1;
        long long mid;
        long long ans;
        while(i<=j){
            mid=(j-i)/2+i;
            
            if(v[mid]==x)return mid;
            else if(v[mid]>x)j=mid-1;
            else{ i=mid+1; ans=mid;}
        }
        if(v[0]>x)return -1;
        return mid;
    }
```
# 9.FIND ceil OF AN ELEMENT IN A SORTED ARRAY
https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
```cpp
        int findFloor(vector<long long> v, long long n, long long x){
        long long i=0,j=n-1;
        long long mid;
        long long ans;
        while(i<=j){
            mid=(j-i)/2+i;
            
            if(v[mid]==x)return mid;
            else if(v[mid]>x){
                j=mid-1;
                ans=mid;
            }
            else i=mid+1;
        }
        if(v.back()<x)return -1;
        return ans;
    }
```
# 10.Next Alphabetical Element
same as above but in this if match then return greater 
```cpp
        while(i<=j){
            mid=(j-i)/2+i;
            
            if(v[mid]==x)i= mid+1;
            else if(v[mid]>x){
                j=mid-1;
                ans=mid;
            }
            else i=mid+1;
        }
        if(v.back()<x)return -1;
        return ans;
```
# 11 .Find position of an element in a sorted array of infinite numbers
https://www.geeksforgeeks.org/find-position-element-sorted-array-infinite-numbers/
```cpp
int findPos(int arr[], int key)
{
    int l = 0, h = 1;
    int val = arr[0];// arr[1] can be also used
 
    // Find h to do binary search
    while (val < key)
    {
        l = h;        // store previous high
        h = 2*h;      // double high index
        val = arr[h]; // update new val
    }
 
    // at this point we have updated low and
    // high indices, Thus use binary search
    // between them
    return binarySearch(arr, l, h, key);
}
```
# 12.Find the index of first 1 in an infinite sorted array of 0s and 1s
https://www.geeksforgeeks.org/find-index-first-1-infinite-sorted-array-0s-1s/
```cpp
 firstfnd range using above question (elemnt in sorted infinite array) from
 that find the range then use 1st occurenece of 1 in that range using BS
```
# 14.Minimum Difference Element in a Sorted Array
```cpp
implement binary search if key is present ans is zero or that value else low and high in BS 
gives the neighbours of key from that find min differnce 

when we run BS then low high index will show the neigbours of element if not present 

int solve(arr[],n,k){
  if(n==1)return arr[0];
  if(k<arr[0])retrun arr[0];
  else if(k>arr[n-1])return arr[n-1];
  while(i<=j){
      mid=(i+j)/2;
      if(arr[mid]==k)return arr[mid];
      else(arr[mid]>k)j=mid-1;
      else i=mid+1;
  }
  return // check for which gives min differnec i or j  and retunrn
}
```
# 15.Find Missing And Repeating 
https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
```cpp
// negative indexing
    int *findTwoElement(int *arr, int n) {
        int *ans=new int[2];
       
       for(int i=0;i<n;i++){
           int temp=arr[abs(arr[i])-1];
           if(temp<0){
               ans[0]=abs(arr[i]);
           }
           else arr[abs(arr[i])-1]=-temp;
       }
       
       for(int i=0;i<n;i++){
           if(arr[i]>0)ans[1]=i+1;
       }
       return ans;
    }
```
# 16.Peak element 
https://practice.geeksforgeeks.org/problems/peak-element/1#
```cpp
    int peakElement(int arr[], int n)
    {
       // Your code here
       if(n==1)return 0;
       int i=0,j=n;
       int mid;
       while(i<=j){
          mid=(j-i)/2+i;
          if(mid==0 && arr[mid]>arr[mid+1])return mid;
          else if(mid==n-1 && arr[mid]>arr[mid-1])return mid;
          else if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])return mid;
          else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1])i=mid+1; // also go for which is max in mid-1 and mid +1 that side
          // also u can use mid< mid+1 this type of solution
          else{
              j=mid-1;
          }
       }
    }

```
# 17.Find maximum element in Bitonic Array
https://www.includehelp.com/icp/maximum-value-in-a-bitonic-array.aspx

same as findingpeak elemnt in array <br>
Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.

Example:

Input:
1 4 8 3 2

Output:
8

# 18.Find an element in Bitonic array
https://www.geeksforgeeks.org/find-element-bitonic-array/

find the idex of peak and divide the array from that point which give two array one increasing and one decreasing use BS on them to find the elements

# 19.Search in a row wise and column wise sorted matrix
https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1#

```cpp
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
       int i=0;int j=M-1;
       while(i<N && j>-1){
           if(mat[i][j]==X)return 1;
           else if(mat[i][j]>X)j--;
           else i++;
       }
       return 0;
	}
```

# 20.Allocate minimum number of pages
https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages/0
```cpp
    bool isvalid(int arr[],int n,int m,int mid){
        int sum=0;int cnt=1;
        
        for(int i=0;i<n;i++){
            // for this apporach i=max(arr[])
            // sum+=arr[i];
            // if(sum>mid){
            //     cnt++;
            //     sum=arr[i];
            // }
            // if(cnt>m)return 0;
            
            if(sum+arr[i]>mid){
                sum=0;
                i--;
                cnt++;
            }
            else sum+=arr[i];
            
            if(cnt>m)return 0;
        }
        return 1;
    }
    int findPages(int arr[], int n, int m) 
    {
        if(n<m)return-1;
        int Max=-1,sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            Max=max(Max,arr[i]);
        }
        int ans=-1;
        int i=0;int j=sum;int mid;
        while(i<=j){
            mid=(j-i)/2+i;
            if(isvalid(arr,n,m,mid)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
```