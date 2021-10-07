#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define STATS_STRING "--stats" //string for --stats parameter

//kksegmentation fault control valgrind + gcc -g 

/*Function that compares 2 strings. Return 0 if strings are the same, otherwise return 1.*/

int compareStrings (char str1[], char str2[])
{
   int i;
   for (i = 0 ; ; i++)
   {
       if (str1[i] != str2[i])
       {
           return 1;
       }
   }
   return 0;
}


int main(int argc, char *argv[]) //argc - the number of arguments, default = 1
{   
    unsigned short int param, level;
   // char opt [10];
    level = atoi(argv[1]);
    param = atoi(argv[2]);
    char *opt = argv[3]; //
    //if (argc == 3)
    //{
     //   opt = argv [3];
      //  printf ("%s \n", opt);
   // }

    //check if level and params are ok 
    printf("lvl %d\nparam %d\nstring %s\n", level, param, opt);
    if (level > 4)
    {
        printf("invalid params\n");
        return 1;
    }
        (void)argc;

return 0;
}
