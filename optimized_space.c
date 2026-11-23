#include <stdio.h>

/* LeetCode 121 - space-optimized: O(1) auxiliary space (no array), O(n) time.
 * Idea: while scanning left to right, remember the lowest price seen so far.
 * On each day, the best profit if we sell today is price - lowestSoFar. */
int maxProfit(int *prices, int pricesSize) {
    if (pricesSize < 2) {
        return 0;
    }

    int minPrice = prices[0];   /* cheapest buy price seen so far */
    int maxProfitFound = 0;     /* best profit seen so far (never negative) */

    for (int day = 1; day < pricesSize; day++) {
        int profit = prices[day] - minPrice;   /* sell today, buy at the minimum */
        if (profit > maxProfitFound) {
            maxProfitFound = profit;
        }
        if (prices[day] < minPrice) {
            minPrice = prices[day];            /* update AFTER using it: buy-before-sell is kept */
        }
    }
    return maxProfitFound;
}

static void runTest(const char *name, int *p, int n) {
    printf("%s: %d\n", name, maxProfit(p, n));
}

int main(void) {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int prices2[] = {7, 6, 4, 3, 1};
    int prices3[] = {5};                 /* edge: one price */
    int prices4[] = {2, 4, 1};           /* handout example */
    int prices5[] = {3, 3, 3, 3};        /* edge: equal prices */
    int prices6[] = {1, 2};              /* edge: two prices, profit */

    runTest("Test 1", prices1, (int)(sizeof(prices1) / sizeof(prices1[0])));
    runTest("Test 2", prices2, (int)(sizeof(prices2) / sizeof(prices2[0])));
    runTest("Extra 1 {5}", prices3, 1);
    runTest("Extra 2 {2,4,1}", prices4, 3);
    runTest("Extra 3 {3,3,3,3}", prices5, 4);
    runTest("Extra 4 {1,2}", prices6, 2);
    return 0;
}
