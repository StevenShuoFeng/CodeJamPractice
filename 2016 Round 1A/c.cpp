/*
https://code.google.com/codejam/contest/4304486/dashboard#s=p2

Problem

You are a teacher at the brand new Little Coders kindergarten. You have N kids in your class, and each one has a different student ID number from 1 through N. Every kid in your class has a single best friend forever (BFF), and you know who that BFF is for each kid. BFFs are not necessarily reciprocal -- that is, B being A's BFF does not imply that A is B's BFF.

Your lesson plan for tomorrow includes an activity in which the participants must sit in a circle. You want to make the activity as successful as possible by building the largest possible circle of kids such that each kid in the circle is sitting directly next to their BFF, either to the left or to the right. Any kids not in the circle will watch the activity without participating.

What is the greatest number of kids that can be in the circle?

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
int a[1005], v[1005], d[1005];
// a is the array that storage to the orignal value
// v is a temporary vector to track which node has been visoted


int main() {
    //freopen("x.in", "r", stdin);

	freopen("C-small-practice.in", "r", stdin);
	// freopen("C-small-attempt0.out", "w", stdout);

	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	tn = 2;
	F1(tt,tn) {

		cin >> n; F1(i, n) cin >> a[i];
		int ans = 0;

		F1(i, n) {
			// initialize visited vector to 0s and count to 0
			F1(j, n) v[j] = 0; k = 0;

			// start from the i-th element, keep going till it's closed loop(reach node already visited)
			j = i;
			while (1) {
				v[j] = 1;
				j = a[j];
				k++;
				if (v[j]) break;
			}

			if (j == i)	
			{

				printf("close loop len starting from %d : %d\n", j, k);
				ans = max(ans, k);
			}
		}


		F1(j, n) d[j] = 0;
		F1(j, n) 
			F1(i, n) 
				if (a[a[i]] != i)
				{
					d[a[i]] = max(d[a[i]], d[i] + 1);
				} 
		printf("\n");

		F1(i, n)
			printf("d[%d] = %d, \n", i, d[i]);

		printf("---\n");
		F1(j, n) v[j] = 0;
		int ans2 = 0;
		F1(i, n) 
		{
			if (!v[i] && a[a[i]] == i) 
			{
				ans2 += 2 + d[i] + d[a[i]];
				v[i] = v[a[i]] = 1;
				printf("v[%d] = v[%d] = 1\n", i, a[i]);
			}
		}


		ans = max(ans, ans2);

		printf("Case #%d: ", tt);
		cout << ans << endl << "=====" << endl;

	}
	return 0;
}
