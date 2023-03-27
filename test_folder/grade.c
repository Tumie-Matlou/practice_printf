#include <stdio.h>
#include <stdlib.h>

/**
 * This program is going to recieve a makr, show you yhr mark then grade it
 * main()- Main function 
 * return - will return 0
 * int grade - will store our input value
 * scanf()
 */
int main(void)
{
        int grade;

        printf("Enter your grade mark here\n");

        scanf("%d", &grade);

        if ((grade > 100) && (grade < 0))
        {
                printf("This grade, %d , is not possible!\n", grade);
        } else if ((grade <= 100) && (grade >= 50))
        {
                printf("This grade, %d , is a PASS\n", grade);
        } else if ((grade > 0) && (grade < 50)) 
        {
                printf("This grade, %d , is a FAIL\n", grade);
        } else { printf("No data found\n");
        }
        return (0);
