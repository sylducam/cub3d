#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *mlx;
	int screen;
	int *width;
	int *height;

	mlx = mlx_init();
	width = malloc(sizeof(int));
	height = malloc(sizeof(int));
	screen = mlx_get_screen_size(mlx, width, height);
	printf("%d\n", screen);
}
