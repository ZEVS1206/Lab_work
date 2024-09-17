#include <stdio.h>
#include <math.h>

#include <check.h>

int check(int k, float resistance[],float resistance_final){
    float sum = 0.0f;
    int i = 0;
    for(;i < k; i++){
        sum += (resistance[i] - resistance_final) * 400000;
        printf("%f\n", sum / 20);
    }
    float result = sum / (float)k / 1000;
    printf("среднее отклонение: %.6f\n", result);
    float accuracy = 1e-8f;
    if (fabs(result) < accuracy){
        return 1;
    }
    return 0;
}
