
#include "minirt.h"

void	parse_line(char *line, t_scene *scene)
{
	while (ft_isspace(*line))
		line++;
	if (*line)
	{
		if (*line == 'R' && ft_isspace(*(line + 1)))
			parse_resolution(line + 1, scene);
		else if (*line == 'A' && ft_isspace(*(line + 1)))
			parse_ambience(line + 1, scene);
		else if (*line == 'c' && *(line + 1) == 'y')
			parse_cylinder(line + 2, scene);
		else if (*line == 'c' && ft_isspace(*(line + 1)))
			parse_camera(line + 1, scene);
		else if (*line == 'l' && ft_isspace(*(line + 1)))
			parse_light(line + 1, scene);
		else if (*line == 's' && *(line + 1) == 'p')
			parse_sphere(line + 2, scene);
		else if (*line == 's' && *(line + 1) == 'q')
			parse_square(line + 2, scene);
		else if (*line == 'p' && *(line + 1) == 'l')
			parse_plane(line + 2, scene);
		else if (*line == 't' && *(line + 1) == 'r')
			parse_triangle(line + 2, scene);
		else
			ft_error("invalid file", scene);
	}
}

void	parse_scene(const char *file, t_scene *scene)
{
	int		fd;
	int		gnl;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error("cannot open file", scene);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		parse_line(line, scene);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	if (gnl < 0)
		ft_error("cannot read from file", scene);
	close(fd);
}
