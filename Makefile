CC = icc
CFLAGS = -xHost -O3

SOURCES = $(wildcard *.c)
TARGETS = $(SOURCES:.c=)

all: $(TARGETS)

c4: c4.c
	$(CC) -mkl $(CFLAGS) $< -o $@

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f c1 c2 c3 c4
