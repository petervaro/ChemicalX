/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.1.129 (20150530)                        **
**                      File: ChemicalX/tests/prefixes.h                      **
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
#ifndef __CHEMICAL_X_TESTS_PREFIXES_H_3054625138382304__
#define __CHEMICAL_X_TESTS_PREFIXES_H_3054625138382304__

/* ANSI Escaped Decorators:
     */

/* Colors */
#define RED     "\x1b[31"
#define YELLOW  "\x1b[33"
#define GREEN   "\x1b[32"
#define WHITE   "\x1b[37"
#define RESET   "\x1b[0m"

/* Font style */
#define REGULAR ";0m"
#define BOLD    ";1m"

/* Wrapper */
#define COLORED(C, T) WHITE REGULAR "[" C BOLD T WHITE REGULAR "]" RESET " "

/* Values */
#define OKAY COLORED(GREEN , " OKAY ")
#define FAIL COLORED(YELLOW, " FAIL ")
#define DEAD COLORED(RED   , " STOP ")

#endif /* __CHEMICAL_X_TESTS_PREFIXES_H_3054625138382304__ */
