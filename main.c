/**
 *  Troy Jones
 *
 *  Purpose:
 *      - Add two random matrices together and print out the time it takes to
 *          do so.
 *
 *  Requirements:
 *      + use c99
 *      + add 2 matrices that are 10,000 x 10,000
 *      + cmd arg : 'n' which will be the number of rows
 *      + use scanf to determine whether the array will be dynamic or automatic
 *      + randomly populate arrays A & B
 *      - printf timing results of sum
 *
 *  References:
 *      - https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
**/

#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "sys/resource.h"

/*******************************************************************************
 *  FUNCTIONS
 ******************************************************************************/
/**
 *  @brief: Prompts user to see what memory type to use to allocate array
 *           memory.
 *  @return: Returns true if user selects dynamic memory, false for automatic
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
 *  @brief:     Creates 2D array with malloc and populates it with random
 *                   numbers below 100.
 *  @return:    Returns pointer to array.
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
 *  @brief:  Adds numbers at corresponding locations in 2D arrays 'A' and
 *  'B', stores result in new 2D array 'result'.
 *
 *  @return:  Returns pointer to array.
 */
int* add_arrays(int* array_A, int* array_B, int grid_size)
{
    int* result = create_array(grid_size);

    for (int row = 0; row < grid_size; row++)
    {
        for (int col = 0; col < grid_size; col++)
        {
            *(result + row * grid_size + col) =
                    *(array_A + row * grid_size + col) +
                    *(array_A + row * grid_size + col);
        }
    }

    return result;
}


/**
 * @brief: Using dynamic memory, creates 2D arrays, calls function to
 * add them together.
 *
 */
void dynamic_stuff(int grid_size)
{
    int *array_A = create_array(grid_size);
    int *array_B = create_array(grid_size);

    int *array_C = add_arrays(array_A, array_B, grid_size);

    free(array_A);
    free(array_B);
    free(array_C);
}


/**
 * @brief: Using automatic memory, creates 2D arrays, adds them together,
 * stores results in third 2D array.
 *
 */
void auto_stuff(int grid_size)
{
  int n = grid_size;
  srand(time(NULL));

  // create three 2D arrays
  int A_grid[n][n];
  int B_grid[n][n];
  int C_grid[n][n];

  // Iterate through 2D arrays, assign random values for each,
  // add numbers at corresponding locations, store result in
  // third 2D array.
  for (int row = 0; row < n; row++)
  {
    for (int col = 0; col < n; col++)
    {
      A_grid[row][col] = rand() % 100;
      B_grid[row][col] = rand() % 100;
      C_grid[row][col] = (A_grid[row][col] + B_grid[row][col]);
    }
  }
}


/*
 * @brief:  Prints timing results of program.
 *
 */
void print_time()
{
    struct rusage usage;

    if (getrusage(RUSAGE_SELF, &usage))
    {
        printf("getrusage no worky\n");
    }
    else
    {
        printf("User CPU time: %li.%li\n", usage.ru_utime.tv_sec,
                usage.ru_utime.tv_usec);
        printf("System CPU time: %li.%li\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("Max resident set size: %li\n", usage.ru_maxrss);
    }
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
    print_time();

    return 0;
}
