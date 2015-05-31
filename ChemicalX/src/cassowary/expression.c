/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.2.172 (20150531)                        **
**                 File: ChemicalX/src/cassowary/expression.c                 **
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
#include <stdlib.h> /*
    func  : malloc
            free
*/
#include <stdbool.h> /*
    type  : bool
    const : true
            false
*/

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include jemalloc headers */
#include <jemalloc/jemalloc.h>

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include ChemicalX headers */
#include "containers/hash_map.h" /*
    type  : cx_HashMap
    func  : cx_HashMap_new
            cx_HashMap_del
*/
#include "cassowary/expression.h" /*
    type  : cass_Expression
*/



/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
bool
cass_Expression_new(cass_Expression **const self)
{
    cass_Expression *expr;
    if (!(expr = malloc(sizeof(cass_Expression))))
    {
        fprintf(stderr, "cass_Expression_new(): Cannot allocate "
                        "memory for cass_Expression\n"
                        "(The name of the variable was: \"%s\")\n"
                        "(Hint: `malloc` (from <stdlib.h>) failed)\n", name);
        goto Self_Alloc_Error;
    }

    if (!cx_HashMap_new(&expr->terms))
    {
        fprintf(stderr, "cass_Expression_new(): Cannot initialize "
                        "cx_HashMap for cass_Expression->terms\n"
                        "(The name of the variable was: \"%s\")\n"
                        "(Hint: `cx_HashMap_new` "
                        "(from \"containers/hash_map.h\") failed)\n", name);
        goto Terms_Init_Error;
    }

    /* If everything went fine */
    *self = expr;
    return true;

    /* If there was an error */
    Terms_Init_Error:
        free(expr);
    Self_Alloc_Error:
        *self = NULL;
        return false;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cass_Expression_del(cass_Expression **const self)
{
    /* If there was an error, or the instance has been deleted */
    if (!*self)
        return;
    /* Delete `terms` member */
    cx_HashMap_del(&(*self)->terms);
    /* Free instance itself */
    free(*self);
    /* Set pointer */
    *self = NULL;
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
cass_Expression_print(cass_Expression *const *const self)
{

}
