/* Configuration file for Besta RTOS EABI target.
   Copyright (C) 2022 dogtopus 

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

/* muteki-shims is necessary for muteki newlib */
#undef  LIB_SPEC
#define LIB_SPEC "%{!shared:%{g*:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}} -lmutekishims"

/* Relocs are needed for post linker to produce the final PE EXE file.
   Also implement the workaround for elf2bestape, although those 2 options are
   generally good to have on their own due to the difference between how ELF and
   PE files are designed. */
#undef  LINK_SPEC
#define LINK_SPEC BPABI_LINK_SPEC " -d -q -z max-page-size=0x1000 -z separate-code"

#undef  TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()		\
    do {					\
	builtin_define ("__bestartos__");		\
	builtin_define ("__bestaeabi__");		\
	builtin_assert ("system=bestartos");	\
	builtin_assert ("system=bestaeabi");	\
	TARGET_BPABI_CPP_BUILTINS();    	\
    } while (0)

