
#include "minirt.h"

static int	array_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int			parse_color(char *line, t_scene *scene)
{
	int		r;
	int		g;
	int		b;
	char	**col;
	int		size;

	size = 0;
	if (!(col = ft_split(line, ',')))
		ft_error("memory error", scene);
	if (((size = array_size(col)) < 3) || !col[0] || !col[1] || !col[2])
	{
		freearr(col, size);
		ft_error("invalid color", scene);
	}
	r = ft_atoi(col[0]);
	g = ft_atoi(col[1]);
	b = ft_atoi(col[2]);
	freearr(col, size);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_error("invalid color", scene);
	return (trgb(0, r, g, b));
}

t_vec		parse_coord(char *line, int nov, t_scene *scene)
{
	t_vec	vec;
	char	**coord;
	int		size;

	size = 0;
	if (!(coord = ft_split(line, ',')))
		ft_error("memory error", scene);
	if (((size = array_size(coord)) < 3) || !coord[0] || !coord[1] || !coord[2])
	{
		freearr(coord, size);
		ft_error("invalid coordinates", scene);
	}
	vec.x = ft_atof(coord[0]);
	vec.y = ft_atof(coord[1]);
	vec.z = ft_atof(coord[2]);
	freearr(coord, size);
	if (nov && !is_norm(vec))
	{
		vec = vec_norm(&vec);
		if (!vec_mscal(vec, vec))
			ft_error("invalid normalized orientation vector", scene);
	}
	return (vec);
}

int			parsing_skip(char *line, t_scene *scene)
{
	int i;

	i = 0;
	while (ft_isspace(*(line + i)) || *(line + i) == '+' || *(line + i) == '-')
		i++;
	if (!((*(line + i) >= '0' && *(line + i) <= '9') || *(line + i) == '.'))
		ft_error("invalid number", scene);
	while ((*(line + i) >= '0' && *(line + i) <= '9') || *(line + i) == '.')
		i++;
	if (*(line + i) == ',')
		i++;
	return (i);
}

int			parsing_vskip(char *line, t_scene *scene)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (k < 3)
	{
		i += parsing_skip(line + i, scene);
		k++;
	}
	return (i);
}
