#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

//max length of strings
#define LENGTH 256

//mode: "r"->read, "w"->write...
FILE* accessAFile(char* path, char* mode);

void modifyAField(FILE* fd, char* fieldName, double value);




#endif
