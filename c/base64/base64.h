#ifndef __BASE64_H__
#define __BASE64_H__

int base64_encode(const char* instr, int inlen, char* outstr);
int base64_decode(const char* instr, int inlen, char* outstr);

#endif