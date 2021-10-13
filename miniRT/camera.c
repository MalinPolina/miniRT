
#include "minirt.h"

void	select_cam(t_scene *scene, t_camera **cam)
{
	t_list	*node;
	int		size;

	node = scene->cam;
	size = ft_lstsize(node);
	if (scene->cam_nbr >= size)
		scene->cam_nbr -= size;
	if (scene->cam_nbr < 0)
		scene->cam_nbr += size;
	size = 0;
	while (size < scene->cam_nbr)
	{
		node = node->next;
		size++;
	}
	*cam = node->content;
}

void	ft_zoom(int z, t_scene *scene)
{
	t_camera	*cam;

	select_cam(scene, &cam);
	if (z)
		cam->view_point = vec_add(cam->view_point, vec_nmult(cam->nov, 5));
	else
		cam->view_point = vec_add(cam->view_point, vec_nmult(cam->nov, -5));
}
