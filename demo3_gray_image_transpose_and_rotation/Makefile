all: transposition_test rotation_test

transposition_test: transposition_test.c transposition.c util.c
	aarch64-linux-gnu-gcc transposition_test.c transposition.c util.c -o transposition_test -I/usr/aarch64-linux-gnu/third-party/libpng-1.6.40/include/ -L/usr/aarch64-linux-gnu/third-party/libpng-1.6.40/lib -L/usr/aarch64-linux-gnu/third-party/zlib-1.2.11/lib -lpng16 -lpng -lm -lz

rotation_test: rotation_test.c rotation.c util.c
	aarch64-linux-gnu-gcc rotation_test.c rotation.c util.c -o rotation_test -I/usr/aarch64-linux-gnu/third-party/libpng-1.6.40/include/ -L/usr/aarch64-linux-gnu/third-party/libpng-1.6.40/lib -L/usr/aarch64-linux-gnu/third-party/zlib-1.2.11/lib -lpng16 -lpng -lm -lz

clean:
	rm transposition_test rotation_test