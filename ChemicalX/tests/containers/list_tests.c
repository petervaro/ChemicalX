/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.2.140 (20150530)                        **
**               File: ChemicalX/tests/containers/list_tests.c                **
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
#include <stdio.h> /*
    const : stderr
    func  : printf
            fprintf
*/

/* Include test headers */
#include "tests/prefixes.h" /*
    macro : OKAY
            FAIL
            DEAD
*/
#include "tests/containers/list_types.h" /*
    type  : IntList
            FloatList
            CharList
            CharPtrList
            CharPtrListList
            CharPtrListListList
    func  : IntList_from_data
            IntList_print
            IntList_del
            FloatList_from_data
            FloatList_print
            FloatList_del
*/

/* Constant data */
static int ints[] = {1, 1, 2, 3, 5, 8, 13, 21, 34};
#define ints_LENGTH sizeof ints / sizeof(int)
static float floats[] = {0.1234f, 2.3456f, 4.5678f};
#define floats_LENGTH sizeof floats / sizeof(float)
static char *strings[] = {"alpha", "beta", "gamma", "delta", "epsilon", "zeta"};


/*----------------------------------------------------------------------------*/
void
list_test_case_001(void)
{
    IntList *i;
    if (!IntList_from_data(&i, ints_LENGTH, ints))
    {
        fprintf(stderr, DEAD "Cannot perform this test case\n");
        return;
    }
    IntList_println(&i);
    IntList_del(&i);
    IntList_println(&i);

    printf(OKAY "Test case `001` passed\n");
}


/*----------------------------------------------------------------------------*/
void
list_test_case_002(void)
{
    FloatList *f;
    if (!FloatList_from_data(&f, floats_LENGTH, floats))
    {
        fprintf(stderr, DEAD "Cannot perform this test case\n");
        return;
    }
    FloatList_println(&f);
    FloatList_del(&f);
    FloatList_println(&f);

    printf(OKAY "Test case `002` passed\n");
}


/*----------------------------------------------------------------------------*/
void
list_test_case_003(void)
{
    CharPtrList     *cpl_1;
    CharPtrList     *cpl_2;
    CharPtrList     *cpl_3;
    CharPtrList     *cpl_4;
    CharPtrList     *cpl_5;
    CharPtrList     *cpl_6;

    if (!CharPtrList_from_data(&cpl_1, 2, strings))
        goto Internal_Error;
    if (!CharPtrList_from_data(&cpl_2, 4, strings))
        goto Internal_Error;
    if (!CharPtrList_from_data(&cpl_3, 1, strings))
        goto Internal_Error;
    if (!CharPtrList_from_data(&cpl_4, 5, strings))
        goto Internal_Error;
    if (!CharPtrList_from_data(&cpl_5, 6, strings))
        goto Internal_Error;
    if (!CharPtrList_from_data(&cpl_6, 3, strings))
        goto Internal_Error;

    CharPtrList_println(&cpl_1);
    CharPtrList_println(&cpl_2);
    CharPtrList_println(&cpl_3);
    CharPtrList_println(&cpl_4);
    CharPtrList_println(&cpl_5);
    CharPtrList_println(&cpl_6);

    printf(OKAY "Test case `003`: 6 CharPtrLists have been created\n");

    CharPtrList *cpls[] = {cpl_1, cpl_2, cpl_3, cpl_4, cpl_5, cpl_6};

    CharPtrListList *cpll_1;
    CharPtrListList *cpll_2;
    CharPtrListList *cpll_3;

    if (!CharPtrListList_from_data(&cpll_1, 2, cpls))
        goto Internal_Error;
    if (!CharPtrListList_from_data(&cpll_2, 4, cpls))
        goto Internal_Error;
    if (!CharPtrListList_from_data(&cpll_3, 6, cpls))
        goto Internal_Error;

    CharPtrListList_println(&cpll_1);
    CharPtrListList_println(&cpll_2);
    CharPtrListList_println(&cpll_3);

    printf(OKAY "Test case `003`: 3 CharPtrListLists have been created\n");

    CharPtrListListList *cplll;

    if (!CharPtrListListList_from_data(&cplll, 3, (CharPtrListList *[]){cpll_1, cpll_2, cpll_3}))
        goto Internal_Error;

    CharPtrListListList_println(&cplll);

    printf(OKAY "Test case `003`: 1 CharPtrListListList has been created\n");

    /* Cleanup */
    CharPtrListListList_del(&cplll);

    CharPtrListList_del(&cpll_1);
    CharPtrListList_del(&cpll_2);
    CharPtrListList_del(&cpll_3);

    CharPtrList_del(&cpl_1);
    CharPtrList_del(&cpl_2);
    CharPtrList_del(&cpl_3);
    CharPtrList_del(&cpl_4);
    CharPtrList_del(&cpl_5);
    CharPtrList_del(&cpl_6);

    printf(OKAY "Test case `003` passed\n");
    return;

    Internal_Error:
        fprintf(stderr, DEAD "Cannot perform this test case\n");
}
