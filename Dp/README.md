# Dynamic programming 
* memoization(top - down)
* Tabulation (Bottom-UP)
write recursvie memomize it then write itterative solution

 * some questions
  * fib(n)
  * LCS 
  * Longest increasing subsequence -  O(n^2) and O(nlog(n))
  * min cost path 
  * coin change (no permuation)
  * 0-1 knapsack
  * edit distance
  * Equal Average Partition 
  * MCM


# knapsack and its variation
## 1.0-1 Knapsack
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#
```cpp
//memomization
    int dp[1002][1002];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }

    int knapSack(int w, int wt[], int val[], int n) 
    { 
        if(n==0 || w==0)return 0;
        if(dp[n][w]!=-1)return dp[n][w];
        else{
        if(wt[n-1]<=w){
          return dp[n][w]= max(knapSack(w,wt,val,n-1),val[n-1]+knapSack(w-wt[n-1],wt,val,n-1));

        }
            else {return dp[n][w]= knapSack(w,wt,val,n-1);  
            }
        }
    }
//tabulation
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       int dp[n+1][w+1];
       // base condition
       for(int i=0;i<n+1;i++)dp[i][0]=0;
       for(int i=0;i<=w;i++)dp[0][i]=0;
       // main recursion fuction
       for(int i=1;i<=n;i++){
           for(int j=1;j<=w;j++){
               if(wt[i-1]<=j){
                   dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
               }else{
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       return dp[n][w];
    }
```
## 2.subset sum problem and Partition Equal Subset Sum 
https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#
```cpp
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)sum+=arr[i];
        if(sum%2!=0)return 0;
        
        bool dp[N+1][sum/2+1];
        for(int i=0;i<=sum/2;i++)dp[0][i]=0;
        for(int i=0;i<=N;i++)dp[i][0]=1;
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum/2;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][sum/2];
    }
```
## 3.count of subset with a given sum
```cpp
int main() {
	// your code goes here
	int t;cin>>t;
	while(t--){
      int n;cin>>n;
      int arr[n];for(auto &i:arr)cin>>i;
      int sum;cin>>sum;

      int dp[n+1][sum+1];
      for(int i=0;i<=n;i++)dp[i][0]=1;
      for(int i=1;i<=sum;i++)dp[0][i]=0;

      for(int i=1;i<=n;i++){
          for(int j=1;j<=sum;j++){
              if(arr[i-1]<=j){
                  dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
              }
              else {
                  dp[i][j]=dp[i-1][j];
              }
          }
      }
      cout<<dp[n][sum]<<endl;
	    
	}
	return 0;
}
```
## 4.Minimum sum partition or Minimum Subset Sum Difference
https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
```cpp
	int minDifference(int arr[], int n) 
	{ 
	    // Your code goes here
    	    int sum=0;
    	    for(int i=0;i<n;i++)sum+=arr[i];
    	    int ans=INT_MAX;
    	    bool dp[n+1][sum+1];
    	    
    	    for(int i=0;i<=n;i++)dp[i][0]=1;
    	    for(int i=1;i<=sum;i++)dp[0][i]=0;
    	    
    	    for(int i=1;i<=n;i++){
    	        for(int j=1;j<=sum;j++){
    	            if(j>=arr[i-1]){
    	                dp[i][j]=dp[i-1][j] | dp[i-1][j-arr[i-1]];
    	            }
    	            else {
    	                dp[i][j]=dp[i-1][j];
    	            }
    	        }
    	    }
    	    
    	    for(int i=0;i<=sum;i++){
    	        if(dp[n][i]){
    	            ans=min(ans,abs(sum-2*i));
    	        }
    	    }
    	    return ans;
	} 
```
## 5.Count the number of subset with a given difference
```cpp
s1-s2=d
s1+s2=s
s1=(d+s)2;
find subet with s1 as sum;
 solve the same way as count of subset of given sum;
```
## 6. target sum ==subset sum diffenrce
https://leetcode.com/problems/target-sum/
>refer Notes 

