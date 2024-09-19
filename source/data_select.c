#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "data_select.h"

int data_select (int M, float resistance[])
{
    float resistance_help[100] = {};
    float sr_ar = 0.0f;
    float amount_of_res = 0.0f;

    int i = 0;
    for (i = 0; i < M; i++)
    {
        amount_of_res += resistance[i];
        resistance_help[i] = resistance[i];
    }
    sr_ar = amount_of_res / (float)M;
    //printf("sr_ar-%lf\n", sr_ar);
    int not_broken_elem_quant = M;
    for (i = 0; i < M; i++)
    {
        if (fabs(resistance[i] - sr_ar) > (float)0.03 * sr_ar)
        {
            not_broken_elem_quant--;
            resistance_help[i] = 0;
        }
    }


    for (i = 0; i < M; i++)
    {
        int j = i;
        while(resistance_help[j] == 0)
        {
            j++;
        }
        resistance[i] = resistance_help[j];
    }

    for (i = not_broken_elem_quant; i < M; i++)
    {
        resistance[i] = 0;
    }
    printf("\n\n");
    for (int i = 0; i < not_broken_elem_quant; i++)
    {
        printf("%lf\n", resistance[i]);
    }

    return not_broken_elem_quant;
}

