#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define F0(i, N) for(int i = 0; i < N; ++i)

using namespace std;  // since cin and cout are both in namespace std, this saves some text

class Solver
{
private:
    int R, C, H, V;
    vector<vector<int>> BD;

    int tot = 0; // total chocolate

    vector<int> rowCnt; // count of chocolate each row
    vector<int> rowCutIndex;

    vector<int> colCnt; // count of chocolate each row
    vector<int> colCutIndex;

public:
    void loadData(){
        cin >> R >> C >> H >> V;

        BD.clear();
        BD.resize(R);

        rowCnt.clear();
        rowCutIndex.clear();
        colCnt.clear();
        colCutIndex.clear();

        F0(i, R){
            F0(j, C){
                char c;
                cin >> c;

                if (c == '@')
                    {BD[i].push_back(1); tot++;}
                else
                    BD[i].push_back(0);
            }

        }

        F0(i, R) 
        {
            int cnt = 0;
            F0(j, C) cnt += BD[i][j];
            rowCnt.push_back(cnt);
        }

        F0(j, C)
        {
            int cnt = 0;
            F0(i, R) cnt += BD[i][j];
            colCnt.push_back(cnt);
        }

        // printLoadData();
    }

    void printLoadData(){
        printf("---------------\n");
        printf("R = %d, C = %d, H = %d, V = %d \n", R, C, H, V);

        F0(i, R) 
        {
            F0(j, C) 
                printf("%d", BD[i][j]);
            cout << " " << rowCnt[i] << endl;
        }
        printf("------\n");
    }

    bool checkRow()
    {
        const int tar = tot/(H+1);
        // printf("Tar each row %d\n", tar);

        if (tot%tar != 0) return false;

        int i = 0;
        for (int k = 0; k < R; ++k)
        {
            i += rowCnt[k];

            if (i > tar) return false;
            if (i < tar) continue;

            rowCutIndex.push_back(k);
            i = 0;
        }

        return true;
    }

    bool checkCol()
    {
        const int tar = tot/(V+1);
        // printf("Tar each col %d\n", tar);

        if (tot%tar != 0) return false;

        int i = 0;
        for (int k = 0; k < C; ++k)
        {
            i += colCnt[k];

            if (i > tar) return false;
            if (i < tar) continue;

            colCutIndex.push_back(k);
            i = 0;
        }

        return true;
    }

    bool sol(){
        if (tot == 0) return true;

        if (!checkRow()) return false;
        if (!checkCol()) return false;

        // check each block 
        int targ = tot/(H+1)/(V+1);
        int r1 = 0, r2 = 0;
        for (auto r : rowCutIndex)
        {
            r2 = r; 

            int c1 = 0, c2 = 0;
            for (auto c : colCutIndex)
            {
                c2 = c;

                int cntBlock = 0;
                for (int i = r1; i <= r2; ++i)
                    for (int j = c1; j <= c2; ++j)
                        cntBlock += BD[i][j];

                if (cntBlock != targ)
                {
                    // printf("row [%d %d] col [%d %d] sum %d != %d \n", r1, r2, c1, c2, cntBlock, targ);
                    return false;
                }
                else
                {
                    // printf("row [%d %d] col [%d %d] sum %d == %d \n", r1, r2, c1, c2, cntBlock, targ);
                }

                c1 = c2+1;
            }
            r1 = r2+1;
        }

        return true;
    }
};

int main() {
    int nTest;

    cin >> nTest; 

    for (int i = 1; i <= nTest; ++i)
    {
        Solver s;

        s.loadData();

        bool ans = s.sol();

        cout << "Case #" << i << ": " << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;        
    }

    return 0;
}