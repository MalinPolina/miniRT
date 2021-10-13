
#include "minirt.h"

int		get_square_color(void *data)
{
	t_square *square;

	square = data;
	return (square->col);
}

t_vec	get_square_normal_vector(void *data, t_vec ray_start,
		t_vec ray, double intersection)
{
	t_vec		norm;
	t_square	*square;

	square = data;
	(void)ray_start;
	(void)intersection;
	norm = square->nov;
	if (vec_mscal(ray, square->nov) > 0)
		norm = vec_nmult(norm, -1);
	return (norm);
}

int		intersect_square(void *data, t_vec ray_start,
		t_vec ray, double *intersection)
{
	t_plane		plane;
	t_vec		vint;
	t_square	*square;

	square = data;
	plane.nov = square->nov;
	plane.coord = square->center;
	if (intersect_plane(&plane, ray_start, ray, intersection))
	{
		vint = vec_add(ray_start, vec_nmult(ray, *intersection));
		if (fabs(square->center.x - vint.x) <= (square->side / 2) &&
			fabs(square->center.y - vint.y) <= (square->side / 2) &&
			fabs(square->center.z - vint.z) <= (square->side / 2))
			return (1);
	}
	return (0);
}

void	free_square_data(void *data)
{
	t_square *square;

	square = data;
	free(square);
}
