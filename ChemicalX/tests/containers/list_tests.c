/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.3.198 (20150531)                        **
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
    func  : fprintf
*/

/* Include test headers */
#include "tests/prefixes.h" /*
    macro : cx_OKAY
            cx_FAIL
            cx_DEAD
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

#define _TEST(N, M) "Test case (" #N ") => " M "\n"
#define TEST(...) _TEST(__VA_ARGS__)

#define TOSTR(V) #V

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
        goto Internal_Error;

    IntList_println(&i);
    IntList_del(&i);
    IntList_println(&i);

    fprintf(stderr, cx_OKAY(TEST(001, "Passed")));
    return;

    Internal_Error:
        fprintf(stderr, cx_DEAD(TEST(001, "Internal error occured")));
}


/*----------------------------------------------------------------------------*/
void
list_test_case_002(void)
{
    FloatList *f;
    if (!FloatList_from_data(&f, floats_LENGTH, floats))
        goto Internal_Error;

    FloatList_println(&f);
    FloatList_del(&f);
    FloatList_println(&f);

    fprintf(stderr, cx_OKAY(TEST(002, "Passed")));
    return;

    Internal_Error:
        fprintf(stderr, cx_DEAD(TEST(002, "Internal error occured")));
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

    fprintf(stderr, cx_OKAY(TEST(003, "6 CharPtrLists have been created")));

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

    fprintf(stderr, cx_OKAY(TEST(003, "3 CharPtrListLists have been created")));

    CharPtrListListList *cplll;

    if (!CharPtrListListList_from_data(&cplll, 3, (CharPtrListList *[]){cpll_1, cpll_2, cpll_3}))
        goto Internal_Error;

    CharPtrListListList_println(&cplll);

    fprintf(stderr, cx_OKAY(TEST(003, "CharPtrListListList has been created")));

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

    fprintf(stderr, cx_OKAY(TEST(003, "Passed")));
    return;

    Internal_Error:
        fprintf(stderr, cx_DEAD(TEST(003, "Internal error occured")));
}


/*----------------------------------------------------------------------------*/
void
list_test_case_004(void)
{
    static bool is_failed = false;

    static CharList *list;
    static size_t    length;
    static size_t    expected = 0;

    CharList_new(&list);
    CharList_len(list, &length);
    if (length != expected)
    {
        is_failed = true;
        fprintf(stderr, cx_FAIL(TEST(004, "Length is not 0")));
    }
    else
        fprintf(stderr, cx_OKAY(TEST(004, "Length is 0")));
    CharList_del(&list);

    expected = 4;
    CharList_from_data(&list, expected, (char[]){'x', 'y', 'z', 'w'});
    CharList_len(list, &length);
    if (length != expected)
    {
        is_failed = true;
        fprintf(stderr, cx_FAIL(TEST(004, "Length is not 4")));
    }
    else
        fprintf(stderr, cx_OKAY(TEST(004, "Length is 4")));
    CharList_del(&list);

    if (CharList_len(list, &length))
    {
        is_failed = true;
        fprintf(stderr, cx_FAIL(TEST(004, "Length method should return `false`")));
    }
    else
        fprintf(stderr, cx_OKAY(TEST(004, "Length method returned `false`")));

    if (is_failed)
        fprintf(stderr, cx_FAIL(TEST(004, "Failed")));
    else
        fprintf(stderr, cx_OKAY(TEST(004, "Passed")));
}


/*----------------------------------------------------------------------------*/
void
list_test_case_005(void)
{
    static bool is_failed = false;

    static FloatList *list;
    static size_t     length;
    static size_t     expected = floats_LENGTH;

    if (!FloatList_from_data(&list, floats_LENGTH, floats))
        goto Internal_Error;
    FloatList_len(list, &length);

    if (length != expected)
    {
        is_failed = true;
        fprintf(stderr, cx_FAIL(TEST(005, "Length is not " TOSTR(floats_LENGTH))));
    }
    else
        fprintf(stderr, cx_OKAY(TEST(005, "Length is " TOSTR(floats_LENGTH))));

    expected = 0;
    FloatList_clear(list);
    FloatList_len(list, &length);

    if (length != expected)
    {
        is_failed = true;
        fprintf(stderr, cx_FAIL(TEST(005, "Length is not 0")));
    }
    else
        fprintf(stderr, cx_OKAY(TEST(005, "Length is 0")));

    FloatList_del(&list);

    if (FloatList_clear(list))
    {
        is_failed = true;
        fprintf(stderr, cx_FAIL(TEST(005, "Clear method should return `false`")));
    }
    else
        fprintf(stderr, cx_OKAY(TEST(005, "Clear method returned `false`")));

    if (is_failed)
        fprintf(stderr, cx_FAIL(TEST(005, "Failed")));
    else
        fprintf(stderr, cx_OKAY(TEST(005, "Passed")));
    return;

    Internal_Error:
        fprintf(stderr, cx_DEAD(TEST(005, "Internal error occured")));
}


/*----------------------------------------------------------------------------*/
void
list_test_case_006(void)
{
    static bool is_failed = false;

    static IntList *list;
    static size_t   copied;
    static int      buffer[ints_LENGTH];

    if (!IntList_from_data(&list, ints_LENGTH, ints))
        goto Internal_Error;
    if (!IntList_to_array(list, &copied, ints_LENGTH, buffer))
        goto Internal_Error;

    if (copied != ints_LENGTH)
        fprintf(stderr, cx_FAIL(TEST(006, "Buffer lengths are not equal")));
    else
        fprintf(stderr, cx_OKAY(TEST(006, "Buffer lengths are equal")));

    for (size_t i=0; i<ints_LENGTH; i++)
        if (buffer[i] != ints[i])
        {
            is_failed = true;
            fprintf(stderr, cx_FAIL(TEST(006, "The new buffer is not the "
                                              "same as the old one")));
            break;
        }
    fprintf(stderr, cx_OKAY(TEST(005, "The two buffers are identical")));

    if (IntList_to_array(list, NULL, 0, NULL))
        fprintf(stderr, cx_FAIL(TEST(006, "ToArray method shoudl return `false`")));
    else
        fprintf(stderr, cx_OKAY(TEST(006, "ToArray method returned `false`")));

    if (IntList_to_array(list, &copied, 0, NULL))
        fprintf(stderr, cx_FAIL(TEST(006, "ToArray method shoudl return `false`")));
    else
        fprintf(stderr, cx_OKAY(TEST(006, "ToArray method returned `false`")));

    if (IntList_to_array(list, &copied, ints_LENGTH, NULL))
        fprintf(stderr, cx_FAIL(TEST(006, "ToArray method shoudl return `false`")));
    else
        fprintf(stderr, cx_OKAY(TEST(006, "ToArray method returned `false`")));

    FloatList_del(&list);

    if (is_failed)
        fprintf(stderr, cx_FAIL(TEST(006, "Failed")));
    else
        fprintf(stderr, cx_OKAY(TEST(006, "Passed")));
    return;

    Internal_Error:
        fprintf(stderr, cx_DEAD(TEST(006, "Internal error occured")));
}
