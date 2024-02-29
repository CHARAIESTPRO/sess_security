#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define GREEN "\x1B[32m"
#define RESET "\x1B[0m"

void starter() {
    char pass[6];
    printf("Enter password: ");
    fflush(stdout);
    if (fgets(pass, sizeof(pass), stdin) == NULL) {
        exit(42);
    } else {
        pass[strcspn(pass, "\n")] = 0; // Remove trailing newline
        if (strcmp(pass, "60065") == 0) {
            printf("%sWelcome back king%s\n", GREEN, RESET);
            exit(13);
        } else {
            exit(42);
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
