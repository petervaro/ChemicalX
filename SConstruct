## INFO ########################################################################
##                                                                            ##
##                                 ChemicalX                                  ##
##                                 =========                                  ##
##                                                                            ##
##              Constraint based, OpenGL powered, crossplatform,              ##
##                     free and open source GUI framework                     ##
##                       Version: 0.0.2.158 (20150531)                        ##
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

# Import settings
from config import *

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
# MAINTENANCE
maintain_run = Environment().Command(target='maintain',
                                     source=None,
                                     action='python3 maintain.py')


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
# RUN ALL TESTS
all_tests_env = Environment()
all_tests_env_run = all_tests_env.Command(target='tests',
                                          source=None,
                                          action='')
# The execution depends on all other tests
all_tests_env.Depends(all_tests_env_run, containers_tests_env_run)


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# MAKE SURE MAINTENANCE IS ALWAYS RUNNING
containers_env.Depends(containers_env_out, maintain_run)
containers_tests_env.Depends(containers_tests_env_run, maintain_run)


#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# INSTALLATION

