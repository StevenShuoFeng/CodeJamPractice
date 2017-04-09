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
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)


// ---------------------------------------------------
// ---------------------------------------------------

int minFlip(string, int);

bool submit = true;

int main()
 {
	if (submit)
	{
		// freopen("A-small-attempt0.in", "r", stdin);
		// freopen("A-small-attempt0.out", "w", stdout);
		
		freopen("A-large.in", "r", stdin);
		freopen("A-large.out", "w", stdout);

		int tt, tn; 
		cin >> tn;

		F1(tt,tn) 
		{
			string sin; cin >> sin;
			int K; cin >> K;

			int ans = minFlip(sin, K);

			printf("Case #%d: %s\n", tt, ans == -1 ? "IMPOSSIBLE" : to_string(ans).c_str());

		}
	}
	else
	{
		string sin = "++-+-";
		int K = 2;

		int ans = minFlip(sin, K);

		printf("\nFinal result: %d\n", ans);

	}

	return 0;
}

int minFlip(string s, int K)
{

	int N = s.size();
	int cnt = 0;
	vector<bool> head(N, true);
	F0(i, N) if (s[i] == '-') head[i] = false;

	// printf("Raw string:\n"); for(auto v : head) printf("%c ", v?'+':'-');

	F0(i, N-K)
	{
		if (head[i]) continue;
		
		for(int j = i; j < i+K; ++j) head[j] = !(head[j]); // flip next K 
		cnt++;

		// printf("\n cnt %d \n", cnt); for(auto v : head) printf("%c ", v?'+':'-');
	}

	bool possible = true;

	// check if last K are the same
	for (int i = N-K; i < N-1; ++i) 
		if (head[i] != head[i+1])
		{
			possible = false; break;
		}

	if (possible&&!head.back()) cnt++;

	if (possible) 
		return cnt; 
	else
		return -1;
}
