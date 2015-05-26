/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.032 (20150526)                        **
**                         File: ChemicalX/src/main.c                         **
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

#include <stdlib.h> /*
    const : EXIT_SUCCESS
            EXIT_FAILURE
*/

/* namespace => cx_Draw() */

#include "cassowary/abstract_variable.h" /*
    type  : cass_AbstractVariable
    func  : cass_AbstractVariable_init
            cass_AbstractVariable_del
            cass_AbstractVariable_print
*/



/*----------------------------------------------------------------------------*/
int
main(void)
{
    cass_AbstractVariable *var;
    if (!cass_AbstractVariable_init(&var, "hello", sizeof "hello"))
        return EXIT_FAILURE;
    cass_AbstractVariable_print(var);
    cass_AbstractVariable_del(&var);
    cass_AbstractVariable_print(var);

    return EXIT_SUCCESS;
}
