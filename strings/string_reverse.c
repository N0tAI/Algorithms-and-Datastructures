#include <stddef.h>

char* string_reverse(char* dest, const size_t dest_size, const char* source, const size_t source_size) {
    const size_t min_size = (dest_size < source_size ? dest_size : source_size) - 1;

    for(size_t i = 0; i < min_size; i++)
        dest[i] = source[min_size - i - 1];
    
    dest[min_size] = '\0';

    return dest;
}
