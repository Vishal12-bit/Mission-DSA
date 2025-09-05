


#include <stdlib.h>

/* LeetCode signature:
 * int* heights, int heightsSize
 */
int largestRectangleArea(int* heights, int heightsSize) {
    if (heightsSize == 0) return 0;

    int n = heightsSize;
    int *stack = (int*)malloc(sizeof(int) * (n + 1));
    int top = -1;
    long long maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int cur = (i == n) ? 0 : heights[i];

        while (top != -1 && cur < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : (i - stack[top] - 1);
            long long area = (long long)height * width;
            if (area > maxArea) maxArea = area;
        }

        stack[++top] = i;
    }

    free(stack);
    return (int)maxArea;
}
