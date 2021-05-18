#include <iostream>
#include <bits/stdc++.h>

using namespace std;

-----------------------------
//print 1 to n 
void print1_n(int n){
    if (n<=0) return;
    print1_n(n-1);
    cout<<n<<" ";
}
----------------------------
// print n to 1
void printn_1(int n){
    if(n<=0)return ;
    cout<<n<<" ";
    printn_1(n-1);
}

----------------------------
// factorial n
int solve(int n){
    if(n==1)return 1;

    return n*solve(n-1);
}

-----------------------------
// height of tree
int solve(node *root){
    if(root==NULL)return 0;

    return 1 + max(solve(root->left),solve(root->right));
}

-------------------------------
// sorting array recursively
void  solve(int a[],int n){  
    if(n<=1)return;
    solve(a,n-1);
    for(int i=0;i<n-1;i++){
        if(a[n-1]>=a[n-2])break;
        if(a[i]>a[n-1])swap(a[i],a[n-1]);
    }

}

//method 2
void sort(vector<int> & v){
    if(v.size()<=1)return ;

    int temp = v.[v.size()-1]; //v.back()
    v.pop_back();
    sort(v);
    insert(v,temp);
}

void insert(vactor<int> &v ,int temp){
    if(v.size()==0 || v.back()<=temp){
        v.push_back(temp);
        return;
    }

    int val= v.back();
    v.pop_back();

    insert(v,temp);
    v.push_back(val);
    return;
}

---------------------------------------
// sorting stack 
void insert(stack<int>& s,int temp){

    if(s.size()==0 || s.top()<=temp){
        s.push(temp);
        return;
    }
    int temp2= s.top();
    s.pop();
    insert(s,temp);
    s.push(temp2);
}

void  solve(stack<int> &s){
   
  if(s.size()<=1)return;
  int temp= s.top();
  s.pop();
  solve(s);

  insert(s,temp);
  return;
}

----------------------------------------
// reverse the stack 

void insert(stack<int>&s,int temp){
    if(s.size()==0){
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);

}
void solve(stack<int>& s){

    if(s.size()<=1)return;
    int temp =s.top();s.pop();
    solve(s);
    insert(s,temp);
}
----------------------------------------
// for deleting middle element from stack 
void solve(stack<int>& s,int size){
    if(s.size()==0)return;
    if(size<=1){
        s.pop();
        return;
    }
    int temp =s.top();s.pop();
    solve(s,size-2);
    s.push(temp);
}

----------------------------------------
// kth symbol of grammer  leetcode 
// link https://leetcode.com/problems/k-th-symbol-in-grammar/

int solve(int n,int k){
 
 if(n==1 && k==1)return 0;
 if(k%2==0) return !solve(n-1,(k+1)/2);
 else return solve(n-1,(k+1)/2); 
}


