/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.123 (20150530)                        **
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

/* Include standard headers */
#include <stdlib.h> /*
    const : EXIT_SUCCESS
            EXIT_FAILURE
*/

/* Include ChemicalX headers */
#include "cassowary/abstract_variable.h" /*
    type  : cass_AbstractVariable
    func  : cass_AbstractVariable_new
            cass_AbstractVariable_del
            cass_AbstractVariable_println
*/

/* FOR TESTING !!! */
#include "utils.h" /*
    func  : cx_Bool_print
            cx_Float_print
            cx_Char_print
            cx_CharPtr_print
*/
#include "containers/list_template.h" /*
    macro : cx_List_TEMPLATE
*/

cx_List_TEMPLATE(BoolList    , bool      , cx_Bool_print   )
cx_List_TEMPLATE(FloatList   , float     , cx_Float_print  )
cx_List_TEMPLATE(CharList    , char      , cx_Char_print   )
cx_List_TEMPLATE(CharPtrList , char *    , cx_CharPtr_print)
cx_List_TEMPLATE(CharListList, CharList *, CharList_print  )


/*----------------------------------------------------------------------------*/
int
main(void)
{
    cass_AbstractVariable *var;
    if (!cass_AbstractVariable_new(&var, "hello", sizeof "hello"))
        return EXIT_FAILURE;
    cass_AbstractVariable_println(&var);
    cass_AbstractVariable_del(&var);
    cass_AbstractVariable_println(&var);

    BoolList *b;
    if (!BoolList_from_data(&b, 4, (bool[]){true, false, false, true}))
        return EXIT_FAILURE;
    BoolList_println(&b);
    BoolList_del(&b);
    BoolList_println(&b);

    FloatList *f;
    if (!FloatList_from_data(&f, 6, (float[]){1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 6.7f}))
        return EXIT_FAILURE;
    FloatList_println(&f);
    FloatList_del(&f);

    CharList *c;
    if (!CharList_from_data(&c, 12, "hello world"))
        return EXIT_FAILURE;
    CharList_println(&c);
    CharList_del(&c);

    CharPtrList *s;
    if (!CharPtrList_from_data(&s, 5, (char*[]){"hello", "world", "how", "are", "you"}))
        return EXIT_FAILURE;
    CharPtrList_println(&s);
    CharPtrList_del(&s);

    CharListList *l;
    if (!CharListList_from_data(&l, 3, (CharList*[]){c, c, c}))
        return EXIT_FAILURE;
    CharListList_println(&l);
    CharListList_del(&l);

    return EXIT_SUCCESS;
}
