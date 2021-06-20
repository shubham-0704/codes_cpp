# algorithm analysis


1) Θ Notation: Average case
2) Big O Notation:  worst case -- upper bound
3) Ω Notation: best case   -- lower bound

binary search 
* n n/2 n/4 ... 1 
*  we can write n/2^k  k is no of times
```
=> n/2^k >=1
=> n>=2^k
=> log(n) >= log(2^k) == k log(2)
=> k <= log(n)
``` 