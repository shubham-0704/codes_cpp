## Arrays and vector 
```cpp
int arr[n]; // stack allocated
int * arr = new int[n]; // heap allocated
vector<int>v; // dynamic allocated

int count[26]={0}; // making all zeros
```

```cpp
void array(stl){
	   //array of STL

    tradition array when passed to a function then a pointer goes to that function 
	u can use const while passing array(tarditional) so it cant be changed in function

	array<int,3> ar={1,2,3};
	cout<<ar[2]<<endl;
	cout<<ar.size()<<endl;
	cout<<ar.data()<<endl;//ives output a pointer to te array
	ar.fill(10);
	cout<<ar[1]<<endl;
	int a=3;
	ar[2]=a;
	cout<<ar[2]<<endl;
	for(auto &i:ar){
		cin>>i;
	}
	sort(ar.begin(),ar.end());
	for(auto &i:ar){
		cout<<i<<endl;
	}
}
```

```cpp
void explainVector() {
	int a[5] = {0, 1, 2, 3, 4};
    vector<int> v4(a, *(&a + 1));

	// A empty vector
	vector<int> v;  // {}

	v.push_back(1); // {1}
	v.emplace_back(2); // {1, 2}

	vector<pair<int, int>>vec;

	v.push_back({1, 2});
	v.emplace_back(1, 2);

	// Vector of size 5 with
	// everyone as 100
	vector<int> v(5, 100); // {100, 100, 100, 100, 100}

	// A vector of size 5
	// initialized with 0
	// might take garbage value,
	// dependent on the vector
	vector<int> v(5); // {0, 0, 0, 0, 0}

	vector<int> v1(5, 20); // {20, 20, 20, 20, 20}
	vector<int> v2(v1); // {20, 20, 20, 20, 20}



	// Take the vector to be {10, 20, 30, 40}
	vector<int>::iterator it = v.begin();

	it++;
	cout << *(it) << " "; // prints 20


	it = it + 2;
	cout << *(it) << " "; // prints 30

	vector<int>::iterator it = v.end();

	vector<int>::iterator it = v.rend();

	vector<int>::iterator it = v.rbegin();



	cout << v[0] << " " << v.at(0);

	cout << v.back() << " ";


	// Ways to print the vector

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}


	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}

	for (auto it : v) {
		cout << it << " ";
	}

	// {10, 20, 12, 23}
	v.erase(v.begin()+1);

	// {10, 20, 12, 23, 35}
	v.erase(v.begin() + 2, v.begin() + 4); // // {10, 20, 35} [start, end)


	// Insert function

	vector<int>v(2, 100); // {100, 100}
	v.insert(v.begin(), 300); // {300, 100, 100};
	v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

	vector<int> copy(2, 50); // {50, 50}
	v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

	// {10, 20}
	cout << v.size(); // 2
	//{10, 20}
	v.pop_back(); // {10}
	// v1 -> {10, 20}
	// v2 -> {30, 40}
	v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}
	v.clear(); // erases the entire vector
	cout << v.empty();

}
```

## 1.find a duplicate and a missing number in array
Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers in order of one space.

Input:[3 1 2 5 3] 

Output:[3, 4] 

Duplicate = 3, Missing = 4
<br>
you can find by maths like n(n+1)/2 and then differnce of squres to find them 

```cpp
//O(n)  // swap sort 
    int *findTwoElement(int *arr, int n) {
        int *ans=new int[2];
        for(int i=0;i<n;i++){
            while(arr[i]-1!=i)
            {   if(arr[i]==arr[arr[i]-1]){
                break;
            }
                swap(arr[i],arr[arr[i]-1]);
                 
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                ans[0]=arr[i];
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
```


## 2.find multiple dupicate and missig number in array
Given an unsorted array of size n. Array elements are in the range from 1 to n. Some numbers from set {1, 2, …n} are missing and some are repeating in the array. Find these two numbers in order of one space.


Input:[3 1 1 5 3] 

Duplicate = 3,1  Missing = 2,4
> same code as above case
```cpp
// same code as above but with while loop
//O(n) // swap sort 
void solve(int arr[],vector<vector<int>>&v,int n){
  int i=0;
  while(i<n){
    if(arr[i]!=arr[arr[i]-1]){
      swap(arr[i],arr[arr[i]-1]);
    }
    else i++;
  }
  for(int i=0;i<n;i++){
    if(arr[i]-1!=i){
      v[0].push_back(arr[i]);
      v[1].push_back(i+1);
    }
  }
}
```

## 3. remove duplicate from sorted array in o(n) time o(1) space
https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1#
```cpp
    int remove_duplicate(int arr[],int n){
      int pos=1;
      for(int i=1;i<n;i++){
          if(arr[pos-1]!=arr[i]){
              arr[pos] = arr[i];
              pos++;
          }
      }
      return pos;
    }
```
## 4. Move all zeroes to end of array 
```cpp
	void pushZerosToEnd(int arr[], int n) {
	    int res=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]!=0){
	            swap(arr[res],arr[i]);
	    
	            res++;
	        }
	    
	    }
	}
```
## 5. rotate array 
```cpp
reverse(arr,arr+n);
reverse(arr+k,arr+n);
reverse(arr,arr+k);
```

## 6.Largest Sum Subarray or kadanes algo
```cpp
int max_final=arr[0];
int max_curr=arr[0];
for(int i=0;i<6;i++){
  max_curr=max(max_curr+arr[i],arr[i]);

  max_final=max(max_final,max_curr);
}
```

## 7. merge two sorted array
```cpp
// input arrays - arr1(size m), arr2(size n)
void merge_sorted(arr1, arr2, m, n)
{
    arr3[m+n] // merged array
    i=0,j=0,k=0
    while(i < m && j < n) 
    {
        if arr1[i] < arr2[j] :
            arr3[k++] = arr1[i++]
        else :
            arr3[k++] = arr2[j++]
    }
    while(i < m)
        arr3[k++] = arr1[i++]
    while(j < n)
        arr3[k++] = arr2[j++]
}
```