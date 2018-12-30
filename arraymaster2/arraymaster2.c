#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


typedef struct array array_t;
struct array {
    size_t length;
    size_t type;
    void* data;
    int64_t (*get)(array_t* this, size_t index);
    void (*set)(array_t* this, size_t index, int64_t value);
};


int64_t int8_get(array_t* this, size_t index) {
    if (index < this->length) {
        return ((int8_t*)this->data)[index];
    }
    return 0;
}

int64_t int16_get(array_t* this, size_t index) {
    if (index < this->length) {
        return ((int16_t*)this->data)[index];
    }
    return 0;
}

int64_t int32_get(array_t* this, size_t index) {
    if (index < this->length) {
        return ((int32_t*)this->data)[index];
    }
    return 0;
}

int64_t int64_get(array_t* this, size_t index) {
    if (index < this->length) {
        return ((int64_t*)this->data)[index];
    }
    return 0;
}


void int8_set(array_t* this, size_t index, int64_t value) {
    if (index < this->length) {
        ((int8_t*)this->data)[index] = (int8_t)value;
    }
}

void int16_set(array_t* this, size_t index, int64_t value) {
    if (index < this->length) {
        ((int16_t*)this->data)[index] = (int16_t)value;
    }
}

void int32_set(array_t* this, size_t index, int64_t value) {
    if (index < this->length) {
        ((int32_t*)this->data)[index] = (int32_t)value;
    }
}

void int64_set(array_t* this, size_t index, int64_t value) {
    if (index < this->length) {
        ((int64_t*)this->data)[index] = (int64_t)value;
    }
}



void flush_line() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


array_t* arrays[10];

void list() {
    for (size_t index = 0; index < 10; ++index) {
        printf("[%c] ", (char)('A' + index));
        array_t* a = arrays[index];
        if (a != NULL) {
            printf("{type: %zu, length: %zu}", a->type, a->length); 
        }
        printf("\n");
    }
}

void init(char id, size_t type, size_t l) {
    if (type != 8 && type != 16 && type != 32 && type != 64) {
        printf("Invalid type\n");
        return;
    }

    size_t index = id - 'A';
    if (index > 9) {
        printf("Invalid array ID\n");
        return;
    }

    array_t* a = arrays[index];
    if (a != NULL) {
        printf("This array already exists.\n");
        return;
    }

    array_t* array = malloc(sizeof(array_t));
    if (array == NULL) {
        printf("Error on allocating memory.\n");
        exit(-1);
    }
    array->length = l;
    array->type = type;
    size_t size = l * (type / 8);
    void* data = malloc(size);
    if (data == NULL) {
        printf("Error on allocating memory.\n");
        exit(-1);
    }
    memset(data, 0, size);

    array->data = data;

    switch(type) {
        case 8:
            array->get = int8_get;
            array->set = int8_set;
            break;
        case 16:
            array->get = int16_get;
            array->set = int16_set;
            break;
        case 32:
            array->get = int32_get;
            array->set = int32_set;
            break;
        case 64:
            array->get = int64_get;
            array->set = int64_set;
            break;
    }

    arrays[index] = array;
}

void delete(char id) {
    size_t index = id - 'A';
    if (index > 9) {
        printf("Invalid array ID\n");
        return;
    }
    array_t* a = arrays[index];
    if (a != NULL) {
        free(a->data);
        free(a);
        arrays[index] = NULL;
    } else {
        printf("Array %c does not exist.", id);
    }
}



int main(int argc, char* argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);


    printf( "\n"
            "We implemeted int8, int16, int32, and int64 arrays in C.\n"
            "However, we didn't have time to test them properly.\n"
            "Here is a little test suite. Hopefully you won't find any exploitable bugs!\n"
            "You can perform the following operations:\n"
            "[1] list\n"
            "    Print a summary of all arrays\n"
            "[2] init <ID> <type> <l>\n"
            "    Create an array with ID {A-J} of type {8, 16, 32, 46} and length l\n"
            "[3] delete <ID>\n"
            "    Delete the array with ID {A-J}\n"
            "[4] set <ID> <i> <value>\n"
            "    Set the value at index i of array ID {A-J}\n"
            "[5] get <ID> <i>\n"
            "    Get the value at index i of array ID {A-J}\n"
            "[6] quit\n"
            "    Leave the progam because there are no bugs anyway\n"
            "\n");


    char* line = NULL;
    size_t linelen;
    while (1) {
        char id;
        size_t type;
        size_t length;
        size_t index;
        int64_t value;
        
        printf( "\n"
                "Enter the command you want to execute.\n"
                "[1] list\n"
                "[2] init <ID> <type> <l>\n"
                "[3] delete <ID> \n"
                "[4] set <ID> <i> <value>\n"
                "[5] get <ID> <i>\n"
                "[6] quit\n"
                "\n> ");

        if (getline(&line, &linelen, stdin) == -1) {
            break;
        }

        if (strncmp(line, "list", 4) == 0) {
            list();
        } else if (sscanf(line, "init %c %zu %zu", &id, &type, &length) == 3) {
            init(id, type, length);
        } else if (sscanf(line, "delete %c", &id) == 1) {
            delete(id);
        } else if (sscanf(line, "get %c %zu", &id, &index) == 2) {
            size_t i = id - 'A';
            if (i > 9) {
                printf("Invalid array ID\n");
                continue;
            }
            array_t* a = arrays[i];
            if (a == NULL) {
                printf("This array does not exist.\n");
                continue;
            }
            printf("%" PRId64 "\n", a->get(a, index));
        } else if (sscanf(line, "set %c %zu %" PRId64, &id, &index, &value) == 3) {
            size_t i = id - 'A';
            if (i > 9) {
                printf("Invalid array ID\n");
                continue;
            }
            array_t* a = arrays[i];
            if (a == NULL) {
                printf("This array does not exist.\n");
                continue;
            }
            a->set(a, index, value);
        }
        else if (strncmp(line, "quit", 4) == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    free(line);
}


