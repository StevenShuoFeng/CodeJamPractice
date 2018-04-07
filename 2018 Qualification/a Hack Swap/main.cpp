#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;  // since cin and cout are both in namespace std, this saves some text

// used only once for calculating the inital damage
int calDamage(string s)
{
    int tot = 0;
    int crnt = 1;

    for (char c : s)
    if (c == 'C')
        crnt *= 2;
    else
        tot += crnt;

    return tot;
}

int countS(string s)
{
    int ans = 0;
    for (char c : s) if (c == 'S') ans++;
    return ans;
}

int sol(int K, string s)
{
	int Ns = countS(s); // #shoots, total damage is minimized when all s do 1 damage (total of ns damage)
	int Nc = s.size() - Ns;
    if (Ns > K) return -1;
    int targ = calDamage(s) - K;

    if (targ <= 0) return 0;

	// printf("#s %d #c %d, need to reduce damage by %d\n", Ns, Nc, targ);

	vector<int> damage_eachC, ns_after_eachC;
    int curnt_damage = 1, num_s_after = Ns;

    for (char c : s)
        if (c == 'S')
            num_s_after--;
        else
        {
            curnt_damage *= 2;
            damage_eachC.push_back(curnt_damage); // current_damage at current C, swap C backward will reduce total damage by half of it.
            ns_after_eachC.push_back(num_s_after); // number of S after current C, max #of swap of this C.
        }


	int ans = 0;

  // move C 
    for (int k = Nc-1; k >= 0; --k)
    {
        int delta = damage_eachC[k]/2;
        int maxMove = ns_after_eachC[k];

        // swap and count
        for (int i = 0; i < maxMove; ++i)
        {
            if (targ <= 0) 
                return ans;
            else
            {
                ans++;
                targ -= delta;
            }
        }
    }

	return ans;
}


int main() {
    int t, K;
    string P;

    cin >> t; 
    for (int i = 1; i <= t; ++i)
    {
        cin >> K;
        cin >> P;

        int ans = sol(K, P);

        if (ans != -1)
        	cout << "Case #" << i << ": " << ans << endl;
        else
        	cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
    }

    return 0;
}