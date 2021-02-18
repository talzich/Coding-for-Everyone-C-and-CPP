/*
	This is the first code in week 4.
	We are going to usd File I/O.
	Feb 19th
*/
#include <stdio.h>

#define MAXSIZE 20


/*
	This method will take a file pointer, an array and an int pointer and will read data from
	the file into the array and will store the right size of the array in the int pointer
*/
void read_file(FILE *ifp, int d[], int *size){
	
	// We will init size to 0 to start the count
	*size = 0;
	
	// fscanf will return 0 or 1 depanding on succesfull of unsuccesfull read
	while(fscanf(ifp, "%d", &d[*size]) == 1){
		(*size)++;
	}
}

// This method will print the content of argument array
void print_data(int d[], int size){

	int i;
	for(i = 1; i <= size; i++){
		printf("%d\t", d[i-1]);
		if(i%10 == 0){
			printf("\n");
		}
	}
	printf("\n");
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

int main(void){
	int d[MAXSIZE], size;
	FILE *ifp;
	ifp = fopen("myhw", "r");
	read_file(ifp, d, &size);
	print_data(d, size);
	printf("avg is %lf\n", average(d, size));
	fclose(ifp);
	return 0;
}












