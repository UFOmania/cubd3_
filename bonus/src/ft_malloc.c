
#include "../../include/parsing_bonus.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef TIME_ALLOCATED
# define TIME_ALLOCATED 0
#endif

void *ft_malloc(size_t __size)
{
	printf("%d \n", TIME_ALLOCATED);
    static int countMalloc = 0;
    void *ptr;

    // If we've reached the limit, simulate malloc failure
    if (countMalloc == TIME_ALLOCATED)
        return NULL;

    // Increase allocation counter
    countMalloc++;

    // Call real malloc — must avoid recursion
    #undef malloc
    ptr = malloc(__size);
     #define malloc(x) ft_malloc(x)

    // Optional: debug log
    if (!ptr)
        fprintf(stderr, "ft_malloc: failed to allocate %zu bytes (call #%d)\n",
                __size, countMalloc);
    else
        fprintf(stderr, "ft_malloc: allocated %zu bytes (call #%d)\n",
                __size, countMalloc);

    return ptr;
}
