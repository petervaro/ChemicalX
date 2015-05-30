/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.126 (20150530)                        **
**               File: ChemicalX/tests/containers/list_types.h                **
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

#ifndef __CHEMICAL_X_TESTS_CONTAINERS_LIST_TYPES_H_965266818368777__
#define __CHEMICAL_X_TESTS_CONTAINERS_LIST_TYPES_H_965266818368777__

/* Include ChemicalX headers */
#include "containers/list_template.h" /*
    macro : cx_List_TEMPLATE_H
*/

cx_List_TEMPLATE_H(IntList            , int              )
cx_List_TEMPLATE_H(FloatList          , float            )
cx_List_TEMPLATE_H(CharList           , char             )
cx_List_TEMPLATE_H(CharPtrList        , char *           )
cx_List_TEMPLATE_H(CharPtrListList    , CharPtrList *    )
cx_List_TEMPLATE_H(CharPtrListListList, CharPtrListList *)

#endif /* __CHEMICAL_X_TESTS_CONTAINERS_LIST_TYPES_H_965266818368777__ */
