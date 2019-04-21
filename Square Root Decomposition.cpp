/**
   1. 0 a b c : Here you are required to return the number of elements 
   with indices in [a,b] greater than or equal to c
   2. 1 a b : Here you are required to change the ath element of array to b.
   Technique: Square root Decompositon.
**/

#include "bits/stdc++.h"
using namespace std;

#define MAX 500005

int n;
int Block;
int ar[MAX];
vector<int>chunk[MAX];

int main(){
	scanf("%d",&n);
	Block=sqrt(n);
	for(int i=0; i<n; i++){
		scanf("%d",&ar[i]);
		chunk[i/Block].push_back(ar[i]);
	}
	int totBlock=ceil((double)n/Block);
	for(int i=0; i<totBlock; i++){
		sort(chunk[i].begin(),chunk[i].end());
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int type;
		scanf("%d",&type);
		if(type==1){
			int ind,value;
			scanf("%d %d",&ind,&value);
			ind--;
			int thisBlock=ind/Block;
			int low=0,high=Block;
			int initial = ar[ind];
			while(low<=high){
				int mid= (low+high)/2;
				if(chunk[thisBlock][mid]==initial){
					chunk[thisBlock][mid]=value;
					break;
				}
				else if(chunk[thisBlock][mid]<initial){
					low=mid+1;
				}
				else{
					high=mid-1;
				}
			}
			ar[ind]=value;
			sort(chunk[thisBlock].begin(),chunk[thisBlock].end());
		}
		else{
			int left,right,c;
			scanf("%d %d %d",&left,&right,&c);
			left--;
			right--;
			int leftBlock = left/Block;
			int rightBlock = right/Block;
			int ans = 0;
			if(leftBlock==rightBlock){
				for(int i=left; i<=right; i++){
					if(ar[i]>=c)ans++;
				}
			}
			else{
				int i=left;
				if(left%Block){
					leftBlock++;
				}
				while(i<leftBlock*Block){
					if(ar[i]>=c)ans++;
					i++;
				}
				while(i+Block-1<=right){
					int curBlock = i/Block;
					int ase = chunk[curBlock].end()-lower_bound(chunk[curBlock].begin(),chunk[curBlock].end(),c);
					ans+=ase;
					i+=Block;
				}
				while(i<=right){
					if(ar[i]>=c)ans++;
					i++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
