#include "api.h"
#include "hqc.h"
#include <stdio.h>

int main(void) {
    // HQC 관련 변수 선언
    unsigned char pk[PQCLEAN_HQC128_CLEAN_CRYPTO_PUBLICKEYBYTES];
    unsigned char sk[PQCLEAN_HQC128_CLEAN_CRYPTO_SECRETKEYBYTES];
    unsigned char ct[PQCLEAN_HQC128_CLEAN_CRYPTO_CIPHERTEXTBYTES];
    unsigned char ss1[PQCLEAN_HQC128_CLEAN_CRYPTO_BYTES];
    unsigned char ss2[PQCLEAN_HQC128_CLEAN_CRYPTO_BYTES];

    for (int i = 0; i < 20000; i++) {
    // 키 생성
    PQCLEAN_HQC128_CLEAN_crypto_kem_keypair(pk, sk);

    // 암호화
    PQCLEAN_HQC128_CLEAN_crypto_kem_enc(ct, ss1, pk);

    // 복호화
    PQCLEAN_HQC128_CLEAN_crypto_kem_dec(ss2, ct, sk);
    }

    // 결과 출력
    printf("공유 비밀키 (암호화 시): ");
    for (int i = 0; i < PQCLEAN_HQC128_CLEAN_CRYPTO_BYTES; i++) {
        printf("%02x", ss1[i]);
    }
    printf("\n");

    printf("공유 비밀키 (복호화 시): ");
    for (int i = 0; i < PQCLEAN_HQC128_CLEAN_CRYPTO_BYTES; i++) {
        printf("%02x", ss2[i]);
    }
    printf("\n");

    return 0;
}
