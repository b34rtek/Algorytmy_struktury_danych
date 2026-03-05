#include <stdio.h>
#include "SparseTable.h"

int main() {
	int amount;
	int minVal, maxVal;
	int n, k;
	scanf_s("%d", &amount);
	scanf_s("%d %d", &minVal, &maxVal);
	scanf_s("%d %d", &n, &k);

	if (maxVal > INT_MAX && minVal < INT_MIN) return 111;

	SparseTable table(n, k);

	for (int z = 0; z < amount; z++) {
		char command;
		int value;

		scanf_s(" %c", &command);

		switch (command) {

		case 'I':
			scanf_s("%d", &value);
			table.insert(value);
			break;
		case 'L':
			scanf_s("%d", &value);
			table.lookup(value);
			break;
		case 'D':
			scanf_s("%d", &value);
			table.deletion(value);
			break;
		case 'P':
			table.print();
			break;
		}
	}
	return 0;
}