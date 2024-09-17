#include <stdio.h>
#include <math.h>
#include "func3.h"

float squareRoot(float a) {

    float i = 0;
    float j = a / 2;

    while (j != i)
    {
        i = j;
        j = (a / i + i) / 2;
    }
    return j;

}


float result(int K, float *resistance)
{
    float amount_resistances = 0.0f;

    for (int i = 0; i < K; i++)
    {
        amount_resistances = amount_resistances + resistance[i];
    }
    printf("amount_resistances-%f\n", amount_resistances);


    float resistance_final = amount_resistances / (float)K;

    float amount_square_diff = 0;

    for (int i = 0; i < K; i++)
    {
        amount_square_diff += ((resistance[i] - resistance_final) * (resistance[i] - resistance_final));
        printf("%f\n", amount_square_diff);
    }
    printf("\n\n%f\n", squareRoot(amount_square_diff) / (float)K);
    float deviation = squareRoot(amount_square_diff) / (float)K;

    printf("%f+-%f  (cопротивление +- среднеквадратичное отклонение)\n", resistance_final, deviation);


    return resistance_final;
}
