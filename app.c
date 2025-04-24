#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Required for getenv

int main(int argc, char *argv[]){
    for (int i = 1; i < argc; i++){
        printf("%d: %s\n", i, argv[i]);
    }

     // Check for the RELEASE environment variable
    const char* release_env = getenv("RELEASE");

    if (release_env != NULL && strcmp(release_env, "true") == 0) {
        printf("This is a RELEASE build.\n");
    } else {
        printf("This is a standard build.\n");
    }

    return 0;
}