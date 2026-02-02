#include "minirt.h"

static bool	in_sphere(t_coords coords, t_scene *scene);
static bool	in_plane(t_coords coords, t_scene *scene);
static bool	in_cylinder(t_coords coords, t_scene *scene);
static bool	in_cylinder_caps(t_coords coords, t_cylinder *cyl, double offset);

bool	in_wall(t_coords coords, t_scene *scene)
{
	return (
		in_cylinder(coords, scene)
		|| in_sphere(coords, scene)
		|| in_plane(coords, scene)
	);
}

static bool	in_sphere(t_coords coords, t_scene *scene)
{
	t_sphere	*sphere;
	double		eq;

	sphere = scene->sphere_list;
	while (sphere)
	{
		eq = fabs(v3_magnitude(v3_substract(coords, sphere->coords)));
		if (fabs(eq - sphere->radius) < EPSILON)
			return (true);
		sphere = sphere->next;
	}
	return (false);
}

static bool	in_plane(t_coords coords, t_scene *scene)
{
	t_plane	*plane;
	double	eq;

	plane = scene->plane_list;
	while (plane)
	{
		eq = v3_dot_product(
				v3_substract(coords, plane->coords), plane->normal);
		if (eq == 0)
			return (true);
		plane = plane->next;
	}
	return (false);
}

static bool	in_cylinder(t_coords coords, t_scene *scene)
{
	t_cylinder	*cylinder;
	double		eq_body_one;
	double		eq_body_two;

	cylinder = scene->cylinder_list;
	while (cylinder)
	{
		eq_body_one = fabs(v3_magnitude(v3_substract(
						v3_substract(coords, cylinder->coords),
						v3_scale(cylinder->axis, v3_dot_product(
								v3_substract(coords, cylinder->coords),
								cylinder->axis)))));
		eq_body_two = v3_dot_product(v3_substract(coords, cylinder->coords),
				cylinder->axis);
		if (fabs(eq_body_one - cylinder->radius) <= EPSILON
			&& eq_body_two <= cylinder->half_height)
			return (true);
		if (in_cylinder_caps(coords, cylinder, cylinder->half_height)
			|| in_cylinder_caps(coords, cylinder, -cylinder->half_height))
			return (true);
		cylinder = cylinder->next;
	}
	return (false);
}

static bool	in_cylinder_caps(t_coords coords, t_cylinder *cyl, double offset)
{
	t_coords	center;
	double		eq_cap_plane;
	double		distance;

	center = ray_at(cyl->coords, cyl->axis, offset);
	eq_cap_plane = v3_dot_product(v3_substract(coords, center), cyl->axis);
	distance = fabs(v3_magnitude(v3_substract(center, coords)));
	if (eq_cap_plane == 0 && distance <= cyl->radius)
		return (true);
	return (false);
}
