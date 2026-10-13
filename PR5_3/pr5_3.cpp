#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double s(const double x);

int main()
{
    double tp, tk;
    int n;

    cout << "tp = "; cin >> tp;
    cout << "tk = "; cin >> tk;
    cout << "n = ";  cin >> n;

    double dt = (tk - tp) / n;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(8) << "t" << "  |"
        << setw(14) << "value" << "|" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i <= n; i++)
    {
        double t = tp + i * dt;
        double value = s(2 * t + 1) + 2 * s(t * t) + sqrt(s(1));

        cout << "|" << setw(8) << setprecision(3) << t << "  |"
            << setw(14) << setprecision(6) << value << "|" << endl;
    }
    cout << "---------------------------" << endl;

    return 0;
}

double s(const double x)
{
    if (fabs(x) >= 1 || x == 0)
        return (cos(x) * cos(x) + 1) / exp(x);
    else
    {
        double sum = 0;
        int k = 0;
        double a = 2 * x;                       // доданок при k = 0: (2x)^1 / 1!
        sum = a;
        do
        {
            k++;
            double R = 4 * x * x / ((2 * k) * (2 * k + 1));   // a_k = a_(k-1) * R
            a *= R;
            sum += a;
        } while (k < 4);
        return sum / sin(2 * x);
    }
}