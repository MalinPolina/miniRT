
#include "minirt.h"

int		get_sphere_color(void *data)
{
	t_sphere *sphere;

	sphere = data;
	return (sphere->col);
}

t_vec	get_sphere_normal_vector(void *data, t_vec ray_start,
		t_vec ray, double intersection)
{
	t_vec		nvec;
	t_vec		vint;
	t_sphere	*sphere;

	sphere = data;
	vint = vec_add(ray_start, vec_nmult(vec_norm(&ray), intersection));
	nvec = vec_sub(vint, sphere->center);
	nvec = vec_norm(&nvec);
	if (vec_mscal(nvec, ray) > 0)
		nvec = vec_nmult(nvec, -1);
	return (nvec);
}

int		intersect_sphere(void *data, t_vec ray_start,
		t_vec ray, double *intersection)
{
	t_vec		tocent;
	double		a;
	double		b;
	double		c;
	t_sphere	*sphere;

	sphere = data;
	tocent = vec_sub(ray_start, sphere->center);
	a = vec_mscal(ray, ray);
	b = vec_mscal(tocent, ray);
	c = vec_mscal(tocent, tocent) - pow(sphere->diam / 2, 2);
	c = b * b - a * c;
	if (c < 0)
		return (0);
	if ((*intersection = (-b - sqrt(c)) / a) <= 1e-12)
		if ((*intersection = (-b + sqrt(c)) / a) <= 1e-12)
			return (0);
	return (1);
}

void	free_sphere_data(void *data)
{
	t_sphere *sphere;

	sphere = data;
	free(sphere);
}
