/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.2.172 (20150531)                        **
**             File: ChemicalX/src/cassowary/abstract_variable.c              **
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

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stddef.h> /*
    type  : size_t
*/
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
    func  : strncpy
*/

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include jemalloc headers */
#include <jemalloc/jemalloc.h>

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include ChemicalX headers */
#include "cassowary/abstract_variable.h" /*
    type  : cass_AbstractVariable
*/
#include "utils.h" /*
    macro : cx_FORMAT_STRUCT
            cx_STRINGIFY_BOOL
*/



/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cass_AbstractVariable_new(cass_AbstractVariable **const self,
                          const char             *const name,
                          const size_t                  name_length)
{
    /* TODO: if name is NULL?
             if name_length is 0? (=> name_length - 1) */

    cass_AbstractVariable *abs_var;
    if (!(abs_var = malloc(sizeof(cass_AbstractVariable))))
    {
        fprintf(stderr, "cass_AbstractVariable_new(): Cannot allocate "
                        "memory for cass_AbstractVariable\n"
                        "(The name of the variable was: \"%s\")\n"
                        "(Hint: `malloc` (from <stdlib.h>) failed)\n", name);
        goto Self_Alloc_Error;
    }

    if (!(abs_var->name = malloc(name_length)))
    {
        fprintf(stderr, "cass_AbstractVariable_new(): Cannot allocate "
                        "memory for cass_AbstractVariable->name\n"
                        "(The name of the variable was: \"%s\")\n"
                        "(Hint: `malloc` (from <stdlib.h>) failed)\n", name);
        goto Name_Alloc_Error;
    }

    /* Store `name` property */
    if (!strncpy(abs_var->name, name, name_length - 1))
    {
        fprintf(stderr, "cass_AbstractVariable_new(): Cannot copy "
                        "name value to cass_AbstractVariable->name\n"
                        "(The name of the variable was: \"%s\")\n"
                        "(Hint: `strncpy` (from <string.h>) failed)\n", name);
        goto Name_Store_Error;
    }

    /* Make sure `name` is NULL terminated */
    abs_var->name[name_length] = '\0';

    /* Set `name_length` and set default values */
    abs_var->name_length   = name_length;
    abs_var->is_dummy      = false;
    abs_var->is_external   = false;
    abs_var->is_pivotable  = false;
    abs_var->is_restricted = false;

    /* If everything went fine */
    *self = abs_var;
    return true;

    /* If there was an error */
    Name_Store_Error:
        free(abs_var->name);
    Name_Alloc_Error:
        free(abs_var);
    Self_Alloc_Error:
        *self = NULL;
        return false;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cass_AbstractVariable_del(cass_AbstractVariable **const self)
{
    /* If there was an error, or the instance has been deleted */
    if (!*self)
        return;
    /* Free the `name` member and the instance itself */
    free((*self)->name);
    free(*self);
    /* Set pointer */
    *self = NULL;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#define cass_AbstractVariable_PRINT(SELF,                                      \
                                    LINE_END)                                  \
    /* If there was an error, or the instance has been deleted */              \
    if (!SELF)                                                                 \
        printf(cx_FORMAT_STRUCT_NULL("cass_AbstractVariable", LINE_END));      \
    /* Print formatted representation of this instance */                      \
    else                                                                       \
        printf(cx_FORMAT_STRUCT("cass_AbstractVariable",                       \
                                ".name=\"%s\", "                               \
                                ".name_length=%zu, "                           \
                                ".is_dummy=%s, "                               \
                                ".is_external=%s, "                            \
                                ".is_pivotable=%s, "                           \
                                ".is_restricted=%s",                           \
                                LINE_END),                                     \
               SELF->name,                                                     \
               SELF->name_length,                                              \
               cx_STRINGIFY_BOOL(SELF->is_dummy),                              \
               cx_STRINGIFY_BOOL(SELF->is_external),                           \
               cx_STRINGIFY_BOOL(SELF->is_pivotable),                          \
               cx_STRINGIFY_BOOL(SELF->is_restricted),                         \
               SELF);


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cass_AbstractVariable_print(cass_AbstractVariable *const *const self)
{
    cass_AbstractVariable_PRINT((*self), "")
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cass_AbstractVariable_println(cass_AbstractVariable *const *const self)
{
    cass_AbstractVariable_PRINT((*self), "\n")
}
