#include "bits/stdc++.h"
using namespace std;


#define MX 100005

int Rank[MX],tempRank[MX];
int SA[MX],tempSA[MX];
int freq[MX];
int n;

int phi[MX],PLCP[MX],LCP[MX];

string s,a,b,c;

void countingSort(int k){
    memset(freq,0,sizeof(freq));
    for(int i=0; i<n; i++){ //Count the freq of each integer rank
        if(i+k<n)freq[Rank[i+k]]++;
        else freq[0]++;
    }
    int sum = 0 , mxASCII = max(300,n); // Store the current frequency
    for(int i=0; i<mxASCII; i++){
        int temp = freq[i];
        freq[i]=sum;        //Store the starting index
        sum += temp;
    }

    for(int i=0; i<n; i++){
        if(SA[i]+k<n){
            tempSA[freq[Rank[SA[i]+k]]++] = SA[i];
        }
        else{
            tempSA[freq[0]++] = SA[i];
        }
    }
    for(int i=0; i<n; i++){    //Store the SA from the tempSA
        SA[i] = tempSA[i];
    }
}

void suffixArray(){
    s = a + b + c ; //Add extra $ for sorting purpose
    n = s.size();

    for(int i=0; i<n; i++)Rank[i]=(int)(s[i]-'!'); //Initial rank for all index
    for(int i=0; i<n; i++)SA[i]=i;            //Position of suffixes
    for(int k=1; k<n; k<<=1){                 //Loop goes in log(n) times
        countingSort(k);                       //Sorting according to second item
        countingSort(0);                      //Sorting according to first item

        tempRank[SA[0]]=0;                    //Give rank 0 for first suffix
        int r = 0;                            //Current Rank
        for(int i=1; i<n; i++){
            if(Rank[SA[i]] == Rank[SA[i-1]] && Rank[SA[i]+k] == Rank[SA[i-1]+k]){ //If the rank same then give to same rank
                tempRank[SA[i]] = r;
            }
            else{
                tempRank[SA[i]] = ++r;
            }
        }
        for(int i=0; i<n; i++){ //Update the rank with RA
            Rank[i]=tempRank[i];
        }
        if(Rank[SA[n-1]] == n-1)break; //Nice optimization trick
    }
}


void find_LCP(){
    phi[SA[0]]=-1; //No suffix before SA[0]
    for(int i=1; i<n; i++){
        phi[SA[i]] = SA[i-1]; //Store the index of previous suffix in phi array
    }
    int L=0;
    for(int i=0; i<n; i++){
        if(phi[i] == -1){   //No suffix before and its the first suffix
            PLCP[i]=0;
            continue;
        }
        while(s[i+L] == s[phi[i]+L])L++;
        PLCP[i]=L;
        L=max(L-1,0);
    }
    for(int i=0; i<n; i++){
        LCP[i]=PLCP[SA[i]];
    }
}

/*

3
aladdin

adding

dinner
WTF
2 0 addinaddingdinner
7 5 addingdinner
0 1 aladdinaddingdinner
3 0 ddinaddingdinner
8 4 ddingdinner
4 1 dinaddingdinner
9 3 dingdinner
13 3 dinner
17 0 er
12 0 gdinner
5 0 inaddingdinner
10 2 ingdinner
14 2 inner
1 0 laddinaddingdinner
6 0 naddingdinner
16 1 ner
11 1 ngdinner
15 1 nner
18 0 r

math

magic

matters
WTF
5 0 agicmatters
1 1 athmagicmatters
10 2 atters
8 0 cmatters
13 0 ers
6 0 gicmatters
3 0 hmagicmatters
7 0 icmatters
4 0 magicmatters
0 2 mathmagicmatters
9 3 matters
14 0 rs
15 0 s
12 0 ters
2 1 thmagicmatters
11 1 tters

*/


int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){

        cin>>a>>b>>c;
        suffixArray();
        find_LCP();

//        cout<<"WTF"<<endl;
//        for(int i=0; i<n; i++){
//            cout<<SA[i]<<" "<<LCP[i]<<" "<<s.substr(SA[i],n-SA[i]+1)<<endl;
//        }

        int ans = 0;
        int fsuru = 0 , fses = a.size()-1;
        int ssuru = a.size() , sses = a.size()+b.size()-1;
        int tsuru = a.size()+b.size() , tses = a.size()+b.size()+c.size()-1;

        for(int i=1; i<n-1; i++){
            if(SA[i]>=fsuru && SA[i]<=fses){
                if(SA[i-1]>=ssuru && SA[i-1]<=sses && SA[i+1]>=tsuru && SA[i+1]<=tses){
                    ans = max(ans, min(LCP[i],LCP[i+1]) );
                }
                else if(SA[i-1]>=tsuru && SA[i-1]<=tses && SA[i+1]>=ssuru && SA[i+1]<=sses){
                    ans = max(ans , min(LCP[i],LCP[i+1]) );
                }
            }
            else if(SA[i]>=ssuru && SA[i]<=sses){
                if(SA[i-1]>=fsuru && SA[i-1]<=fses && SA[i+1]>=tsuru && SA[i+1]<=tses){
                    ans = max(ans, min(LCP[i],LCP[i+1]));
                }
                else if(SA[i-1]>=tsuru && SA[i-1]<=tses && SA[i+1]>=fsuru && SA[i+1]<=fses){
                    ans = max(ans, min(LCP[i],LCP[i+1]) );
                }
            }
            else{
                if(SA[i-1]>=fsuru && SA[i-1]<=fses && SA[i+1]>=ssuru && SA[i+1]<=sses){
                    ans = max(ans, min(LCP[i],LCP[i+1]) );
                }
                else if(SA[i-1]>=ssuru && SA[i-1]<=sses && SA[i+1]>=fsuru && SA[i+1]<=fses){
                    ans = max(ans, min(LCP[i],LCP[i+1]));
                }
            }
        }

        printf("Case %d: %d\n",cs++,ans);

    }
    return 0;
}

