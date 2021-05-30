# Greedy
always slecect the best or go for optimisations
```cpp
//general straucture 
res=0;
while(){
    i=select_item;
    if(feasible(i))res+=i;
}
return res;
```
>min coin problme looks like can be solved this way but it fails use DP there 

## 1.Activity Selection /N meeting in one roome
* sort according to finish time
* initialize 1st element as soltion
* add if does not overlap  
```cpp
 // O(nlogn)
    static bool compare(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    
    int act_sel(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),compare);
        
        int ans=0;
        int last_time=0;
        for(int i=0;i<n;i++){
            if(v[i].first>last_time){
                ans++;
                last_time=v[i].second;
            }
        }
        return ans;
    }

    // n - meeting
        int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),[](pair<int,int>a,pair<int,int>b){return a.second<b.second;});
        
        int ans=0;
        int prev=0;
        for(int i=0;i<n;i++){
            if(prev<v[i].first){
                ans++;
                prev=v[i].second;
            }
        }
        
        return ans;
    }
```
## 2.Huffman Decoding
if 0 then move left if 1 then move right on tree

```cpp
string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    // Code here
    string s;
    MinHeapNode* temp=root;
    for(int i=0;i<binaryString.size();i++){

        if(binaryString[i]=='1')temp=temp->right;
        else temp=temp->left;
        
        if(temp->left==NULL && temp->right==NULL){
            s+=temp->data;
            temp=root;
        }
    }
    return s;
}
```
## 3.Fractional Knapsack 
* sort in decending by value/weight ratio
* res =0 capacity and transverse 
* one item only one time
```cpp
    static bool comp(Item a,Item b){
        return ((double)a.value/double(a.weight))>((double)b.value/double(b.weight));

    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans=0;
        sort(arr,arr+n,comp);
        for(int i=0;i<n;i++){
            if(W==0)break;
            if(W>=arr[i].weight){
                W-=arr[i].weight;
                ans+=arr[i].value;
            }
            else{
    
                ans+= (W * (double(arr[i].value)/arr[i].weight));
                break;
                
            }
        }
        return ans;
    }
```

## 4.Job Sequencing Problem 
* sort in decreasing order profit
* make a slot and try to fill slots latest slot
```cpp
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
      sort(arr,arr+n,comp);
      bool slot[102]={0};slot[0]=1;
      vector<int>ans(2,0);
      for(int i=0;i<n;i++){
          int j=arr[i].dead;
          while(j){
              if(!slot[j]){
                  slot[j]=1;
                  ans[0]++;
                  ans[1]+=arr[i].profit;
                  break;
              }
              j--;
          }
      }
      return ans;
    } 
```