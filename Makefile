all: build clean

CFLAGS := *.c -o ../main.out -lm -L../lib ../lib/libraylib.a -I../lib/
this_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown OS')

ifeq ($(this_OS),Linux)
    CFLAGS += -lGL -lm -lpthread -ldl -lrt
	CFLAGS += -lX11
endif
ifeq ($(this_OS),Darwin)
    CFLAGS += -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL
endif
ifeq ($(this_OS),BSD)
    CFLAGS += -lGL -lpthread -lm
	CFLAGS += -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
endif

download_raylib:
	git clone --depth 1 -b master --filter=blob:none https://github.com/raysan5/raylib --sparse
	(cd raylib && git sparse-checkout init --cone && git sparse-checkout set src)

build_raylib: download_raylib
	(cd raylib/src && make)

	mkdir -p lib
	(cd raylib/src && mv libraylib.a ../../lib/)
	(cd raylib/src && mv raylib.h ../../lib/)

	[ ! -e raylib ] || rm -rf raylib

build: src
	(cd src && gcc $(CFLAGS))
