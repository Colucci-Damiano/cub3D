/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_dda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:16:25 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 15:32:48 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	ft_check_collision(t_program *p)
{
	int		x;
	int		y;
	bool	collision;

	collision = false;
	x = p->ray.map_check.x;
	y = p->ray.map_check.y;
	if (x >= 0 && y >= 0)
	{
		if (ft_in_set(p->map[y][x], "D1LPU"))
		{
			p->ray.collision = p->map[y][x];
			collision = true;
		}
	}
	return (collision);
}

void	ft_update_ray_length(t_program *p, t_rayinfo *ray)
{
	if (ray->length1d.x < ray->length1d.y)
	{
		p->ray.side = 0;
		ray->map_check.x += ray->step.x;
		ray->real_distance = ray->length1d.x;
		ray->length1d.x += ray->scaling_factor.x;
	}
	else
	{
		p->ray.side = 1;
		ray->map_check.y += ray->step.y;
		ray->real_distance = ray->length1d.y;
		ray->length1d.y += ray->scaling_factor.y;
	}
}

void	ft_loop_collision(t_program *p)
{
	double		dist_max;
	t_rayinfo	*ray;

	ray = &p->ray;
	ray->real_distance = 0;
	ray->side = 0;
	dist_max = 100;
	while (ray->real_distance < dist_max)
	{
		ft_update_ray_length(p, ray);
		if (ft_check_collision(p))
			break ;
	}
	if (p->ray.side == 0)
		ray->perp_distance = fabs((ray->map_check.x - ray->ray_start.x + \
		(1 - ray->step.x) / 2) / ray->ray_dir.x);
	else
		ray->perp_distance = fabs((ray->map_check.y - ray->ray_start.y + \
		(1 - ray->step.y) / 2) / ray->ray_dir.y);
}

void	ft_ray_casting(t_program *p)
{
	int			pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		ft_init_ray(p, pixel);
		ft_loop_collision(p);
		ft_draw_texture(p, pixel);
		ft_background(p, pixel);
		pixel++;
	}
}
