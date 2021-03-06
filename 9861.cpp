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

int n, m, a[300100], i, p, sum, ans;

int main(){
    scanf("%d %d", &n, &m);
    for(i=1;i<=n;++i)
        scanf("%d", &a[i]);
    p=0;
    for(i=1;i<=n;++i){
        sum+=a[i];
        if(sum<=m)
            ans=max(ans, sum);
        else{
            while(sum>m && p<=i)
                sum-=a[p++];
            if(sum<=m)
                ans=max(ans, sum);
        }
    }
    printf("%d\n", ans);
    return 0;
}
