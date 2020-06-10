#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
int * stringToInteger(char * string, int n){//String array {1 2 0 4} to Integer array
    int * integerArray = calloc(n, sizeof(int));
    if (integerArray == NULL){printf("\nMemory error\n");return 0;}
    for (int i = 0, p = 0; p<n;i++, p++){
        char * tempChar = (char*)malloc(10*sizeof(char ));
        if (tempChar == NULL){printf("\nMemory error\n");return 0;}
        for (int d = 0; string[i]!=' ' && string[i]!='\0'; i++, d++){
            tempChar[d] = string[i];
        }
        *(integerArray+p) = atoi(tempChar);
        free(tempChar);
    }
    return integerArray;
}
int getDifference(int * pInt, int n){
    int min = getMinimalElement(pInt, n), max = getMaximumElement(pInt,n);
    if (min>max)return 0;
    int sum = 0;
    for (int i = 0; i<n; i++) {
        if (pInt[i] == min){
            for (int j = i; pInt[j]!=max; j++) {
                sum+=pInt[j];
            }
            return sum;
        }
    }
}
int * sort(int * pArray, int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n-1; j++){
            if (pArray[j]>pArray[j+1]){
                int temp = pArray[j];
                pArray[j] = pArray[j+1];
                pArray[j+1] = temp;
            }
        }
    }
    return pArray;
}
int getMinimalElement(int * pInt, int n){
    int MINIMAL = 32767;
    for (int i = 0; i < n; ++i) {
        if (MINIMAL > pInt[i] && pInt[i]%2!=0){
            MINIMAL = pInt[i];
        }
    }
    return  MINIMAL;
}
int getMaximumElement(int * pInt, int n){
    int MAXIMUM = -32768;
    for (int i = 0; i < n; ++i) {
        if (MAXIMUM < pInt[i] && pInt[i]%2==0){
            MAXIMUM = pInt[i];
        }
    }
    return MAXIMUM;
}
int main() {
 FILE * file = NULL;
 const char fileName[] = "..//lab-11-2.txt"; //Your file patch
 file = fopen(fileName, "r");
 char * tempString = (char *)malloc(250+sizeof(char));
 char * string;
 string = "";
 if (file != NULL){
     printf("File \"%s\" successfully opened.", fileName);
     do {
         fgets(tempString,250,file);
         strcat(string, tempString);
     } while (!feof(file));
     free(tempString); fclose(file);
 } else{printf("Error opening file.");return 0;}
    printf("\n");
 int n = 500;
 int * array = sort(stringToInteger(string,n), n);
 for (int i = 0; i< n; i++){
     printf("%d ", array[i]);
 }
 printf("\nMinimal element of the array - %d", getMinimalElement(array, n));
 printf("\nMaximal element of the array - %d", getMaximumElement(array, n));
 printf("\nThe difference between the minimum odd and maximum even element of the array- %d", getDifference(array, n));
    return 0;
}
