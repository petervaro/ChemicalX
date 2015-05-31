/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.3.190 (20150531)                        **
**             File: ChemicalX/include/containers/list_template.h             **
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
#ifndef __CHEMICAL_X_CONTAINERS_LIST_TEMPLATE_H_906927306272855__
#define __CHEMICAL_X_CONTAINERS_LIST_TEMPLATE_H_906927306272855__

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stddef.h> /*
    type  : size_t
*/
#include <stdbool.h> /*
    type  : bool
*/

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include ChemicalX headers */
#include "containers/list.h" /*
    type  : cx_List
    func  : cx_List_new
            cx_list_del
            cx_List_print
            cx_List_println
            cx_List_from_data
*/



/* Declaration of type */
/*----------------------------------------------------------------------------*/
#define cx_List_TEMPLATE_H(LIST_TYPE,                                          \
                           DATA_TYPE)                                          \
    /*-----------------------------------------------------------------------*/\
    typedef cx_List LIST_TYPE;                                                 \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## new(LIST_TYPE **const self);                             \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## from_data(LIST_TYPE **const self,                        \
                                size_t            item_count,                  \
                                DATA_TYPE  *const items);                      \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    LIST_TYPE ## _ ## del(LIST_TYPE **const self);                             \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    LIST_TYPE ## _ ## print(LIST_TYPE *const *const self);                     \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    LIST_TYPE ## _ ## println(LIST_TYPE *const *const self);                   \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## len(LIST_TYPE *const self,                               \
                          size_t          *length);                            \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## clear(LIST_TYPE *const self);                            \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## to_array(LIST_TYPE *const self,                          \
                               size_t          *copy_count,                    \
                               size_t           item_count,                    \
                               DATA_TYPE       *items);



/* Definition of type */
/*----------------------------------------------------------------------------*/
#define cx_List_TEMPLATE_C(LIST_TYPE,                                          \
                           DATA_TYPE,                                          \
                           DATA_PRINTER)                                       \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## new(LIST_TYPE **const self)                              \
    {                                                                          \
        return cx_List_new(self, sizeof(DATA_TYPE));                           \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## from_data(LIST_TYPE **const self,                        \
                                size_t            item_count,                  \
                                DATA_TYPE  *const items)                       \
    {                                                                          \
        return cx_List_from_data(self, sizeof(DATA_TYPE), item_count, items);  \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    LIST_TYPE ## _ ## del(LIST_TYPE **const self)                              \
    {                                                                          \
        cx_List_del(self);                                                     \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    LIST_TYPE ## _ ## print(LIST_TYPE *const *const self)                      \
    {                                                                          \
        cx_List_print(self, &DATA_PRINTER);                                    \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    LIST_TYPE ## _ ## println(LIST_TYPE *const *const self)                    \
    {                                                                          \
        cx_List_println(self, &DATA_PRINTER);                                  \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## len(LIST_TYPE *const self,                               \
                          size_t          *length)                             \
    {                                                                          \
        return cx_List_len(self, length);                                      \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## clear(LIST_TYPE *const self)                             \
    {                                                                          \
        return cx_List_clear(self);                                            \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    bool                                                                       \
    LIST_TYPE ## _ ## to_array(LIST_TYPE *const self,                          \
                               size_t          *copy_count,                    \
                               size_t           item_count,                    \
                               DATA_TYPE       *items)                         \
    {                                                                          \
        return cx_List_to_array(self, copy_count, item_count, items);          \
    }

#endif /* __CHEMICAL_X_CONTAINERS_LIST_TEMPLATE_H_906927306272855__ */
