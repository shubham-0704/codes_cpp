## string
```cpp
getline(cin, str, 'a'); // a is terminating character
string s;
sizeof(s) //
#include <sstream>
String name = “1234”;
Int a = stoi(name);

Int a = 9876;
Ostringstream s;
S<<a;
String b;
B=s.str();

// supports all mazor vector functions
to_string(int value) for converting int into string
(ariable type)var  to type cast int in  char;
Str.size()  // for size of string;
s1.substr(6, 5) //use part of string pos and len
str.append()// add srinf
str.insert(3,”string”)
str.erase(3,1)
str.pop_back();
str.replace(0,4,”string”)
str.find(“string”)
str.find_first_of(“aeiou”)// str.find_first_of(“aeiou”,start_pos);
str.back();
```

> char can act as int in array
```cpp
int arr[256]={0};
arr['a']=23;
```

#### substring --> continous
#### subsequence --> order matter
#### subset -->order not matter 


## 1.left most repeating character
```cpp
//methof 1
const int CHAR=256;
{
    int fIndex[CHAR]={0};
    fill(fIndex,fIndex+CHAR,-1);
    int res=INT_MAX;
    for(int i=0;i<str.length();i++){
        int fi=fIndex[str[i]];
        if(fi==-1)
        fIndex[str[i]]=i;
        else
        res=min(res,fi);
    }
    
    return (res==INT_MAX)?-1:res;
}

//method 2
int leftMost(string &str) 
{
    bool visited[CHAR];
    fill(visited,visited+CHAR,false);
    int res=-1;
    for(int i=str.length()-1;i>=0;i--){
        if(visited[str[i]])
        res=i;
        else
        visited[str[i]]=true;
    }
    
    return res;
}
 
int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost repeating character:"<<endl;
    cout<<leftMost(str)<<endl;  
    
    return 0; 
}
```
## 2. left most non repeating character
```cpp
const int CHAR=256;
int nonRep(string &str) 
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    
    for(int i=0;i<str.length();i++){
        if(fI[str[i]]==-1)
        fI[str[i]]=i;
        else
        fI[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fI[i]>=0)res=min(res,fI[i]);
    }
    return (res==INT_MAX)?-1:res;
}
```

## 3. pattern search
```cpp
naive or brute force O9=(nm)  O((n-m+1)m)

but distinct elemnt is present in pattern  then it can 0(n) worst case O((n-m+1)m)
```

## 4. Rabin Karp Algorithm (search algo)
use hashed value to check if it matces then only it check for match;
```cpp
void rb(string p,string text){
    int hasp=0;
    // creating hash of pattern search you can create any type  of hash 
    //here we use ascii sum of pattter u can also use  summation  of  pattern[i]*d^i
    // this will improve the time complexity
    for(int i=0;i<p.size();i++)hasp+=p[i]; 
    int j=p.size()+1;
    int window=0;
    for(int i=0;i<p.size();i++)window+=text[i];

    for(int i=0;i<text.size()-p.size()+1;i++){
        if(window==hasp){
            if(p==text.substr(i,p.size()))cout<<i<<" "<<j-1<<endl;
        }
        window+=text[j]-text[i];
        j++;
    }
}

int main(){
    string txt = "GEEKS FOR GEEKS";string pat="GEEK";
    cout<<"All index numbers where pattern found:"<<" ";
    rb(pat,txt);
}
```
## 5 kmp search
```cpp
// preproccesing
// lps in o(n^3)  longest proper prefix suffix
int lps(int arr[],int pos,int n,string s){
   if(pos==0)return 0;
   int l= pos;
   while(pos){
       // if use own implementaion for comapring subsritng it will be for efficent
       if(s.substr(0,pos)==s.substr(l-pos+1,pos))return pos;
       pos--;
   }
  return 0;
}
int main(){
  string s;cin>>s;
  int n=s.size();
  int arr[n];
  for(int i=0;i<n;i++){
      arr[i]=lps(arr,i,n,s);
  }
}


//o(n) LPS

int main(){
  string s="abcaby"; //pattern
  string text="abxabcabcaby";
  int n=s.size();
  int arr[n];
  arr[0]=0;

  int i=1,j=0; // j shows lenght of longest prefix and suffix
  while(i<n){
      if(s[i]==s[j]){
          arr[i]=j+1;
          i++;j++;
      }
      else{
          if(!j)arr[i++]=0;
          else{
              j=arr[j-1];
          }
      }
  }
  for(auto i:arr)cout<<i<<" ";// Lps

  //search

 i=0,j=0;
  while(i<text.size()){
            if(s[j]==text[i]){i++;j++;}

        if (j == n) { 
            printf("Found pattern at index %d ", i - j); 
            j = arr[j - 1]; 
        } 
        else if (i < text.size() && s[j] != text[i]) { 
            if (j == 0) 
                i++;
            else
                j = arr[j - 1];  
        }
  }

}
```

## 6.Given a string, we need to find lexicographic rank of a string
```cpp
//not repetition of characters
int lexRank(string &str) 
{ 
    int res = 1; 
    int n=str.length();
    int mul= fact(n);
    int count[CHAR]={0};
    for(int i=0;i<n;i++)
        count[str[i]]++;
    for(int i=1;i<CHAR;i++)
        count[i]+=count[i-1];
    for(int i=0;i<n-1;i++){
        mul=mul/(n-i);
        res=res+count[str[i]-1]*mul;
        for(int j=str[i];j<CHAR;j++)
            count[j]--;
    }
    return res; 
}
```

