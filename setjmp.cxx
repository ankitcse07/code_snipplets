// This example illustrates the usage of setjmp/longjmp. 
// see man-pages for more information

#include <stdio.h>
#include <setjmp.h>

jmp_buf bufferA, bufferB;

void routineB(); // forward declaration 

void routineA()
{
    int r ;

    printf("(A1)\n");

    r = setjmp(bufferA);
    if (r == 0) routineB();
    else
        printf("1 Return from routine \n");

    printf("(A2) r=%d\n",r);

    r = setjmp(bufferA);
    if (r == 0) longjmp(bufferB, 20001);
    else
        printf("2 Return from routine \n");

    printf("(A3) r=%d\n",r);

    r = setjmp(bufferA);
    if (r == 0) longjmp(bufferB, 20002);
    else
        printf("3 Return from routine \n");

    printf("(A4) r=%d\n",r);
}

void routineB()
{
    int r;

    printf("(B1)\n");

    r = setjmp(bufferB);
    if (r == 0) longjmp(bufferA, 10001);

    printf("(B2) r=%d\n", r);

    r = setjmp(bufferB);
    if (r == 0) longjmp(bufferA, 10002);

    printf("(B3) r=%d\n", r);

    r = setjmp(bufferB);
    if (r == 0) longjmp(bufferA, 10003);
}


int main(int argc, char **argv) 
{
    routineA();
    return 0;
}
