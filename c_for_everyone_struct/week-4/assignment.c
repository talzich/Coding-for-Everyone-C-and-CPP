/*
    This program is the general version of week 4 assignment
    by Tal Zichlinsky
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This method will take a file pointer, an int and an array and will read data from 
    the file into the array. In addition, this method writes the data into the output file
*/
void read_file(FILE *ifp, FILE *ofp, int d[], int size){
	
    int i; 
    for(i = 0; i < size; i++){
        fscanf(ifp, "%d", &d[i]);
    }
}

// This methos will return the average of the contents of argument array
double average(int d[], int size){
	double avg;
	int i;
	for(i = 0; i < size; i++){
		avg += d[i];
	}
	return (avg/size);
}

// This method will return the maximum element in the array. 
int find_max(int d[], int size){
    if(size < 1){
        perror("No data");
        exit(1);
    }

    int i, max = d[0];
    for(i = 1; i < size; i++){
        if(d[i] >  max)
            max = d[i];
    }
    return max;
}

// This methods prints all the elements of the array
void print_array(int d[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d\t", d[i]);
        if((i+1)%10 == 0)
            printf("\n");
    }
    printf("\n");
}

// This method stores the answer in the file passed as parameter
void store_answer(int d[], int size, double avg, int max, FILE *ofp){

    char line1[] = "File contained following elements:\n";
    char maximum[] = "Max is:\t";
    char average[] = "Average is:\t";
    char c, element[10];
    int i, j;
    
    // Writing first line to the file
    for(i = 0; i < strlen(line1); i++){
        putc(line1[i], ofp);
    }

    // Writing all elements to the file.
    // First for loop iterates through all the elements in the array.
    // Inner for loop iterates through
    for(i = 0; i < size; i++){
        sprintf(element, "%d", d[i]);
        for(j = 0; j < strlen(element); j++){
            putc(element[j], ofp);
        }
        putc('\t', ofp);
        if((i+1)%10 == 0)
            putc('\n', ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);

    // Writing maximum line maximum value to the file
    for(i = 0; i < strlen(maximum); i++){
        putc(maximum[i], ofp);
    }

    // Writing maximum value to the file
    sprintf(element, "%d", max);
    for (i = 0; i < strlen(element); i++){
        putc(element[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);

    // Writing average line to the file
    for(i = 0; i < strlen(average); i++){
        putc(average[i], ofp);
    }

    // Writing average value to the file
    sprintf(element, "%f", avg);
    for(i = 0; i < strlen(element); i++){
        putc(element[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);

}

// This method will take a file pointer as parameter and will print the content of the file
void print_file(FILE *fp){

	rewind(fp);
	char c;
	while((c = getc(fp)) != EOF){
		putc(c, stdout);
	}
}

int main(int argc, char *argv[]){

    FILE *ifp, *ofp; // Those files will be our input and output files
    int size, max;
    double avg;
    char str_avg[50];
    
    // Opening the files
    ifp = fopen("data", "r");
    ofp = fopen("answer-hw3", "w+");
    
    // Checking validity of file
    if(fscanf(ifp, "%d", &size) != 1){
        printf("File empty\n");
        exit(1);
    }
    
    int data[size];

    // It's importent not to rewind before that point
    read_file(ifp, ofp, data, size);

    // Storing the values of max element and average
    avg = average(data, size);
    max = find_max(data, size);

    store_answer(data, size, avg, max, ofp);
    print_file(ofp);
}