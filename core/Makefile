CC		?= gcc
PKGCONFIG	= $(shell which pkg-config)
CFLAGS		= $(shell $(PKGCONFIG) --cflags gtk+-3.0)
CFLAGS		+= -g -ggdb -O0
CFLAGS		+= -I../include
LIBS		= $(shell $(PKGCONFIG) --libs gtk+-3.0)
SRC		= gtkscope.c
OBJS		= $(SRC:.c=.o)

all: $(OBJS)

%.o: %.c
	$(CC) -c -o $(@F) $(CFLAGS) $<

clean: 
	rm -f $(OBJS)
