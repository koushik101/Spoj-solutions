#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>
#include <ctime>
#include <stdint.h>
#include <unistd.h>
 
 using namespace std;
 
#define ll long long int
#define INF 2147483647
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 20010;
int i, sa[N], tsa[N], ra[N], tra[N], t, c[N], k, n, r, p, sum;
char s[N];

void csort(int k){
    memset(c, 0, sizeof c);
    for(i=0;i<n;++i)
        c[i+k<n?ra[i+k]:0]++;
    sum=0;
    for(i=0;i<max(300, n);++i)
        p=c[i], c[i]=sum, sum+=p;
    for(i=0;i<n;++i)
        tsa[c[sa[i]+k<n?ra[sa[i]+k]:0]++]=sa[i];
    for(i=0;i<n;++i)
        sa[i]=tsa[i];
}
void Suffix_Array(){
    for(i=0;i<n;++i)
        sa[i]=i, ra[i]=s[i];
    for(k=1;k<n;k<<=1){
        csort(k);
        csort(0);
        r=0, tra[sa[0]]=r;
        for(i=1;i<n;++i)
            if(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k])
                tra[sa[i]]=r;
            else
                tra[sa[i]]=++r;
        for(i=0;i<n;++i)
            ra[i]=tra[i];
    }
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        n=(int)strlen(s);
        for(i=0;i<n;++i)
            s[i+n]=s[i];
        n=2*n;
        s[n++]='{';
        Suffix_Array();
        for(i=0;i<n;++i)
            if(sa[i]<(n-1)/2){
                printf("%d\n", sa[i]+1);
                break;
            }
    }
    return 0;
}
