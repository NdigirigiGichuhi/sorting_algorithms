#include "sort.h"


void bubble_sort(int *array, size_t size)
{
    /* {23, 45, 6, 8, 14, 86}*/
    size_t i, j, temp, flag;

    for (i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (j = 0; j < size-1-i; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag =1;
                print_array(array,size);
            }
        }
        if (flag == 0)
            break;
    }
}
