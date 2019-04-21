#include <bits/stdc++.h>
using namespace std;

/**Binary search: For finding an element in sorted array
   Lower-bound:   Find an element X in a sorted array of intergers such that X>=K, where key K is given.
   Upper-bound:   Find an element X in a sorted array of intergers such that X>K, where key K is given.
**/

int binary(int input[],int n,int num){
    int lo=1;
    int hi=n;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(input[mid]==num){
            return mid;  // a match is found
        }
        else if(input[mid]<num){  // if middle element is less than the key
            lo=mid+1;  // key will be right part if it exists
        }
        else{
            hi=mid-1;   // otherwise key will be in left part if it exists
        }
    }
    return -1;
}


int lower_bou(int input[],int n,int k){
    int lo=1;
    int hi=n;
    int mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(input[mid]>=k&&(mid==1||input[mid-1]<k)){
            return mid;  // checking conditions for lowerbound
        }
        else if(input[mid]>=k){  // answer should be in left part
            hi=mid-1;  // answer should be in left part
        }
        else{
            lo=mid+1;    // answer should in right part if it exists
        }
    }
    return mid;  // this will execute when there is no element in the given array which >= K
}

int upper_bou(int input[],int n,int k){
    int lo=1;
    int hi=n;
    int mid;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(input[mid]>k&&(mid==1||input[mid-1]<k)){
            return mid;  // checking conditions for lowerbound
        }
        else if(input[mid]>=k){  // answer should be in left part
            hi=mid-1;  // answer should be in left part
        }
        else{
            lo=mid+1;    // answer should in right part if it exists
        }
    }
    return mid;  // this will execute when there is no element in the given array which >= K
}




int main(){
    int n;
    cin>>n;
    int ar[n+10];
    for(int i=1; i<=n; i++){
        cin>>ar[i];
    }
    return 0;
}
