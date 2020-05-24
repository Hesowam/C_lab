#include <stdio.h>
int CharacterCheck(char* str, char sym) {
    int count = 0;
    for (int i=0; str[i]!='\0'; i++){
        if (str[i] == sym) {
            count++;
        }
    }
    return count;
}
void main() {
    char *string;
    string = "You motherfucker, come on you little ass. fuck with me, eh? You fucking little asshole, dickhead cocksucker!";
    printf("\nOn string - % s\n Count char \",\" - %d\n Count char \"!\" - %d \n Count char \".\" - %d",
           string, CharacterCheck(string,','),CharacterCheck(string,'!'),CharacterCheck(string,'.'));
}