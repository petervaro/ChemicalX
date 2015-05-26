/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.016 (20150526)                        **
**           File: ChemicalX/include/cassowary/abstract_variable.h            **
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
#ifndef __CHEMICAL_X_CASSOWARY_ABSTRACT_VARIABLE_H_32906941309829807__
#define __CHEMICAL_X_CASSOWARY_ABSTRACT_VARIABLE_H_32906941309829807__

/* Include standard headers */
#include <stddef.h> /*
    type  : size_t
*/
#include <stdbool.h> /*
    type  : bool
*/

/*----------------------------------------------------------------------------*/
/* Properties of cass_AbstractVariable */
#define cass_ABSTRACT_VARIABLE()    \
    char       *name;               \
    size_t      name_length;        \
    bool        is_dummy;           \
    bool        is_external;        \
    bool        is_pivotable;       \
    bool        is_restricted;



/*----------------------------------------------------------------------------*/
typedef struct
{
    cass_ABSTRACT_VARIABLE()
} cass_AbstractVariable;
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cass_AbstractVariable_init(cass_AbstractVariable **self,
                           const char             *name,
                           const size_t            name_length);
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cass_AbstractVariable_del(cass_AbstractVariable **self);
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cass_AbstractVariable_print(cass_AbstractVariable *self);

#endif /* __CHEMICAL_X_CASSOWARY_ABSTRACT_VARIABLE_H_32906941309829807__ */
