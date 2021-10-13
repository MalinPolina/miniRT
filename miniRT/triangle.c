
#include "minirt.h"

int			get_triangle_color(void *data)
{
	t_triangle *triangle;

	triangle = data;
	return (triangle->col);
}

t_vec		get_triangle_normal_vector(void *data, t_vec ray_start,
			t_vec ray, double intersection)
{
	t_vec		nvec;
	t_vec		a;
	t_vec		b;
	t_triangle	*triangle;

	triangle = data;
	(void)ray_start;
	(void)intersection;
	a = vec_sub(triangle->p3, triangle->p2);
	b = vec_sub(triangle->p1, triangle->p2);
	nvec = vec_mvec(a, b);
	nvec = vec_norm(&nvec);
	if (vec_mscal(ray, nvec) > 0)
		nvec = vec_nmult(nvec, -1);
	return (nvec);
}

static int	ft_triangle(t_vec a, t_vec b, t_vec vint)
{
	double	alpha;
	double	beta;

	alpha = (vec_mscal(b, b) * vec_mscal(vint, a) - vec_mscal(a, b)
			* vec_mscal(vint, b)) / (vec_mscal(a, a) * vec_mscal(b, b)
			- pow(vec_mscal(a, b), 2));
	if (alpha >= 0 && alpha <= 1)
	{
		beta = (vec_mscal(vint, b) - alpha * vec_mscal(a, b)) /
				vec_mscal(b, b);
		if (beta >= 0 && beta <= 1)
			if ((alpha + beta) <= 1)
				return (1);
	}
	return (0);
}

int			intersect_triangle(void *data, t_vec ray_start,
			t_vec ray, double *intersection)
{
	t_plane		plane;
	t_vec		a;
	t_vec		b;
	t_vec		vint;
	t_triangle	*triangle;

	triangle = data;
	plane.coord = triangle->p2;
	a = vec_sub(triangle->p3, triangle->p2);
	b = vec_sub(triangle->p1, triangle->p2);
	plane.nov = vec_mvec(a, b);
	if (intersect_plane(&plane, ray_start, ray, intersection))
	{
		vint = vec_add(ray_start, vec_nmult(ray, *intersection));
		if (ft_triangle(a, b, vec_sub(vint, triangle->p2)))
			return (1);
	}
	return (0);
}

void		free_triangle_data(void *data)
{
	t_triangle *triangle;

	triangle = data;
	free(triangle);
}
