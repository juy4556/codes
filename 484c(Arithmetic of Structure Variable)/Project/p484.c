#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
}Point;
void SwapPoint(Point *ppos1, Point *ppos2) {
	int temp1,temp2;
	temp1 = ppos1->xpos;
	ppos1->xpos = ppos2->xpos;
	ppos2->xpos = temp1;
	temp2 = ppos1->ypos;
	ppos1->ypos = ppos2->ypos;
	ppos2->ypos = temp2;
}
void ShowPoint(Point pos) {
	printf("[%d, %d]\n", pos.xpos, pos.ypos);
}
int main() {
	Point pos1 = { 2,4 };
	Point pos2 = { 5,7 };
	SwapPoint(&pos1, &pos2);
	ShowPoint(pos1);
	ShowPoint(pos2);
	return 0;
}