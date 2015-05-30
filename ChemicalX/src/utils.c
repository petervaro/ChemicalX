/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.123 (20150530)                        **
**                        File: ChemicalX/src/utils.c                         **
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
    func  : printf
*/
#include <stddef.h> /*
    type  : size_t
            ptrdiff_t
*/
#include <stdbool.h> /*
    type  : bool
*/

/* Include ChemicalX headers */
#include "utils.h" /*
    macro : cx_STRINGIFY_BOOL
*/

/*----------------------------------------------------------------------------*/
void
cx_Bool_print(bool *const value)
{
    printf("%s", cx_STRINGIFY_BOOL(*value));
}


/*----------------------------------------------------------------------------*/
void
cx_Int_print(int *const value)
{
    printf("%d", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_LongInt_print(long int *const value)
{
    printf("%ldL", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_LongLongInt_print(long long int *const value)
{
    printf("%lldLL", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_UnsignedInt_print(unsigned int *const value)
{
    printf("%uU", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_UnsignedLongInt_print(unsigned long int *const value)
{
    printf("%luUL", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_UnsignedLongLongInt_print(unsigned long long int *const value)
{
    printf("%lluULL", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_SizeT_print(size_t *const value)
{
    printf("(size_t)%zu", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_PtrdiffT_print(ptrdiff_t *const value)
{
    printf("(ptrdiff_t)%td", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_Char_print(char *const value)
{
    if (*value)
        printf("'%c'", *value);
    else
        printf("'\\0'");
}


/*----------------------------------------------------------------------------*/
void
cx_CharPtr_print(char *const *const value)
{
    printf("\"%s\"", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_Float_print(float *const value)
{
    printf("%ff", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_Double_print(double *const value)
{
    printf("%f", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_LongDouble_print(long double *const value)
{
    printf("%LfL", *value);
}


/*----------------------------------------------------------------------------*/
void
cx_Ptr_print(void *const *const value)
{
    printf("%p", *value);
}
