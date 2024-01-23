#include<math.h>
#include"fonctions.h"

float delta(float a, float b, float c)
{
    float deter = (b * b) - (4 * a * c);
    return deter;
}

float racine1(float a, float b, float c)
{
    float delt1 = delta(a, b, c);
    float x1 = (((-1) * b) - powf(delt1, 0.5)) / (2 * a);
    return x1; 
}

float racine2(float a, float b, float c)
{
    float delt2 = delta(a, b, c);
    float x2 = (((-1) * b) + powf(delt2, 0.5)) / (2 * a);
    return x2;
}