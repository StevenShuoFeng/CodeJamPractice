#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)


// ---------------------------------------------------
// ---------------------------------------------------

bool submit = true;

void findLR(ll N, ll K, pair<ll, ll>& out)
{
	ll w = 1, t = 1;

	while(w*2-1 < K) { w *= 2; t += w;}
	t -= w; w /= 2;
	ll np = K-t;

	ll sizP = (N-t)/(t+1), nLargeSlot = (N-t)%(t+1);

	ll siz = np <= nLargeSlot ? sizP+1 : sizP;

	out.first = siz/2;
	out.second = siz%2==0 ? siz/2-1 : siz/2;
}

int main()
 {
	if (1)
	{
		// freopen("C-small-1-attempt0.in", "r", stdin);
		// freopen("C-small-1-attempt0.out", "w", stdout);

		// freopen("C-small-2-attempt0.in", "r", stdin);
		// freopen("C-small-2-attempt0.out", "w", stdout);
		
		freopen("C-large.in", "r", stdin);
		freopen("C-large.out", "w", stdout);

		int tt, tn; 
		cin >> tn;
		ll N, K;

		F1(tt,tn) 
		{
			cin >> N; cin >> K;
			pair<ll, ll> minmax;
			findLR(N, K, minmax);

			printf("Case #%d: %lld %lld\n", tt, minmax.first, minmax.second);
		}
	}

	return 0;
}