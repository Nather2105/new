// Варіант №15

// Розробити програму, яка створює односпрямований список , елементами якого є дійсні числа.
//  У заданому списку  поміняти місцями сусідні елементи. Передбачити перегляд списку тільки один раз.
#include <stdio.h>

#include <stdlib.h>
int main()
{
    struct list
    {
        int data;
        struct list *next;
    };
    int n, i;
    printf("Input N: ");
    scanf("%d", &n);
    struct list *plist, *head;
    plist = (struct list*)malloc(sizeof(struct list));
    head = plist; // створення списка
    i = 1;
    do
    {
        scanf("%d", &plist->data);
        plist->next = (struct list*)malloc(sizeof(struct list));
        plist = plist->next;
    } while (++i < n);
    scanf("%d", &plist->data);
    plist->next = 0;
    plist = head; // Виведення елементів списку
    while (plist != 0)
    {
        printf("%d ", plist->data);
        plist = plist->next;
    }
    plist = head;
    i = 0;
    int swap;
    while(i < n-1){
        swap = plist->data; 
        plist->data = plist->next->data;
        plist->next->data = swap;
        plist = plist->next->next;
        i+=2;
    }
    plist = head;
    printf("\n");
    while (plist != 0)
    {
        printf("%d ", plist->data);
        plist = plist->next;
    }
}