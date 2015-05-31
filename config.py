## INFO ########################################################################
##                                                                            ##
##                                 ChemicalX                                  ##
##                                 =========                                  ##
##                                                                            ##
##              Constraint based, OpenGL powered, crossplatform,              ##
##                     free and open source GUI framework                     ##
##                       Version: 0.0.2.172 (20150531)                        ##
##                              File: config.py                               ##
##                                                                            ##
##   For more information about the project, visit <http://chemicalx.org>.    ##
##                       Copyright (C) 2015 Peter Varo                        ##
##                                                                            ##
##  This program is free software: you can redistribute it and/or modify it   ##
##   under the terms of the GNU General Public License as published by the    ##
##       Free Software Foundation, either version 3 of the License, or        ##
##                    (at your option) any later version.                     ##
##                                                                            ##
##    This program is distributed in the hope that it will be useful, but     ##
##         WITHOUT ANY WARRANTY; without even the implied warranty of         ##
##            MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            ##
##            See the GNU General Public License for more details.            ##
##                                                                            ##
##     You should have received a copy of the GNU General Public License      ##
##     along with this program, most likely a file in the root directory,     ##
##        called 'LICENSE'. If not, see <http://www.gnu.org/licenses>.        ##
##                                                                            ##
######################################################################## INFO ##

# Import python modules
from os.path import join


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# Basic settings
debug         = False
input_dir     = 'ChemicalX'
build_dir     = 'build'
output_dir    = 'dist'



#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# Source files
container_src = [
    join('src', 'utils.c'),
    join('src', 'containers', 'list.c'),
    # join('src', 'containers', 'map.c'),
    # join('external', 'xxHash',     'xxhash.c'),
]
cassowary_src = [
    join('src', 'cassowary', 'abstract_variable.c'),
    # join('src', 'cassowary', 'expression.c'),
]
chemicalx_src = []

# Include dirs
container_inc = [
    'include',
    'external',
]
cassowary_inc = []
chemicalx_inc = []

# Library dirs
container_dir = []
cassowary_dir = []
chemicalx_dir = []

# Libraries
container_lib = [
    'jemalloc',
]
cassowary_lib = [
    'jemalloc',
]
chemicalx_lib = [
    'jemalloc',
]

# Library outputs
container_out = 'cx_container'
cassowary_out = 'cx_cassowary'
chemicalx_out = 'cx'



#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# Source files
container_tests_src = [
    join('tests', 'containers', 'tests.c'),
    join('tests', 'containers', 'list_types.c'),
    join('tests', 'containers', 'list_tests.c'),
]
cassowary_tests_src = []
chemicalx_tests_src = []

# Include dirs
container_tests_inc = [
    '.',
    'include',
]
cassowary_tests_inc = []
chemicalx_tests_inc = []

# Library dirs
container_tests_dir = [
    output_dir,
]
cassowary_tests_dir = [
    output_dir,
]
chemicalx_tests_dir = [
    output_dir,
]

# Libraries
container_tests_lib = [
    container_out,
]
cassowary_tests_lib = [
    container_out,
    cassowary_out,
]
chemicalx_tests_lib = [
    container_out,
    cassowary_out,
]

# Executables
container_tests_out = 'cx_container_tests'
cassowary_tests_out = 'cx_cassowary_tests'
chemicalx_tests_out = 'cx_chemicalx_tests'
