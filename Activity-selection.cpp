#include <bits/stdc++.h>
using namespace std;

struct activity{
    int start;
    int finish;
};

bool cmp(activity a1,activity a2){
    return (a1.finish<a2.finish);
}

void activity_selcetion(activity arr[],int num){
    sort(arr,arr+num,cmp);
    int i=0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";
    for(int j=1; j<num; j++){
        if(arr[j].start>=arr[i].finish){
            cout << "(" << arr[j].start << ", "<< arr[j].finish << "), ";
            i=j;
        }
    }
}

int main(){
    int num;
    while(scanf("%d",&num)==1){
        activity work[num];
        for(int i=0; i<num; i++){
            scanf("%d%d",&work[i].start,&work[i].finish);
        }
        activity_selcetion(work,num);
    }
    return 0;
}

/**6
   5 9
   1 2
   3 4
   0 6
   5 7
   8 9
**/
