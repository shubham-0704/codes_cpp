# Bactracking

## 1.rat in maze
```cpp
    int vist[6][6];
    bool issafe(int i,int j,vector<vector<int>> &m,int n){
        if(i<n && j<n && i>-1 && j>-1 && m[i][j]==1 && vist[i][j]==0 )return 1;
        return 0;
    }
    void solve(vector<vector<int>> &m,int n,vector<string>&ans,string op,int i,int j){
        if(i==n-1 && j==n-1){
            ans.push_back(op);return ;
        }
        if(issafe(i,j,m,n)){
            vist[i][j]=1;
            
            solve(m,n,ans,op+'D',i+1,j);
            solve(m,n,ans,op+'R',i,j+1);
            solve(m,n,ans,op+'U',i-1,j);
            solve(m,n,ans,op+'L',i,j-1);
            
            vist[i][j]=0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++)vist[i][j]=0;
        }
        vector<string>ans;
        if(m[0][0]==0 || m[n-1][n-1]==0)return ans;
        
        solve(m,n,ans,"",0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
```
## 2.N- queen problem
```cpp
#include <bits/stdc++.h>
using namespace std;

#define N 4 
  
int board[N][N];  
  
bool isSafe(int row, int col) 
{ 
  
    for (int i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  
bool solveRec(int col) 
{ 
    if (col == N) 
        return true; 
  
    for (int i = 0; i < N; i++) { 
     
        if (isSafe(i, col)) { 
            board[i][col] = 1; 
  
            if (solveRec(col + 1)) 
                return true; 
  
            board[i][col] = 0;
        } 
    } 
  
    return false; 
} 
  
bool solve() 
{
    if (solveRec(0) == false) { 
        printf("Solution does not exist"); 
        return false; 
    } 
  
    printSolution(board); 
    return true; 
}


```
## 3.sudoku
```cpp
bool safe(int grid[N][N],int i,int j,int n){
       for(int p=0;p<N;p++){
           if(grid[p][j]==n){
            return 0;
           }
       }
          for(int p=0;p<N;p++){
           if(grid[i][p]==n){
            return 0;
           }
       } 
      
          int ti,tj;ti=i/3;tj=j/3;
          for(int p=3*ti;p<3*ti+3;p++){
              for(int q=3*tj;q<3*tj+3;q++){
                  if(grid[p][q]==n){
                    return 0;
                  }
                   
              }
          }
      return 1; 
}
bool SolveSudoku(int grid[N][N])  
{  int i,j;
    int flag=0;
    for( i=0;i<N;i++){
       for( j=0;j<N;j++){
          if(grid[i][j]==0){flag=1;break;}
       }if(flag)break;
   }
   if(i==N && j==N)return 1;
   else{
       for(int n=1;n<10;n++){
                     
            if(safe(grid,i,j,n)){
                grid[i][j]=n;
                if(SolveSudoku(grid))return 1;
                else 
                grid[i][j]=0;
            }
            
       }return 0;
   }
}
```