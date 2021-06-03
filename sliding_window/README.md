## sliding window 
- Type of problem 
    * fixed window size (Q 1 to 5)
    * variable size --> list map set be used (Q 6 onwards)

```cpp
//basic code structure
while(j< n){
    calculations

    if(j<k)j++
    else{}
        ans=cal
    upadte i term //sliding the window
    i++,j++;
    }
}
```
## 1. Sliding window problem

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


## 2.First negative integer in every window of size k 
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

```cpp

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
           
           vector<long long >ans;
           long long i=0,j=0;
           queue<int>q;// u can use vector or dequeue also
           while(j<N){
               if(j<k-1){
                   if(A[j]<0)q.push(A[j]);
                   j++;
               }
               else{
                if(A[j]<0)q.push(A[j]);
               
               if(q.size()==0){
                   ans.push_back(0);
               }
               else {
                   ans.push_back(q.front());
                   if(A[i]==q.front())q.pop();
               }
               
               i++;
               j++;
               
               }
           }
           return ans;
 }
```

## 3.Count Occurences of Anagrams 
https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

```cpp
	int search(string k, string s) {

    unordered_map<char,int>mp;
    int len=k.size();int n=s.size();
    for(int i=0;i<len;i++)mp[k[i]]++;
    
    int count =mp.size();
    int ans=0;
    
    for(int i=0;i<len-1;i++){
        if(mp.find(s[i])!=mp.end()){
            mp[s[i]]--;
            if(mp[s[i]]==0)count--;
        }
    }

    int i=0;int j=len-1;
            while(j<n){
                if(mp.find(s[j])!=mp.end()){
                    mp[s[j]]--;
                    if(mp[s[j]]==0)count--;
                }
                if(count==0)ans++;
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1)count++;
                }
                
                i++;j++;
            }

	  return ans;  
	}

// another way for same code
int solve(string s, string ana){
    unordered_map<char, int> m;
    for(auto it : ana) m[it]++;

    int k=ana.length();
    int count=m.size();
    
    int i=0, j=0;
    int ans=0;
    
    while(j<s.length()){
    
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }
        if((j-i+1)<k) j++; 
        else if((j-i+1)==k){

            if(count==0) ans++;

            if(m.find(s[i])!=m.end()){
                m[s[i]]++;
                if(m[s[i]]==1) count++;
            }

            i++;
            j++;
        }
    }
    return ans;
}

```
## 4.Maximum of all subarrays of size k 
https://www.interviewbit.com/problems/sliding-window-maximum/#
```cpp
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>v;
        int i=0,j=0;
        
        deque<int>q;
        int n=nums.size();
        while(j<n)
        {
            while(q.size()>0 && q.back()<nums[j])
                q.pop_back();
                q.push_back(nums[j]);
            
            if(j-i+1<k)
                j++;
            else
            {
                v.push_back(q.front());
                if(nums[i]==q.front())
                    q.pop_front();
                i++;
                j++;
            }
            
        }
        return v;
     }
```
## 5.Largest Subarray of sum K
Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is: 
4
```cpp
// a general code for varibale window length
/*
  while(j<n){
      claculation

      if condition=k upadte ans;
      else if condition <k j++ 
      else if condition>k 
                while condtion>k condtion remove i and i++
                    if condition ==k update ans
                    j++;
  }
*/
int solve(vector<int> &A, const int &k) {
	int n = A.size();
	int i = 0, j = 0, sum = 0;
	int mx = INT_MIN;
	while (j < n) {
		sum += A[j];

		if (sum < k) {
			j++;
		} else if (sum == k) {
			mx = max(mx, j - i + 1);
			j++;
		} else if (sum > k) {
			while (sum > k) {
				sum = sum - A[i];
				i++;
			}
             if(sum==s) mx = max(mx, j - i + 1);;
			j++;
		}
	}
	return mx;
}

// subarray with given sum same logic of above
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int i=0,j=0;
        long long sum=0;
        while(j<n){
            sum+=arr[j];
            
            if(sum==s)return {i+1,j+1};
            else if(sum>s){
                while(sum>s)sum-=arr[i++];
                if(sum==s)return {i+1,j+1};
            }
            j++;
        }
        return {-1};
    }
```
## 6.Longest K unique characters substring
* Pick Toys -->same logic we have to find max number of toys we can pick continuous which  of only 2 type means k=2 here
https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
```cpp
    int longestKSubstr(string s, int k) {
    // your code here
    int ch[256]={0}; // map also can be used
    int count=0;
    int i=0,j=0;
    int ans=-1;
    while(j<s.size()){
       if(ch[s[j]]==0){
           ch[s[j]]++;count++;
       }
       else {
           ch[s[j]]++;
       }
       if(count==k)ans=max(ans,j-i+1);
       else if(count>k){
           while(count>k){
               if(ch[s[i]]==1){
                   ch[s[i]]--;
                   count--;
               }
               else ch[s[i]]--;
               
               i++;
           }
           if(count==k)ans=max(ans,j-i+1);
       }
       j++;
        
    }
    return ans;
    }

//toy 
    int maxtoy(string toy, int k=2) {
    unordered_map<int,int>mp;
    int count=0;
    int i=0,j=0;
    int ans=0;
    while(j<toy.size()){
       if(mp.find(toy[j]==mp.end() || mp[toy[j]]==0)){
           mp[toy[j]]++;count++;
       }
       else {
           mp[toy[j]]++;
       }
       if(count==k)ans=max(ans,j-i+1);
       else if(count>k){
           while(count>k){
               if(mp[toy[i]]==1){
                   ch[toy[i]]--;
                   count--;
               }
               else mp[toy[i]]--;
               
               i++;
           }
           if(count==k)ans=max(ans,j-i+1);
       }
       j++;
        
    }
    return ans;
    }
```

## 7.Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/
```cpp
    int lengthOfLongestSubstring(string s) {
       int ans=0;
        int ch[256]={0};
        int n=s.size();
        int i=0;int j=0;
        while(j<n){
            if(ch[s[j]]==0){
                ch[s[j]]++;
                ans=max(ans,j-i+1);
                j++;
            }else{
              while(ch[s[j]]!=0 & i<j ){
                  ch[s[i]]--;
                  i++;
              }  
              ch[s[j]]++;
                ans=max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }
```
## 8.Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/
```cpp
string minWindow(string s, string t) {
        string ans="";
        unordered_map<char,int>mp;
        for(int i=0;i<t.size();i++)mp[t[i]]++;
        int count=mp.size();
        int ans1 =INT_MAX;
        int i=0,j=0;
        while(j<s.size()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0)count--;
            }
            if(count==0){
                if(ans1>(j-i+1)){ans=s.substr(i,j-i+1);ans1=j-i+1;}
                
                while(count<=0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1)count++;
                        i++;
                        
                    }
                    else
                        i++;
                    if(count==0){
                        if(ans1>(j-i+1)){ans=s.substr(i,j-i+1);ans1=j-i+1;}
                    }    
                }
            }
            j++;   
        }
	return ans;
}
```