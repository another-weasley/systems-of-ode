#ifndef EESODE_H
#define EESODE_H

#include "SODE.hpp"
#include <vector>
#include <functional>

using namespace std;
class ExplicitEulerSODE: public SODE
{
    private:
        float find_step(const vector <float>& parameters, float t, float max_step = 0.1);
    public: 
        ExplicitEulerSODE(vector <function <float (vector <float>, float t)>> equations, vector <float> init_conditions, float t = 0.01, 
        float T = 1, float e = 10^(-3)) : SODE(equations, init_conditions, t, T, e){}
        void solve(float max_step = 0.1);
};

#endif