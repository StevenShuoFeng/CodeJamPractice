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

//////////////////////////////////////////
//////////////////////////////////////////

void printmat(const vector<vector<int> >& mat)
{
	F0(i, mat.size())
	{
		F0(j, mat[0].size())  printf("%d ",mat[i][j]);
		printf("\n");
	}
}

vector<int> solve(map<int, int> m)
{
	vector<int> out;
	for (auto s : m) if (s.second%2 != 0) out.push_back(s.first);
	sort(out.begin(), out.end());
	return out;
}

int main() {
    //freopen("x.in", "r", stdin);

	// freopen("B-small-practice.in", "r", stdin);
	// freopen("B-small-practice.out", "w", stdout);
	
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn)
	{
		int N; cin >> N;
		
		map<int, int> m;
		F0(i, N*(N*2-1))
		{
			cin >> n; m[n]++;
		}
		
		vector<int> ans = solve(m);

		printf("Case #%d: ", tt);
		for (auto k : ans) printf("%d ", k);
		printf("\n");

	}

	return 0;
}
