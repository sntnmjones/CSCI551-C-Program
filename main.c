/**
 *  Troy Jones
 *
 *  Purpose:
 *      - Add two random matrices together and print out the time it takes to
 *          do so.
 *
 *  Requirements:
 *      + use c99
 *      - add 2 matrices that are 10,000 x 10,000
 *      + cmd arg : 'n' which will be the number of rows
 *      + use scanf to determine whether the array will be dynamic or automatic
 *      - randomly populate arrays A & B
 *      - printf timing results of sum
 *
 *  References:
 *      - https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
**/

#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

/*******************************************************************************
 *  FUNCTIONS
 ******************************************************************************/
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


/**
 *
 */
int* create_array(int grid_size)
{
    int *array = malloc(grid_size * grid_size * sizeof(int));
    srand(time(NULL));

    for (int row = 0; row < grid_size; row++)
    {
        for (int col = 0; col < grid_size; col++)
        {
            *(array + row * grid_size + col) = rand() % 100;
        }
    }

    return array;
}


/**
 *
 */
void dynamic_stuff(int grid_size)
{
    int *array_A = create_array(grid_size);
    int *array_B = create_array(grid_size);


    free(array_A);
    free(array_B);
}


/**
 *
 */
void auto_stuff(int grid_size)
{
    printf("Auto stuff not complete.\n");
}


/*******************************************************************************
 *  MAIN
 ******************************************************************************/
int main(int argc, char const *argv[])
{
    int grid_size = atoi(argv[1]);

    if (is_dynamic())
    {
        dynamic_stuff(grid_size);
    }
    else
    {
        auto_stuff(grid_size);
    }

    return 0;
}