# unbounded knapsack and its variation
## 1.Unbounded Knapsack
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
```cpp
// 2D dp
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        for(int i=0;i<=N;i++)dp[i][0]=0;
        for(int i=0;i<=W;i++)dp[0][i]=0;
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][W];
    }

// 1D dp ****

int unboundedKnapsack(int W, int n,int val[], int wt[])
{
    // dp[i] is going to store maximum value
    // with knapsack capacity i.
    int dp[W+1];
    memset(dp, 0, sizeof dp);
 
    // Fill dp[] using above recursive formula
    for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
 
    return dp[W];
}
```
## 2.Rod cutting 
same as above
## 3.coin change number of ways (order Not matter)
https://practice.geeksforgeeks.org/problems/coin-change2448/1#
```cpp
// 2d dp
    long long int count( int S[], int m, int n )
    {
       
        //code here.
        long long int d[m+1][n+1];
        for(int i=0;i<=m;i++)d[i][0]=1;
        for(int i=1;i<=n;i++)d[0][i]=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(S[i-1]<=j){
                    d[i][j]= d[i-1][j]+d[i][j-S[i-1]];
                }
                else d[i][j]=d[i-1][j];
            }
        }
        return d[m][n];
    }
// 1 d dp
    long long int count( int S[], int m, int n )
    {
       
        long long  int table[n+1];         
         // Initialize all table values as 0         
         memset(table, 0, sizeof(table));         
         // Base case (If given value is 0)         
         table[0] = 1;         
         // Pick all coins one by one and update the table[] values         
         // after the index greater than or equal to the value of the         
         // picked coin         
         for(int i=0; i<m; i++) // m for coins         
         for(int j=S[i]; j<=n; j++)         
         table[j] += table[j-S[i]];         
         return table[n]; 
    }
```
## 4.Coin change problem: Minimum number of coins
https://practice.geeksforgeeks.org/problems/number-of-coins1824/1#
```cpp
// derive from recursion soution
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int dp[M+1][V+1];
	    for(int i=0;i<=V;i++)dp[0][i]=-1;
	    for(int i=0;i<=M;i++)dp[i][0]=0;
	    
	    for(int i=1;i<=M;i++){
	        for(int j=1;j<=V;j++){
	            if(coins[i-1]<=j){
	                int temp1=dp[i-1][j];
	                int temp2=dp[i][j-coins[i-1]];
	                
	                if(temp1!=-1 && temp2!=-1)dp[i][j]=min(temp1,temp2+1);
	                else if(temp1!=-1)dp[i][j]=temp1;
	                else if(temp2!=-1)dp[i][j]=temp2+1;
	                else dp[i][j]=-1;
	            }else{
	                if(dp[i-1][j]!=-1)dp[i][j]=dp[i-1][j];
	                else dp[i][j]=-1;
	            }
	        }
	    }
	    return dp[M][V];
	} 
// 1D
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
       int dp[V+1];
       dp[0]=0;
       for(int i=1;i<=V;i++)dp[i]=INT_MAX-1;
       for(int i=1;i<=V;i++){
           for(int j=0;j<M;j++){
               if(coins[j]<=i){
                   dp[i]=min(dp[i],dp[i-coins[j]]+1);
               }
           }
       }
       if(dp[V]>=INT_MAX-1)return -1;
       else return dp[V];
	} 
```
# Longest Common Subsequence (LCS)
## 1.Longest Common Subsequence (LCS)
https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#
```cpp
// memomization
    int dp[1001][1001];
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int lcs(int x, int y, string &s1, string &s2)
    {
        // your code here
        if(x==0 || y==0)return 0;
        if(dp[x][y]!=-1)return dp[x][y];
        if(s1[x-1]==s2[y-1])return dp[x][y]= 1+lcs(x-1,y-1,s1,s2);
        else{
            return dp[x][y]=max(lcs(x-1,y,s1,s2),lcs(x,y-1,s1,s2));
        }
    }
// tabulation
    int lcs(int x, int y, string &s1, string &s2)
    {
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]= 1+dp[i-1][j-1];
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }  
            }
        }  
        return dp[x][y];     
    }
```
## 2.Longest Common Substring 
https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
```cpp
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=0;
                }
                
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
```
## 3.Printing Longest common subsequence
```cpp
solve LCS problem 

after that 
i=m,j=n;
string s;
while(i>0 && j>0){
    if(x[i-1]==y[j-1]){
        s=x[i-1]+s;
        i--;j--;
    }
      else if (dp[i-1][j] > dp[i][j-1])
         i--;
      else
         j--;
}
you will get the solution
```
## 4.Shortest Common Supersequence 
```cpp
    int shortestCommonSupersequence(char* X, char* Y, int m, int n)
    {
        //code here
        int dp[m+1][n+1];
         
        for(int i=0;i<=m;i++)dp[i][0]=0;
        for(int i=0;i<=n;i++)dp[0][i]=0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return m-dp[m][n]+n;
    }
```
## 5.Minimum number of deletions and insertions. 
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
```cpp
find lcs 
return |A|-lcs +|b|-lcs;
  |a|-lcs =deletion
  |b|-lcs=insertion
```
## 6.Longest Palindromic Subsequence
Given a sequence, find the length of the longest palindromic subsequence in it.
Example :
Input:"bbbab"
Output:4
```cpp
solve->> Lcs(a,reverse(a));
```
## 7.Minimum number of deletions to make a string palindrome
Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
Examples :

Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string
```cpp
|s|-LPS == |s|-LPS(s,reverse(s));
```
## 8.Print shortest common Supersequence
Given two strings X and Y, print the shortest string that has both X and Y as subsequences. If multiple shortest supersequence exists, print any one of them.

