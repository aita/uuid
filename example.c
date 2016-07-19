#include "uuid.h"
#include <stdio.h>

int
main()
{
    int i;
    uuid_t uu;
    char buf[37];

    for (i = 0; i < 10; i++) {
        uuid_generate(uu);
        uuid_unparse(uu, buf);
        printf("%s\n", buf);
    }

    return 0;
};
