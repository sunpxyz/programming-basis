// samp_05_01.cpp
//
// 2018.09.12

#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 10000;
/*
int main() {
	int n, q, x, a[maxn], kase = 0;
	while (scanf("%d%d", &n, &q) == 2 && n) {
		printf("CASE# %d:\n", ++kase);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		while (q--) {
			scanf("%d", &x);
			int p = lower_bound(a, a + n, x) - a;
			if (a[p] == x) {
				printf("%d found at %d\n", x, p + 1);
			} else {
				printf("%d not found\n", x);
			}
		}
	}

	return 0;
}
*/

/*
4 1
2 3 5 1
5

5 2
1 3 3 3 1
2 3
*/