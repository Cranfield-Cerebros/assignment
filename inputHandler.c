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



void modifyAField(FILE* fd, char* path, char* fieldName, double value){
    char tempPath[] = "temp.txt";
    FILE* fdTemp = accessAFile(tempPath, "w");

    double currentValue;
    char currentFieldName[256];
    char line[256];

    while (!feof(fd)){

        fgets(line, LENGTH, fd);

        if (strncmp(line, fieldName, strlen(fieldName)) == 0) {

            fprintf(fdTemp, "%s %f;\n", fieldName, value);

        } else {

            fprintf(fdTemp, "%s", line);

        }

    }

    if (remove(path) == 0){
        fprintf(stderr, "Failed to remove the file parameters.txt\n");
    }

    if (rename(tempPath, path) == 0){
        fprintf(stderr, "Failed to rename the file temp.txt as parameters.txt\n");
    }

    closeFile(fdTemp);
    closeFile(fd);
}



void closeFile(FILE* fd){
    fclose(fd);
}
