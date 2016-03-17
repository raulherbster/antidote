AM_CPPFLAGS =  -I$(top_builddir) -I$(top_srcdir) -I$(top_builddir)/src -I$(top_srcdir)/src

bin_PROGRAMS = simulator_agent

simulator_agent_SOURCES = simulator_agent.c simulator_parser.c jsmn.c ../apps/sample_agent_common.c

simulator_agent_LDADD = \
             ../src/communication/plugin/libcommpluginimpl.la \
             ../src/libantidote.la

AUTOMAKE_OPTIONS = subdir-objects
