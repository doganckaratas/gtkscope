CC ?= gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = $(shell $(PKGCONFIG) --cflags gtk+-3.0)
LIBS = $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRC = gtkscope.c gtkscopewin.c
OBJS = $(SRC:.c=.o)

all: gtkscopeapp

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

gtkscopeapp: $(OBJS)
	$(CC) -o $(@F) $(OBJS) $(LIBS)

clean: 
	rm -f $(OBJS)
	rm -f gtkscopeapp
