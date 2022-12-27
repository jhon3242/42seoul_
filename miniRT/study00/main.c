#include <stdio.h>

int main() 
{
	int i, j;
	double r, g, b;
	int canvas_width = 256;
	int canvas_height = 256;

	// 랜더링
	// P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
	printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
	j = canvas_height;
	while (--j >= 0) {
		i = -1;
		while (++i < canvas_width) {
			r = (double)i / (canvas_width - 1);
			g = (double)j / (canvas_height - 1);
			b = 0.25;
			printf("%d %d %d\n", (int)(255.999* r), (int)(255.999* g), (int)(255.999* b));
		}
	}
}