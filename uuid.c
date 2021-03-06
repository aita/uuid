#include "uuid.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

uuid_t UUID_NIL = {0};

int
rand_bytes(unsigned char *out, size_t size)
{
    int fd, r;

    fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    r = read(fd, out, size);
    if (r < 0) {
        return -1;
    }
    if (r != size) {
        return -1;
    }
    close(fd);

    return 0;
}

void
uuid_generate(uuid_t out)
{
    uuid_generate_random(out);
}

void
uuid_generate_random(uuid_t out)
{
    if (rand_bytes(out, sizeof(uuid_t)) < 0) {
        memcpy(out, UUID_NIL, sizeof(uuid_t));
        return;
    }

    out[6] = (out[6] & 0x0F) | 0x40;
    out[8] = (out[8] & 0x3F) | 0x80;
}

void
uuid_unparse(uuid_t uu, uuid_string_t out)
{
    uuid_unparse_upper(uu, out);
}

void
uuid_unparse_upper(uuid_t uu, uuid_string_t out)
{
    snprintf(out,
             sizeof(uuid_string_t),
             "%02X%02X%02X%02X-"
             "%02X%02X-"
             "%02X%02X-"
             "%02X%02X-"
             "%02X%02X%02X%02X%02X%02X",
             uu[0], uu[1], uu[2], uu[3],
             uu[4], uu[5],
             uu[6], uu[7],
             uu[8], uu[9],
             uu[10], uu[11], uu[12], uu[13], uu[14], uu[15]);
}

void
uuid_unparse_lower(uuid_t uu, uuid_string_t out)
{
    snprintf(out,
             sizeof(uuid_string_t),
             "%02x%02x%02x%02x-"
             "%02x%02x-"
             "%02x%02x-"
             "%02x%02x-"
             "%02x%02x%02x%02x%02x%02x",
             uu[0], uu[1], uu[2], uu[3],
             uu[4], uu[5],
             uu[6], uu[7],
             uu[8], uu[9],
             uu[10], uu[11], uu[12], uu[13], uu[14], uu[15]);
}
