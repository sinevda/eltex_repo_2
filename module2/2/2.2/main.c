/* 

2.2 (1 балл). Написать программу-калькулятор: в основном меню программа
запрашивает у пользователя необходимое действие и аргументы. Затем
вызывает указанную функцию и выводит результат. После этого снова
запрашивает действие.

*/

#include <stdio.h>
#include <stdlib.h>

#include "func.h"

int main(int argc, char *argv[]){
    while(1){
        int number;

        printf("Калькулятор. \nВыберите операцию:\n\
                0) Выход;\n\
                1) Сумма;\n\
                2) Разность;\n\
                3) Умножение;\n\
                4) Деление;\n");

        scanf("%d", &number);

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
            printf("Результат: %.2lf\n", sum(ptr, d));
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
            printf("Результат: %.2lf\n", diff(ptr, d));
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
            printf("Результат: %.2lf\n", mult(ptr, d));
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
            
            printf("Результат: %.2lf\n", dev(ptr, d));
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


    return 0;
}