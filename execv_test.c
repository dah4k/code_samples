#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>         /* execv() */

void pdebugFmt(char const *fmt,...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

void pdebugArr(char *const prefix, char *const argv[])
{
    int i = 0;
    while (*argv) {
        fprintf(stderr, "%s[%d] = %s\n", prefix, i++, *argv++);
    }
}

int main(int argc, char *const argv[])
{
    pdebugFmt("argc = %d\n", argc);
    pdebugArr("argv", argv);

    char *const cmd_path = argv[1];
    char *const *cmd_argv = &argv[1];

    pdebugFmt("\tcmd_path = %s\n", cmd_path);
    pdebugArr("\tcmd_argv", cmd_argv);

    execv(cmd_path, cmd_argv);  /* success never returns */
    perror(cmd_path);

    return EXIT_FAILURE;
}
