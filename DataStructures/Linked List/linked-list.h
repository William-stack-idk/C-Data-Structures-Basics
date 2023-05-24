#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * @file linked_list.h
 * @brief Declaration of the linked list data structure and related functions.
 */

/**
 * @struct Node
 * @brief Structure representing a node in the linked list.
 */
typedef struct Node
{
    int value;         /**< The value stored in the node. */
    struct Node *next; /**< Pointer to the next node in the list. */
} Node;

/**
 * @struct LinkedList
 * @brief Structure representing a Linked List.
 */
typedef struct
{
    Node *head; /**< Pointer to the first node in the list. */
    Node *tail; /**< Pointer to the last node in the list. */
} LinkedList;

/**
 * @brief Creates an empty linked list.
 * @return A pointer to the newly created linked list.
 */
LinkedList *create_linkedList();

/**
 * @brief Checks if a linked list is empty.
 * @param list The linked list to check.
 * @return 1 if the list is empty, 0 otherwise.
 */
int is_empty(LinkedList *list);

/**
 * @brief Adds a new node with the given value at the beginning of the linked list.
 * @param list The linked list to which the node will be added.
 * @param value The value to be stored in the new node.
 * @return 0 if the operation is successful.
 */
int add_first(LinkedList *list, int value);

/**
 * @brief Adds a new node with the given value at the end of the linked list.
 * @param list The linked list to which the node will be added.
 * @param value The value to be stored in the new node.
 * @return 0 if the operation is successful.
 */
int add_last(LinkedList *list, int value);

/**
 * @brief Removes all nodes from the linked list.
 * @param list The linked list to clear.
 * @return 0 if the operation is successful.
 */
int clear(LinkedList *list);

/**
 * @brief Checks if the linked list contains a node with the given value.
 * @param list The linked list to search in.
 * @param value The value to search for.
 * @return 1 if the value is found, 0 otherwise.
 */
int contains(LinkedList *list, int value);

/**
 * @brief Finds the first occurrence of a node with the given value in the linked list.
 * @param list The linked list to search in.
 * @param value The value to search for.
 * @return A pointer to the node with the specified value, or NULL if not found.
 */
Node *find(LinkedList *list, int value);

/**
 * @brief Removes the first node with the given value from the linked list.
 * @param list The linked list from which to remove the node.
 * @param value The value to remove.
 * @return 1 if a node is removed, 0 if the value is not found.
 */
int remove_node(LinkedList *list, int value);

/**
 * @brief Prints the values of all nodes in the linked list.
 * @param list The linked list to print.
 * @return 0 if the operation is successful.
 */
int print_list(LinkedList *list);

#endif
