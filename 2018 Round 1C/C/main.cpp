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
    int N;
    vector<int> weight;

public:
    void loadData()
    {
        cin >> N;

        weight.clear();

        F0(j, N){
            int w;
            cin >> w;
            weight.push_back(w);
        }

        // printLoadData();
    }

    void printLoadData()
    {
        printf("---------------\n");
        printf("N = %d\n", N);

        F0(i, N) 
            printf("%d,", weight[i]);
        cout << endl;
    }

    int sol(){

        vector<int> cnt(N, 1);
        vector<int> w = weight;

        int ret = 1;

        for (int i = 1; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (cnt[j] >= cnt[i] && w[j] <= 6*weight[i])
                {
                    cnt[i] = cnt[j]+1;
                    w[i] = w[j] + weight[i];
                }

                if (cnt[j] == cnt[i]-1 && w[j]+weight[i] < w[i])
                {
                    w[i] = w[j] + weight[i];
                }
            }

            // printf("[%d]-%d, w = %d, cnt = %d\n", i, weight[i], w[i], cnt[i]);

            ret = max(ret, cnt[i]);
        }

        return ret;
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