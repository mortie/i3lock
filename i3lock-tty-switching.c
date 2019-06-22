#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stropts.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/vt.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <lock|unlock>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int req;
    if (strcmp(argv[1], "lock") == 0) {
        req = VT_LOCKSWITCH;
    } else if (strcmp(argv[1], "unlock") == 0) {
        req = VT_UNLOCKSWITCH;
    } else {
        printf("Usage: %s <lock|unlock>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int term = open("/dev/console", O_RDWR);
    if (term < 0) {
        perror("/dev/console");
        return EXIT_FAILURE;
    }

    if (ioctl(term, req) < 0) {
        perror("/dev/consol");
    }

    return EXIT_SUCCESS;
}
