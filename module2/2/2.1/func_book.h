#ifndef FUNC_BOOK_H
#define FUNC_BOOK_H

typedef struct AdditionalInformation{
        char *tg;
        char *vk;
        char *whatsapp;
        char *github;
} AI;

typedef struct PhoneBook{
        char *name;
        char *surname;
        char *patronymic;
        char *number;
        char *email;
        AI additional;
} Book;

void showContact();

void addContact();

void delContact(int index);

void changeContact(int index);

void clear_buffer();

#endif