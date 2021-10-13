
#include "minirt.h"

void	parse_sphere(char *line, t_scene *scene)
{
	t_sphere	*node;
	t_object	*obj;

	obj = NULL;
	if (!(node = malloc(sizeof(t_sphere))))
		ft_error("unable to malloc", scene);
	node->center = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->diam = ft_atof(line);
	line += parsing_skip(line, scene);
	node->col = parse_color(line, scene);
	if (!(obj = malloc(sizeof(t_object))))
		ft_error("unable to malloc", scene);
	obj->data = node;
	obj->get_color = get_sphere_color;
	obj->get_normal_vector = get_sphere_normal_vector;
	obj->intersect = intersect_sphere;
	obj->free_data = free_sphere_data;
	ft_lstadd_back(&scene->obj, ft_lstnew(obj));
}

void	parse_plane(char *line, t_scene *scene)
{
	t_plane		*node;
	t_object	*obj;

	obj = NULL;
	if (!(node = malloc(sizeof(t_plane))))
		ft_error("unable to malloc", scene);
	node->coord = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->nov = parse_coord(line, 1, scene);
	line += parsing_vskip(line, scene);
	node->col = parse_color(line, scene);
	if (!(obj = malloc(sizeof(t_object))))
		ft_error("unable to malloc", scene);
	obj->data = node;
	obj->get_color = get_plane_color;
	obj->get_normal_vector = get_plane_normal_vector;
	obj->intersect = intersect_plane;
	obj->free_data = free_plane_data;
	ft_lstadd_back(&scene->obj, ft_lstnew(obj));
}

void	parse_square(char *line, t_scene *scene)
{
	t_square	*node;
	t_object	*obj;

	obj = NULL;
	if (!(node = malloc(sizeof(t_square))))
		ft_error("unable to malloc", scene);
	node->center = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->nov = parse_coord(line, 1, scene);
	line += parsing_vskip(line, scene);
	node->side = ft_atof(line);
	line += parsing_skip(line, scene);
	node->col = parse_color(line, scene);
	if (!(obj = malloc(sizeof(t_object))))
		ft_error("unable to malloc", scene);
	obj->data = node;
	obj->get_color = get_square_color;
	obj->get_normal_vector = get_square_normal_vector;
	obj->intersect = intersect_square;
	obj->free_data = free_square_data;
	ft_lstadd_back(&scene->obj, ft_lstnew(obj));
}

void	parse_cylinder(char *line, t_scene *scene)
{
	t_cylinder	*node;
	t_object	*obj;

	obj = NULL;
	if (!(node = malloc(sizeof(t_cylinder))))
		ft_error("unable to malloc", scene);
	node->coord = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->nov = parse_coord(line, 1, scene);
	line += parsing_vskip(line, scene);
	node->diam = ft_atof(line);
	line += parsing_skip(line, scene);
	node->height = ft_atof(line);
	line += parsing_skip(line, scene);
	node->col = parse_color(line, scene);
	if (!(obj = malloc(sizeof(t_object))))
		ft_error("unable to malloc", scene);
	obj->data = node;
	obj->get_color = get_cylinder_color;
	obj->get_normal_vector = get_cylinder_normal_vector;
	obj->intersect = intersect_cylinder;
	obj->free_data = free_cylinder_data;
	ft_lstadd_back(&scene->obj, ft_lstnew(obj));
}

void	parse_triangle(char *line, t_scene *scene)
{
	t_triangle	*node;
	t_object	*obj;

	obj = NULL;
	if (!(node = malloc(sizeof(t_triangle))))
		ft_error("unable to malloc", scene);
	node->p1 = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->p2 = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->p3 = parse_coord(line, 0, scene);
	line += parsing_vskip(line, scene);
	node->col = parse_color(line, scene);
	if (!(obj = malloc(sizeof(t_object))))
		ft_error("unable to malloc", scene);
	obj->data = node;
	obj->get_color = get_triangle_color;
	obj->get_normal_vector = get_triangle_normal_vector;
	obj->intersect = intersect_triangle;
	obj->free_data = free_triangle_data;
	ft_lstadd_back(&scene->obj, ft_lstnew(obj));
}
