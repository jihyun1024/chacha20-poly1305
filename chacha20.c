// chacha20 알고리즘만 구현
#include "chacha20.h"

#include <stdio.h>

void chacha20_block(uint8_t output[64], const uint32_t key[8], 
    uint32_t counter, const uint32_t nonce[3]) {

    uint32_t state[16];
    uint32_t x[16];

    // 고정된 상수 ("expand 32-byte k"를 Little-Endian으로)
    state[0] = 0x61707865;
    state[1] = 0x3320646e;
    state[2] = 0x79622d32;
    state[3] = 0x6b206574;

    // 256bit 키
    for (int i = 0; i < 8; i++) state[4 + i] = key[i];

    // 블록 카운터
    state[12] = counter;

    // nonce
    state[13] = nonce[0];
    state[14] = nonce[1];
    state[15] = nonce[2];

    memcpy(x, state, sizeof(state));

    // 20-round 연산 수행 (Column 10번 + Diagonal 10번 = 20번)
    for (int i = 0; i < 10; i++) {
        QUARTERROUND(x[0], x[4], x[8], x[12]); // Column
        QUARTERROUND(x[1], x[5], x[9], x[13]);
        QUARTERROUND(x[2], x[6], x[10], x[14]);
        QUARTERROUND(x[3], x[7], x[11], x[15]);
        QUARTERROUND(x[0], x[5], x[10], x[15]); // Diagonal
        QUARTERROUND(x[1], x[6], x[11], x[12]);
        QUARTERROUND(x[2], x[7], x[8], x[13]);
        QUARTERROUND(x[3], x[4], x[9], x[14]);
    }

    // 상태 += 초기 상태
    for (int i = 0; i < 16; i++) {
        uint32_t value = x[i] + state[i];

        // Little-Endian 형태로 출력 버퍼에 저장
        output[i * 4 + 0] = (uint8_t)(value >> 0);
        output[i * 4 + 1] = (uint8_t)(value >> 8);
        output[i * 4 + 2] = (uint8_t)(value >> 16);
        output[i * 4 + 3] = (uint8_t)(value >> 24);
    }
}

void chacha20_encrypt(uint8_t *output, const uint8_t *input, size_t len,
    const uint32_t key[8], uint32_t counter, const uint32_t nonce[3]) {
    
    uint8_t keystream[64];
    size_t offset = 0;

    while (len > 0) {
        chacha20_block(keystream, key, counter++, nonce);

        size_t block_len = (len > 64) ? 64 : len;
        for (size_t j = 0; j < block_len; j++) {
            output[offset + j] = input[offset + j] ^ keystream[j];
        }

        offset += block_len;
        len -= block_len;
    }
}