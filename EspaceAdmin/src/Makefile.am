## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = espaceadmin

espaceadmin_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	login.c login.h \
	agents.c agents.h \
	coordonnees.c coordonnees.h

espaceadmin_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

