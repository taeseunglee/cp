#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	int a, b;
	char c;
	sf("%d %c %d", &a, &c, &b);
	if(c == '+') pf("%d", a + b);
	else if(c == '-') pf("%d", a - b);
	else if(c == '*') pf("%d", a * b);
	else if(c == '<') pf(a < b? "benar" : "salah");
	else if(c == '>') pf(a > b? "benar" : "salah");
	else if(c == '=') pf(a == b? "benar" : "salah");
	nl;
	return 0;
}
