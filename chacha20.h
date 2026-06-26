#ifndef CHACHA20_H
#define CHACHA20_H

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ROT_L32(x, n) (((x) << (n)) | ((x) >> (32 - (n)))) // n비트 왼쪽 시프트 연산 (32비트 기준)

// Quarter-Round 매크로
#define QUARTERROUND(a, b, c, d) \
    a += b; d ^= a; d = ROT_L32(d, 16); \
    c += d; b ^= c; b = ROT_L32(b, 12); \
    a += b; d ^= a; d = ROT_L32(d, 8); \
    c += d; b ^= c; b = ROT_L32(b, 7);

// 20라운드 블록 연산 수행 함수
void chacha20_block(uint8_t output[64], const uint32_t key[8], 
    uint32_t counter, const uint32_t nonce[3]);

// ChaCha20 암호화 함수
void chacha20_encrypt(uint8_t *output, const uint8_t *input, size_t len,
     const uint32_t key[8], uint32_t counter, const uint32_t nonce[3]);

#endif