#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func_book.h"

#define MAXSTRING 40
#define MAXCONTACTS 50

Book *person[MAXCONTACTS];

int count = 0;

char * input_func(){

    char buf[MAXSTRING];

    fgets(buf, MAXSTRING, stdin);
    
    size_t len = strlen(buf);
    
    if(len > 0 && buf[len-1] == '\n') buf[len-1] = '\0';
    
    char * str = malloc(strlen(buf) + 1);
    if (str != NULL){
        strcpy(str, buf);
    }
    
    return str;
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void addContact(){

    if(count >= MAXCONTACTS){
        printf("Ваша телефонная книга переполнена, либо удалите людей из жизни, либо остановитесь");
        return;
    }

    person[count] = malloc(sizeof(Book));

    printf("Введите имя:\n");
    person[count]->name = input_func();
    
    printf("Введите фамилию:\n");
    person[count]->surname = input_func();
    
    int d;
    printf("Желаете ли вы ввести дополнительную информацию?\n\
        1. Да\n\
        2. Нет\n");
    
    scanf("%d", &d);
    clear_buffer();
    if(d == 1){
        printf("Введите отчество:\n");
        person[count]->patronymic = input_func();
        
        printf("Введите номер телефона:\n");
        person[count]->number = input_func();

        printf("Введите почту:\n");
        person[count]->email = input_func();
    }
    else if(d == 2) printf("Пропускаем ввод дополнительной информации.\n");
    else{
        printf("Неверный ввод.\n");
        return;
    }
    int temp;
    printf("Хотите ли вы добавить профили?\n\
    1. Да\n\
    2. Нет\n");
    scanf("%d", &temp);
    clear_buffer();
    
    if(temp == 1){
        printf("Что вы хотите добавить?\n\
        1. Telegram;\n\
        2. VK\n\
        3. WhatsApp\n\
        4. GitHub\n");
        int temp2;
        scanf("%d", &temp2);
        clear_buffer();
        switch (temp2)
        {
        {
        case 1:
            printf("Введите Telegram:\n");
            person[count]->additional.tg = input_func();
            break;
        }
        {
        case 2:
            printf("Введите VK:\n");
            person[count]->additional.vk = input_func();
            break;
        }
        {
        case 3:
            printf("Введите WhatsApp:\n");
            person[count]->additional.whatsapp = input_func();
            break;
        }
        {
        case 4:
            printf("Введите GitHub:\n");
            person[count]->additional.github = input_func();
            break;
        }
        {
        default:
            printf("Неверный пункт. Обойдешься без дополнительной информации. Выход.\n");
            break;
        }
    }
    }

    else if (temp == 2){
        printf("Печально что ваш контакт не имеет ничего :(\n");
    }

    else if (temp != 2 || temp != 1){
        printf("Неверный ввод.\n");
    }

    ++count;
    return;
}

void showContact(){
    if(count == 0){
        printf("Телефонная книга пуста\n");
        return;
    }
    printf("Существующие контакты:\n\n");

    for(int i = 0, j = 1; i < count; ++i){
        printf("%d. ", j);
        printf("%s ", person[i]->name);
        printf("%s ", person[i]->surname);
        if(person[i]->patronymic != NULL) printf("%s ", person[i]->patronymic);
        if(person[i]->number != NULL) printf("%s ", person[i]->number);
        if(person[i]->email != NULL) printf("%s ", person[i]->email);
        if(person[i]->additional.tg != NULL) printf("Telegram: %s ", person[i]->additional.tg);
        if(person[i]->additional.vk != NULL) printf("VK: %s ", person[i]->additional.vk);
        if(person[i]->additional.whatsapp != NULL) printf("WhatsApp: %s ", person[i]->additional.whatsapp);
        if(person[i]->additional.github != NULL) printf("GitHub: %s ", person[i]->additional.github);
        printf("\n\n");
        ++j;
    }
    return;
} 

void delContact(int index){

    if(count == 0){
        printf("Кого ты собираешься удалять? У тебя никого нет в книге..");
        return;
    }

    if(index < 1 || index > count){
        printf("Неверный индекс, ты хочешь удалить пустоту из своей жизни..\n");
        return;
    }

    int idx = index - 1;
    free(person[idx]->name);
    person[idx]->name = NULL;
    free(person[idx]->surname);
    person[idx]->surname = NULL;
    free(person[idx]->patronymic);
    person[idx]->patronymic = NULL;
    free(person[idx]->number);
    person[idx]->number = NULL;
    free(person[idx]->email);
    person[idx]->email = NULL;

    if(person[idx]->additional.tg != NULL){
        free(person[idx]->additional.tg);
        person[idx]->additional.tg = NULL;
    }
    if(person[idx]->additional.vk != NULL){
        free(person[idx]->additional.vk);
        person[idx]->additional.vk = NULL;
    }
    if(person[idx]->additional.whatsapp != NULL){
        free(person[idx]->additional.whatsapp);
        person[idx]->additional.whatsapp = NULL;
    }
    if(person[idx]->additional.github != NULL){
        free(person[idx]->additional.github);
        person[idx]->additional.github = NULL;
    }
    free(person[idx]);
    person[idx] = NULL;

    for (int i = idx; i < count - 1; i++) {
        person[i] = person[i + 1];
    }

    count--;
    printf("Персонаж с индексом: %d успешно удалён из вашей жизни.\n", index);
    return;
}

void changeContact(int index){
    if(index < 1 || index > count){
        printf("Неверный индекс.\n");
        return;
    }
    int temp;
    printf("Что вы хотите изменить?\n\
        1. Имя\n\
        2. Фамилия\n\
        3. Отчество\n\
        4. Номер\n\
        5. Почта\n");
    
    if(person[index - 1]->additional.tg != NULL) printf("\t6. Telegram\n");
    if(person[index - 1]->additional.vk != NULL) printf("\t7. VK\n");
    if(person[index - 1]->additional.whatsapp != NULL) printf("\t8. WhatsApp\n");
    if(person[index - 1]->additional.github != NULL) printf("\t9. GitHub\n");

    scanf("%d", &temp);
    clear_buffer();
    char * new_value = NULL;
    switch (temp)
    {
    case 1:
        printf("Введите новое имя: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->name);
            person[index - 1]->name = new_value;
            printf("Имя успешно изменено!\n");
        }
        break;
    case 2:
        printf("Введите новую фамилию: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->surname);
            person[index - 1]->surname = new_value;
            printf("Фамилия успешно изменена!\n");
        }
        break;
    case 3:
        printf("Введите новое отчество: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->patronymic);
            person[index - 1]->patronymic = new_value;
            printf("Отчество успешно изменено!\n");
        }
        break;
    case 4:
        printf("Введите новый номер телефона: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->number);
            person[index - 1]->number = new_value;
            printf("Номер телефона успешно изменен!\n");
        }
        break;
    case 5:
        printf("Введите новую почту: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->email);
            person[index - 1]->email = new_value;
            printf("Почта успешно изменена!\n");
        }
        break;
    case 6:
        printf("Введите новый Telegram: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->additional.tg);
            person[index - 1]->additional.tg = new_value;
            printf("Telegram успешно изменен!\n");
        }
        break;
    case 7:
        printf("Введите новый VK: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->additional.vk);
            person[index - 1]->additional.vk = new_value;
            printf("VK успешно изменен!\n");
        }
        break;
    case 8:
        printf("Введите новый WhatsApp: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->additional.whatsapp);
            person[index - 1]->additional.whatsapp = new_value;
            printf("WhatsApp успешно изменен!\n");
        }
        break;
    case 9:
        printf("Введите новый GitHub: ");
        new_value = input_func();
        if (new_value != NULL) {
            free(person[index - 1]->additional.github);
            person[index - 1]->additional.github = new_value;
            printf("GitHub успешно изменен!\n");
        }
        break;
    default:
        break;
    }

    return;
}