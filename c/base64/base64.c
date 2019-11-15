#include "base64.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* encode_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

const short decode_table[128] = { /* 解码时把'='看做'A'使用 */
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63, 
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1,  0/*=*/, -1, -1, 
    -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1, 
    -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1
};

int base64_encode(const char* instr, int inlen, char* outstr)
{
    int applen = 0, j = 0;
    unsigned int bin = 0;
    char *tmp = NULL;

    if ( !instr || !outstr || inlen < 0) {
        return -1;
    }

    applen = (3 - inlen % 3) % 3;
    inlen += applen;    /* 凑成3的倍数 */
    tmp = (char *) malloc((inlen + 1) * sizeof(char));
    memset(tmp, 0, inlen + 1);
    memcpy(tmp, instr, inlen - applen);

    for (int i = 0; i < inlen; i += 3) {
        bin = tmp[i];
        bin = bin << 8 | tmp[i+1];
        bin = bin << 8 | tmp[i+2];
        outstr[j++] = encode_table[(bin & 0x00fc0000) >> 18];
        outstr[j++] = encode_table[(bin & 0x0003f000) >> 12];
        outstr[j++] = encode_table[(bin & 0x00000fc0) >> 6];
        outstr[j++] = encode_table[(bin & 0x0000003f)];
    }
    for ( outstr[j] = 0; applen-- > 0; outstr[--j] = '=');

    return 0;
}

int base64_decode(const char* instr, int inlen, char* outstr)
{
    int j = 0;
    unsigned int bin = 0;

    if ( !instr || !outstr || inlen < 0) {
        return -1;
    }
    for (int i = 0; i < inlen; i += 4) 
    {
        bin = decode_table[instr[i]];
        bin = bin << 6 | decode_table[instr[i+1]];
        bin = bin << 6 | decode_table[instr[i+2]];
        bin = bin << 6 | decode_table[instr[i+3]];
        outstr[j++] = ( bin & 0x00ff0000 ) >> 16;
        outstr[j++] = ( bin & 0x0000ff00 ) >> 8;
        outstr[j++] = ( bin & 0x000000ff );
    }
    for ( outstr[j] = 0; instr[--inlen] == '='; outstr[--j] = 0);

    return 0;
}


#if 0
/* example */
int main(int argc, char const *argv[]){
    char s1[100], s2[100] = {0};
    base64_encode(argv[1], strlen(argv[1]), s1);
    base64_decode(s1, strlen(s1), s2);
    printf("base64_encode: %s\nbase64_decode: %s\n", s1, s2);
    return 0;
}
#endif

