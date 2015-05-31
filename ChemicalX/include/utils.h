/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.2.172 (20150531)                        **
**                      File: ChemicalX/include/utils.h                       **
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
#ifndef __CHEMICAL_X_UTILS_H_4967258996282923__
#define __CHEMICAL_X_UTILS_H_4967258996282923__

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stddef.h> /*
    type  : size_t
            ptrdiff_t
*/
#include <stdbool.h> /*
    type  : bool
*/



/*----------------------------------------------------------------------------*/
/* V: value,
   S: struct name
   M: members stringified
   E: (line) ending */
#define cx_STRINGIFY_BOOL(V)                     V ? "true" : "false"
#define cx_FORMAT_STRUCT(S, M, E)                "<struct " S "{" M "} at %p>" E
#define cx_FORMAT_STRUCT_NULL(S, E)              "NULL was <struct " S ">" E
#define cx_FORMAT_CONTAINER_STRUCT_BEFORE(S, M)  "<struct " S "{" M "} has ("
#define cx_FORMAT_CONTAINER_STRUCT_AFTER(E)      ") at %p>" E

/*----------------------------------------------------------------------------*/
void
cx_Bool_print(bool *const value);
/*----------------------------------------------------------------------------*/
void
cx_Int_print(int *const value);
/*----------------------------------------------------------------------------*/
void
cx_LongInt_print(long int *const value);
/*----------------------------------------------------------------------------*/
void
cx_LongLongInt_print(long long int *const value);
/*----------------------------------------------------------------------------*/
void
cx_UnsignedInt_print(unsigned int *const value);
/*----------------------------------------------------------------------------*/
void
cx_UnsignedLongInt_print(unsigned long int *const value);
/*----------------------------------------------------------------------------*/
void
cx_UnsignedLongLongInt_print(unsigned long long int *const value);
/*----------------------------------------------------------------------------*/
void
cx_SizeT_print(size_t *const value);
/*----------------------------------------------------------------------------*/
void
cx_PtrdiffT_print(ptrdiff_t *const value);
/*----------------------------------------------------------------------------*/
void
cx_Char_print(char *const value);
/*----------------------------------------------------------------------------*/
void
cx_CharPtr_print(char *const *const value);
/*----------------------------------------------------------------------------*/
void
cx_Float_print(float *const value);
/*----------------------------------------------------------------------------*/
void
cx_Double_print(double *const value);
/*----------------------------------------------------------------------------*/
void
cx_LongDouble_print(long double *const value);
/*----------------------------------------------------------------------------*/
void
cx_Ptr_print(void *const *const value);

#endif /* __CHEMICAL_X_UTILS_H_4967258996282923__ */
