CC		?= gcc
PKGCONFIG	= $(shell which pkg-config)
CFLAGS		= $(shell $(PKGCONFIG) --cflags gtk+-3.0)
CFLAGS		+= -I../include
LIBS		= $(shell $(PKGCONFIG) --libs gtk+-3.0)

SRC		= window.c view.c menu.c
OBJS		= $(SRC:.c=.o)

all: $(OBJS)

%.o: %.c
	$(CC) -g -ggdb -c -o $(@F) $(CFLAGS) $<

clean:
	rm -f $(OBJS)
