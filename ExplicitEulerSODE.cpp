#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include "ExplicitEulerSODE.hpp"

using namespace std;

float ExplicitEulerSODE::find_step(const vector<float> &parameters, float t, float max_step)
{
    int n = parameters.size();
    float step = 100;
    float possible_step = 0.1;
    for (int i = 0; i < n; ++i)
    {
        possible_step = m_e / (abs(m_equations[i](parameters, t)) + m_e / max_step);
        if (possible_step < step)
            step = possible_step;
    }

    return step;
}

void ExplicitEulerSODE::solve(float max_step)
{
    int n = m_init_conditions.size();
    vector<float> parameters = m_init_conditions;
    vector<float> changed_parameters(n);
    vector<vector<float>> changes;
    vector<float> time_changes;

    float t = m_t;
    changes.push_back(m_init_conditions);
    time_changes.push_back(t);
    float step = 0;

    while (t < m_T)
    {
        step = this->find_step(parameters, t, max_step);
        t += step;
        for (int i = 0; i < n; ++i)
        {
            changed_parameters[i] = parameters[i] + step * m_equations[i](parameters, t);
        }
        parameters = changed_parameters;
        changes.push_back(parameters);
        time_changes.push_back(t);
    }

    n = time_changes.size();
    for (int i = 0; i < n; ++i)
    {
        cout << "t = " << time_changes[i] << " параметры: ";
        for (const auto &item : changes[i])
        {
            cout << item << " ";
        }
        cout << endl;
    }
}
