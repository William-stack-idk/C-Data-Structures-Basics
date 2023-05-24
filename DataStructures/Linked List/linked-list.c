#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

LinkedList *create_linkedList()
{
    LinkedList *ptr = malloc(sizeof(LinkedList));
    if (ptr == NULL)
        return NULL;
    ptr->head = ptr->tail = NULL;
    return ptr;
}

int is_empty(LinkedList *list)
{
    if (!list)
        return -1;
    return list->head == NULL;
}

int add_first(LinkedList *list, int value)
{
    if (!list)
        return -1;
    Node *ptr = malloc(sizeof(Node));
    if (ptr == NULL)
        return -1;
    ptr->value = value;
    if (isEmpty(list))
    {
        ptr->next = NULL;
        list->head = list->tail = ptr;
        return 0;
    }
    ptr->next = list->head;
    list->head = ptr;
    return 0;
}

int add_last(LinkedList *list, int value)
{
    if (!list)
        return -1;
    Node *ptr = malloc(sizeof(Node));
    if (ptr == NULL)
        return -1;
    ptr->next = NULL;
    ptr->value = value;
    if (isEmpty(list))
    {
        list->head = list->tail = ptr;
        return 0;
    }
    list->tail->next = ptr;
    return 0;
}

int clear(LinkedList *list)
{
    if (!list)
        return -1;
    Node *current = list->head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
    free(list);
    return 0;
}

int contains(int value, LinkedList *list)
{
    if (!list)
        return -1;
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->value == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *find(int value, LinkedList *list)
{
    if (!list)
        return -1;
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->value == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int remove_node(int value, LinkedList *list)
{
    if (!list)
        return -1;
    Node *current = list->head;
    Node *next = current->next;
    if (current->value == value)
    {
        list->head = next;
        free(current);
        return 0;
    }
    while (next != NULL)
    {
        if (next->value == value)
        {
            current->next = next->next;
            return 0;
        }
        current = next;
        next = current->next;
    }
    return 1;
}

int print_list(LinkedList *list)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
    return 0;
}