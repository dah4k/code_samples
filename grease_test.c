#include <stdio.h>
#include <stdint.h>

/* JA3/JA3S calculations must ignore GREASE values
 * as described in RFC 8701.
 */
#define IS_GREASE_TLS(x) ((((x) & 0x0f0f) == 0x0a0a) && \
                          (((x) & 0x00ff) == (((x)>>8) & 0x00ff)))

int main()
{
    uint16_t i;

    puts("[*] Start GREASE Test");
    i = 0x0000;

loop:
    IS_GREASE_TLS(i)
        ? printf("[+] GREASE value: %08x\n", i)
        : printf("[-] Normal value: %08x\n", i)
        ;
    if (i++ != 0xffff) goto loop;

    puts("[*] End GREASE Test");
    return 0;
}
