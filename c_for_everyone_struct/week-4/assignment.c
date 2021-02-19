/*
    This program is the general version of week 4 assignment
    by Tal Zichlinsky
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This method will take a file pointer, an int and an array and will read data from 
    the file into the array
*/
void read_file(FILE *ifp, int d[], int size){
	
    int i; 
    for(i = 0; i < size; i++){
        fscanf(ifp, "%d", &d[i]);
    }
}

// This method will return the average of the contents of argument array
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

// This method stores the answer in the file passed as parameter
void store_answer(int d[], int size, double avg, int max, FILE *ofp){

    // Those strings will be written to the file in that order
    char line1[] = "File contained following elements:\n";
    char maximum[] = "Max is:\t";
    char average[] = "Average is:\t";

    // We will use that string for convertion of the numeric values of our data
    char element[10];
    
    // Indices
    int i, j;
    
    // Writing first line to the file
    for(i = 0; i < strlen(line1); i++){
        putc(line1[i], ofp);
    }

    // Writing all elements to the file.
    // First for loop iterates through all the elements in the array.
    // Inner for loop iterates through each element and writes it to the file
    for(i = 0; i < size; i++){

        // Converting each element to string and writing it to ofp
        sprintf(element, "%d", d[i]);
        for(j = 0; j < strlen(element); j++){
            putc(element[j], ofp);
        }
        putc('\t', ofp);

        // Break line every 10 elements
        if((i+1)%10 == 0)
            putc('\n', ofp);

    }
    putc('\n', ofp);
    putc('\n', ofp);

    // Writing maximum line to the file
    for(i = 0; i < strlen(maximum); i++){
        putc(maximum[i], ofp);
    }

    // Writing maximum value to the file
    sprintf(element, "%d", max); // Converting max value to string
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
    sprintf(element, "%lf", avg); // Converting avg value to string
    for(i = 0; i < strlen(element); i++){
        putc(element[i], ofp);
    }
    putc('\n', ofp);
    putc('\n', ofp);
}

// This method will take a file pointer as parameter and will print the content of the file
void print_file(FILE *fp){
	rewind(fp); // In case file pointer needs to be rewind
	char c;
	while((c = getc(fp)) != EOF){
		putc(c, stdout);
	}
}

int main(int argc, char *argv[]){

    FILE *ifp, *ofp; // Those files will be our input and output files
    int n, max;
    double avg;

    // Checking number of arguments
    if(argc != 2){
        printf("Wrong number of arguments, please specify only input file name\n");
        exit(1);
    }
    
    // Opening the files
    ifp = fopen(argv[1], "r");
    ofp = fopen("answer-hw3", "w+");
    
    // If the file is valid, declare an array data of size n
    if(fscanf(ifp, "%d", &n) != 1){
        printf("File empty\n");
        exit(1);
    }
    int data[n];

    // It's importent not to rewind before that point
    read_file(ifp, data, n);

    // Storing the values of max element and average
    avg = average(data, n);
    max = find_max(data, n);

    store_answer(data, n, avg, max, ofp);
    print_file(ofp);

    // Closing the files
    fclose(ifp);
    fclose(ofp);
}