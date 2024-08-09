#include <stdio.h>
#include "util/util.h"

int main() 
{
    size_t size = 5, length = 100;
    char **arr = UTIL_getFileValues("../names.txt", size, length);

    for (size_t i = 0 ; i < size ; i++) {
        printf("%s\n", arr[i]);
    }

    free(arr);

    return 0;
}