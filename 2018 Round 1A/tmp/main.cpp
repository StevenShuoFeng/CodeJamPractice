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
    int M, N;
    vector<vector<char>> BD;

public:
    void loadData()
    {
        cin >> M >> N;

        BD.clear();
        BD.resize(M);

        F0(i, M) F0(j, N){
            char c;
            cin >> c;
            BD[i].push_back(c);
        }

        printLoadData();
    }

    void printLoadData()
    {
        printf("---------------\n");
        printf("M = %d, N = %d\n", M, N);

        F0(i, M) 
        {
            F0(j, N) 
                printf("%c", BD[i][j]);
            cout << endl;
        }

    }

    int sol(){

        return 0;
    }
};

int main() {
    int nTest;

    cin >> nTest; 

    for (int i = 1; i <= nTest; ++i)
    {
        Solver s;

        s.loadData();

        int ans = s.sol();

        cout << "Case #" << i << ": " << ans << endl;        
    }

    return 0;
}