
AC_PREQUIRE([2.6])
AC_INIT([AutoBaidu], [0.1], [7723n12@sina.com], [autobaidu], [no pages])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

# check for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_INSTALL

# check for libs

# check for glib
PKG_CHECK_MODULES(GLIB, [glib-2.0 >= 2.18])
AC_SUBST(GLIB_LIBS)
AC_SUBST(GLIB_CFLAGS)

# check for gobject
PKG_CHECK_MODULES(GOBJECT, [gobject-2.0])
AC_SUBST(GOBJECT_CFLAGS)
AC_SUBST(GOBJECT_LIBS)

# check for libsoup
PKG_CHECK_MODULES(LIBSOUP, [libsoup-2.4 >= 2.26])
AC_SUBST(LIBSOUP_CFLAGS)
AC_SUBST(LIBSOUP_LIBS)


# config files
AC_CONFIG_FILES([
		 Makefile
		 src/Makefile
		)

AC_OUTPUT
