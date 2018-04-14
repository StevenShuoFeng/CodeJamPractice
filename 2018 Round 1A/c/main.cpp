#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

#define F0(i, N) for(int i = 0; i < N; ++i)

using namespace std;  // since cin and cout are both in namespace std, this saves some text

class Solver
{
private:
    int N;
    double P;
    double Z = 0;
    double Tar;
    vector<pair<double, double>> SIZ;

public:
    void loadData()
    {
        cin >> N >> P;
        P /= 2;

        SIZ.clear();

        F0(i, N){
            double l, w;
            cin >> l >> w;
            SIZ.push_back({l, w});
            Z += l+w;
        }

        Tar = P - Z;

        // printLoadData();
    }

    void printLoadData()
    {
        printf("---------------\n");
        printf("N = %d, P = %f, Z = %f, tar = %f\n", N, P, Z, Tar);

        F0(i, N) printf("[%f %f] ", SIZ[i].first, SIZ[i].second);

        printf("\n---------------\n");
    }

    double sol(){
        if (Tar == 0) return Z*2;

        int w = SIZ.front().first, h = SIZ.front().second;
        float l = min(w, h);
        float r = sqrt(w*w + h*h);

        int i = 0;
        while( (l*(i+1) <= Tar) && i < N)
            ++i;

        // printf("%d pieces closest to %f, l*i = %f, r*i = %f\n", i, Tar, l*i, r*i);

        double ans;
        if (l*i <= Tar && r*i >= Tar) 
            ans = Tar;
        else
            ans = r*i;

        return (ans + Z)*2;
    }
};

int main() {
    int nTest;

    cin >> nTest; 

    for (int i = 1; i <= nTest; ++i)
    {
        Solver s;

        s.loadData();

        double ans = s.sol();

        printf("Case #%d: %.6f\n", i, ans);    
    }

    return 0;
}