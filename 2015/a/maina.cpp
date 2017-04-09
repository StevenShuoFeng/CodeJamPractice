#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)

string util(string s)
{
	if (s.size() == 1) return s;

	string out;

	F0(i, s.size())
	{
		// if (i == 0) out.push_back(s[i])
		if (s[i] >= out[0])
			out = s[i] + out;
		else
			out += s[i];
	}

	return out;
}

int main()
 {
	
	// freopen("A-large-practice.in", "r", stdin);
	// freopen("A-large-practice.out", "w", stdout);

	freopen("A-small-practice.in", "r", stdin);
	freopen("A-small-practice.out", "w", stdout);

	int tt, tn; 
	cin >> tn;

	F1(tt,tn) 
	{
		string s; 
		cin >> s;

		string ans = util(s);

		printf("Case #%d: %s\n", tt, ans.c_str());

	}
		
	return 0;
}