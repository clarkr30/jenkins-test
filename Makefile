# Check if RELEASE is set to true, otherwise use default flags
ifeq ($(RELEASE), true)
    CFLAGS = -O2 -DRELEASE_BUILD
else
    CFLAGS = -g
endif

app:
	gcc -o app app.c

clean:
	rm app

all: app