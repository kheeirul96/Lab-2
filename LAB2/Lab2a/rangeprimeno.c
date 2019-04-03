#include <stdio.h>
#include <stdlib.h>

 

void main()

{

    int num1, num2, i, j, flag, temp, count = 0;

 
	printf("Range of Prime Number \n");
    printf("Enter the value of num1 and num2 \n");
	printf("1st Number : \n");
    scanf("%d", &num1);
	printf("2nd Number :\n");
	scanf("%d", &num2);
    if (num2 < 2)

    {

        printf("There are no primes upto %d\n", num2);

        exit(0);

    }

    printf("Prime numbers are \n");

    temp = num1;

    if ( num1 % 2 == 0)

    {

        num1++;

    }

    for (i = num1; i <= num2; i = i + 2)

    {

        flag = 0;

        for (j = 2; j <= i / 2; j++)

        {

            if ((i % j) == 0)

            {

                flag = 1;

                break;

            }

        }

        if (flag == 0)

        {

            printf("%d\n", i);

            count++;

        }

    }

    printf("Number of primes between %d & %d = %d\n", temp, num2, count);

}