Examples:

Input: X = "AGGTAB",  Y = "GXTXAYB"
Output: "AGXGTXAYB" OR "AGGXTXAYB" 
OR Any string that represents shortest
supersequence of X and Y

Input: X = "HELLO",  Y = "GEEK"
Output: "GEHEKLLO" OR "GHEEKLLO"
OR Any string that represents shortest 
supersequence of X and Y
```cpp
same as printing LCS but also add all other char  while transvering 
refer notes 
```
## 9.Longest repeating subsequence in same string
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
```cpp
// same as LCS BUt i!=j this condtion is extra
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        dp[i][0]=0;
		        dp[0][i]=0;
		    }
		    
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(str[i-1]==str[j-1] && i!=j){
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
		    return dp[n][n];
		}
```
## 10.Sequence Pattern Matching
```cpp
just check |pat| =LCS(S,pat)

or u can also do it by two pointers
```
## 11.Minimum number of insertion in a string to make it a palindrome
https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
```cpp
ans=|s|-LPS(s)
where
LPS(S)=LCS(S,reverse(s));
```

# Matrix chain multiplication (MCM)
```cpp
//general format

int solve(int arr[],int i,int j){
    if(i>j)return 0;

    for(int k=i;k<j;k++){
        int temp_ans= solve(arr,i,k) +/- solve(arr,k,j);
        ans= function(temp_ans);
    }
    return ans;
}
```
## 1.Matrix Chain Multiplication
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
```cpp
// recursive
    int solve(int arr[],int i,int j){
        if(i>=j)return 0;
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
            res=min(temp,res);
        }
        return res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr,1,N-1);
        
    }
//memoization
    int dp[102][102];
    
    int solve(int arr[],int i,int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            int temp=solve(arr,i,k)+solve(arr,k+1,j)+ arr[i-1]*arr[k]*arr[j];
            res=min(temp,res);
        }
        return dp[i][j]=res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
        
    }
```
## 2.Palindrome Partitioning
https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
```cpp
// recursion + memomization
    int dp[501][501];
    bool ispal(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j])return 0;
            i++;j--;
        }
        return 1;
    }
    int solve(string &s,int i,int j){
        
        if(i>=j )return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(ispal(s,i,j))return dp[i][j]=0;
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            int temp= solve(s,i,k)+solve(s,k+1,j)+1;
            
            res=min(res,temp);
        }
        return dp[i][j]=res;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.size()-1);
    }
// some  optimization 
    int solve(string &s,int i,int j){
        
        if(i>=j )return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(ispal(s,i,j))return dp[i][j]=0;
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            // optimisation
            int left,right;
            if(dp[i][k]!=-1) left=dp[i][k];
            else left=dp[i][k] =solve(s,i,k);

            if(dp[k+1][j]!=-1)right=dp[k+1][j];
            else right=dp[k+1][j]=solve(s,K+1,j);
            int temp= left+right+1;
            
            res=min(res,temp);
        }
        return dp[i][j]=res;
    }

// another way
int sol(string &s,int i,int j){
    if(i>=j)return 0;
    
    int ans=INT_MAX;
    for(int k= i+1;k<=j;k++){
        int t;
          if(isp(s,i,k-1)){
            if(isp(s,k,j))return 1;
             else 
             t = 1 + sol(s,k,j); 
          }
        ans=min(ans,t);
    }
    return ans;
}
int palindromePartitioning(string str) {
    // Write your code here
    int i=0;
    int j=str.size()-1;
    if(isp(str,i,j))return 0;
    
    return sol(str,i,j);
}
```
## 3.Evaluate Expression to True Boolean Parenthesization
https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
```cpp
// i =0 j= N-1;
// memomize it with 3d vector or map
int sol(string &s ,int i ,int j , bool istrue){
    if(i>j)return 0;

    if(i==j){
        if(istrue)return s[i]=='T';
        else return s[i]=='F';
    }
    int ans =0;

    for(int k= i+1;i<=j-1;k+=2){
        int lt = sol(s,i,k-1,1);
        int lf =sol(s,i,k-1,0);
        int rt = sol(s,k+1,j,1);
        int rf = sol(s,k+1,j,0);

        if(s[k]=='&'){
            if(istrue){
                ans+= lt*rt;
            }
            else ans +=lt*rf +lf *rt + lf *rf;
        }
        else if(s[k]=='|'){
            if(istrue){
                ans+= lt*rt +lt*rf + lf *rt;
            }
            else ans+= lf * rf;
        }
        else if(s[k]=='^'){
            if(istrue){
                ans+=lf *rt + lt *rf;
            }
            else {
                ans+= lt *rt + lf *rf;
            }
        }
    }
    return ans;
}
```
## 4.Scrambled string Recursive
```cpp
// memoization  use map   map<string,bool>mp;

//key  = a + " "+ b;

bool sol(string a,string b){
    if(a==b)return 1;
    if(a.size()<=1)return 0;

    int n = a.size();
    bool flag  =0;

    for(int i= 1;i<n;i++){
        bool cond1 =  sol(a.substr(0,i),b.substr(n-i,i)) && sol(a.substr(i,n-i),b.substr(0,n-i));
        bool cond2 =  sol(a.substr(0,i),b.substr(0,i)) && sol(a.substr(i,n-i),b.substr(i,n-i));

        if(cond1 || cond2){
            flag =1;
            break;
        }
    }

    return flag;
}

bool scramble(string a,string b){
    if(a.size()!= b.size())return 0;
     
     if(a==b)return 1;

     return sol(a,b);
}
```
## 5. Egg droping problem
```cpp
// memoization 

int solve(int egg,int floor){
    if(floor == 0 || floor ==1)return floor;

    if(egg==1)return floor;

    int ans =INT_MAX;

    for(int k=1;k<=floor;k++){
        int temp = 1+max(solve(egg-1,floor-1),solve(egg,floor-k));

        ans =min(ans,temp);
    }
    return ans;
}
```

