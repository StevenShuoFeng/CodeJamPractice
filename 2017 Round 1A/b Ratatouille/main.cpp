/*
https://code.google.com/codejam/contest/5304486/dashboard

Problem

You are catering a party for some children, and you are serving them a cake in the shape of a grid with R rows and C columns. Your assistant has started to decorate the cake by writing every child's initial in icing on exactly one cell of the cake. Each cell contains at most one initial, and since no two children share the same initial, no initial appears more than once on the cake.

Each child wants a single rectangular (grid-aligned) piece of cake that has their initial and no other child's initial(s). Can you find a way to assign every blank cell of the cake to one child, such that this goal is accomplished? It is guaranteed that this is always possible. There is no need to split the cake evenly among the children, and one or more of them may even get a 1-by-1 piece; this will be a valuable life lesson about unfairness.

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<n;i++)

typedef long long ll;
typedef pair<int,int> pii;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
const double eps = 1e-8;

set<int> countServing(int oneServing, int p)
{
	set<int> ans;

	int n = round(((float)p)/oneServing);

	if (p >= n*oneServing*0.9 && p <= n*oneServing*1.1f) 
		return n;
	else 
		return 0;

	return ans;
}

int solv(int N, int P, const vector<int>& R, const vector<vector<int>>& pkg)
{
}

int main() {
	// freopen("B-large-practice.in", "r", stdin);
	// freopen("B-large-practice.out", "w", stdout);

	freopen("B-small-practice.in", "r", stdin);
	freopen("B-small-practice.out", "w", stdout);

	int tt, tn; cin >> tn;

	F0(tt,tn) 
	{		
		int N, P;

		cin >> N >> P;

		vector<int> R;
		F0(i, N)
		{
			int r; cin >> r; R.push_back(r);
		}

		vector<vector<int>> pkg(N, vector<int>(P));
		F0(i, N) F0(j, P)
		{
			cin >> pkg[i][j];
		}

		int ans = solv(N, P, R, pkg);

		printf("Case #%d:\n", tt+1);
		cout << ans << endl;

	}
	return 0;
}
