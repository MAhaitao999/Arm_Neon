#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <arm_neon.h>

//----------------------------
//
//
//
//使用NEON实现 a+b=c
//
//
//
//----------------------------
int main(int argc, char *argv[])
{
    unsigned char a[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    unsigned char b[8] = {8, 9, 10, 11, 12, 13, 14, 15};
    unsigned char c[8];

	uint8x8_t rega;
	uint8x8_t regb;
	uint8x8_t regc;

	rega = vld1_u8(&a[0]);
	regb = vld1_u8(&b[0]);

	regc = vadd_u8(rega, regb);
	vst1_u8(&c[0], regc);

	// 测试
	for (int i = 0; i < 8; ++i) {
	    printf("%d ", c[i]);
	}
	printf("\n");

	return 0;
}
