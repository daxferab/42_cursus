#include "minirt.h"

bool	read_color(char **line, t_color *color)
{
	int	red;
	int	green;
	int	blue;

	if (!read_int_maxed(line, &red, INT_MAX_COLOR))
		return (false);
	color->red = red / 255.0;
	if (*(*line)++ != ',')
		return (false);
	if (!read_int_maxed(line, &green, INT_MAX_COLOR))
		return (false);
	color->green = green / 255.0;
	if (*(*line)++ != ',')
		return (false);
	if (!read_int_maxed(line, &blue, INT_MAX_COLOR))
		return (false);
	color->blue = blue / 255.0;
	return (true);
}
