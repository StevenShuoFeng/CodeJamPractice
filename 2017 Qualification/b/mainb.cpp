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

bool isTidy(ll N);

ll findNextTidy(ll N);

bool submit = true;

int main()
 {
	if (submit)
	{
		// freopen("B-small-attempt0.in", "r", stdin);
		// freopen("B-small-attempt0.out", "w", stdout);
		
		freopen("B-large.in", "r", stdin);
		freopen("B-large.out", "w", stdout);

		int tt, tn; 
		cin >> tn;

		F1(tt,tn) 
		{
			ll N; 
			cin >> N;

			while (!isTidy(N))
			{
				N = findNextTidy(N);
			}

			printf("Case #%d: %lld\n", tt, N);
		}
	}

	return 0;
}


ll findNextTidy(ll N)
{
	stringstream strstream;
	string str;

	strstream << N;
	strstream >> str;

	bool fillNine = false;
	for (int i = 0; i < str.size()-1; ++i) 
	{
		if (str[i] > str[i+1] && !fillNine)
		{
			str[i] = str[i] -1; 
			fillNine = true;
			continue;
		}

		if (fillNine) str[i] = '9';
	}

	if (fillNine) str[str.size()-1] = '9';

	return stoll(str);
}

bool isTidy(ll N)
{
	stringstream strstream;
	string str;

	strstream << N;
	strstream >> str;

	for (int i = 1; i < str.size(); ++i) 
		if (str[i] < str[i-1])
		{
			return false;
		}

	return true;
}
