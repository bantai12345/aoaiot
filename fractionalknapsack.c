#include <stdio.h>
#include <stdlib.h>
struct Item {
    int weight;
    int profit;
    float ratio;
};
int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item2->ratio - item1->ratio > 0) ? 1 : -1;
}
void fractionalKnapsack(int W, struct Item items[], int n) {
    qsort(items, n, sizeof(items[0]), compare);
    int currentWeight = 0, i;
    float finalProfit = 0.0;
    printf("Object\tWeight\tProfit\tRatio\tKnapsack\tFraction\n");
    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            finalProfit += items[i].profit;
            printf("%d\t%d\t%d\t%.2f\t%d\t\t100%%\n", i + 1, items[i].weight, items[i].profit, items[i].ratio, W - currentWeight);
        } else {
            int remainingWeight = W - currentWeight;
            float fraction = (float)remainingWeight / items[i].weight;
            finalProfit += items[i].profit * fraction;
            printf("%d\t%d\t%d\t%.2f\t%d\t\t%.2f%%\n", i + 1, items[i].weight, items[i].profit, items[i].ratio, W - currentWeight, fraction * 100);
            break;
        }
    }
    printf("\nTotal profit in knapsack: %.2f\n", finalProfit);
}
int main() {
    int n, W, i;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    struct Item items[n];
    printf("Enter the weight of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the weight and profit of each object:\n");
    for (i = 0; i < n; i++) {
        printf("Enter weight of object %d: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Enter profit of object %d: ", i + 1);
        scanf("%d", &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }
    fractionalKnapsack(W, items, n);
    return 0;
}

