#include <cs50.h>
#include <stdio.h>

int numDigits(long x);
int my_floor(double x);

int main(void)
{
    long number = get_long("Number: ");
    int l = (int)my_floor(numDigits(number)); //Calculating the number of digits

    long frstNum = number;
    while (frstNum >= 10)
    {
        frstNum /= 10; // Calculating the first number
    }

    long scndNum = number;
    while (scndNum >= 100)
    {
        scndNum /= 10; // Calculating the first 2 numbers
    }

    long second = number / 10; //Dividing number by 10 to start on the second to last digit.
    int tms3 = 0;
    for (int i = 1; i <= (l / 2); i++) // This is the function for multiplying by 2 and then adding
    {
        long mods = second % 10;
        second = (second / 100);
        int tms2 = mods * 2;
        if (tms2 >= 10)
        {
            tms2 = ((tms2 / 10) + (tms2 % 10)); // Here if the number has more than 1 digit, it gets divided into it's two digits.
        }
        tms3 += tms2;
    }

    int tms4 = 0;
    for (int i = 0; i <= (l / 2); i++) // Function for getting the sum of the numbers that were not multiplied
    {
        long mods = number % 10;
        number = (number / 100);
        tms4 += mods;
    }

    int verificator = (tms3 + tms4) % 10; //Verifying if the number ends with 0
    if (verificator == 0)
    {
        if ((scndNum == 34 || scndNum == 37) && l == 15)
        {
            printf("AMEX\n");
        }

        else if ((scndNum == 51 || scndNum == 52 || scndNum == 54 || scndNum == 55) && l == 16)
        {
            printf("MASTERCARD\n");
        }

        else if ((l == 13 || l == 16) && frstNum == 4)
        {
            printf("VISA\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}

int numDigits(long x) 
{
    int num = 1;
    while (x >= 10) {
        x /= 10;
        num++;
    }
    return num;
}

int my_floor(double x) 
{
    int result;
    if (x >= 0) {
        result = (int) x;
    } else {
        result = (int) x - 1;
    }
    return result;
}