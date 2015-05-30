/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.123 (20150530)                        **
**                   File: ChemicalX/src/containers/list.c                    **
**                                                                            **
**   For more information about the project, visit <http://chemicalx.org>.    **
**                       Copyright (C) 2015 Peter Varo                        **
**                                                                            **
**  This program is free software: you can redistribute it and/or modify it   **
**   under the terms of the GNU General Public License as published by the    **
**       Free Software Foundation, either version 3 of the License, or        **
**                    (at your option) any later version.                     **
**                                                                            **
**    This program is distributed in the hope that it will be useful, but     **
**         WITHOUT ANY WARRANTY; without even the implied warranty of         **
**            MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            **
**            See the GNU General Public License for more details.            **
**                                                                            **
**     You should have received a copy of the GNU General Public License      **
**     along with this program, most likely a file in the root directory,     **
**        called 'LICENSE'. If not, see <http://www.gnu.org/licenses>.        **
**                                                                            **
************************************************************************ INFO */

/* Include standard headers */
#include <stdio.h> /*
    macro : NULL
    const : stderr
    func  : printf
            fprintf
*/
#include <stdlib.h> /*
    func  : malloc
            free
*/
#include <stdbool.h> /*
    type  : bool
    const : true
            false
*/
#include <string.h> /*
    func  : memcpy
*/

/* Include ChemicalX headers */
#include "containers/list.h" /*
    type  : cx_List
            cx_ListNode
*/
#include "utils.h" /*
    macro : cx_FORMAT_CONTAINER_STRUCT_BEFORE
            cx_FORMAT_CONTAINER_STRUCT_AFTER
