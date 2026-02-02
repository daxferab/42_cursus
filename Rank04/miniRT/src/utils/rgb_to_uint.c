#include "minirt.h"

uint32_t	rgb_to_uint(t_color *color)
{
	int	red;
	int	green;
	int	blue;

	red = color->red * 255;
	green = color->green * 255;
	blue = color->blue * 255;
	return (red << 24 | green << 16 | blue << 8 | 255);
}
