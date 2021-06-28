# maths
```cpp
1. (a+b)%c = (a%c+b%c)%c
2. (a*b)%c = ((a%c)*(b%c))%c
3. (a-b)%c = ((a%c)-(b%c)+c)%c  or  
    (a-b)%c = ((a%c)-(b%c))%c  then check if(ans <0) ans+=c;
4. (a/b)%c = ((a%c)?(d%c))%c
In the last property above, d is the multiplicative modulo inverse of b and c.
d= pow(b,c-2)%c  where c should be prime.
```
## isprime
```cpp
bool isprime(int n){
	if(n<=1)return 0;

	for(int i=2;i*i<=n;i++){
		if(n%i)return 0;
	}
	return 1;
}
```
## binary exponential
```cpp
void power(int n,int a){

   int ans=1;
   while(a>0){
	   if((a & 1)){ans*=n;a--;}
	   else {
		   n*=n;
		   a=a>>1;
	   }
   }

   cout<<ans<<endl;
}
```
## gcd euclid
```cpp
// GCD(a,b)= GCD(b,a%b)
// __gcd(a,b)   inbuilt function
// a*b =lcm *gcd
int GCD(int A, int B)
{
	if (B == 0)
		return A;
	else
		return GCD(B, A % B);
}

```
## prime factorisation
```cpp
// O(sqrt(n))  using sieve u can improve time complexity
vector<int> primeFactors(int N){
	vector<int>ans;
	
	for(int i=2;i<=sqrt(N);i++){
		if(N%i==0){
			ans.push_back(i);
		int cnt=0;
		while(N%i==0){
			cnt++;
			N=N/i;
		}
		ans.push_back(cnt);
		}
	}
	if(N>1){
		ans.push_back(N);
		ans.push_back(1);
	}
	
	return ans;
}

//make seive and store element of least prime divisor to that location
int n=1e6;
int arr[n+1];
memset(arr,-1,sizeof(arr));

for(int i=2;i<=n;i++){
	if(arr[i]==-1){
		for(int j=i;j<=n;j++){
			if(arr[j]==-1)arr[j]=i;
		}
	}
}

 int num;cin>>num;
 while(num!=1 ){
	 if(arr[nums]==-1){
		 cout<<nums;break;
	 }
	 cout<<arr[num];
	 num/=arr[num];
 }
```
## sieve 
```cpp
   int n= 101;
   bool arr[n+1]={0};
   arr[0]=arr[1]=1;

   for(int i=2;i*i<=n;i++){
	   if(!arr[i]){
		   for(int j=i*i;j<=n;j+=i){
			   arr[j]=1;
		   }
	   }
   }

   for(int i=0;i<n;i++)
	   if(!arr[i])cout<<i<<" ";

// segmented sieve use sqrt (n) size arr and compute prime in that then it use that prime to generate 
// further numbers 
```
