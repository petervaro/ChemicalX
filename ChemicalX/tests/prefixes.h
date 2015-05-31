/* INFO ************************************************************************
**                                                                            **
**                                 ChemicalX                                  **
**                                 =========                                  **
**                                                                            **
**              Constraint based, OpenGL powered, crossplatform,              **
**                     free and open source GUI framework                     **
**                       Version: 0.0.3.189 (20150531)                        **
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

/* Based on ANSI Escaped Decorators:
    http://ascii-table.com/ansi-escape-sequences.php */

/* Variables: CP: color-prefix
              P : prefix
              CM: color-message
              M : message */

/* Colors */
#define cx_RED     "\x1b[31m"
#define cx_GREEN   "\x1b[32m"
#define cx_BLUE    "\x1b[34m"

#define cx_CYAN    "\x1b[36m"
#define cx_MAGENTA "\x1b[35m"
#define cx_YELLOW  "\x1b[33m"

#define cx_BLACK   "\x1b[30m"
#define cx_WHITE   "\x1b[37m"

#define cx_RESET   "\x1b[0m"

/* Font style */
#define cx_BOLD    "\x1b[1m"

/* Wrapper */
#define cx_PREFIXER_(CP, P, CM, M)                                             \
    cx_RESET                                                                   \
    cx_WHITE "[" CP cx_BOLD P cx_RESET cx_WHITE "] "                           \
    cx_RESET CM cx_BOLD M                                                      \
    cx_RESET

/* Wrapper-redirector */
#define cx_PREFIXER(...) cx_PREFIXER_(__VA_ARGS__)

/* Predefinitions */
#define cx_OKAY_(M) cx_PREFIXER(cx_GREEN  , " OKAY ", cx_WHITE, M)
#define cx_FAIL_(M) cx_PREFIXER(cx_RED    , " FAIL ", cx_WHITE, M)
#define cx_DEAD_(M) cx_PREFIXER(cx_MAGENTA, " STOP ", cx_WHITE, M)

/* Predefinition-redirectors */
#define cx_OKAY(...) cx_OKAY_(__VA_ARGS__)
#define cx_FAIL(...) cx_FAIL_(__VA_ARGS__)
#define cx_DEAD(...) cx_DEAD_(__VA_ARGS__)

#endif /* __CHEMICAL_X_TESTS_PREFIXES_H_3054625138382304__ */
