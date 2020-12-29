#include <stdio.h> 

int main(void){

    FILE *myFile;
    myFile = fopen("seals.txt", "r");
    if(myFile == NULL){
        perror("Error in fopen");
        exit(1);
    }

    int word_counter = 0, in_word = 0;
    char ch;

    while((ch = fgetc(myFile)) != EOF){

        if(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\0'){
            if(in_word){
                in_word = 0;
                word_counter++;
            }
        }
        else in_word = 1;
    }
    printf("Number of words: %d\n", word_counter);
}