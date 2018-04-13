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

int i, j, k, l, m, n, M, N;

void printM(const vector<vector<char>>& grid)
{
	F0(i, grid.size()){
		F0(j, grid[0].size()){
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

void solv(vector<vector<char>>& grid)
{
	map<int, vector<pair<char, int>>> l;

	// check location of current initials, each element of l is a vector of <char, colInx> pair
	F0(i, M) 
	F0(j, N)
	{
		if (grid[i][j] != '?')
			l[i].push_back({grid[i][j], j});
	}

	// fillin non-empty rows
	for(auto rows : l)
	{
		int r = rows.first;
		auto allCharThisRow = rows.second;
		for (auto p : allCharThisRow)
		{
			char c = p.first;
			int col = p.second-1;
			while(col >= 0 && grid[r][col] == '?')
				grid[r][col--] = c;
		}

		char c = allCharThisRow.back().first;
		int col = allCharThisRow.back().second+1;
		while(col < N && grid[r][col] == '?')
				grid[r][col++] = c;
	}

	// fillin empty rows
	F0(i, M)
	{
		if (l.find(i) == l.end())
		{
			int j = i;
			for (auto k : l) 
				if (k.first > j)
				{
					j = k.first;
					break;
				}

			grid[i]= grid[j];
		}
	}

	i = j = l.rbegin()->first;
	while(j < M)
	{
		grid[j++]= grid[i];
	}


}

int main() {
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);

	// freopen("A-small-practice.in", "r", stdin);
	// freopen("A-small-practice.out", "w", stdout);

	int tt, tn; cin >> tn;

	F0(tt,tn) 
	{		
		cin >> M >> N;

		vector<vector<char>> grid(M, vector<char>(N));

		F0(m, M) F0(n, N) cin >> grid[m][n];
		solv(grid);

		printf("Case #%d:\n", tt+1);
		// cout << ans << endl << "=====" << endl;
		printM(grid);

	}
	return 0;
}
