#include <stdio.h>

int main(void){
    char c = 'a';
    printf("c in ASCII is %d\n", c);
    printf("c is the character %c\n", c);
    printf("Three consecutive chars are: %c%c%c\n",c, c+1, c+2 );
    printf("Three bell rings sounds like: %c%c%c\n",'\a', '\a', '\a' );
    return 0;
}
