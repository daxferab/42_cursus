#include "minirt.h"

static bool		has_obstacles(t_scene *scene, t_point *point);
static double	add_light(t_point point, t_scene scene);
static void		add_to_color(
					t_point *point, t_color base,
					double light, t_color amb_color);

void	apply_lights(t_point *point, t_scene *scene)
{
	double	total_intensity;
	t_v3	distance;
	t_color	base_color;

	base_color = point->color;
	total_intensity = scene->ambient->ratio;
	distance = v3_substract(scene->light->coords, point->coords);
	point->light_ray = v3_normalize(distance);
	point->light_distance = v3_magnitude(distance);
	point->coords_adjusted = ray_at(point->coords, point->normal, EPSILON);
	if (!has_obstacles(scene, point))
		total_intensity += add_light(*point, *scene);
	if (total_intensity > 1.0)
		total_intensity = 1.0;
	add_to_color(point, base_color, total_intensity, scene->ambient->color);
}

static bool	has_obstacles(t_scene *scene, t_point *point)
{
	return (
		scene->light_in_wall
		|| v3_dot_product(point->normal, point->light_ray) < 0
		|| crash_with_planes(scene, point)
		|| crash_with_spheres(scene, point)
		|| crash_with_cylinders(scene, point)
	);
}

static void	add_to_color(
	t_point *point, t_color base, double light, t_color amb_color)
{
	point->color.red = base.red * light * amb_color.red;
	point->color.green = base.green * light * amb_color.green;
	point->color.blue = base.blue * light * amb_color.blue;
}

static double	add_light(t_point point, t_scene scene)
{
	double	light_intensity;
	double	lambert;
	double	attenuation;

	lambert = v3_dot_product(point.normal, point.light_ray);
	if (lambert > 0)
	{
		attenuation = 1.0 / (1.0 + 0.1 * point.light_distance);
		light_intensity = scene.light->ratio * lambert * attenuation;
		return (light_intensity);
	}
	return (0);
}
