/*
	This program will take a file, and will double space 
	every new line
*/

#include <stdio.h>
#include <stdlib.h>

// This method will take a file pointer as parameter and will print the content of the file
void print_file(FILE *fp){

	rewind(fp);
	char c;
	while((c = getc(fp)) != EOF){
		putc(c, stdout);
	}
}

// This method will do the actual double spacing 
void double_space(FILE *ifp, FILE *ofp){

	rewind(ifp);
	char c;
	while((c = getc(ifp)) != EOF){
		putc(c, ofp);
		if(c == '\n'){
			putc('\n', ofp);
		}
	}
}

int main(int argc, char *argv[]){

	FILE *ifp, *ofp;
	if(argc != 3){
		perror("No input or output");
		exit(1);
	}
	
	ifp = fopen(argv[1], "r+");
	ofp = fopen(argv[2], "w+");
	double_space(ifp, ofp);
	print_file(ifp);
	print_file(ofp);
	return 0;
}




