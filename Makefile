CC      = gcc
CFLAGS  = -Wall -Wextra -O2
LDFLAGS = -lraylib -lwayland-client -lwayland-cursor -lwayland-egl \
          -lxkbcommon -lEGL -lGL -lm -lpthread -ldl
 
TARGET  = boids
SRC     = $(wildcard *.c)

.PHONY: all clean
 
all: $(TARGET)
 
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
 
clean:
	rm -f $(TARGET)
