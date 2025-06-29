#include <stdio.h>

typedef enum{FALSE, TRUE} boolean;

//  a b c d e f g h i j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
//  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

int hashKey(char letter){
    int hash = -1;
    if(letter >= 'a' && letter <= 'z'){
        hash = (letter - 'a');
    }
    return hash;
}

char toLower(char letter){
    if(letter >= 'A' && letter <= 'Z'){ return letter + 32; }
    return letter;
}

boolean isPangram(char *string){
    int i, alphabet[26] = {0};
    while(*string){
        int index = hashKey(toLower(*string));
        if (index >= 0 && index < 26){
            alphabet[index] = 1;
        }
        string++;
    }
    for(i = 0; i < 26 && alphabet[i] == 1; i++){}

    return (i == 26) ? TRUE : FALSE;
}


int main(){
    printf("Check whether the sentence is a pangram\n(Contains every letter in the alphabet)\n\n");

    char string[256]; // could be more but let's limit to 256
    printf("Input Sentence:  ");
    scanf("%s", string);

    boolean result = isPangram(string);
    printf("Pangram check:  %s\n\n", (result == TRUE) ? "True" : "False");


    return 0;
}


/*
    FOUND OUT AFTERWARDS:
        - COULD'VE USED BIT SHIFTING TO REPRESENT THE ALPHABET INSTEAD OF A 26 SIZED ARRAY
        - ALSO USE FGETS() INSTEAD OF SCANF() TO GET THE STRING INPUT 
*/