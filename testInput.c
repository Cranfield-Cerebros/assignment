#include <stdio.h>
#include "inputHandler.h"

int main(){

    char path[] = "parameters.txt";
    char mode = "r"

    FILE* fd = accessAFile(path, mode);

    modifyAField(fd, path, "alphaK1", 0.86);
    
    return 0;
}
