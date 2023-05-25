#ifndef GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_H
/**
 * @file generic_linked_list.h
 * @brief Declaration of the generic linked list data structure and related functions.
 */

/**
 * @struct GenericData
 * @brief Structure representing generic data along with its size.
 */
typedef struct
{
    void *ptr;   /**< Pointer to the generic data */
    size_t size; /**< Size of the data in bytes */
} GenericData;

/**
 * @struct Node
 * @brief Structure representing a node in the generic linked list.
 */
typedef struct Node
{
    GenericData data;  /**< Generic data stored in the node. */
    struct Node *next; /**< Pointer to the next node in the list. */
} Node;

/**
 * @struct LinkedList_G
 * @brief Structure representing a generic Linked List.
 */
typedef struct
{
    Node *head;           /**< Pointer to the first node in the list. */
    Node *tail;           /**< Pointer to the last node in the list. */
    size_t _element_size; /**< size of the data stored in each node in bytes. */
} LinkedList_G;

/**
 * @brief Creates an empty generic linked list.
 * @param data_size The size of the data to be stored in each node.
 * @return A pointer to the newly created generic linked list.
 */
LinkedList_G *create_linkedList(size_t data_size);

/**
 * @brief Checks if a generic linked list is empty.
 * @param list The generic linked list to check.
 * @return 1 if the list is empty, 0 otherwise.
 */
int is_empty(LinkedList_G *list);

/**
 * @brief Adds a new node with the given value at the beginning of the generic linked list.
 * @param list The generic linked list to which the node will be added.
 * @param value Pointer to the value to be stored in the new node.
 * @param data_size The size of the data to be added.
 * @return 0 if the operation is successful.
 */
int add_first(LinkedList_G *list, void *value, size_t data_size);

/**
 * @brief Adds a new node with the given value at the end of the generic linked list.
 * @param list The generic linked list to which the node will be added.
 * @param value Pointer to the value to be stored in the new node.
 * @param data_size The size of the data to be added.
 * @return 0 if the operation is successful.
 */
int add_last(LinkedList_G *list, void *value, size_t data_size);

/**
 * @brief Removes all nodes from the generic linked list.
 * @param list The generic linked list to clear.
 * @return 0 if the operation is successful.
 */
int clear(LinkedList_G *list);

/**
 * @brief Checks if the generic linked list contains a node with the given value.
 * @param list The generic linked list to search in.
 * @param value Pointer to the value to search for.
 * @param compare Callback function used to compare two generic data types.
 * @return 1 if the value is found, 0 otherwise.
 * @note The callback function must adhere to the function signiture specified in the decleration.
 * @example
 * // Example usage of the function with a callback function
 * int compare(void *A, void *B){
 *      //Compare A and B
 *      return 1; //Return 1 if the values are equal, zero otherwise.
 * }
 *
 * // Calling the function with the callback
 * int status = contains(list, data, compare);
 */
int contains(LinkedList_G *list, void *value, int (*compare)(void *, void *));

/**
 * @brief Finds the first occurrence of a node with the given value in the generic linked list.
 * @param list The generic linked list to search in.
 * @param value Pointer to the value to search for.
 * @param compare Callback function used to compare two generic data types.
 * @return A pointer to the node with the specified value, or NULL if not found.
 * @note The callback function must adhere to the function signiture specified in the decleration.
 * @example
 * // Example usage of the function with a callback function
 * int compare(void *A, void *B){
 *      //Compare A and B
 *      return 1; //Return 1 if the values are equal, zero otherwise.
 * }
 *
 * // Calling the function with the callback
 * Node *node = find(list, data, compare);
 */
Node *find(LinkedList_G *list, void *value, int (*compare)(void *, void *));

/**
 * @brief Removes the first node with the given value from the generic linked list.
 * @param list The generic linked list from which to remove the node.
 * @param value pointer to the value to remove.
 * @param compare Callback function used to compare two generic data types.
 * @return 1 if a node is removed, 0 if the value is not found.
 * @note The callback function must adhere to the function signiture specified in the decleration.
 * @example
 * // Example usage of the function with a callback function
 * int compare(void *A, void *B){
 *      //Compare A and B
 *      return 1; //Return 1 if the values are equal, zero otherwise.
 * }
 *
 * // Calling the function with the callback
 * int status = remove(list, data, compare);
 */
int remove_node(LinkedList_G *list, void *value, int (*compare)(void *, void *));

/**
 * @brief Prints the values of all nodes in the linked list.
 * @param list The linked list to print.
 * @param callback A callback function that prints the genric data.
 * @return 0 if the operation is successful.
 * @note The callback function must adhere to the function signiture specified in the decleration.
 * @example
 * // Example usage of the function with a callback function
 * void compare(void *A){
 *      //Print A
 * }
 *
 * // Calling the function with the callback
 * int status = print(list, callback);
 */
int print_list(LinkedList_G *list, void (*callback)(void *));

#endif