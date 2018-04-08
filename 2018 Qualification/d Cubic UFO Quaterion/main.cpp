#include <iostream>  // includes cin to read from stdin and cout to write to stdout
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;  // since cin and cout are both in namespace std, this saves some text

struct POINT
{
    double x = 0;
    double y = 0;
    double z = 0;

    POINT()
    {}

    POINT(double xin, double yin, double zin): x(xin), y(yin), z(zin)
    {}

    void show() const
    {
        printf("%.14f, %.14f, %.14f\n", x, y, z);
    }
};

struct VECTOR
{
    double x = 0;
    double y = 0;
    double z = 0;

    VECTOR()
    {}

    VECTOR(double xin, double yin, double zin): x(xin), y(yin), z(zin)
    {}

    double getNorm()
    {
        return sqrt(x*x + y*y + z*z);
    }

    void normalize()
    {
        double mag = getNorm();

        x /= mag;
        y /= mag;
        z /= mag;
    }
};

const POINT k_p1(0.5, 0.0, 0.0);
const POINT k_p2(0.0, 0.5, 0.0);
const POINT k_p3(0.0, 0.0, 0.5);

POINT rotate(VECTOR rotAxis, double theta, const POINT& point)
{
    // Quaternion
    rotAxis.normalize();
    double qr = cos(theta/2);
    double qi = sin(theta/2) * rotAxis.x;
    double qj = sin(theta/2) * rotAxis.y;
    double qk = sin(theta/2) * rotAxis.z;

    // Rotation matrix
    double a11, a12, a13, a21, a22, a23, a31, a32, a33;

    a11 = 1 - 2*(qj*qj + qk*qk);
    a22 = 1 - 2*(qi*qi + qk*qk);
    a33 = 1 - 2*(qj*qj + qj*qj);

    a12 = 2*(qi*qj - qk*qr);
    a23 = 2*(qj*qk - qi*qr);
    a31 = 2*(qi*qk - qj*qr);

    a13 = 2*(qi*qk + qj*qr);
    a21 = 2*(qi*qj + qk*qr);
    a32 = 2*(qj*qk + qi*qr);

    // Rotate, rotation matrix mutiplies point vector
    POINT out;
    out.x = a11*point.x + a12*point.y + a13*point.z;
    out.y = a21*point.x + a22*point.y + a23*point.z;
    out.z = a31*point.x + a32*point.y + a33*point.z;

    return out;
}

vector<POINT> sol(double A)
{
    vector<POINT> ans(3);
    ans[0] = k_p1;
    ans[1] = k_p2;
    ans[2] = k_p3;

    for (int k = 0; k < 3; ++k)
    {
        // printf("\npoint #%d:\n", k+1);

        POINT& p = ans[k];
        // printf("orig:\n");
        // p.show();

        printf("acos(1.0/A) %.14f, M_PI_4 %.14f \n", acos(1.0/sqrt(2)), M_PI_4);
        p = rotate(VECTOR(0,0,1), acos(1.0/A), p);

        // printf("final:\n");
        // p.show();
    }

    return ans;
}



int main() {
    int t;
    double A;

    cin >> t; 
    for (int i = 1; i <= t; ++i)
    {
        cin >> A;

        vector<POINT> ans = sol(A);

        cout << "Case #" << i << ":" << endl;

        ans[0].show();
        ans[1].show();
        ans[2].show();
    }

    return 0;
}