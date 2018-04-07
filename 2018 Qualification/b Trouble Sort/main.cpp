#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define F0(ii, N) for (int ii = 0; ii < N; ++ii)
#define F1(ii, N) for (int ii = 1; ii < N; ++ii)

int k, tmp;

// void printV(const vector<int>& v)
// {
//     for (int k : v) printf("%d ", k);
//     printf("\n");
// }

int sol(const vector<int>& v)
{
    vector<int> v1, v2;
    for (int i = 0; i < v.size(); i += 2) v1.push_back(v[i]);
    for (int i = 1; i < v.size(); i += 2) v2.push_back(v[i]);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    F0(k, v2.size())
    {
        if (v1[k] > v2[k]) return k*2;

        if (k+1 < v1.size())
            if (v2[k] > v1[k+1]) return k*2+1;
    }

    return -1;
}

int main() {
    int t, N;

    cin >> t; 
    for (int i = 1; i <= t; ++i)
    {
        cin >> N;
        vector<int> v;
        
        F0(k, N) {cin >> tmp; v.push_back(tmp);}

        int ans = sol(v);

        if (ans != -1)
        	cout << "Case #" << i << ": " << ans << endl;
        else
        	cout << "Case #" << i << ": " << "OK" << endl;
    }

    return 0;
}