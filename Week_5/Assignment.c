#include <stdio.h> 
#include <stdlib.h>

size_t word_conter(FILE *my_file){
    
    if(my_file == NULL){
        perror("Error in file");
        exit(1);
    }

    size_t counter = 0, in_word = 0;
    char ch;

    while((ch = fgetc(my_file)) != EOF){

        if(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\0'){
            if(in_word){
                in_word = 0;
                counter++;
            }
        }
        else in_word = 1;
    }

    return counter;
}


int main(void){

    FILE *my_file;
    my_file = fopen("seals.txt", "r");

    if(my_file == NULL){
        perror("Error in file");
        exit(1);
    }

    size_t size = word_conter(my_file);
    printf("Number of integers in file: %lu\n", size);

    rewind(my_file);

    int weight = 0;
    int seals[size];

    int i;

      for(i = 0; i < size; i++){
        if(fscanf(my_file, "%d", &weight) == 1)
            seals[i] = weight;
        else break;
    }

    for(i = 0; i < size; i++){
        printf("%d\t %d\n", i, seals[i]);
    }
    
    fclose(my_file);    
    return 0;
}