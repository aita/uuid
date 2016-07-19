#ifndef _UUID_H_
#define _UUID_H_

typedef unsigned char uuid_t[16];

extern uuid_t UUID_NIL;

void uuid_generate(uuid_t out);
void uuid_generate_random(uuid_t out);
void uuid_unparse(uuid_t uu, char *out);
void uuid_unparse_upper(uuid_t uu, char *out);
void uuid_unparse_lower(uuid_t uu, char *out);

#endif /* _UUID_H_ */
