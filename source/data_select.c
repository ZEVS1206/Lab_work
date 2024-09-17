#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "data_select.h"

int data_select (int M, float resistance[])
{
    float resistance_help[100] = {};
    double mid_res = 0;

    int i = 0;
    for (i = 0; i < M; i++)
    {
        mid_res += resistance[i];
        resistance_help[i] = resistance[i];
    }
    mid_res /= (double)M;

    int not_broken_elem_quant = M;
    for (i = 0; i < M; i++)
    {
        if (abs(resistance[i] - mid_res) > (double)0.03 * mid_res)
        {
            not_broken_elem_quant--;
            resistance_help[i] = -1;
        }
    }


    for (i = 0; i < M; i++)
    {
        if (resistance_help[i] != -1)
        {
            resistance[i] = resistance_help[i];
        }
    }

    for (i = not_broken_elem_quant; i < M; i++)
    {
        resistance[i] = -1;
    }
    // printf("AAAAA\n");
    // for (i = 0; i < M; i++){
    //     printf("%f\n", resistance[i]);
    // }
    // printf("AAAAAA\n");
    // printf("nbeq-%d\nM-%d\n", not_broken_elem_quant, M);
    return not_broken_elem_quant;
}

