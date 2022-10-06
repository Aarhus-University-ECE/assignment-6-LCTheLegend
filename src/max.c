#include <stdio.h>
#include <assert.h>

int max(int* numbers, int size)
{
    // Excercise 2
    assert(size > 0);
    int max = 0;

    for(int i = 0 ; i < size - 1 ; i++)
    {
        if(numbers[i] > max)
            max = numbers[i];
    }
    return max;
}
