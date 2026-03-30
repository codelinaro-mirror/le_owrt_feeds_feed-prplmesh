include ../makefile.inc

# BEGIN-INTERNAL
ifdef STAGINGDIR
-include $(STAGINGDIR)/components.config
endif
# END-INTERNAL


CFLAGS += -std=gnu99 -fPIC -g -Wall -Werror -Wextra -Wno-unused-but-set-variable -I$(STAGINGDIR)/include/ -I$(STAGINGDIR)/usr/include/
CFLAGS += -Wimplicit-function-declaration -Wl,--no-undefined
CFLAGS += -I../include_priv/
CFLAGS += -DSAHTRACES_ENABLED -DSAHTRACES_LEVEL_DEFAULT=500

LDFLAGS += -L$(STAGINGDIR)/lib -L$(STAGINGDIR)/usr/lib -L$(STAGINGDIR)/usr/lib/amx/wld
LDFLAGS += -Wl,-rpath,/lib -Wl,-rpath,/usr/lib -Wl,-rpath,/usr/lib/amx/wld
LDFLAGS += -lsahtrace -lswlc -lwld
LDFLAGS += -lamxc -lamxm -lamxp -lamxd -lamxb -lamxo


OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c */*.c */*/*.c))

all: $(COMPONENT).so

$(COMPONENT).so: $(OBJECTS)
	$(CC) -Wl,-soname,$(@) -shared -fPIC -o $(@) $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $(@) $(<)
	@$(CC) $(CFLAGS) -MM -MP -MT '$(@) $(@:.o=.d)' -MF $(@:.o=.d) $(<) >/dev/null

clean:
	rm -f $(COMPONENT).so *.o *.d *.a *.gcno *.gcda
	find . -name *.o -delete
	find . -name *.d -delete

-include $(OBJECTS:.o=.d)

.PHONY: all clean