# DP on Trees
```cpp
// general format
int solve(root,int & ans){

    if(root==NULL)return 0;

    int l= solve(root->left);
    int r=solve(root->right);
    int temp_ans= fumction(l,r);
    ans= funtion(ans,temp_ans);
    return ans;
}
```

## 1.Diameter of Binary Tree 
https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
```cpp
    int solve(Node *root ,int &ans){
        if(root==NULL)return 0;
        int l=solve(root->left,ans);
       int r = solve(root->right,ans);
       ans=max(ans,l+r+1);
       return max(l,r)+1;
    }
```
## 2.Maximum Path Sum | From any node to any node
https://leetcode.com/problems/binary-tree-maximum-path-sum/
```cpp
 int sum(TreeNode* root, int& res)
    {
        if(root == NULL)
            return 0;
        
        int l = sum(root -> left, res);
        int r = sum(root -> right, res);
        
        int temp = max(max(l, r) + root -> val, root -> val);
        int ans = max(temp, l + r + root -> val);
        res =  max(res, ans);
        
        return temp;
    }
```
## 3.Maximum Path sum | From leaf node to leaf node
```cpp
 int sum(TreeNode* root, int& res)
    {
        if(root == NULL)
            return 0;
        
        int l = sum(root -> left, res);
        int r = sum(root -> right, res);
        
        int temp = max(l, r) + root -> val;
        int ans = max(temp, l + r + root -> val);
        res =  max(res, ans);
        
        return temp;
    }
```