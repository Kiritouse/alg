
#include <stdio.h>
#include <stdlib.h>

int min_blocks_to_remove(int w, int n, int d, int blocks[]) {
	blocks[0] = 1;
	blocks[n + 1] = w;
	int i = 0, j = 1;
	int min_blocks = n + 2;
	while (j <= n + 1) {
		if (blocks[j] - blocks[i] > d) {
			if (j - i - 1 < min_blocks) {
				min_blocks = j - i - 1;
				if (min_blocks == 0) {
					break;
				}
			}
			i++;
		} else {
			j++;
		}
	}
	return min_blocks == n + 2 ? -1 : min_blocks;
}

int main() {
	int w, n, d;
	int blocks[100007] = {0};
	scanf("%d %d %d", &w, &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &blocks[i]);
	}
	printf("%d\n", min_blocks_to_remove(w, n, d, blocks));
	return 0;
}