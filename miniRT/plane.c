
#include "minirt.h"

int		get_plane_color(void *data)
{
	t_plane	*plane;

	plane = data;
	return (plane->col);
}

t_vec	get_plane_normal_vector(void *data, t_vec ray_start,
t_vec ray, double intersection)
{
	t_vec	norm;
	t_plane	*plane;

	plane = data;
	(void)ray_start;
	(void)intersection;
	norm = plane->nov;
	if (vec_mscal(ray, plane->nov) > 0)
		norm = vec_nmult(norm, -1);
	return (norm);
}

int		intersect_plane(void *data, t_vec ray_start,
t_vec ray, double *intersection)
{
	double	par;
	t_plane	*plane;

	plane = data;
	par = vec_mscal(ray, plane->nov);
	if (par)
	{
		*intersection = vec_mscal(plane->nov,
				vec_sub(plane->coord, ray_start)) / par;
		if (*intersection > 0)
			return (1);
	}
	return (0);
}

void	free_plane_data(void *data)
{
	t_plane	*plane;

	plane = data;
	free(plane);
}
