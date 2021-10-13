
#include "minirt.h"

void	add_rays(t_scene *scene)
{
	t_list *node;

	node = scene->cam;
	while (node)
	{
		ray_to_pixel(node->content, scene->res.x, scene->res.y);
		node = node->next;
	}
}

void	ray_to_pixel(t_camera *cam, int k, int m)
{
	double	half_height;
	double	half_width;
	t_vec	vn;
	t_vec	bn;

	if (!cam->hfov)
		cam->hfov = 135;
	half_width = tan((cam->hfov * (M_PI / 180.0)) / 2);
	half_height = half_width * (m - 1) / (k - 1);
	vn = vec_init(0, 1, 0);
	bn = vec_mvec(vn, cam->nov);
	if (!vec_mscal(bn, bn))
	{
		vn = vec_init(1, 0, 0);
		bn = vec_mvec(vn, cam->nov);
		cam->lower_left.z = cam->nov.z - half_width * cam->nov.y;
		cam->lower_left.x = cam->nov.x - half_height;
		cam->lower_left.y = cam->nov.y + half_width * cam->nov.z;
	}
	else
		cam->lower_left = vec_init(cam->nov.x - half_width * cam->nov.z,
				cam->nov.y - half_height,
				cam->nov.z + half_width * cam->nov.x);
	cam->horizontal = vec_nmult(bn, 2 * half_width / (k - 1));
	cam->vertical = vec_nmult(vn, 2 * half_height / (m - 1));
}
