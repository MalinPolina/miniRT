
#include "minirt.h"

double	vec_mscal(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_mvec(t_vec v1, t_vec v2)
{
	t_vec v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

t_vec	vec_norm(t_vec *v)
{
	double	s;
	t_vec	nv;

	s = sqrt(vec_mscal(*v, *v));
	nv = vec_ndiv(*v, s);
	return (nv);
}

int		is_norm(t_vec v)
{
	t_vec	norm;

	if (v.x == 0 && v.y == 0 && v.z == 0)
		return (0);
	norm = vec_norm(&v);
	if (norm.x == v.x && norm.y == v.y && norm.z == v.z)
		return (1);
	return (0);
}
