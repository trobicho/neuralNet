#pragma once
#include <math.h>
#include "ActivFunc.h"

class Sigmoide: public ActivFunc
{
    public:
        Sigmoide(){};
        double f(double x, double k){return 1/(1+exp(-(x/k)));}
};
