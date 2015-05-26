/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.044 (20150526)                        **
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

/* Include user defined headers */
#include "cassowary/abstract_variable.h" /*
    type  : cass_AbstractVariable
*/
#include "utils.h" /*
    macro : cx_FORMAT_STRUCT
            cx_STRINGIFY_BOOL
*/



/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cass_AbstractVariable_init(cass_AbstractVariable **self,
                           const char             *name,
                           const size_t            name_length)
{
    cass_AbstractVariable *abs_var;
    if (!(abs_var = malloc(sizeof(cass_AbstractVariable))))
    {
        fprintf(stderr, "cass_AbstractVariable_init(): Cannot allocate "
                        "space for cass_AbstractVariable\n"
                        "(Hint: the name was: '%s')\n", name);
        goto Self_Alloc_Error;
    }

    if (!(abs_var->name = malloc(name_length)))
    {
        fprintf(stderr, "cass_AbstractVariable_init(): Cannot allocate "
                        "space for cass_AbstractVariable->name\n"
                        "(Hint: the name was: '%s')\n", name);
        goto Name_Alloc_Error;
    }

    /* Store `name` property */
    if (!strncpy(abs_var->name, name, name_length - 1))
    {
        fprintf(stderr, "cass_AbstractVariable_init(): Cannot copy "
                        "name to cass_AbstractVariable->name\n"
                        "(Hint: the name was: '%s')\n", name);
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
cass_AbstractVariable_del(cass_AbstractVariable **self)
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
void
cass_AbstractVariable_print(cass_AbstractVariable *self)
{
    /* If there was an error, or the instance has been deleted */
    if (!self)
    {
        printf(cx_FORMAT_STRUCT("cass_AbstractVariable", ""), self);
        return;
    }
    /* Print formatted representation of this instance */
    printf(cx_FORMAT_STRUCT("cass_AbstractVariable",
                            ".name=\"%s\", "
                            ".name_length=%zu, "
                            ".is_dummy=%s, "
                            ".is_external=%s, "
                            ".is_pivotable=%s, "
                            ".is_restricted=%s"),
           self->name,
           self->name_length,
           cx_STRINGIFY_BOOL(self->is_dummy),
           cx_STRINGIFY_BOOL(self->is_external),
           cx_STRINGIFY_BOOL(self->is_pivotable),
           cx_STRINGIFY_BOOL(self->is_restricted),
           self);
}
