/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:21:14 by dcolucci          #+#    #+#             */
/*   Updated: 2023/06/22 18:32:34 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_program_init(t_program *p)
{
	p->map = 0;
}

int	main(int ac, char **av)
{
	t_program	p;

	if (ac == 2)
	{
		ft_program_init(&p);
		ft_map_checker(&p, av[1]);
		ft_print_mat(p.map, false);
		ft_free_program(&p);
	}
}