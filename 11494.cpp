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
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9
 
template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}
 
typedef vector<int> vi;
typedef pair<int, int> ii;

int t, r, u, cs = 1;
double ans;

int main() {
	scanf("%d", &t);
	while( t-- ) {
		scanf("%d %d", &r, &u);
		ans = (double) ( r * 9.806 ) / (double) (u * u);
		if( ans >= -1.0 && ans <= 1.0 ){
			ans = asin(ans);
			ans = ( 180 * ans ) / PI;
			ans /= 2.0;
			printf("Scenario #%d: %.2lf\n", cs++, ans);
		}
		else
			printf("Scenario #%d: -1\n", cs++);
	}
	return 0;
}
