#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;  // since cin and cout are both in namespace std, this saves some text

typedef vector<double> CORD;

vector<CORD> sol(double A)
{
	double area = 1.414213;
    double angle = acos(A/area);


    CORD p1(3), p2(3), p3(3);

    double r = sqrt(2)/2; // middle point of a edge to origin

    p1[0] = r*(-cos(angle) - sin(angle) )/2;
    p1[1] = r*( cos(angle) - sin(angle) )/2;
    p1[2] = 0;

    p2[0] = r*( cos(angle) - sin(angle) )/2;
    p2[1] = r*( cos(angle) + sin(angle) )/2;
    p2[2] = 0;

    p3[0] = 0;
    p3[1] = 0; 
    p3[2] = 0.5;

    vector<CORD> ans(3);
    ans[0] = p1; ans[1] = p2; ans[2] = p3; 
    return ans;
}


int main() {
    int t;
    double A;

    cin >> t; 
    for (int i = 1; i <= t; ++i)
    {
        cin >> A;

        vector<CORD> ans = sol(A);

        cout << "Case #" << i << ":" << endl;

        printf("%.14f %.14f %.14f\n", ans[0][0],ans[0][1],ans[0][2]);
        printf("%.14f %.14f %.14f\n", ans[1][0],ans[1][1],ans[1][2]);
        printf("%.14f %.14f %.14f\n", ans[2][0],ans[2][1],ans[2][2]);
    }

    return 0;
}