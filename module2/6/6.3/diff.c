double diff(double *arr, int n){

    double result = arr[0];

    for(int i = 1; i < n; ++i){
        result -= arr[i];    
    }

    return result;
}