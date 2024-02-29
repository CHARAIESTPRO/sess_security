#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/select.h>

#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

void starter() {
    char pass[6];
    printf("Enter password: ");
    fflush(stdout);
    
    // Set up a file descriptor set for stdin
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    
    // Set timeout to 3 seconds
    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;
    
    int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &timeout);
    if (ret == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        // Timeout occurred
        printf("Timeout occurred\n");
        exit(EXIT_FAILURE);
    } else {
        if (fgets(pass, sizeof(pass), stdin) == NULL) {
            exit(EXIT_FAILURE);
        } else {
            pass[strcspn(pass, "\n")] = 0; // Remove trailing newline
            if (strcmp(pass, "60065") == 0) {
                printf("%sWelcome back king%s\n", GREEN, RESET);
                exit(EXIT_SUCCESS);
            } else {
                exit(EXIT_FAILURE);
            }
        }
    }
}

void no_ctrlc() {
    exit(EXIT_FAILURE);
}

int main() {
    signal(SIGINT, no_ctrlc);
    signal(SIGQUIT, no_ctrlc);
    while (1) {
        starter();
    }
    return EXIT_FAILURE;
}
