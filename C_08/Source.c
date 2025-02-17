#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    char Brand[20];
    int year;
    float engine_volume;
};

int compareByYear(const void *a, const void *b) 
{
    const struct Car *cars1 = (const struct Car *)a;
    const struct Car *cars2 = (const struct Car *)b;

    if (cars1->year > cars2->year) return 1;   
    if (cars1->year < cars2->year) return -1;  
    return 0;  
}


void fast_print(const struct Car* s, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Brand %s\t Year: %d\tEngiine volume: %.2f\n", s[i].Brand, s[i].year, s[i].engine_volume);
    }
}

int main()
{
    int size = 5; //size of array

    struct Car* cars = malloc(sizeof(struct Car) * size); //Dynamic array type Car

    if (!cars) //Error malloc() memmory
    {
        printf("Error memory is not");
        return 1;
    }

    for (int i = 0; i < size; i++) //Enter data
    {
        printf("\nCar %d\n\n", i+1);

        printf("Enter Brand:");
        scanf_s("%s", cars[i].Brand, (uintptr_t)_countof(cars[i].Brand));

        printf("Enter year:");
        scanf_s("%d", &cars[i].year);

        printf("Enter engine volume:");
        scanf_s("%f", &cars[i].engine_volume);
    }

    printf("\nBefore qsort:\n");
    fast_print(cars, size);

    qsort(cars, size, sizeof(struct Car),compareByYear); //sort

    printf("\nAfter qsort:\n");
    fast_print(cars, size);
    
    free(cars);
}
