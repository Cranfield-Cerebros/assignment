#include <stdio.h>
#include <stdlib.h>

#include "inputHandler.h"

FILE* accessAFile(char* path, char* mode){
    FILE* fd = fopen(path, mode);

    if (fd == NULL) {
        perror("Failed to open the file %s", path);
        exit(-1);
    }
    return fd;
}



void modifyAField(FILE* fd, char* path, char* fieldName, double value){
    char temp[] = "temp.txt";
    FILE* fdTemp = accessAFile(temp, "w");

    double currentValue;
    char currentFieldName[256];
    char line[256]

    while(!feof(fd)){
        fscanf(fd, "%s %f", currentFieldName, &currentValue);
        fgets(line, LENGTH, fd);

        if (strcmp(currentFieldName, fieldName) == 0) {
            fprintf(fdTemp, "%s %f", fieldName, value);
        } else {
            fprintf(fdTemp, "%s", line);
        }
    }
    remove(path);
    rename(temp, path);

    closeFile(fdTemp);
    closeFile(fd);
}



void closeFile(FILE* fd){
    fclose(fd);
}
