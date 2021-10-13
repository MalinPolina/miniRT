
#include "minirt.h"

static void	create_window(t_scene *scene)
{
	scene->win_ptr = mlx_new_window(scene->mlx_ptr, scene->res.x,
									scene->res.y, "miniRT");
	start_image(scene);
	mlx_hook(scene->win_ptr, 17, 0, hook_close, scene);
	mlx_key_hook(scene->win_ptr, key_hook, scene);
	mlx_loop(scene->mlx_ptr);
}

static void	start_minirt(t_scene *scene)
{
	t_camera	*cam;

	add_rays(scene);
	if (!(scene->mlx_ptr = mlx_init()))
		ft_error("unable to set up connection to graphical system", scene);
	scene->img.img = mlx_new_image(scene->mlx_ptr, scene->res.x, scene->res.y);
	scene->img.addr = mlx_get_data_addr(scene->img.img,
					&scene->img.bits_per_pixel, &scene->img.line_length,
					&scene->img.endian);
	if (scene->save)
	{
		cam = scene->cam->content;
		create_bmp(scene, cam);
		free_scene(scene);
		exit(0);
	}
	create_window(scene);
}

int			main(int argc, char **argv)
{
	t_scene scene;

	ft_memset(&scene, 0, sizeof(scene));
	if (argc > 3 || argc < 2 ||
		(argc == 3 && ft_strncmp(argv[2], "--save", 6) != 0))
		ft_error("wrong arguments", &scene);
	if (!ft_strncmp(argv[1] + (ft_strlen(argv[1] - 3)), ".rt", 3))
		ft_error("wrong scene description file format", &scene);
	if (argc == 3)
		scene.save = 1;
	if (!(scene.mlx_ptr = mlx_init()))
		ft_error("unable to set up connection to graphical system", &scene);
	parse_scene(argv[1], &scene);
	if (!scene.res_full)
	{
		scene.res.x = 1280;
		scene.res.y = 800;
	}
	start_minirt(&scene);
	return (0);
}
