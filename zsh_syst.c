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
	system("ft_lock");
        exit(42);
    } else if (ret == 0) {
        // Timeout occurred
	system("ft_lock");
        exit(42);
    } else {
        if (fgets(pass, sizeof(pass), stdin) == NULL) {
	system("ft_lock");
            exit(42);
        } else {
            pass[strcspn(pass, "\n")] = 0; // Remove trailing newline
            if (strcmp(pass, "60065") == 0) {
		system("clear");
                printf("%sWelcome back king%s\n", GREEN, RESET);
                exit(13);
            } else {
	system("ft_lock");
                exit(42);
            }
        }
    }
}

void no_ctrlc() {
    exit(42);
}

int main() {
    signal(SIGINT, no_ctrlc);
    signal(SIGQUIT, no_ctrlc);
    while (1) {
        starter();
    }
    return 42;
}
