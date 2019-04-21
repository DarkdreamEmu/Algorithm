/***************************************************DarkdreamOFmy**********************************************************/
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <assert.h>
#include <time.h>
#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef                                     long int li;
typedef                                     long long int lli;
typedef                                     unsigned long long int ull;
typedef                                     signed long long int sll;
typedef                                     long double lld;
typedef                                     vector<int>vi;
typedef                                     vector<long>vl;
typedef                                     vector<long long int>vll;
typedef                                     vector<double>vd;
typedef                                     vector<long double>vld;
typedef                                     vector<char>vc;
typedef                                     vector<string>vs;
typedef                                     pair<int,int>pii;
typedef                                     pair<long long,long long>pll;
typedef                                     pair<double,double>pdd;
typedef                                     pair<char,char>pcc;
typedef                                     pair<string,string>pss;
typedef                                     map<int,int>mii;
typedef                                     map<long long,long long>mll;
typedef                                     map<char,char>mcc;
typedef                                     map<string,string>mss;
typedef                                     map<string,int>msi;
typedef                                     map< int,vector<int> >miv;
typedef                                     map<vector<int>,vector<int> >mvvi;
typedef                                     map<string,vector<int> >msv;
typedef                                     set<int>si;
typedef                                     set<string>ss;
typedef                                     set<vector<int> >sv;
typedef                                     queue<int>qi;
typedef                                     queue<long long>qll;
typedef                                     queue<string>qs;
typedef                                     stack<int>stki;
typedef                                     stack<long long>stkll;

/**-------------------END OF typedef------------------------------**/


const int                                   INF  = 1000000000;
const int                                   MAX  = 4007;
const int                                   MAX2 = 1000000;
const int                                   MAXD = 20;
const int                                   BASE = 1000000007;
const int                                   MOD  = 1000000007;
const int                                   psz  = 2000006;

/**-------------------Constant int--------------------------------**/

#define sI(a)                               scanf("%d",&a)
#define sI2(a,b)                            sI(a) , sI(b)
#define sI3(a,b,c)                          sI(a), sI(b), sI(c)
#define sI4(a,b,c,d)                        sI(a), sI(b), sI(c), sI(d)

#define sL(a)                               scanf("%lld",&a)
#define sL2(a,b)                            sL(a) , sL(b)
#define sL3(a,b,c)                          sL(a), sL(b), sL(c)
#define sL4(a,b,c,d)                        sL(a), sL(b), sL(c), sL(d)

#define pI(a)                               printf("%d",a)
#define pI2(a,b)                            pI(a) , pI(b)
#define pI3(a,b,c)                          pI(a), pI(b), pI(c)
#define pI4(a,b,c,d)                        pI(a), pI(b), pI(c), pI(d)

#define pL(a)                               printf("%lld",a)
#define pL2(a,b)                            pL(a) , pL(b)
#define pL3(a,b,c)                          pL(a), pL(b), pL(c)
#define pL4(a,b,c,d)                        pL(a), pL(b), pL(c), pL(d)
#define pN                                  printf("\n");


/**----------------------Scan and print end--------------------------**/

#define min3(a,b,c)                         min(a,min(b,c))
#define max3(a,b,c)                         max(a,max(b,c))
#define min4(a,b,c,d)                       min(min(a,b),min(c,d))
#define max4(a,b,c,d)                       max(max(a,b),max(c,d))
#define max5(a,b,c,d,e)                     max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e)                     min(min3(a,b,c),min(d,e))

/**----------------------MAX and MIN end-----------------------------**/

#define fst                                 first
#define snd                                 second
#define all(a)                              a.begin(),a.end()
#define rall(a)                             a.rbegin(),a.rend()
#define SQR(a)                              ((a)*(a))
#define Unique(a)                           sort(all(a)),a.erase(unique(all(a)),a.end())
#define Iterator(a)                         __typeof__(a.begin())
#define rIterator(a)                        __typeof__(a.rbegin())
#define FORI(a,it)                          for(Iterator(a) it = a.begin();it != a.end(); it++)
#define RFORI(a,it)                         for(rIterator(a) it = a.rbegin();it != a.rend(); it++)
#define FOR(i, a, b)                        for(int i=(a);i<(b);i++)
#define RFOR(i, b, a)                       for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value)                       memset(A,value,sizeof(A))
#define SZ(V)                               (int)V.size()
#define PB                                  push_back
#define MP                                  make_pair
#define Pi                                  3.14159265358979
#define read(x)                             freopen(x, "r", stdin)
#define write(x)                            freopen(x, "w", stdout)

/**---------------------End of define of all----------------------**/


int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

/**-----------------------Directional------------------------------**/

inline int number_of_edges(int degreeofvertices)   {int res; res=(degreeofvertices)/2;return res;};
inline int josephus(int n,int k)                   {if(n==1){return 1;}else{return (josephus(n-1,k)+k-1)%n+1;}}


/**-----------------------Normal equations-------------------------**/

inline int binary_src(int a[],int n,int k)         {int lo=0,hi=n-1,mid;while(lo<=hi){mid=(lo+hi)/2;if(a[mid]==k){return mid+1;}else if(a[mid]>k){hi=mid-1;}else if(a[mid]<k){lo=mid+1;}}return -1;}
inline bool isLeap(lli y)                          {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false); }
inline int chToIn(char a)                          {int b;b = a-'0';return b;}
inline char inTOch(int a)                          {char b;b= a+'0';return b;}
inline int stToIn(string a)                        {int b;b=atoi(a.c_str());return b;}
inline string appendChar(string s,char a)          {s.append(1,a);return s;}
inline string rev(string a)                        {int siz=SZ(a);string res="";RFOR(i,siz,0){res+=a[i];}return res;}
inline int gcd(int a, int b)                       {return (b == 0 ? a : gcd(b, a % b));}
inline int lcm(int a, int b)                       {return (a * (b / gcd(a, b))); }
vll factors_n; inline lli factor_find_n(lli n)     {for(lli i=2; i<=n; i++)while(n%i==0){n/=i; factors_n.PB(i);}}
vll factors_sqr; inline lli factor_find_sqrt(lli n){for(lli i=2; i*i<=n; i++)while(n%i==0){n/=i; factors_sqr.PB(i);}}
inline lli bigmod(lli a,lli b,lli m)               {if(b==0)return 1%m;lli x=bigmod(a,b/2,m);x=(x*x)%m;if(b%2==1){x=(x*a)%m;}return x;}
inline lli phi(lli n)                              {lli ret=n;for(lli i=2; i*i<=n; i++){if(n%i==0){while(n%i==0)n/=i;}ret-=ret/i;}if(n>1){ret-=ret/n;}return ret;}

/**---------------------End of functions--------------------------**/
