#include <stdio.h>
#include <stdlib.h>
#include "generic_linked_list.h"

LinkedList_G *create_linkedList(size_t data_size)
{
    LinkedList_G *list = malloc(sizeof(LinkedList_G));
    if (!list)
    {
        return NULL;
    }
    list->_element_size = data_size;
    list->head = list->tail = NULL;
}

int is_empty(LinkedList_G *list)
{
    return list->head == NULL;
}

int add_first(LinkedList_G *list, void *value, size_t data_size)
{
    if (!list)
        return -1;
    if (list->_element_size != data_size)
        return -1;
    Node *node = malloc(sizeof(Node));
    if (!node)
        return -1;
    node->data.ptr = malloc(data_size);
    if (!node->data.ptr)
    {
        free(node);
        return -1;
    }
    node->data.size = data_size;
    char *Dptr = node->data.ptr;
    char *Sptr = value;
    while (data_size > 0)
    {
        *Dptr = *Sptr;
        ++Dptr;
        ++Sptr;
        --data_size;
    }
    if (is_empty(list))
    {
        node->next = NULL;
        list->head = list->tail = node;
        return 0;
    }
    node->next = list->head;
    list->head = node;
    return 0;
}

int add_last(LinkedList_G *list, void *value, size_t data_size)
{
    if (!list)
        return -1;
    if (list->_element_size != data_size)
        return -1;
    Node *node = malloc(sizeof(Node));
    if (!node)
        return -1;
    node->data.ptr = malloc(data_size);
    if (!node->data.ptr)
    {
        free(node);
        return -1;
    }
    node->data.size = data_size;
    char *Dptr = node->data.ptr;
    char *Sptr = value;
    while (data_size > 0)
    {
        *Dptr = *Sptr;
        ++Dptr;
        ++Sptr;
        --data_size;
    }
    node->next = NULL;
    if (is_empty(list))
    {
        list->head = list->tail = node;
        return 0;
    }
    list->tail->next = node;
    list->tail = node;
    return 0;
}

int clear(LinkedList_G *list)
{
    if (!list)
        return -1;
    Node *current = list->head;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current->data.ptr);
        free(current);
        current = next;
    }
    list->head = list->tail = NULL;
    return 0;
}

int contains(LinkedList_G *list, void *value, int (*compare)(void *, void *))
{
    if (!list || !compare)
        return -1;
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (compare(value, temp->data.ptr))
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *find(LinkedList_G *list, void *value, int (*compare)(void *, void *))
{
    if (!list || !compare)
        return NULL;
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (compare(value, temp->data.ptr))
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int remove_node(LinkedList_G *list, void *value, int (*compare)(void *, void *))
{
    if (!list || !compare)
        return -1;
    if (is_empty(list))
        return 1;
    Node *current = list->head;
    Node *next = current->next;
    if (compare(current->data.ptr, value))
    {
        list->head = next;
        free(current->data.ptr);
        free(current);
        return 0;
    }
    while (next != NULL)
    {
        if (compare(next->data.ptr, value))
        {
            current->next = next->next;
            free(next->data.ptr);
            free(next);
            return 0;
        }
        current = next;
        next = current->next;
    }
    return 1;
}

int print_list(LinkedList_G *list, void (*callback)(void *))
{
    if (!list || !callback)
        return -1;
    Node *temp = list->head;
    while (temp != NULL)
    {
        callback(temp->data.ptr);
        temp = temp->next;
    }
    return 0;
}