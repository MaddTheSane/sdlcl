CFLAGS = -fPIC -Wall -Wextra -O2 `sdl2-config --cflags` -fvisibility=hidden -g
LDFLAGS = -shared -ldl
TARGET = libSDL-1.2.so.0

SRCS = main.c video.c yuv.c cursor.c audio.c audiocvt.c timer.c events.c \
	keyboard.c mouse.c joystick.c rwops.c thread.c cpuinfo.c version.c \
	cdrom.c loadso.c stdlib.c
OBJS = $(SRCS:.c=.o)
HEADERS = redir.h unredir.h

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

$(SRCS:.c=.d):%.d:%.c $(HEADERS)
	$(CC) $(CFLAGS) -MM $< >$@

redir.h: symbols.x
	sed 's/SDL2_SYMBOL(\([^,]*\),.*/#define \1 re\1/' $^ > $@

unredir.h: symbols.x
	sed 's/SDL2_SYMBOL(\([^,]*\),.*/#undef \1/' $^ > $@

ifneq ($(MAKECMDGOALS),clean)
include $(SRCS:.c=.d)
endif

.PHONY: clean
clean:
	-$(RM) $(TARGET) $(OBJS) $(SRCS:.c=.d) $(HEADERS)
