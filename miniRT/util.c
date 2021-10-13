
#include "minirt.h"

void	cust_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_error(char *str, t_scene *scene)
{
	printf("Error\n%s\n", str);
	free_scene(scene);
	exit(0);
}

void	free_scene(t_scene *scene)
{
	t_object	*obj;

	if (scene->cam)
		ft_lstclear(&scene->cam, free);
	if (scene->light)
		ft_lstclear(&scene->light, free);
	if (scene->obj)
	{
		obj = scene->obj->content;
		ft_lstclear(&scene->obj, obj->free_data);
	}
}

int		key_hook(int key, t_scene *scene)
{
	if (key == 53)
		hook_close(scene);
	else
	{
		if (key == 124)
			scene->cam_nbr += 1;
		else if (key == 123)
			scene->cam_nbr -= 1;
		else if (key == 126)
			ft_zoom(1, scene);
		else if (key == 125)
			ft_zoom(0, scene);
		start_image(scene);
	}
	return (0);
}

int		hook_close(t_scene *scene)
{
	mlx_destroy_window(scene->mlx_ptr, scene->win_ptr);
	free_scene(scene);
	exit(0);
	return (0);
}
