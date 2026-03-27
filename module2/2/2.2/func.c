#include <stdio.h>

double sum(double *arr, int n){

    double result = 0;

    for(int i = 0; i < n; ++i){
        result += arr[i];
    }

    return result;
}

double diff(double *arr, int n){

    double result = arr[0];

    for(int i = 1; i < n; ++i){
        result -= arr[i];    
    }

    return result;
}

double dev(double *arr, int n){

    double result = arr[0];

    for(int i = 1; i < n; ++i){
        result /= arr[i];    
    }

    return result;
}

double mult(double *arr, int n){

    double result = arr[0];

    for(int i = 1; i < n; ++i){
        result *= arr[i];    
    }

    return result;
}