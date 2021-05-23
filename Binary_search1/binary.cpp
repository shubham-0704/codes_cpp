#include <iostream>
#include<bits/stdc++.h>

using namespace std;


// binary search 

//recursive 
int solve(int a[],int start,int end ,int comp){

   if (start>end)return -1;
   int mid = (end-start)/2 + start;

   if(a[mid]==comp)return mid;
   else if (a[mid]>comp){
       end=mid-1;
   }
   else {
       start =mid +1;
   }
   return solve(a,start,end,comp);
}

//iterative approch
int solve(int a[],int start,int end ,int comp){

   while(start<=end){
   int mid = (end-start)/2 + start;
   if(a[mid]==comp)return mid;
      else if (a[mid]>comp){
       end=mid-1;
   }
   else {
       start =mid +1;
   }
   }
   return -1;
}
------------------------------------------------
// 1st occurence eg 1,2,3,3,4,4,4,5,6  1st 4 comes at 4th position

int solve(int a[],int start,int end ,int comp){

   int oc1=-1;
   int oc_last= -1;

   while(start<=end){
   int mid = (end-start)/2 + start;
   if(a[mid]==comp){
       oc1= mid;
       end=mid-1;
       }
      else if (a[mid]>comp){
       end=mid-1;
   }
   else {
       start =mid +1;
   }
   }
   return oc1;
}

------------------------------------------------
// how many times a sorted array is rotated 