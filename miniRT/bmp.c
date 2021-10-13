
#include "minirt.h"

static void	bmp_header(int size, int width, int height, int fd)
{
	char	header[54];

	ft_memset(header, 0, 54);
	header[0] = 'B';
	header[1] = 'M';
	ft_memcpy(header + 4, &size, 4);
	header[10] = 54;
	header[14] = 40;
	ft_memcpy(header + 18, &width, 4);
	ft_memcpy(header + 22, &height, 4);
	header[26] = 1;
	header[28] = 24;
	write(fd, header, 54);
}

static void	write_bmp(t_scene *scene, int fd, int padding_size)
{
	int		i;
	int		j;
	int		c;
	char	padding[3];

	ft_memset(padding, 0, 3);
	j = scene->res.y - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->res.x)
		{
			c = *(unsigned int *)(scene->img.addr
				+ (scene->img.bits_per_pixel / 8) * i
				+ scene->img.line_length * j);
			write(fd, &c, 3);
			i++;
		}
		if (padding_size)
			write(fd, padding, padding_size);
		j--;
	}
}

void		create_bmp(t_scene *scene, t_camera *cam)
{
	int		fd;
	int		size;
	int		width;
	int		height;
	int		padding_size;

	create_image(scene, cam);
	if ((fd = open("miniRT.bmp", O_WRONLY | O_CREAT
					| O_TRUNC | O_APPEND, 0666)) <= 0)
		ft_error("unable to create bmp file", scene);
	width = scene->res.x;
	height = scene->res.y;
	padding_size = (4 - (width * 3) % 4) % 4;
	size = 54 + (3 * width * padding_size * height);
	bmp_header(size, width, height, fd);
	write_bmp(scene, fd, padding_size);
	close(fd);
}
