#include <iostream>

#include <stdio.h>
void my_int_func(int x)
{
    printf( "%d\n", x );
}

int main()
{
    void (*foo)(int);
    /* the ampersand is actually optional */
    foo = &my_int_func;

    foo(100);

    system("pause");
    return 0;
}
