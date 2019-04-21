/**Cumulative sum technique for 1Dimensional and 2 dimensional**/

#include <bits/stdc++.h>
using namespace std;

int one_dimen(){
    int n;
    scanf("%d",&n);
    int ar[n+10];
    int s[n+10];
    for(int i=1; i<=n; i++){
        scanf("%d",&ar[i]);
    }
    s[0]=0;
    s[1]=ar[1];
    for(int i=2; i<=n; i++){
        s[i]=s[i-1]+ar[i];
    }
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",s[b]-s[a-1]);
}

int two_dimen(){
    int n;
    scanf("%d",&n);
    int ar[n+10][n+10];
    int s[n+10][n+10];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d",&ar[i][j]);
        }
    }
    s[0][0]=0;
    s[1][1]=ar[1][1];
    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+ar[i][j];
        }
    }
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("%d\n",s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1]);
}

int main(){
    two_dimen();
    return 0;
}

/**5
   1 2 4 5 6
   1 2
   3
**/
