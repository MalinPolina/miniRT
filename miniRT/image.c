
#include "minirt.h"

static void	find_intersection(t_solution *save,
			t_vec ray, t_camera *cam, t_scene *scene)
{
	double		inter;
	t_object	*obj;
	t_list		*place;

	place = scene->obj;
	while (place)
	{
		inter = 0;
		obj = place->content;
		if (obj->intersect(obj->data, cam->view_point, ray, &inter))
		{
			if (save->inter > inter || !save->inter)
			{
				save->vinter = vec_add(cam->view_point,
										vec_nmult(ray, inter));
				save->norm = obj->get_normal_vector(obj->data,
									cam->view_point, save->vinter, inter);
				save->color = light_start(scene, &save->vinter,
									&save->norm, obj->get_color(obj->data));
				save->inter = inter;
			}
		}
		place = place->next;
	}
}

void		create_image(t_scene *scene, t_camera *cam)
{
	t_solution	save;
	int			i;
	int			j;
	t_vec		ray;

	i = 0;
	while (i < scene->res.x)
	{
		j = 0;
		while (j < scene->res.y)
		{
			ft_memset(&save, 0, sizeof(save));
			ray = vec_add(cam->lower_left,
						vec_add(vec_nmult(cam->horizontal, i),
						vec_nmult(cam->vertical, j)));
			find_intersection(&save, ray, cam, scene);
			cust_mlx_pixel_put(&scene->img, i, j, save.color);
			j++;
		}
		i++;
	}
}

void		start_image(t_scene *scene)
{
	t_camera	*cam;

	printf("Starting\n");
	cam = scene->cam->content;
	select_cam(scene, &cam);
	create_image(scene, cam);
	mlx_put_image_to_window(scene->mlx_ptr, scene->win_ptr,
							scene->img.img, 0, 0);
	printf("Ready\n");
}
