#ifndef SODE_H
#define SODE_H

#include <vector>
#include <functional>

using namespace std;
class SODE
{
    protected:
        vector <function <float (vector <float>, float)>> m_equations;
        vector <float> m_init_conditions;
        float m_t;
        float m_T;
        float m_e;
        SODE(vector <function <float (vector <float>, float t)>> equations, vector <float> init_conditions, float t = 0.01, float T = 1, float e = 10^(-3))
        {
            m_equations = equations;
            m_init_conditions = init_conditions;
            m_t = t;
            m_T = T;
            m_e = e;
        }
};

#endif