----------------------------------------------
// tower of hanoi
long long toh(int N, int from, int to, int aux) { 
    if(N==1){
        cout <<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        return 1;
    }
    
    long long temp = toh(N-1,from,aux,to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    return temp +1+ toh(N-1,aux,to,from);   
    
}
-----------------------------------------------------
// all subset of string 

void solve(string s,string op){
  if(s.size()==0){
      cout<<"otput :"<<op<<endl;
      return ;}
  char temp= s.back();
  s.pop_back();
  solve(s,op);
  solve(s,temp+op);
 
}
// you can do in this way also 
void solve(string inp,string op){
    if(inp.size()==0){
        cout<<op<<endl;
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(inp[0]);
    inp.erase(inp.begin()+0);
    solve(inp,op1);
    solve(inp,op2);
 
}
--------------------------------------------------
//unique subset of string

void solve(string inp,string op,unordered_set<string>&ans){
  if(inp.size()==0){
      ans.insert(op);
      return;
  }

  char temp= inp.back();
  inp.pop_back();

  solve(inp,op,ans);
  solve(inp,temp+op,ans);
  
 
}

--------------------------------------------------
// permuation of spaces in string 
// eg abc  o/p :  a bc,ab c,a b c,abc
void solve(string inp,string op){
  if(inp.size()==1 ){
      cout<<op+inp<<endl;
      return;
  }
  
  char temp= inp[0];
  inp.erase(inp.begin()+0);
  solve(inp,op+temp);
  solve(inp,op+temp+" ");
}
---------------------------------------------------
//permuation with case chnage 
// eg i/p ab o/p  ab,Ab,aB,AB
// only small case alphabet
void solve(string inp,string op){
if(!inp.size()){
    cout<<op<<endl;
    return;
}
char temp= inp.back();
inp.pop_back();
solve(inp,temp+op);
solve(inp,(char)toupper(temp)+op);
 
}

// same code form starting 
void solve(string inp,string op){
if(!inp.size()){
    cout<<op<<endl;
    return;
}
char temp= inp[0];
inp.erase(inp.begin()+0);
solve(inp,op+temp);
solve(inp,op+(char)toupper(temp));
 
}
---------------------------------------------------
//letter case permuation 
//eg i/p a1B2 o/p : a1b2,A1b2,a1B2,A1B2
void solve(string inp,string op){
    if(!inp.size()){
        cout<<op<<endl;
        return;
    }
    if(isalpha(inp[0])){
    char temp= inp[0];
    inp.erase(inp.begin()+0);
    solve(inp,op+(char)tolower(temp));
    solve(inp,op+(char)toupper(temp));
    }
    else {
        op.push_back(inp[0]);
        inp.erase(inp.begin()+0);
        solve(inp,op);
    }
}
---------------------------------------------------
//generate all balanced  parenthesisi of length n
void solve(int n,int op,int cl,string ans){
    // if n= 6 then op cl =3
  if(n==0){
      cout<<ans<<endl;
      return;
  }

  if(op==cl){
      solve(n-1,op-1,cl,ans+"(");
  }
  else{
    if(op==0){
      solve(n-1,0,cl-1,ans+")");
    }
    else{
          solve(n-1,op-1,cl,ans+"(");
    solve(n-1,op,cl-1,ans+")");
    }

  }

}

// method 2
void solve(int open ,int close ,string op,vector<string> &v){
    if(open ==0 && close ==0){
        v.push_back(op);return;
    }
    if(open!=0){
        solve(open-1,close,op+"(",v);
    }
    if(close>open)solve(open,close-1,op+")",v);
}
---------------------------------------------------
//print n digit binary number such that # 1's is greater than  or equal 0's
// in all the prefixes
void solve(int one ,int zero ,int n,string ans){
  if(n==0){
    cout<<ans<<endl;return ;
  }
  
  if(one-zero>=1){
    solve(one+1,zero,n-1,ans+"1");
    solve(one,zero+1,n-1,ans+"0");
  }
  else {
    solve(one+1,zero,n-1,ans+"1");
  }
}

// method 2
void solve(int one  ,int zero ,int n,int op){
    if (n==0){
        cout<<op<<endl; return ;
    }
    solve(one+1,zero,n-1,op+"1");
    if(one>zero)solve(one, zero+1,n-1,op+"0");
}
---------------------------------------------------
//josephus problem
int solve(int n,int k,vector<int>&v,int index){
  if(v.size()==1)return v[0];

  index= (index+k-1)%v.size();
  v.erase(v.begin()+index);
  return solve(n-1,k,v,index);

}
// efficient approach
//  in this we use recurison by shifting  the position 
/*let n=5 k= 3;
   a b c d e   1st round  c wil die 
   0 1 2 3 4

   a b d e  -->  also written as d e a b  we shift to make equation j(n,k)= j(n-1,k)+k
   0 1 3 4        added + k to componesate for the shift 

   d e a b  -->  (0+3)%5=3 which gives postion of d in prevoius order  
   0 1 2 3 

   link for understanding https://www.youtube.com/watch?v=9ovJVBsZPyU

   j(n,k)=(j(n-1,k)+k)%n
*/

int solve(int n,int k){
    if(n==1)return 0;
    
    return (solve(n-1,k)+k)%n;
}

// iterative solution 
    int solve(int n, int k) {
       int ans=0;
       for(int i=2;i<=n;i++){
           ans=(ans+k)%i;
           
       }
       return ans+1;
    }

int main()
{

    return 0;
}