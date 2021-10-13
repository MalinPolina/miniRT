
#include "minirt.h"

t_vec	vec_init(double x, double y, double z)
{
	t_vec v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	t_vec v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}

t_vec	vec_nmult(t_vec v1, double a)
{
	t_vec v;

	v.x = v1.x * a;
	v.y = v1.y * a;
	v.z = v1.z * a;
	return (v);
}

t_vec	vec_ndiv(t_vec v1, double a)
{
	t_vec v;

	if (!a)
		return (vec_init(0, 0, 0));
	v.x = v1.x / a;
	v.y = v1.y / a;
	v.z = v1.z / a;
	return (v);
}
