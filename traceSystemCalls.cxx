// This testcase allocates memory via malloc and strace is used 
// to see what kind of system calls are invoked internall
//                                  --agarg(24.03.2015)
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    for(int j = 0 ; j < 33; j++)
    {
        char *abc = (char *)malloc(4096);
        for(int i  = 0; i < 4096; i++)
            abc[i] = i;
    }
    return 0;

}

// If we look at the output of strace a.out
// we can see that brk system call is used to allocated
// memory on heap in terms of pages.  
//
//brk(0)                                  = 0x88f7000
//brk(0x8919000)                          = 0x8919000
//

// As see above total 34 pages(each of size 4096) has been
// allocated further allocating memory will again increase
// heap size in terms of certain number of pages. As brk
// system call is expensive so OS has heurisitcs of allocating
// more pages than required.