*/

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static inline void
cx_List_insert_nodes(cx_List     *self,
                     cx_ListNode *before,
                     cx_ListNode *first,
                     cx_ListNode *last,
                     cx_ListNode *after)
{
    /* If first node of sub-sequence will be an nth node of the list */
    if (before)
        before->next = first;
    /* If first node of sub-sequence will be the first node of the list */
    else
        self->head = first;
    /* If last node of  sub-sequence will be an nth node of the list */
    if (after)
        last->next = after;
    /* If last node of sub-sequence will be the last node of the list */
    else
    {
        self->tail = last;
        last->next = NULL;
    }
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
static inline bool
cx_List_new_nodes(cx_List     *self,
                  cx_ListNode *before,
                  cx_ListNode *after,
                  size_t       item_size,
                  size_t       item_count,
                  char        *items)
{
    /* Pointers to nodes of a new sub-sequence */
    cx_ListNode *first,
                *last,
                *nth;

    /* Create first node and also set as last,
       in case there is only one item added to the list */
    if (!(first = last = malloc(sizeof(cx_ListNode) + item_size)))
    {
        fprintf(stderr, "internal node-adder function: Cannot allocate "
                        "memory for cx_ListNode\n"
                        "(Hint: `malloc` (from <stdlib.h>) failed)\n");
        goto Node_First_Alloc_Error;
    }

    /* Copy data into the first node */
    if (!memcpy(first->data, items, item_size))
    {
        fprintf(stderr, "internal node-adder function: Cannot copy "
                        "input data to cx_ListNode->data\n"
                        "(Hint: `memcpy` (from <string.h>) failed)\n");
        goto Node_First_Data_Copy_Error;
    }

    /* Create an array of pointers to nodes in case the allocation of
       a node fails then the already created nodes can be cleaned up */
    cx_ListNode **nodes;
    if (!(nodes = malloc(sizeof(cx_ListNode*)*(item_count - 1))))
    {
        fprintf(stderr, "internal node-adder function: Cannot allocate "
                        "memory for temporary clean-up array for cx_ListNodes\n"
                        "(Hint: `malloc` (from <stdlib.h>) failed)\n");
        goto Node_Store_Error;
    }

    /* Create remaining nodes and link one after another */
    size_t i,
           node_count = 0;
    for (i=1; i<item_count; i++)
    {
        /* Create new node */
        if (!(nth = malloc(sizeof(cx_ListNode) + item_size)))
        {
            fprintf(stderr, "internal node-adder function: Cannot allocate "
                            "memory for cx_ListNode\n"
                            "(Hint: `malloc` (from <stdlib.h>) failed)\n");
            goto Node_Nth_Alloc_Error;
        }

        /* Store node in temporary array, increase counter */
        nodes[node_count++] = nth;

        /* Copy data into the nth node */
        if (!memcpy(nth->data, items + i*item_size, item_size))
        {
            fprintf(stderr, "internal node-adder function: Cannot copy "
                            "input data to cx_ListNode->data\n"
                            "(Hint: `memcpy` (from <string.h>) failed)\n");
            goto Node_Nth_Data_Copy_Error;
        }

        /* Link current node after last one and move on */
        last = last->next = nth;
    }

    /* If everything went fine */
    free(nodes);
    cx_List_insert_nodes(self, before, first, last, after);
    self->length += item_count;
    return true;

    /* If there was an error */
    Node_Nth_Data_Copy_Error:
    Node_Nth_Alloc_Error:
        for (i=0; i<node_count; i++)
            free(nodes[i]);
        free(nodes);
    Node_Store_Error:
    Node_First_Data_Copy_Error:
        free(first);
    Node_First_Alloc_Error:
        return false;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cx_List_new(cx_List **self,
            size_t    item_size)
{
    cx_List *list;
    if (!(list = malloc(sizeof(cx_List))))
    {
        fprintf(stderr, "cx_List_new(): Cannot allocate memory for cx_List\n"
                        "(Hint: `malloc` (from <stdlib.h>) failed)\n");
        goto Self_Alloc_Error;
    }

    /* Set default values */
    list->data_size = item_size;
    list->length    = 0;
    list->head      = NULL;
    list->tail      = NULL;

    /* If everything went fine */
    *self = list;
    return true;

    /* If there was an error */
    Self_Alloc_Error:
        *self = NULL;
        return false;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cx_List_from_data(cx_List **self,
                  size_t    item_size,
                  size_t    item_count,
                  void     *items)
{
    cx_List *list;
    if (!cx_List_new(&list, item_size))
    {
        fprintf(stderr, "cx_List_from_data(): Cannot initialize cx_List\n"
                        "(Hint: `cx_List_new` "
                        "(from \"containers/list.h\") failed)\n");
        goto Self_Alloc_Error;
    }

    if (!cx_List_new_nodes(list, NULL, NULL, item_size, item_count, items))
    {
        fprintf(stderr, "cx_List_from_data(): Cannot add items to cx_List\n"
                        "(Hint: internal node-adder function failed)\n");
        goto Node_Addition_Error;
    }

    /* If everything went fine */
    *self = list;
    return true;

    /* If there was an error */
    Node_Addition_Error:
        cx_List_del(&list);
    Self_Alloc_Error:
        *self = NULL;
        return false;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cx_List_del(cx_List **self)
{
    /* If there was an error, or the instance has been deleted */
    if (!*self)
        return;

    /* Free all nodes of the instance */
    cx_ListNode *next,
                *node = (*self)->head;
    while (node)
    {
        next = node->next;
        free(node);
        node = next;
    }
    /* Free the instance itself */
    free(*self);
    /* Set pointer */
    *self = NULL;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#define cx_List_PRINT(SELF,                                                    \
                      DATA_PRINTER,                                            \
                      SEPARATOR,                                               \
                      LINE_END)                                                \
    /* If there was an error, or the instance has been deleted */              \
    if (!SELF)                                                                 \
        printf(cx_FORMAT_STRUCT_NULL("cx_List", LINE_END));                    \
    /* Print formatted representation of this instance */                      \
    else                                                                       \
    {                                                                          \
        /* Start printing data */                                              \
        printf(cx_FORMAT_CONTAINER_STRUCT_BEFORE("cx_List",                    \
                                                 ".data_size=%zu, "            \
                                                 ".length=%zu"),               \
               SELF->data_size,                                                \
               SELF->length);                                                  \
                                                                               \
        /* If list is empty do not try to access elements */                   \
        if (!SELF->length)                                                     \
            goto List_Is_Empty;                                                \
                                                                               \
        /* Print first item */                                                 \
        DATA_PRINTER(&SELF->head->data);                                       \
        cx_ListNode *node = SELF->head->next;                                  \
                                                                               \
        /* Print remaining items */                                            \
        while (node)                                                           \
        {                                                                      \
            printf(SEPARATOR);                                                 \
            DATA_PRINTER(&node->data);                                         \
            node = node->next;                                                 \
        }                                                                      \
                                                                               \
        List_Is_Empty:                                                         \
        /* Stop printing data */                                               \
            printf(cx_FORMAT_CONTAINER_STRUCT_AFTER(LINE_END), SELF);          \
    }


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cx_List_print(cx_List *const *const self,
              void                (*data_printer)())
{
    cx_List_PRINT((*self), data_printer, ", ", "")
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cx_List_println(cx_List *const *const self,
                void                (*data_printer)())
{
    cx_List_PRINT((*self), data_printer, ", ", "\n")
}
