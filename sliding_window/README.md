## sliding window 
- Type of problem 
    * fixed window size
    * variable size --> list map set be used 
- problems
    * [sliding window problem](#Sliding-window-problem)
    * [First negative integer in every window of size k ](#First-negative-integer-in-every-window-of-size-k)
    * [Count Occurences of Anagrams ](#Count-Occurences-of-Anagrams)


## Sliding window problem

arr[]= 2,5,1,8,2,9,1  max or min sum of subarray of size k

```cpp
int solve(int a[],int k,int n){
 int sum=0;
 int ans=0;
 int i=0;
 int j=0;

 for(j;j<n;j++){
     if((j-i+1)<=k){
         sum+=a[j];
     }
     else{
         sum+=a[j]-a[i];
         i++;
         ans=max(ans,sum);
     }
 }
  return ans;
}
```


## First negative integer in every window of size k 
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

```cpp
vector<int> solve(int a[],int k,int n){
  int i=0,j=0;
  int index=0;
  vector<int>temp;
  vector<int>ans;
  while(j<n){
      if(j-i+1<k){
          if(a[j]<0) temp.push_back(a[j]);

          j++;
      }
      else {
          if(temp.size()==index)ans.push_back(0);
          else {
              ans.push_back(temp[index]);
              
          }
          if(a[i]==temp[index])index++;
          if(a[j]<0) temp.push_back(a[j]);
          i++;
          j++;
      }
  }
  return ans;
}
```

## Count Occurences of Anagrams 
https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

```cpp
int solve(string s,string k){
  int ana=0;
  for(int i=0;i<k.size();i++){
    ana+=k[i]-'a'+1;
  }
  int ans=0;
 int i=0,j=0;
 int sum=0;
 while(j<s.size()){
     if(j-i+1<k.size()){
        sum+=s[j]-'a'+1;
        j++;
     }
     else{
       if(ana==sum+(s[j]-'a'+1))ans++;
    sum+=s[j]-'a'+1;
    sum-=s[i]-'a'+1;
    i++;j++;

     }
 }

 return ans;
}
```
