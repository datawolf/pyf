dnl Configure script for GRUB.
dnl Copyright 1999,2000,2001,2002,2003,2004,2005,2008,2009,2010 Free Software Foundation, Inc.

dnl Permission to use, copy, modify and distribute this software and its
dnl documentation is hereby granted, provided that both the copyright
dnl notice and this permission notice appear in all copies of the
dnl software, derivative works or modified versions, and any portions
dnl thereof, and that both notices appear in supporting documentation.
dnl
dnl THE FREE SOFTWARE FOUNDATION ALLOWS FREE USE OF THIS SOFTWARE IN ITS
dnl "AS IS" CONDITION.  THE FREE SOFTWARE FOUNDATION DISCLAIMS ANY
dnl LIABILITY OF ANY KIND FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE
dnl USE OF THIS SOFTWARE.

AC_PREREQ(2.59)
AC_INIT([Multiboot], [0.6.96], [bug-grub@gnu.org])
AC_CONFIG_SRCDIR([doc/multiboot.texi])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE

#
# Programs
#

AC_CHECK_TOOL(CC, gcc)
AC_PROG_CC
AM_PROG_AS
# We need this for older versions of Autoconf.
_AM_DEPENDENCIES(CC)

dnl Because recent automake complains about AS, set it here.
CCAS="$CC"
AC_SUBST(CCAS)

dnl Build the example Multiboot kernel.
AC_ARG_ENABLE(example-kernel,
  [  --enable-example-kernel
                          build the example Multiboot kernel])
AM_CONDITIONAL(BUILD_EXAMPLE_KERNEL, test "x$enable_example_kernel" = xyes)

dnl Because recent automake complains about CCASFLAGS, set it here.
CCASFLAGS='$(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) $(CFLAGS)'
AC_SUBST(CCASFLAGS)

AC_ARG_ENABLE(mbchk,
  [  --enable-mbchk
                          build the mbchk (multiboot checker)])
AM_CONDITIONAL(BUILD_MBCHK, test "x$enable_mbchk" = xyes)

if test "x$enable_mbchk" = xyes; then
  AC_PATH_PROG(HELP2MAN, help2man)
fi

AM_CONDITIONAL([COND_MAN_PAGES], [test x$enable_mbchk = xyes -a x$HELP2MAN != x])

dnl Output.
AC_CONFIG_FILES([Makefile doc/Makefile util/Makefile])
AC_OUTPUT
