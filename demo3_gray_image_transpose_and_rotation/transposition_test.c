#include <stdio.h>
#include <stdlib.h>
#include <arm_neon.h>
#include <string.h>
#include <math.h>
#include <float.h>

#include <png.h>
#include "util.h"
#include "transposition.h"

int main(int argc, char *argv[])
{
    png_bytep input;
    size_t x, y;                               // Var für Bild und Muster
    readImageData("gray.png", &input, &x, &y); // Bild lesen

    png_bytep output = malloc(sizeof(png_bytep) * x * y);

    tran_8(input, output, x, y); // 8-bit-tief Bild Transposition

    writeImageData("out.png", output, y, x, 8);
    free(input);
    free(output);
}