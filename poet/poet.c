#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct poem {
    char text[1024];
    char author[64];
    int score;
} poem_t;

poem_t poem;

void reward() {
    char flag[128];
    FILE* file = fopen("./flag.txt", "r");
    fgets(flag, 128, file);

    printf("\n"
           "CONGRATULATIONS\n\n"
           "THE POET\n%.64s\n\n"
           "RECEIVES THE AWARD FOR POET OF THE YEAR 2018!\n\n"
           "THE PRIZE IS THE FOLLOWING FLAG:\n%s\n"
           "+---------------------------------------------------------------------------+\n\n",
           poem.author, flag);
    exit(0);
}


void rate_poem() {
    char tmp[1024];
    strcpy(tmp, poem.text);
    char* token = strtok(tmp, " \n");
    while (token) {
        if(!strcmp(token, "ESPR")   ||
           !strcmp(token, "eat")    ||
           !strcmp(token, "sleep")  ||
           !strcmp(token, "pwn")    ||
           !strcmp(token, "repeat")    ||
           !strcmp(token, "CTF")    ||
           !strcmp(token, "capture")    ||
           !strcmp(token, "flag")) {
            poem.score += 100;
        }
        token = strtok(NULL, " \n");
    }
    
    printf("\n+---------------------------------------------------------------------------+\n"
           "THE POEM\n%.1024s\n"
           "SCORED %d POINTS.\n",
           poem.text, poem.score);
}


void get_poem() {
    printf("Enter the poem here:\n> ");
    gets(poem.text);
    poem.score = 0;
}


void get_author() {
    printf("Who is the author of this poem?\n> ");
    gets(poem.author);
}



int main(int argc, char* argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("\n"
           "**********************************************************\n"
           "* We are searching for the poet of the year 2018.        *\n"
           "* Submit your one line poem now to win an amazing prize! *\n"
           "**********************************************************\n\n");

    while (1) {
        get_poem();

        get_author();

        rate_poem();

        if (poem.score == 1000000) {
            reward();
        } else {
            printf("\n"
                   "SORRY, THIS POEM IS JUST NOT GOOD ENOUGH.\n"
                   "YOU MUST SCORE EXACTLY 1000000 POINTS.\n"
                   "TRY AGAIN!\n"
                   "+---------------------------------------------------------------------------+\n\n");
        }
    }
}
