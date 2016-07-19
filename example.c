#include "uuid.h"
#include <stdio.h>

int
main()
{
    int i;
    uuid_t uu;
    uuid_string_t out;

    for (i = 0; i < 10; i++) {
        uuid_generate(uu);
        uuid_unparse(uu, out);
        printf("%s\n", out);
    }

    return 0;
};
