#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
char * deleteSpaces(char * string){
    char * newString = (char*)malloc(250*sizeof(char));
    int count = 0;
    for (int i = 0; *(string+i)!='\0';i++){
        if (*(string+i) != ' '){
            newString[count] = *(string+i);
            count++;
        }
    }
    newString[count]='\0';
    return newString;
}
int main() {
 FILE * file = NULL;
 char fileName[] = "C:\\Users\\boost\\CLionProjects\\untitled1\\lab-11-1.txt"; //Your file patch
 file = fopen(fileName, "r");
 char* string = (char*)malloc(250+sizeof(char));
 if (file != NULL){
     printf("File \"%s\" successfully opened.", fileName);
     do {
         fgets(string,50,file);
     } while (!feof(file));
     fclose(file);
 } else{printf("Error opening file.");}
 printf("\n");
 puts(deleteSpaces(string));
    return 0;
}