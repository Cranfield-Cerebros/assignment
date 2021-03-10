#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputHandler.h"

FILE* accessAFile(char* path, char* mode){
    FILE* fd = fopen(path, mode);

    if (fd == NULL) {
        char* errMsg = strcat("Failed to open the file ", path);
        perror(errMsg);
        exit(-1);
    }
    return fd;
}


void closeFile(FILE* fd){
    fclose(fd);
}


void modifyAField(FILE* fd, char* path, char* fieldName, double value){
    char tempPath[] = "temp.txt";
    FILE* fdTemp = accessAFile(tempPath, "w");

    int lenFieldName = strlen(fieldName);
    char line[LENGTH];

    while (!feof(fd)){

        fgets(line, LENGTH, fd);

        if (strncmp(line, fieldName, lenFieldName) == 0) {

            fprintf(fdTemp, "%-*s %g;\n", 15, fieldName, value); //16-1 (because space in the format string)

        } else {

            fprintf(fdTemp, "%s", line);

        }

    }

    closeFile(fdTemp);
    closeFile(fd);

    if (remove(path) == -1){
        printf("Failed to remove the file parameters.txt. %s\n", strerror(errno));
    }

    if (rename(tempPath, path) == -1){
        printf("Failed to rename the file temp.txt as parameters.txt. %s\n", strerror(errno));
    }

}
