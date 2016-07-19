#include "uuid.h"
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define UUID_STRING_LENGTH 37

uuid_t UUID_NIL = {0};


int
rand_bytes(unsigned char *out, size_t size)
{
    int fd, err;

    fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1) {
        return -1;
    }
    err = read(fd, out, size);
    close(fd);

    return err;
}

void
uuid_generate(uuid_t out)
{
    uuid_generate_random(out);
}

void
uuid_generate_random(uuid_t out)
{
    if (rand_bytes(out, sizeof(uuid_t) < 0)) {
        memcpy(out, UUID_NIL, sizeof(uuid_t));
        return;
    }

    out[6] = (out[6] & 0x0F) | 0x40;
    out[8] = (out[8] & 0x3F) | 0x80;
}

void
uuid_unparse(uuid_t uu, char *out)
{
    uuid_unparse_upper(uu, out);
}

void
uuid_unparse_upper(uuid_t uu, char *out)
{
    snprintf(out,
             UUID_STRING_LENGTH,
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
uuid_unparse_lower(uuid_t uu, char *out)
{
    snprintf(out,
             UUID_STRING_LENGTH,
             "%02x%02x02x%02x-"
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
