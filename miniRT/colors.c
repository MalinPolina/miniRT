
#include "minirt.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_trans(int col)
{
	return ((col >> 24) & 0xFF);
}

int	ft_red(int col)
{
	return ((col >> 16) & 0xFF);
}

int	ft_green(int col)
{
	return ((col >> 8) & 0xFF);
}

int	ft_blue(int col)
{
	return (col & 0xFF);
}
