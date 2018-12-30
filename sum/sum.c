#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>



void flush_line() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


void calculator() {
    printf("---------------------\n");
    printf("Simple Sum Calculator\n");
    printf("---------------------\n");
    printf("\n");

    size_t num;
    printf("How many values to you want to sum up?\n> ");
    while (scanf("%zu", &num) != 1) {
        printf("Try again\n> ");
        flush_line();
    }
    flush_line();

    int64_t* values = calloc(num, sizeof(int64_t));
    printf("Allocated space for %zu values\n", num);

    printf( "\n"
            "Enter the values you want to sum up.\n"
            "You can perform the following operations:\n"
            "[1] set <x> <d>\n"
            "    Set the x-th value to d\n"
            "[2] get <x>\n"
            "    Read the x-th value\n"
            "[3] sum\n"
            "    Calculate the sum of all values and leave the program\n"
            "[4] bye\n"
            "    Leave the program                       \n"
            "\n");

    char* line = NULL;
    size_t linelen;
    while (1) {
        size_t index;
        int64_t value;
        
        printf( "\n"
                "Enter the command you want to execute.\n"
                "[1] set <x> <d>\n"
                "[2] get <x>\n"
                "[3] sum\n"
                "[4] bye\n"
                "\n> ");

        if (getline(&line, &linelen, stdin) == -1) {
            break;
        }

        if (sscanf(line, "set %zu %" PRId64, &index, &value) == 2) {
            if (index < num) {
                values[index] = value;
            } else {
                printf("Index out of bounds\n");
            }
        } else if (sscanf(line, "get %zu", &index) == 1) {
            if (index < num) {
                printf("%" PRId64 "\n", values[index]);
            } else {
                printf("Index out of bounds\n");
            }
        } else if (strncmp(line, "sum", 3) == 0) {
            int64_t sum = 0;
            for (int i = 0; i < num; ++i) {
                sum += values[i];
            }
            printf("The sum is: %" PRId64 "\n", sum);
            break;
        } else if (strncmp(line, "bye", 3) == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    free(line);
}


int main(int argc, char* argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);

    calculator();
}


