AM_CPPFLAGS =  -I$(top_builddir) -I$(top_srcdir) -I$(top_builddir)/src -I$(top_srcdir)/src


lib_LTLIBRARIES = libbluezplugin.la

if BLUEZ_5
libbluezplugin_la_SOURCES = plugin_glib_socket_bluez5.c plugin_bluez_bluez5.c
else
libbluezplugin_la_SOURCES = plugin_glib_socket.c plugin_bluez.c
endif

@PACKAGE@_include_plugindir = $(pkgincludedir)/communication/plugin
@PACKAGE@_include_plugin_HEADERS = plugin_glib_socket.h plugin_bluez.h

libbluezplugin_la_CFLAGS = @GLIB_CFLAGS@ @GIO_CFLAGS@ @DBUS_CFLAGS@
