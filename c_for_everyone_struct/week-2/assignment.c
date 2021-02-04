#include <stdio.h>

// This enum represents months in a year
typedef enum month{ jan, feb, march, apr, may, jun, jul, aug, sep, oct, nov, dec} month;

// This struct will represent a date, including a day and a month (apr 1st, jan 2nd)
typedef struct date{ month m; int day; }date;

// This function will print date when getting a struct date as a parameter.
void printdate(date d){

	// Notice that for months with different number of days, different validity checks are made.
	switch(d.m){
		case jan:
			if (d.day < 1 || d.day > 31){
                printf("Wrong input!\nThe day you chose doesn't match the month.\n");
                break;
			}
			printf("January %d\n", d.day);
				break;
		case feb:
			if (d.day < 1 || d.day > 28){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			printf("February %d\n", d.day);
				break;
		case march:
            if (d.day < 1 || d.day > 31){
                printf("Wrong input!\nThe day you chose doesn't match the month.\n");
                break;
			}
			printf("March %d\n", d.day);
				break;
		case apr:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			printf("April %d\n", d.day);
				break;
        case may:
			if (d.day < 1 || d.day > 31){
                printf("Wrong input!\nThe day you chose doesn't match the month.\n");
                break;
			}
            printf("May %d\n", d.day);
				break;
		case jun:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			printf("June %d\n", d.day);
				break;
        case jul:
			if (d.day < 1 || d.day > 31){
                printf("Wrong input!\nThe day you chose doesn't match the month.\n");
                break;
			}
            printf("July %d\n", d.day);
				break;
        case aug:
			if (d.day < 1 || d.day > 31){
                printf("Wrong input!\nThe day you chose doesn't match the month.\n");
                break;
			}
            printf("August %d\n", d.day);
				break;
		case sep:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			printf("September %d\n", d.day);
				break;
        case oct:
			if (d.day < 1 || d.day > 31){
                printf("Wrong input!\nThe day you chose doesn't match the month.\n");
                break;
			}
            printf("October %d\n", d.day);
				break;
		case nov:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			printf("November %d\n", d.day);
				break;
        case dec:
			if (d.day < 1 || d.day > 31){
                printf("Wrong input!\nThe day you chose doesn't match the month.\n");
                break;
			}
            printf("December %d\n", d.day);
				break;
	}
}

date *nextday(date d){

	static date next;
	// Notice that for months with different number of days, different validity checks are made.
	switch(d.m){
		case jan:
			if (d.day < 1 || d.day > 31){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 32){next.day = 1; next.m = feb;}
			return &next;
		case feb:
			if (d.day < 1 || d.day > 28){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 29){next.day = 1; next.m = march;}
			return &next;
		case march:
            if (d.day < 1 || d.day > 31){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 32){next.day = 1; next.m = apr;}
			return &next;
		case apr:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 31){next.day = 1; next.m = may;}
			return &next;
        case may:
			if (d.day < 1 || d.day > 31){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 32){next.day = 1; next.m = jun;}
			return &next;
		case jun:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 31){next.day = 1; next.m = jul;}
			return &next;
        case jul:
			if (d.day < 1 || d.day > 31){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 32){next.day = 1; next.m = feb;}
			return &next;
        case aug:
			if (d.day < 1 || d.day > 31){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 32){next.day = 1; next.m = sep;}
			return &next;
		case sep:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 31){next.day = 1; next.m = oct;}
			return &next;
        case oct:
			if (d.day < 1 || d.day > 31){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 32){next.day = 1; next.m = nov;}
			return &next;
		case nov:
			if (d.day < 1 || d.day > 30){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 31){next.day = 1, next.m = dec;}
			return &next;
        case dec:
			if (d.day < 1 || d.day > 31){
				printf("Wrong input!\nThe day you chose doesn't match the month.\n");
				break;
			}
			next.day = d.day + 1;
			if(next.day == 32){next.day = 1; next.m = jan;}
			return &next;
	}
	return &next;
}

// February 28, March 14, October 31, and  December 31
int main(void){

	date d1;
	d1.day = 1;
	d1.m = jan;
	printdate(d1);
	printdate(*(nextday(d1)));

	date d2;
	d2.day = 28;
	d2.m = feb;
	printdate(d2);
	printdate(*(nextday(d2)));

	date d3;
	d3.day = 14;
	d3.m = march;
	printdate(d3);
	printdate(*(nextday(d3)));

	date d4;
	d4.day = 31;
	d4.m = oct;
	printdate(d4);
	printdate(*(nextday(d4)));

	date d5;
	d5.day = 31;
	d5.m = dec;
	printdate(d5);
	printdate(*(nextday(d5)));

	return 0;
}