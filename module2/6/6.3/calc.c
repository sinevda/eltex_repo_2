/*

6.3 (3 балла). Доработать решение задачи 2.3 (калькулятор) так, чтобы
функции загружались из динамических библиотек. В одной библиотеке
находится одна функция. При запуске программы считывается каталог с
библиотеками и загружаются найденные функции.

*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "func.h"

int main(int argc, char *argv[]){
    double (*func) (double *, int);
    void * library_handler;
    library_handler = dlopen("/home/mok/Projects/6.3/func.so", RTLD_LAZY);
    if(!library_handler){
        fprintf(stderr, "dlopen() error: %s\n", dlerror());
        return -1;
    }
    while(1){
        int number;

        printf("Калькулятор. \nВыберите операцию:\n\
                0) Выход;\n\
                1) Сумма;\n\
                2) Разность;\n\
                3) Умножение;\n\
                4) Деление;\n");
                
        if (scanf("%d", &number) != 1) {
            printf("Неверный ввод. Введите число!\n");
            while (getchar() != '\n'); 
            continue; 
        }
        switch (number){
        {
        case 1:
            int d;
            printf("Введите количество суммируемых элементов: ");
            scanf("%d", &d);
            printf("Введите слагаемые: ");
            double *ptr = malloc(sizeof(double) * d);
            for(int i = 0; i < d; ++i){
                scanf("%lf", &ptr[i]);
            }
            func = dlsym(library_handler, "sum");
            double result = func(ptr, d);
            printf("Результат: %.2lf\n", result);
            free(ptr);
            break;
        }
        {
        case 2:
            int d;
            printf("Введите количество элементов: ");
            scanf("%d", &d);
            printf("Введите элементы для разности: ");
            double *ptr = malloc(sizeof(double) * d);
            for(int i = 0; i < d; ++i){
                scanf("%lf", &ptr[i]);
            }
            func = dlsym(library_handler, "diff");
            double result = func(ptr, d);
            printf("Результат: %.2lf\n", result);
            free(ptr);
            break;
        }
        
         case 3:
        {
            int d;
            printf("Введите количество элементов: ");
            scanf("%d", &d);
            printf("Введите элементы для умножения: ");
            double *ptr = malloc(sizeof(double) * d);
            for(int i = 0; i < d; ++i){
                scanf("%lf", &ptr[i]);
            }
            func = dlsym(library_handler, "mult");
            double result = func(ptr, d);
            printf("Результат: %.2lf\n", result);
            free(ptr);
            break;  
        }
        case 4:
        {
            int d;
            printf("Введите количество элементов: ");
            scanf("%d", &d);
            printf("Введите элементы для деления: ");
            double *ptr = malloc(sizeof(double) * d);
            for(int i = 0; i < d; ++i){
                scanf("%lf", &ptr[i]);
                if(ptr[i] == 0){
                     printf("Обнаружен 0, делить на 0 нельзя.\n");
                     break;
                }
            }
            func = dlsym(library_handler, "dev");
            double result = func(ptr, d);
            printf("Результат: %.2lf\n", result);
            free(ptr);
            break;  
        }
        case 0:
        {
            printf("Выполнен выход.\n");
            return 0;
        }
        default:
            printf("Неверный ввод.");
            return 0;
        }
    }

    dlclose(library_handler);
    return 0;
}