/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.126 (20150530)                        **
**                 File: ChemicalX/include/containers/list.h                  **
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

/* Header guard */
#ifndef __CHEMICAL_X_CONTAINERS_LIST_H_944183585536577__
#define __CHEMICAL_X_CONTAINERS_LIST_H_944183585536577__

/* Include standard headers */
#include <stddef.h> /*
    type  : size_t
*/
#include <stdbool.h> /*
    type  : bool
*/

/*----------------------------------------------------------------------------*/
typedef struct cx_list_node
{
    struct cx_list_node *next;    /* Pointer to next node */
    char                 data[];  /* Internally stored data */
} cx_ListNode;



/*----------------------------------------------------------------------------*/
typedef struct
{
    size_t       data_size;  /* Size of the data in each node */
    size_t       length;     /* Number of nodes in the list */
    cx_ListNode *head;       /* Pointer to first node */
    cx_ListNode *tail;       /* Pointer to last node */
} cx_List;

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cx_List_new(cx_List **self,
            size_t    item_size);
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cx_List_from_data(cx_List **self,
                  size_t    item_size,
                  size_t    item_count,
                  void     *items);
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cx_List_del(cx_List **self);
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cx_List_print(cx_List *const *const self,
              void                (*data_printer)());
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cx_List_println(cx_List *const *const self,
                void                (*data_printer)());

#endif /* __CHEMICAL_X_CONTAINERS_LIST_H_944183585536577__ */
