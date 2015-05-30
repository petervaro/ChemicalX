/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.126 (20150530)                        **
**               File: ChemicalX/tests/containers/list_types.c                **
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

/* Include ChemicalX headers */
#include "utils.h" /*
    func  : cx_Int_print
            cx_Float_print
            cx_Char_print
            cx_CharPtr_print
*/
#include "containers/list_template.h" /*
    macro : cx_List_TEMPLATE_C
*/

/* Include test headers */
#include "tests/containers/list_types.h"

cx_List_TEMPLATE_C(IntList            , int              , cx_Int_print)
cx_List_TEMPLATE_C(FloatList          , float            , cx_Float_print)
cx_List_TEMPLATE_C(CharList           , char             , cx_Char_print)
cx_List_TEMPLATE_C(CharPtrList        , char *           , cx_CharPtr_print)
cx_List_TEMPLATE_C(CharPtrListList    , CharPtrList *    , CharPtrList_print)
cx_List_TEMPLATE_C(CharPtrListListList, CharPtrListList *, CharPtrListList_print)
