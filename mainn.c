#include <stdlib.h>

char    *test(const char *s)
{
    char *c = malloc(15);
    free((char *)s);
    return (c);
}

void check_leaks();
int main()
{
    char *s = malloc(2);
    s = test(s);
    s = test(s);
    free(s);
    check_leaks();
}