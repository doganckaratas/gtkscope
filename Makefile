CC		?= gcc
PKGCONFIG       = $(shell which pkg-config)
MAKE		?= make
CFLAGS		= -g -ggdb -O0
TARGET		= gtkscope
LIBS            = $(shell $(PKGCONFIG) --libs gtk+-3.0)
OBJS		= $(shell find -name *.o)

.PHONY: all
all: $(TARGET)
	$(CC) -o $< $(OBJS) $(LIBS)

$(TARGET): $(OBJS)
	$(MAKE) -C view all
	$(MAKE) -C core all

.PHONY: clean
clean:
	rm -rf $(TARGET)
	$(MAKE) -C view clean
	$(MAKE) -C core clean
