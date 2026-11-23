# CE101 – LeetCode 121: Best Time to Buy and Sell Stock

Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## Files
- `original.c` – starter version, O(n^2) time, O(n) auxiliary space (VLA)
- `optimized_time.c` – single pass with running minimum, O(n) time, O(1) space
- `optimized_space.c` – same O(1)-space algorithm (already minimal extra space)
- `report.pdf` – written report (Q1–Q5, traces, AI disclosure)
- `screenshots/` – `test_original.png`, `extra_tests.png`

## Compile and run
```
gcc -std=c99 -Wall -Wextra original.c -o original && ./original
gcc -std=c99 -Wall -Wextra optimized_time.c -o optimized_time && ./optimized_time
gcc -std=c99 -Wall -Wextra optimized_space.c -o optimized_space && ./optimized_space
```
(Windows: run `original.exe` etc.)

## Tests
Starter: {7,1,5,3,6,4} -> 5, {7,6,4,3,1} -> 0.
Extra: {5} -> 0, {1,2} -> 1, {2,4,1} -> 2, {3,3,3,3} -> 0.
