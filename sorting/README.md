# sorting
```cpp
bool comp(pair<int,int>p1, pair<int,int>p2) {
	if(p1.second < p2.second) {
		return true; 
	} else if(p1.second == p2.second){
		if(p1.first>p2.second) return true; 
	}
	return false; 
}


	sort(a+2, a+4); // [first, last)

	sort(a, a+n, greater<int>()); // descending order 
    
    pair<int,int> a[] = {{1,2}, {2, 1}, {4, 1}}; 

    // sort it according to second element 
    // if second element is same, then sort 
    // it according to first element but in descending 

	sort(a, a+n ,comp); 
	// {4,1}, {2, 1}, {1, 2}}; 
```

# 1 Bubble sort 
put max element to last in each iteration
```cpp
void bubbleSort(int arr[], int n){
    for(int i = 0;i < n; i++){
        for(int j = 0 ; j < n - i -1; j++){
            if( arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
// while loop
    void bubbleSort(int arr[], int n)
    {
        int index=n;
        while(index>1){
            for(int i=0;i<index-1;i++){
                if(arr[i]>arr[i+1])swap(arr[i],arr[i+1]);
            }
            index--;
        }
    }
// efficient 
void bubbleSort(int arr[], int n){
    
    bool swapped;
    for(int i = 0;i < n; i++){
        
        swapped = false;
        for(int j = 0 ; j < n - i -1; j++){
            if( arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        
        if( swapped == false)
        break;
    }
}
```

# 2.selection sort
select the min elemnt and swap that
```cpp
void selectionSort(int arr[], int n){
    
    for(int i = 0; i < n; i++){
        int min_ind = i;
        
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j;
            }
        }
        
        swap(arr[i], arr[min_ind]);
    } 
}

    void selectionSort(int arr[], int n)
    {
       int index=0;int min;int i;
       while(index!=n){
           min=index;
       for(i=index;i<n;i++){
          if(arr[min]>arr[i]){
              min=i;
          } 
          
       }
       swap(arr[index],arr[min]);
       index++;
        }
    }
```
# 3. insertion sort
```cpp
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++){
            int j, key;
                j=i;
                key=arr[j];
                while(j>0 && key<arr[j-1] ){
                    arr[j]=arr[j-1];
                    j--;     
                }
            arr[j]=key;
            }
    }
```
# 4.merge sort
```cpp
void merge(int arr[],int l,int mid,int h){
  
  int aux[h-l+1];
  for(int k=l;k<=h;k++){
      aux[k-l]=arr[k];
  }
  int i=l,j=mid+1;
int k=l;
      while(i<=mid && j<=h){
          if(aux[i-l]<=aux[j-l]){
              arr[k++]=aux[i-l];
              i++;
          }
          else {
              arr[k++]=aux[j-l];
              j++;
          }
      }
      while(i<=mid){
          arr[k++]=aux[i-l];
          i++;
      }
    while(j<=h){
          arr[k++]=aux[j-l];
          j++;
      }

}
void msort(int arr[],int l,int h){
    if(l==h)return ;

    int mid = (h-l)/2+l;
    msort(arr,l,mid);
    msort(arr,mid+1,h);
    merge(arr,l,mid,h);
}
```
# 
```cpp

```
# 
```cpp

```
# 
```cpp

```
# 
```cpp

```