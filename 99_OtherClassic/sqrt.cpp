#include <iostream>
using namespace std;

// 要求 |a - t^0.5| < g
double sqrt(const double x, const double g)
{
    if (x <= 0) return 0;
    if (x == 1) return 1;
    
    double low  = (x > 1 ? 1 : x);
    double high = (x > 1 ? x : 1);
    
    while (true) {
        double r = low + (high-low)/2; 
        double diff = r*r - x; 
        
        if (diff == 0) return r; 
        
        if (diff > 0) {
            if ((r-g)*(r-g) <= x) return r; 
            else high = r;
        }
        else {
            if ((r+g)*(r+g) >= x) return r;
            else low = r;
        }
    }
}

int main()
{
    double t = sqrt(10, 0.1);
    cout << "sqrt(10) = " << t << endl;
    
    t = sqrt(9, 0.1);
    cout << "sqrt(9) = " << t << endl;
    
    t = sqrt(100, 0.1);
    cout << "sqrt(100) = " << t << endl;
    
    t = sqrt(0.9, 0.01);
    cout << "sqrt(0.9) = " << t << endl;

    return 0;
}
