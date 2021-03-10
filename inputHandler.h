#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

//max length of strings
#define LENGTH 256

//mode: "r"->read, "w"->write...
FILE* accessAFile(char* path, char* mode);


//1st: file descriptor, 2nd: its path, 3rd: value to modify, 4th: new value
//!\\ close the given file descriptor at the end 
void modifyAField(FILE* fd, char* path, char* fieldName, double value);




#endif
