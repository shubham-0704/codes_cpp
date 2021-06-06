```cpp
//header file
#include<bits/stdc++.h>
#include<iostream>
#define f(i,a,n) for(int i=a;i<n;i++)
typedef long long ll;
typedef vector<int> v;
using namespace std;
```
```cpp
srand(time(NULL))
int var=rand()%10;

Cout<<setprecision(2);
Cout<<fixed<<setprecision(2)

Escape sequence = \n,\t,\a,\0;
sizeof()// size in bytes
```

```cpp
int main(){
	abs() 
	ternary operator   sattemt ? true satament : false satament;
	remainder(a,b) -> for floating points also
     fmin(),fmax(),max(),min(),swap()
	getline(cin,variable);   
return 0;
}


void explainExtra() {

	int num = 7; // 111 
	int cnt = __builtin_popcount(); 

	long long num = 165786578687;
	int cnt = __builtin_popcountll();


	string s = "123"; 

	do {
		cout << s << endl; 
	} while(next_permutation(s.begin(), s.end())); 

	// 123
	// 132
	// 213
	// 231
	// 312
	// 321

	int maxi = *max_element(a,a+n); 
}
```
## struct 
```cpp
class student{
 public: // access specifier--> private & protected(by default private)
  string name;
  int age;
  ..
  ..
};
Class -----object  process is called instantiation


struct student{
 public: // access specifier--> private & protected (optional usually not there by deaflt public)
  string name;
  int age;
  ..
  ..
//You can put here function
 String show(){
   Return age;}
};

int main(){

student stu1;
stu1.age=20; 
stu1.name="";}
cout<<stu1.show();
also put value by student s1={20,”shubham”}

you can pass whole struct object to a function
eg:
struct Rect{
    int l;
    int b;
};
void area(Rect a){
    cout<<a.l*a.b;
}
int main()
{
    Rect r;
    r.l=20;
    r.b=2;
    
    area(r);

    return 0;
}
```

```cpp
// pointers
int *ptr;

value == *ptr;

FUNCTION OVERLOADING
same name of function but differnet argument
e.g
int area(int a,int b){}
int area(int a){} 

default argument
declaring value for defult conditions

int add(int a,int b,int c=0;int d=0,int e=0){}
 
INLINE FUNCTION 
--reduce time of excution
 inline int add(int x,int y){}



constructor and destructor

same name as class for con..
same name but with ~ for destr..
    

#include <algorithm>
Sort(v.begin(),v.end());
Reverse(v.begin(),v.end());
And for array use array as pointer



freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
Upper_bound();
Lower_bound();
Auto i=Equal_range();-->i.first,i.second;

string a = "hatti"; string b = a+a; cout << b << "\n"; // hattihatti b[5] = ’v’; cout << b << "\n"; // hattivatti string c = b.substr(3,4); cout << c << "\n"; // tiva

use power function always with nearbyint() – because while converting the double into int errors came into picture

fileopening process writing a file
#include<fstream>
  ofstream file;
    file.open("text.txt",ios::app);
    string s="aloo os gd for sports\n";
    file<<s;
cout<<file.is_open();
    file.close();
readind a file
#include<fstream>
#include <iostream>
using namespace std;
int main()
{
  ifstream file;
    file.open("text.txt");
    string input;
   std::vector<string> s ;
    while(file>>input){
        s.push_back(input);
    }
    
    //for taking as line as input
    string line;
    getline(file,line)
     for(auto i:s)cout<<i<<endl;
     file.close();
    return 0;
}

For making  many file and running 
//all decalrtion shoud be haere
//mathn.h
#ifndef maal
#define maal
int power(int a,int b);
#endif

// al definton shoudl be here 
//mathn.cpp
#include"mathn.h"
int power(int a,int b){
    int result=1;
    while(b--){
        result*=a;
    }
    return result;
}

// main code to run all the things
//main.cpp
#include <iostream>
#include<vector>
#include "mathn.h"
using namespace std;
int main(){
    int n=3;
    int m=3;
    
    cout<<power(n,m);
}

Namespace varname{
  Int mul(){}
}
//in main code 
Varname::mul();

Template : for function and class
Alterantive for function overloading 
template<typename T>
void swap(T &a,T&b){ T temp=x;}here we doesn’t define data type but a template
```