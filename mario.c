#include <cs50.h>
#include <stdio.h>
#include <string.h>

string design(int pyr, int ad);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height desired (Between 1 and 8): "); //Prompt the user for height.
    }
    while (height > 8 || height < 1); //Only number between 1 and eight.

    for (int c = 1; c <= height; c++) // Variable c will be the counter for number of rows and will also help in the adjust of character printing iteration.
    {
        design(height, c);
        printf("\n");
    }
}


string design(int pyr, int ad)
{
    // Function for printing less spaces each iteration
    int n = pyr - ad;
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }

    //Function for printing more hashtags each iteration
    int h = pyr - ad;
    do
    {
        printf("#");
        h++;
    }
    while (h < pyr);

    printf("  "); //Adding space between pyramids

    //Function to print right pyramyd
    int hh = pyr - ad;
    do
    {
        printf("#");
        hh++;
    }
    while (hh < pyr);
    return 0;
}