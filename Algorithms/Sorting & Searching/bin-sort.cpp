/*
    Author :- katsuNakajima
    Reference :- https://en.wikipedia.org/wiki/Bucket_sort
*/
#include <stdio.h>
#define M 10 /* Maximum of data range */

/**
 * numbers[] Array to be sorted
 * number_of_item
 * Number of data to be sorted; the number of data to be sorted in numbers.
 */
void bucket_sort(int numbers[], int number_of_item) {
    int buckets[M];
    int i;

    /* prepare buckets */
    for (i = 0; i < M; i++) {
        buckets[i] = 0;
    }
    /* putting in bucket */
    for (i = 0; i < number_of_item; i++) {
        buckets[numbers[i]] = numbers[i];
    }
    /* back into the original array */
    int j = 0;
    for (i = 0; i < M; i++) {
        if (0 < buckets[i]) {
            numbers[j++] = buckets[i];
        }
    }
}

void print_data(int numbers[]) {
    int i;
    for (i = 0; i < M; i++) {
        if (numbers[i] == 0) {
            continue;
        }
        printf("[%d] %d\n", i, numbers[i]);
    }
}

int main() {
    int numbers[M] = {7, 5, 4, 3, 2, 1};

    printf("unsorted\n");
    print_data(numbers);
    printf("\n");

    /* bucket sort */
    bucket_sort(numbers, 6);

    printf("sorted\n");
    print_data(numbers);
    printf("\n");

    return 0;
}
