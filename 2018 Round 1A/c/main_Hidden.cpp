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

    void allRange(map<double, double>& range)
    {
        int prevN = 0;
        while(true)
        {
            int n = range.size();

            auto i = range.begin(); F0(k, prevN) i++;

            for (; i != range.end(); ++i)
            {
                for (auto k : SIZ)
                {
                    double l = i->first + k.first;
                    double r = i->second + k.second;

                    if (l > Tar)
                        return;
                    else
                    {
                        if (range.find(l) == range.end())
                            range[l] = r;
                        else
                            range[l] = max(range[l], r);
                    }
                }
            }

            prevN = n+1;
        }
    }

    double sol(){
        if (Tar == 0) return Z*2;

        // map the size of each cookie to the range of addition from cut
        for (int i = 0; i < N; ++i)
        {
            double w = SIZ[i].first, h = SIZ[i].second;
            SIZ[i].first = min(w, h);
            SIZ[i].second = sqrt(w*w + h*h);
        }
        sort(SIZ.begin(), SIZ.end());

        // F0(i, N) printf("cookie %d, [%.3f %.3f]\n", i, SIZ[i].first, SIZ[i].second);
        // printf("\n---------------\n");

        map<double, double> range;
        for(auto k : SIZ) range[k.first] = k.second;

        allRange(range);
        // for(auto i : range) printf("[%.3f %.3f]\n", i.first, i.second);


        double ans = 0;

        double l = range.rbegin()->first, r = range.rbegin()->second;
        // printf("Largest range [%.3f %.3f]\n", l, r);

        if (l <= Tar && r >= Tar)
            ans = Tar;
        else
            ans = r;

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