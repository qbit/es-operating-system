SUBDIRS = . testsuite

SUFFIXES = .h .idl

%.h : %.idl
	esidl -I$(srcdir)/../include -include es/object.idl -object Object $<

noinst_PROGRAMS = \
	main hello cairo expat server client \
	eventManager eventManagerClient \
	console consoleClient \
	upcallTest upcallTestClient \
	fontconfig newlib

AM_LDFLAGS = -v -static -Wl,--no-omagic,-Map,$@.map,--cref -L$(prefix)/lib
AM_CPPFLAGS = -I- \
	-I../include \
	-I$(srcdir)/../include \
	-I$(prefix)/include \
	-I$(prefix)/include/freetype2 \
	-I$(prefix)/include/cairo \
	-I$(prefix)/include/pixman-1

LDADD = ../os/libes++/libes++.a -lcairo -lpixman-1 -lfontconfig -lexpat -lfreetype -lm

hello_SOURCES = hello.cpp

cairo_SOURCES = cairo.cpp

expat_SOURCES = expat.cpp

main_SOURCES = main.cpp

server_SOURCES = server.cpp

client_SOURCES = client.cpp

# binder_SOURCES = binder.cpp binder.h

# binderClient_SOURCES = binderClient.cpp binder.h

eventManager_SOURCES = eventManager.cpp eventManager.h IEventQueue.idl

eventManagerClient_SOURCES = eventManagerClient.cpp eventManager.h IEventQueue.idl

BUILT_SOURCES = IEventQueue.h

console_SOURCES = console.cpp canvas.cpp canvas.h

consoleClient_SOURCES = consoleClient.cpp

upcallTest_SOURCES = upcallTest.cpp

upcallTestClient_SOURCES = upcallTestClient.cpp

fontconfig_SOURCES = fontconfig.cpp

newlib_SOURCES = newlib.cpp

CLEANFILES = $(BUILT_SOURCES) $(nodist_eventManager_SOURCES)

clean-local:
	-rm -f  *.map

