#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    alignas(64) char buf[80];   // extra space so we can cross boundary
    for (int i = 0; i < 80; i++) buf[i] = i;

    __m128i v = _mm_loadu_si128((__m128i*)&buf[60]); // crosses the 64-byte line
    printf("first byte = %d\n", ((char*)&v)[0]);
    return 0;
}
