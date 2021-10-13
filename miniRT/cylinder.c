
#include "minirt.h"

int				get_cylinder_color(void *data)
{
	t_cylinder *cylinder;

	cylinder = data;
	return (cylinder->col);
}

static int		height_check(t_cylinder *cylinder, t_vec ray_start,
				t_vec ray, double intersection)
{
	t_vec	inter;
	t_vec	hvec;
	t_vec	norm;

	norm = cylinder->nov;
	inter = vec_add(ray_start, vec_nmult(ray, intersection));
	if (vec_mscal(norm, vec_sub(inter, cylinder->coord)) < 0)
		norm = vec_nmult(norm, -1);
	hvec = vec_add(cylinder->coord, vec_nmult(norm, cylinder->height / 2));
	if (vec_mscal(norm, vec_sub(inter, hvec)) < 0)
		return (1);
	return (0);
}

t_vec			get_cylinder_normal_vector(void *data, t_vec ray_start,
				t_vec ray, double intersection)
{
	t_vec		nvec;
	t_vec		topoint;
	t_vec		inter;
	t_cylinder	*cylinder;

	cylinder = data;
	inter = vec_add(ray_start, vec_nmult(ray, intersection));
	topoint = vec_sub(inter, cylinder->coord);
	nvec = vec_sub(topoint, vec_nmult(cylinder->nov,
			vec_mscal(topoint, cylinder->nov)));
	nvec = vec_norm(&nvec);
	if (vec_mscal(ray, nvec) > 0)
		nvec = vec_nmult(nvec, -1);
	return (nvec);
}

int				intersect_cylinder(void *data, t_vec ray_start,
				t_vec ray, double *intersection)
{
	t_vec		tmp;
	double		a;
	double		b;
	double		c;
	t_cylinder	*cylinder;

	cylinder = data;
	tmp = vec_mvec(vec_sub(ray_start, cylinder->coord), cylinder->nov);
	a = vec_mscal(vec_mvec(ray, cylinder->nov), vec_mvec(ray, cylinder->nov));
	b = vec_mscal(tmp, vec_mvec(ray, cylinder->nov));
	c = vec_mscal(tmp, tmp) - pow(cylinder->diam / 2, 2);
	c = b * b - a * c;
	if (c < 0)
		return (0);
	if ((*intersection = (-b - sqrt(c)) / a) > 1e-12)
		if (height_check(cylinder, ray_start, ray, *intersection))
			return (1);
	if ((*intersection = (-b + sqrt(c)) / a) > 1e-12)
		if (height_check(cylinder, ray_start, ray, *intersection))
			return (1);
	return (0);
}

void			free_cylinder_data(void *data)
{
	t_cylinder *cylinder;

	cylinder = data;
	free(cylinder);
}
