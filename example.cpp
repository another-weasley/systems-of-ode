#include "ExplicitEulerSODE.hpp"
#include <cmath>

using namespace std;

int main()
{
    vector<function<float (vector<float>, float)> > ee1 = {
      [](vector<float> x, float t) { return -x[0]*x[1] + sin(t)/t; },
      [](vector<float> x, float t) { return -x[1]*x[1] + 3.5*t/(1+t*t); }   
    };  

    vector <float> ei1 = {0, -0.412};

    ExplicitEulerSODE ex1(ee1, ei1);
    ex1.solve();
    return 0;
}