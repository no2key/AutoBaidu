SUBDIRS = test


AM_CFLAGS = $(GLIB_CFLAGS) $(GOBJECT_CFLAGS) -Wall 

bin_PROGRAMS = autobaidu

autobaidu_LDADD = $(GLIB_LIBS) $(GOBJECT_LIBS)
autobaidu_SOURCES = autobaidu.c autobaidu.h \
		    baidu-user.c baidu-user.h
