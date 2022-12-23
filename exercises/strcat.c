#include <stdio.h>

void my_strcat(char *c, const char *d){
    printf("%s\n%s\n", c, d);
    while((*c++ = *d++) != '\0')
        printf("%s\n", c);
}

int main(){
    char a[] = "Hello, ";
    char b[] = "World!";
    char *c = a;
    char *d = b;
    // while((*c++ = *d++) != '\0');
    // printf("%s\n", a);
    // my_strcat(c, d);
    while((*c++ = *d++) != '\0');
    printf("%s\n%s\n", c, d);
}