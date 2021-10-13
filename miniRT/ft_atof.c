
#include "minirt.h"

static float	ft_atof2(char *str, float n)
{
	int i;

	i = 1;
	while (ft_isdigit(*(str + i)))
	{
		n += ((*(str + i) - '0') * 1.0) / (10 * i);
		i++;
	}
	return (n);
}

float			ft_atof(char *str)
{
	float	n;
	int		m;

	m = 0;
	n = ft_atoi(str);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			m = 1;
		str++;
	}
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
		n = ft_atof2(str, n);
	if (n > 0 && m)
		n *= -1;
	return (n);
}
