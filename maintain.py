#!/usr/bin/env python3
## INFO ########################################################################
##                                                                            ##
##                                 ChemicalX                                  ##
##                                 =========                                  ##
##                                                                            ##
##              Constraint based, OpenGL powered, crossplatform,              ##
##                     free and open source GUI framework                     ##
##                       Version: 0.0.2.142 (20150531)                        ##
##                             File: maintain.py                              ##
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
from copy    import deepcopy

# Module level constants
CURRENT_DIR = '.'
POST_COMMIT = 0  # True or False => skip CLIC (version) changes only

# Import cutils modules
try:
    import cutils.ccom
    import cutils.clic
    import cutils.cver

    web_dev = '.js', '.css', '.html'
    c_build = ('SConstruct',)

    exclude = deepcopy(cutils.ccom.EXCLUDE)
    exclude['folders'].append('build')
    exclude['folders'].append('dist')
    exclude['folders'].append(join('ChemicalX', 'external'))
    exclude['folders'].append('cassowary_implementations')

    ccom_include = deepcopy(cutils.ccom.INCLUDE)
    ccom_include['extensions'].extend(web_dev)
    ccom_include['names'].extend(c_build)

    clic_include = deepcopy(cutils.clic.INCLUDE)
    clic_include['extensions'].extend(web_dev)
    clic_include['names'].extend(c_build)

    # Update version
    cutils.cver.version(CURRENT_DIR,
                        sub_max=9,
                        rev_max=9,
                        build_max=999)

    # Collect all special comments
    cutils.ccom.collect(CURRENT_DIR,
                        include=ccom_include,
                        exclude=exclude,
                        overwrite=POST_COMMIT)

    # Update header comments
    cutils.clic.header(CURRENT_DIR,
                       include=clic_include,
                       exclude=exclude,
                       overwrite=POST_COMMIT)
except ImportError:
    print('[WARNING] cutils modules are missing: '
          'install it from http://www.cutils.org')
