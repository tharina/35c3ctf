// compile with -no-pie -fno-stack-protector

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void spawn_shell() {
    char* args[] = {(char*)"/bin/bash", NULL};
    execve("/bin/bash", args, NULL);
}

int main() {
    char buf[1024];

    cout << "Which environment variable do you want to read? ";
    cin >> buf;

    cout << buf << "=" << getenv(buf) << endl;
}
