
#include "minirt.h"

void	parse_light(char *line, t_scene *scene)
{
	t_light	*node;
	double	n;

	if (!(node = ft_calloc(1, sizeof(t_light))))
		ft_error("unable to malloc", scene);
	node->light_point = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	n = ft_atof(line);
	if (n < 0 || n > 1)
		ft_error("invalid light brightness ratio", scene);
	node->br = n;
	line += parsing_skip(line, scene);
	node->col = parse_color(line, scene);
	ft_lstadd_back(&scene->light, ft_lstnew(node));
}

void	parse_camera(char *line, t_scene *scene)
{
	t_camera	*node;
	int			n;

	if (!(node = ft_calloc(1, sizeof(t_camera))))
		ft_error("unable to malloc", scene);
	node->view_point = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->nov = parse_coord(line, 1, scene);
	line += parsing_vskip(line, scene);
	n = ft_atoi(line);
	if (n < 0 || n > 180)
		ft_error("invalid horizontal field of view", scene);
	node->hfov = n;
	ft_lstadd_back(&scene->cam, ft_lstnew(node));
}

void	parse_resolution(char *line, t_scene *scene)
{
	int	x;
	int	y;

	if (!scene->res_full)
	{
		scene->res_full = 1;
		if ((scene->res.x = ft_atoi(line)) < 1)
			ft_error("invalid resolution", scene);
		if ((scene->res.y = ft_atoi(line + parsing_skip(line, scene))) < 1)
			ft_error("invalid resolution", scene);
		mlx_get_screen_size(scene->mlx_ptr, &x, &y);
		if (x < scene->res.x)
			scene->res.x = x;
		if (y < scene->res.y)
			scene->res.y = y;
	}
	else
		ft_error("invalid file", scene);
}

void	parse_ambience(char *line, t_scene *scene)
{
	double	l;

	if (!scene->amb_full)
	{
		scene->amb_full += 1;
		l = ft_atof(line);
		if (l >= 0.0 && l <= 1.0)
			scene->amb.light = l;
		else
			ft_error("invalid ambiant lighting", scene);
		scene->amb.col = parse_color(line + parsing_skip(line, scene), scene);
	}
	else
		ft_error("invalid file", scene);
}
