#include <stdio.h>
#include <string.h>
#include <stddef.h>


void reverse (char *s) {
    size_t str_len = strlen(s);
    if (!str_len) return;

    int i = 0;
    int j = str_len - 1;

    char tmp;
    while (i < j) {
        printf("i: %d, j: %d\n", i, j);
        tmp = s[i];
        s[i] = s[j];
        // s[0] = s[2]
        s[j] = tmp;
        // s[2] = s[0]
        i++;
        j--;
    }

}

void reverse_strings_array(size_t len, size_t width, char strs[len][width]) {
    if (!strs || !len) return;
    for (size_t i = 0; i < len; i++) reverse(strs[i]);
}

int main(void)
{

    const char *str = "123abc123";
    const char *accept = "0123456789";

    size_t len = strspn(str, accept);
    printf("Digits at start: %zu\n", len); // prints: 3
    return 0;
    // char str[][4] = {"123", "456", "789"};
    // size_t arr_len = sizeof(str) / sizeof(*str);
    // if (!arr_len) return 0;
    // reverse_strings_array(arr_len, sizeof(*str), str);
    // for (size_t i = 0; i < arr_len; i++) {
    //     printf("STRING [%ld]: %s \n", i, str[i]);
    // }

    

    return 0;
}
