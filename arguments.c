#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to print an error message and exit the program
void error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

// Function to check if a string is a valid integer
bool isInteger(const char *str) {
    for (const char *ptr = str; *ptr; ptr++) {
        if (!isdigit(*ptr)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    // Initialize variables to store values
    int length = -1;
    char *i = NULL;
    char *w = NULL;
    bool iSpecified = false;
    bool wSpecified = false;
    bool lengthSpecified = false;

    // Parse command-line arguments
    for (int argIndex = 1; argIndex < argc; argIndex++) {
        char *arg = argv[argIndex];
        if (arg[0] == '-') {
            if (argIndex + 1 >= argc) {
                error("Missing argument for option");
            }

            char *option = arg + 1; // Skip the '-'
            char *value = argv[argIndex + 1];

            if (strcmp(option, "length") == 0) {
                if (!isInteger(value)) {
                    error("Invalid value for -length");
                }
                if (lengthSpecified) {
                    error("Option -length specified more than once");
                }
                length = atoi(value);
                lengthSpecified = true;
            } else if (strcmp(option, "i") == 0) {
                if (iSpecified) {
                    error("Option -i specified more than once");
                }
                i = value;
                iSpecified = true;
            } else if (strcmp(option, "w") == 0) {
                if (wSpecified) {
                    error("Option -w specified more than once");
                }
                w = value;
                wSpecified = true;
            } else {
                error("Unknown option");
            }

            argIndex++; // Skip the next argument since it's the value for the option
        } else {
            error("Options should start with '-'");
        }
    }

    // Print parsed values
    printf("length: %d\n", length);
    printf("i: %s\n", i ? i : "Not specified");
    printf("w: %s\n", w ? w : "Not specified");

    return 0;
}




