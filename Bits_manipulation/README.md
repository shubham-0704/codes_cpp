# Bit manipulation
```cpp
a^0= a;
a^a=0;

//bit masking

a= a & (~a+1); // this create rightmost set bit as 1 and rest zeero

~ a  = 1's complement
~a+1 = 2's complement
```
https://www.youtube.com/watch?v=QZzH7ZTksKk

## way to count set bits
```cpp
__builtin_popcount();
__builtin_popcountll();

while(n){
    if(n &1)cnt++;
    n=n>>1;
}
while(n){         // when we subtrat 1 from n
    cnt++;        //  then right side of right most 1 become all one
    n=n & (n-1)
    /* n=12 = 1100
       n=n-1 =11  = 1011
    */
}

//for 0 to n 
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for ( int i = 1; i <= num; i++ ) {
            // dp[i] = dp[i/2] + i % 2; this is also correct
            dp[i] = dp[i&(i-1)] + 1;  
//  i&(i-1) drops the lowest set bit. For example: i = 14, its binary representation is 1110, so i-1 is 1101, i&(i-1) = 1100, the number of "1" in its binary representation decrease one, so ret[i] = ret[i&(i-1)] + 1.            
        }
        return dp;
    }
```
## MSB in O(1)
```cpp 
    n = n | n >> 1;
    n = n | n >> 2;
    n = n | n >> 4;
    n = n | n >> 8;
    n = n | n >> 16;
    n = n + 1;
    return (n >> 1);
```
## generate power set of string
```cpp
// can be done easly with reursion

// using bit manipultion
		void AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    int n=s.size();
		    int temp= pow(2,n)-1;
		   string t1="";
		   
	   for(int i=1;i<=temp;i++){
		       t1="";
		       for(int j=0;j<n;j++){
		          if((i & (1<<j)))t1=t1+s[j];
		      }
		      cout<<t1<<endl;
		   }
		}
```

## power of 2
```cpp
// count set bit ==1 

// another way  n & (n-1)== 0 then power of two
```
## square of number without operator or power function
```cpp
// 5 * 5 == 5 * ( 1.2^2 + 0.2^1 + 1.2^0)
    int n;cin>>n;
    int t1=n;
    int ans=0;
    int cnt=0;
    while(n){
        if(n & 1){
            ans+=(t1<<cnt);
        }

        cnt++;
        n=n>>1;

    }
    cout<<ans<<endl;
```

## xor qeries 
```cpp
// find xor like prefix sum same prefix xor 
// for any query like l r  return arr[r]^arr[l-1];
eg 1 2 3 5 6 8
 a^a =0 so if we need  from l to r then taking xor with arr[l-1]
 will make value of 0 to l-1 xor =0
```
## All Pair Sum XOR
```cpp
arr { 1 7 2 4};
find xor of all pair sum eg  (1+1)^(1^7)...(2+4)^(4+4);
// all pairs with i!=j will be cancel out only i==jterm wil remain
```
## Total Sum of all Pair XOR
```cpp
 arr : [a1 a2 a3 a4]
 (a1^a2)+(a1^a3)+(a1^a4)+
        + (a2^a3)+(a2^a4)+
                 + (a3^a4)
for(int i=0;i<32;i++){
    int cnt_zero=0,cnt_one=0;
    for(int j=0;i<n;j++)
    {
        if(arr[j] & (1<<i)) cnt_one++;
        else cnt_zero++;
    }
    int p= cnt_zero*cnt_one;
    res+=p* pow(2,i);
}

```
## no of bits to flip to make a to b
```cpp
count set bits in (a^b);
```

## single number II
```cpp
// array contain all elemnts two times except one number which is one time
take xor of all elemnts  A^A=0 all two time will become zero and B^0=B number will be found

// 2nd question 
// all number appera 3 times except one that is one time
let x is solution 
f[i] number of elemnts with ith bits set
f[i] if ith bit set in solution then f[i] it will in form of 3n + 1
find modulo by 3 and get the number
```

##  AND Product of all value in range a to b
```cpp
// observation ith bit have 2^i consecutive 1's or 0's
    int gap=b-a+1;
    int t=2;
    int ans=0;
    for(int i=0;i<32;i++){
        if(gap>=t);
        else if( (a & (1<<i)) & (a & (1<<i))  )ans+=(1<<i);

        t+=pow(2,i);
    }
    cout<<ans<<endl;
// we can use pow(2,i) in place of t
gap > pow(2,i); and t increent is not needed;

```

## count total set bits from 1 to n
```cpp
    int countSetBits(int n=4)
    {
        // Your logic here
        int ans=0;
        int n1=log2(n)+1;
        n++;
        for(int i=0;i<n1;i++){
            int temp= n/(1<<(i+1));
            ans+=(temp*(1<<i));  
			int temp1=(n%(1<<(i+1)));
             if(temp1>((1<<(i))))
            ans+=temp1-(1<<(i));
        }
        return ans;
    }
```
## Non Repeating Numbers 
```cpp
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x =0;
        for(auto i:nums)x^=i;
        
        int mask = x & (~x+1);
        for(int i=0;i<nums.size();i++){
            if((nums[i] & mask))nums[i]=-nums[i];
        }
        int ans1=0;
        int ans2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)ans1=(ans1 ^ abs(nums[i]));
            else ans2^=nums[i];
        }
        
        if(ans2<ans1)swap(ans1,ans2);
        return {ans1,ans2};
    }
```

## divide number without operator
https://www.youtube.com/watch?v=htX69j1jf5U
```cpp
void solve(int n ,int a){
	if(a==0){cout<<"invalid\n";return;}
    
	int sign = (a<0) ^ (n<0);

	n=abs(n);a=abs(a);

	int ans=0;
    int temp=a;
	int i=0;
	while(n>=a){
		while((temp<<i) <= n){
		    i++;
		}
		i--;
		ans+= (1<<i);
        n=n-(temp<<i) ;
		i=0;
	}
// take care of sign 
   cout<< ans<<endl;

}
```

> source : code N code Youtbe channel
