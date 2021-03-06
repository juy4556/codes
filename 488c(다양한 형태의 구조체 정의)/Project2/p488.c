#include <stdio.h>
typedef struct point {
	int xpos;
	int ypos;
}Point;
typedef struct rectangle{
	Point pos1;
	Point pos2;
}Rectangle;
int AreaOfRectangle(Rectangle rec) {
	int width, height;
	width = (rec.pos2.xpos) - (rec.pos1.xpos);
	height = (rec.pos2.ypos) - (rec.pos1.ypos);
	return width * height;
}
void FourPointOfRectangle(Rectangle rec) {
	printf("[%d, %d]\n",rec.pos1.xpos,rec.pos1.ypos );
	printf("[%d, %d]\n", rec.pos1.xpos, rec.pos2.ypos);
	printf("[%d, %d]\n", rec.pos2.xpos, rec.pos1.ypos);
	printf("[%d, %d]\n", rec.pos2.xpos, rec.pos2.ypos);
}
int main() {
	Rectangle rec = { 0,0,100,100 };
	FourPointOfRectangle(rec);
	printf("직사각형의 넓이: %d", AreaOfRectangle(rec));

	return 0;
}