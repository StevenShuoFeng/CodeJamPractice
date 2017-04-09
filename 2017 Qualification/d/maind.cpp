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

struct ModelInfo
{
	ModelInfo(char stylein, int rin, int cin): 
	style(stylein), r(rin), c(cin)
	{};

	char style = '$';
	int r = -1;
	int c = -1;
};

int maxScore(vector<vector<char>>& grid, vector<ModelInfo>& updates);
void printGrid(const vector<vector<char>>& grid);
int countScore(const vector<vector<char>>& grid);

bool submit = true;

int main()
 {
	freopen("D-small-attempt4.in", "r", stdin);
	if (submit) freopen("D-small-attempt4.out", "w", stdout);
	
	// freopen("D-large.in", "r", stdin);
	// freopen("D-large.out", "w", stdout);

	int tt, tn; 
	cin >> tn;

	F1(tt,tn) 
	{
		int N, K; cin >> N; cin >> K;

		// read grid
		vector<vector<char>> grid(N, vector<char>(N, '.'));
		F0(i, K) 
		{
			char m; int r, c;  cin >> m; cin >> r; cin >> c;
			grid[r-1][c-1] = m;
		}

		
		if (!submit) printGrid(grid);

		vector<ModelInfo> updates;
		int score = maxScore(grid, updates);

		if (!submit) printGrid(grid);

		printf("Case #%d: %d %d\n", tt, score, (int)updates.size());
		for(auto m : updates) printf("%c %d %d\n", m.style, m.r+1, m.c+1); // they use 1 indexing....

	}

	return 0;
}

int maxScore(vector<vector<char>>& grid, vector<ModelInfo>& updatedModel)
{
	const int N = grid.size();

	vector<bool> rflag(N, true);
	vector<bool> cflag(N, true);
	vector<bool> dflagl(2*N+1, true);
	vector<bool> dflagr(2*N+1, true);

	// initalize all 3 flag arrays to true. update after scanning grid
	F0(r, N)
		F0(c, N)
		{
			if (grid[r][c] == '.') continue;

			if (grid[r][c] != '+')
			{
				rflag[r] = false; 
				cflag[c] = false;
			}

			if (dflagl[c-r+N-1] && grid[r][c] != 'x')
			{
				dflagl[c-r+N-1] = false;
				dflagr[c+r] = false;
			}
		}
	
	// if (!submit)
	// {
	// 	printf("\nRow flag:\n");
	// 	F0(r, N) printf("%c ", rflag[r]? 'Y' : 'N');
	// 	printf("\nCol flag:\n");
	// 	F0(c, N) printf("%c ", cflag[c]? 'Y' : 'N');
	// 	printf("\nDiagnal-left flag:\n");
	// 	F0(i, 2*N-1) printf("%c ", dflagl[i]? 'Y' : 'N');
	// 	printf("\nDiagnal-right flag:\n");
	// 	F0(i, 2*N-1) printf("%c ", dflagr[i]? 'Y' : 'N');
	// }

	// check one-by-one for upgrade
	for (int r = N-1; r >= 0; --r)
		for (int c = N-1; c >= 0; --c)
		{
			char& s = grid[r][c];
			switch (grid[r][c])
			{
				case 'o' : break;

				case '.' :

					if (rflag[r]&&cflag[c] && dflagl[c-r+N-1]&&dflagr[c+r]) // all true
					{
						rflag[r] = cflag[c] = dflagl[c-r+N-1] = dflagr[c+r] = false;
						s = 'o';
						updatedModel.push_back(ModelInfo(s, r, c));
						break;
					}

					if (dflagl[c-r+N-1]&&dflagr[c+r]) // diag true
					{
						dflagl[c-r+N-1] = dflagr[c+r] = false;
						s = '+';
						updatedModel.push_back(ModelInfo(s, r, c));
						break;
					}
					
					if (rflag[r]&&cflag[c]) // row,col true
					{
						rflag[r] = cflag[c] = false; 
						s = 'x';
						updatedModel.push_back(ModelInfo(s, r, c));
						break;
					}

					break;

				case '+' :
					if (rflag[r]&&cflag[c]) // row,col true
					{
						rflag[r] = cflag[c] = false; 
						s = 'o';
						updatedModel.push_back(ModelInfo(s, r, c));
						break;
					}

					break;

				case 'x' :
					if (dflagl[c-r+N-1]&&dflagr[c+r]) // diag true
					{
						dflagl[c-r+N-1] = dflagr[c+r] = false;
						s = 'o';
						updatedModel.push_back(ModelInfo(s, r, c));
						break;
					}

					break;

				default: break;
			}
		}

	return countScore(grid);
}

void printGrid(const vector<vector<char>>& grid)
{
	printf("\nGrid:\n");
	F0(r, grid.size())
	{
		F0(c, grid.size())
			printf("%c ", grid[r][c]);
		printf("\n");
	}
}

int countScore(const vector<vector<char>>& grid)
{
	int score = 0;

	F0(r, grid.size())
	{
		F0(c, grid.size())
		{
			char s = grid[r][c];
			switch (s)
			{
				case '.' : score += 0; break;
				case 'x' : score += 1; break;
				case '+' : score += 1; break;
				case 'o' : score += 2; break;
				default : break;
			}
		}
	}

	return score;
}