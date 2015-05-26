## INFO ########################################################################
##                                                                            ##
##                                 ChemicalX                                  ##
##                                 =========                                  ##
##                                                                            ##
##              Constraint based, OpenGL powered, crossplatform,              ##
##                     free and open source GUI framework                     ##
##                       Version: 0.0.1.016 (20150526)                        ##
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
print '{:#^80}'.format(' SCONS BUILD ')

# Import python modules
from sys     import argv
from os.path import join

# Config variables
debug       = False
gcc         = 'gcc'
clang       = 'clang'
input_dir   = 'ChemicalX'
build_dir   = 'build'
output_dir  = 'dist'
target      = 'cx'
source      = [join('src', 'main.c'),
               join('src', 'cassowary', 'abstract_variable.c')]

#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
# Output
TARGET = join(output_dir, target)

# C Compiler
CC = clang

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
CCFLAGS.extend(GCCFLAGS if CC == gcc else CLANGFLAGS if CC == clang else [])

# C Pre-Processor Path (Include)
CPPPATH = [join(build_dir, 'include')]

# Library paths
LIBPATH = ['/usr/lib',
           '/usr/local/lib']

# Libraries
LIBS = []

# Create environment
environment = Environment(CC=CC,
                          CCFLAGS=['-' + flag for flag in CCFLAGS if flag],
                          CPPPATH=CPPPATH,
                          LIBPATH=LIBPATH,
                          LIBS=LIBS)

# Specify output directory
environment.VariantDir(variant_dir=build_dir,
                       src_dir=input_dir)

compile_src = environment.Program(target=TARGET,
                                  source=[join(build_dir, file) for file in source])

# Run "administrative" cutils-tools first
cutils_hook = environment.Command(target='cutils',
                                  source=None,
                                  action='python3 build.py')
environment.Depends(compile_src, cutils_hook)

# If `run` is specified as argument
execute_app = environment.Command(target='run',
                                  source=None,
                                  action='./' + TARGET)
environment.Depends(execute_app, compile_src)

# If there is no argument specified, only compile target
environment.Default(TARGET)
