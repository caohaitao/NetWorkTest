#include "stdafx.h"
#include "NetWorkMath.h"
#include <math.h>

#define MATH_E 2.718281828459
#define PRECISION 0.1

bool NetWorkMath::IsTwoFloatNear(float f1, float f2)
{
        if (fabs(f1-f2)<PRECISION){
                return true;
        }
        return false;
}

float NetWorkMath::SigMode(float f)
{
        return 1.0 / (1 + pow(MATH_E, -f));
}
