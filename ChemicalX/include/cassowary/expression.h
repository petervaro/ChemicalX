/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.071 (20150530)                        **
**               File: ChemicalX/include/cassowary/expression.h               **
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
#ifndef __CHEMICAL_X_CASSOWARY_EXPRESSION_H_5751759941745008__
#define __CHEMICAL_X_CASSOWARY_EXPRESSION_H_5751759941745008__

/* Include ChemicalX headers */
#include "containers/map.h" /*
    type  : cx_HashMap
*/

/*----------------------------------------------------------------------------*/
/* Properties of cass_Expression */
#define cass_Expression_HEAD()  \
    float       constant;       \
    cx_HashMap *terms;



/*----------------------------------------------------------------------------*/
typedef struct
{
    cass_Expression_HEAD()
} cass_Expression;
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#endif /* __CHEMICAL_X_CASSOWARY_EXPRESSION_H_5751759941745008__ */
