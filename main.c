/**
 *  Troy Jones
 *
 *  Purpose:
 *      - Add two random matrices together and print out the time it takes to
 *          do so.
 *
 *  Requirements:
 *      - use c99
 *      - add 2 matrices that are 10,000 x 10,000
 *      - cmd arg : 'n' which will be the number of rows
 *      - use scanf to determine whether the array will be dynamic or automatic
 *      - randomly populate arrays A & B
 *      - printf timing results of sum
**/

#include "stdio.h"
#include "stdbool.h"

/**
 *  @brief: Prompts user to see what memory type to use to allocate array
 *           memory.
 */
bool is_dynamic()
{
    int user_selection = 0;
    bool dynamic = true;

    printf("Enter '0' for dynamic, '1' for automatic.\n");
    scanf("%i", &user_selection);

    if (user_selection)
    {
        dynamic = false;
    }

    return dynamic;
}

int main(int argc, char const *argv[])
{
    if (is_dynamic())
    {
        printf("dynamic\n");
    }
    else
    {
        printf("auto\n");
    }

    return 0;
}
