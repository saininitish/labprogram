#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit;
    int weight;
    double valuePerWeight;
} Item;

int compareItems(const void *a, const void *b) {
    double ratioA = ((Item *)a)->valuePerWeight;
    double ratioB = ((Item *)b)->valuePerWeight;
    return (ratioB > ratioA) ? 1 : -1;
}

double fractionalKnapsack(int capacity, Item items[], int numItems) {
    qsort(items, numItems, sizeof(Item), compareItems);

    double totalValue = 0.0;

    for (int i = 0; i < numItems; i++) {
        if (capacity == 0) {
            break;
        }

        if (items[i].weight <= capacity) {
            totalValue += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalValue += (double)capacity / items[i].weight * items[i].profit;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    int numItems = 5;
    Item items[] = {
        {20, 5, 0.0},
        {30, 8, 0.0},
        {40, 10, 0.0},
        {32, 12, 0.0},
        {55, 15, 0.0}
    };

    int capacity = 20;

    double optimalValue = fractionalKnapsack(capacity, items, numItems);

    printf("Optimal value for the Knapsack problem: %.2f\n", optimalValue);

    return 0;
}
