#include "minirt.h"

static void	intersect_objects(t_scene *scene, t_point *point, int i, int j);

void	render(t_scene *scene)
{
	double	i;
	double	j;
	t_point	point;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			point.color = scene->background_color;
			if (!scene->camera_in_wall
				&& scene->camera->fov > 0 && scene->camera->fov < 180)
			{
				intersect_objects(scene, &point, i, j);
				if (point.closest >= 0)
					apply_lights(&point, scene);
			}
			mlx_put_pixel(scene->img, i, j, rgb_to_uint(&point.color));
			j++;
		}
		i++;
	}
	if (mlx_image_to_window(scene->mlx, scene->img, 0, 0) == -1)
		free_exit(scene, ERR_MLX_PRINT);
}

static void	intersect_objects(t_scene *scene, t_point *point, int i, int j)
{
	point->closest = -1;
	point->cam_ray = get_ray_direction(scene, i, j);
	intersect_planes(scene, point);
	intersect_spheres(scene, point);
	intersect_cylinders(scene, point);
}
