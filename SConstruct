## INFO ########################################################################
##                                                                            ##
##                                 ChemicalX                                  ##
##                                 =========                                  ##
##                                                                            ##
##              Constraint based, OpenGL powered, crossplatform,              ##
##                     free and open source GUI framework                     ##
##                       Version: 0.0.1.129 (20150530)                        ##
##                              File: SConstruct                              ##
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

# Indicate the beginning of building
print '\n{:#^80}\n'.format(' SCONS BUILD ')

# Import python modules
from os.path import join


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# Config variables
debug         = False
input_dir     = 'ChemicalX'
build_dir     = 'build'
output_dir    = 'dist'

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
container_lib = []
cassowary_lib = []
chemicalx_lib = []

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



#------------------------------------------------------------------------------#
# Library outputs
CONTAINER_LIB_TARGET = join(output_dir, container_out)
CASSOWARY_LIB_TARGET = join(output_dir, cassowary_out)
CHEMICALX_LIB_TARGET = join(output_dir, chemicalx_out)

# Executable outputs
CONTAINER_TESTS_TARGET = join(output_dir, container_tests_out)
CASSOWARY_TESTS_TARGET = join(output_dir, cassowary_tests_out)
CHEMICALX_TESTS_TARGET = join(output_dir, chemicalx_tests_out)

# C Compiler (gcc|clang)
CC = 'clang'

# C Compiler Flags
CCFLAGS = ['v',
           'O3',
           'Wall',
           'Wextra',
           'pedantic',
           'std=c11',
           'g' if debug else '']

# GCC Specific Compiler Flags
GCCFLAGS = ['fdiagnostics-color=always']

# CLANG Specific Compiler Flags
CLANGFLAGS = ['fcolor-diagnostics',
              'fmacro-backtrace-limit=0']

# Add compiler specific flags
CCFLAGS.extend(GCCFLAGS if CC == 'gcc' else CLANGFLAGS if CC == 'clang' else [])

# C Pre-Processor Path (Include)
CPPPATH = []

# Library paths
LIBPATH = ['/usr/lib',
           '/usr/local/lib']


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# ADMINISTRATION
dev_hook_run = Environment().Command(target='dev_hook',
                                     source=None,
                                     action='python3 build.py')


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# CONTAINER LIBRARY

# Create environment
containers_env = \
    Environment(CC=CC,
                CCFLAGS=['-' + flag for flag in CCFLAGS if flag],
                CPPPATH=CPPPATH + [join(build_dir, d) for d in container_inc],
                LIBPATH=LIBPATH + container_dir,
                LIBS=container_lib)
# Specify output directory
containers_env.VariantDir(variant_dir=build_dir,
                          src_dir=input_dir)
# Create library
containers_env_out = \
    containers_env.SharedLibrary(target=CONTAINER_LIB_TARGET,
                                 source=[join(build_dir, f) for f in container_src])


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# CONTAINER TESTS

# Create environment
containers_tests_env = \
    Environment(CC=CC,
                CCFLAGS=['-' + flag for flag in CCFLAGS if flag],
                CPPPATH=CPPPATH + [join(build_dir, d) for d in container_tests_inc],
                LIBPATH=LIBPATH + container_tests_dir,
                LIBS=container_tests_lib)
# Specify output directory
containers_tests_env.VariantDir(variant_dir=build_dir,
                                src_dir=input_dir)
# Create library
containers_tests_env_out = \
    containers_tests_env.Program(target=CONTAINER_TESTS_TARGET,
                                 source=[join(build_dir, f) for f in container_tests_src])

# This program depends on libraries
containers_tests_env.Depends(containers_tests_env_out, containers_env_out)

# Runs tests
containers_tests_env_run = \
    containers_tests_env.Command(target='run_container_tests',
                                 source=None,
                                 action='./' + CONTAINER_TESTS_TARGET)
# The execution depends on the program
containers_tests_env.Depends(containers_tests_env_run, containers_tests_env_out)


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# MAKE SURE DEVELOPER-HOOK IS ALWAYS RUNNING
containers_env.Depends(containers_env_out, dev_hook_run)
containers_tests_env.Depends(containers_tests_env_run, dev_hook_run)
