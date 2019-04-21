#include <algorithm>
#include <utility>
#include <vector>
#include <stdio.h>
using namespace std;

//we will put weight in the first place
//and price in the second place

typedef pair<int,int>PII;
vector<PII>V;

bool cmp(PII A,PII B)
{
    //we want to order on decreasing order of price/weight
    //So: return A.price/A.weight>B.price/B.weight
    return A.second*B.first>A.first*B.second;
}

void fractional_knapsack()
{
    int n,w;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int weight,price;
        scanf("%d%d",&weight,&price);
        V.push_back(PII(weight,price));
    }
    sort(V.begin(),V.end(),cmp);
    scanf("%d",&w);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        //w is remaining capacity
        //V[i].first is weight of i'th element
        //so we steal minimum of them
        int z=min(w,V[i].first);
        w-=z;
        ans+=z*V[i].second;
    }
    printf("Maximum cost: %d\n",ans);
}

int main()
{
    fractional_knapsack();
    return 0;
}
