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