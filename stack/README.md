# stack 
* [ array + brute force(n^2) ] --> 2nd loop depend on 1st loop  stack may be used here

```cpp
void explainStack() {
	#include<stack> //header file
	stack<int> st;
	st.push(1); // {1}
	st.push(2); // {2, 1}
	st.push(3); // {3, 2, 1}
	st.push(3); // {3, 3, 2, 1}
	st.emplace(5); // {5, 3, 3, 2, 1}
	cout << st.top(); // prints 5  "** st[2] is invalid **"
	st.pop(); // st looks like {3, 3, 2, 1}
	cout << st.top(); // 3
	cout << st.size(); // 4
	cout << st.empty();
	stack<int>st1, st2;
	st1.swap(st2);

}
```
## 1.nearest greater to left 
```cpp
void solve(vector<int>v) {
   vector<int>ans;
   stack<int>s;
   int a=0;
   for(int i=0;i<v.size();i++){
       while(!s.empty() && s.top()<=v[i]){
         s.pop();
       }
       if(s.empty())ans.push_back(-1);
       else ans.push_back(s.top());

       s.push(v[i]);
   }
   for(auto i:ans)cout<<i<<" ";
}
```
## 2.nearest greater to right
- https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#
```cpp
void solve(vector<int>v) {
   vector<int>ans;
   stack<int>s;
   for(int i=v.size()-1;i>-1;i--){
       while(!s.empty() && s.top()<=v[i]){
         s.pop();
       }
       if(s.empty())ans.push_back(-1);
       else ans.push_back(s.top());

       s.push(v[i]);
   }
   reverse(ans.begin(),ans.end());
   for(auto i:ans)cout<<i<<" ";
}
```
## 3.nearest smaller to left 
```cpp
void solve(vector<int>v) {
   vector<int>ans;
   stack<int>s;
  for(int i=0;i<v.size();i++){
    while(s.size()!=0 && s.top()>=v[i]){
      s.pop();
    }
    if(s.empty())ans.push_back(-1);
    else ans.push_back(s.top());

    s.push(v[i]);
  }
   for(auto i:ans)cout<<i<<" ";
}
```
## 4. nearest smaller to right
*  same logic as above question 
## 5.stock span problem
* https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
* this problem is same as nearest greatest left problem
```cpp
void solve(vector<int>v) {
   vector<int>ans;
   stack<pair<int,int>>s;
  for(int i=0;i<v.size();i++){
    while(s.size()!=0 && s.top().first<=v[i]){
      s.pop();
    }
    if(s.empty())ans.push_back(1+i);
    else ans.push_back(i-s.top().second);

    s.push({v[i],i});
  }
   for(auto i:ans)cout<<i<<" ";
}
```
## 6.maximum area of hitogramm
* https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

```cpp
    long long getMaxArea(long long arr[], int n)
    {       long long ans=-1;
            long long temp=-1;
            int left[n];
            stack<pair<long long ,int>>s;
            
            for(int i=0;i<n;i++){
                while(!s.empty() && s.top().first>=arr[i]){
                    s.pop();
                }
                if(s.empty())left[i]=i;
                else left[i]=i-s.top().second-1;
                
                s.push({arr[i],i});
            }
            
            while(!s.empty())s.pop();
            for(int j=n-1;j>-1;j--){
                while(!s.empty() && s.top().first>=arr[j]){
                    s.pop();
                }
                if(s.empty())left[j]+=n-1-j;
                else left[j]+=s.top().second-j-1;
                
                s.push({arr[j],j});
            }
            
        for(int i=0;i<n;i++){
            temp=(arr[i]*(long long)(left[i]+1));
            if(temp>ans)ans=temp;
        }
        return ans;
    }
```
## 7.max area of rectangle in binary matrix
```cpp
0 1 1 0      0 1 1 0 --h1
1 1 1 1  ->  1 2 2 1 --h2
1 1 1 1      2 3 3 2 --h3
1 1 0 0      3 4 0 0 --h4 
```

pass h1 h2 h3 h4 by getmaxarea or maximum area of histogram i.e above question and max of all will be ans

## 8. rain water trapping
* https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#
```cpp
    int trappingWater(int arr[], int n){
        int maxl[n],maxr[n];
        maxl[0]=arr[0];maxr[n-1]=arr[n-1];
        for(int i=1;i<n;i++)maxl[i]=max(maxl[i-1],arr[i]);
        for(int i=n-2;i>-1;i--)maxr[i]=max(maxr[i+1],arr[i]);
        
        int wat[n];
        for(int i=0;i<n;i++){
            wat[i]=min(maxl[i],maxr[i])-arr[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
           ans+=wat[i];
        }
        return ans;
    }
```
## 9.implemenataion of min stack
* o(n) space
```cpp
class stack1{
private:
    std::stack<int>s,ss;

public:
  void push(int a){
    if(ss.empty()){
      s.push(a);
      ss.push(a);
    }
    else {
      s.push(a);
      if(ss.top()>=a)ss.push(a);
    }
  }

  void pop(){
    if(s.top()==ss.top()){
      s.pop();
      ss.pop();
    }
    else s.pop();
  }
  void top(){
    cout<<s.top()<<endl;
  }
  void min(){
    cout<<ss.top()<<endl;
  }

};
```
* o(1) space
```cpp
class stack1{
private:
    std::stack<int>s;
    int min_element=-1;

public:
  void push(int a){
     if(s.size()==0){
       s.push(a);
       min_element=a;
     }
     else{
       if(a>=min_element){
         s.push(a);
       }
       else{
         s.push(2*a-min_element);
         min_element=a;
       }
     }
  }

  void pop(){
    if(s.top()>=min_element){
      s.pop();
    }
    else {
      min_element=2*min_element-s.top();
      s.pop();
    
    }
  }
  void top(){
    if(s.top()>=min_element)cout<<s.top()<<endl;
    else cout<<min_element<<endl;
  }
  void min(){
    if(s.size()==0)cout<<"-1"<<endl;
    else cout<<min_element<<endl;
  }

};
```
## implemenation of stack using heap
## the celebrity problem
## longest valid parenthesis
## TOH (iterative)


