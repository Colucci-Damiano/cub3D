/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcolucci <dcolucci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:43:18 by dcolucci          #+#    #+#             */
/*   Updated: 2023/07/11 17:43:40 by dcolucci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_putstrerr(char *s)
{
	ft_putstr_fd("\033[31m", STDERR_FILENO);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (s)
	{
		ft_putstr_fd(s, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	ft_putstr_fd("\033[0m", STDERR_FILENO);
}

void	ft_print_vector(void *v, bool doubl)
{
	if (doubl)
		printf("FloatVector x = %f, y = %f\n", \
		((t_dvector *)(v))->x, ((t_dvector *)(v))->y);
	else
		printf("FloatVector x = %d, y = %d\n", \
		((t_ivector *)(v))->x, ((t_ivector *)(v))->y);
}

void	ft_print_mat(char **mat, bool new_line)
{
	int		i;

	i = 0;
	if (!mat)
		return ;
	if (new_line == true)
		while (mat[i])
			printf("%s\n", mat[i++]);
	else
		while (mat[i])
			printf("%s", mat[i++]);
}

void	ft_fps(t_program *p, time_t start, time_t end)
{
	int		fps;
	time_t	new_end;
	char	*itoa;
	char	*tmp;

	fps = (int)((double)1000 / (end - start));
	if (fps > 60)
	{
		new_end = (time_t)((double)1000 / (60) + start);
		usleep((new_end - end) * 1000);
		fps = (int)((double)1000 / (new_end - start));
	}
	itoa = ft_itoa(fps);
	tmp = ft_strjoin("FPS : ", itoa);
	mlx_string_put(p->mlx, p->window, WIDTH / 2, HEIGHT / 50, 0xFF00000, tmp);
	free(itoa);
	free(tmp);
}

void	ft_trama(void)
{
	printf("\033[32mDopo una estenuante ricerca per la via di casa,\n");
	printf("sei riuscuito ad uscire dal labirinto, e hai torvato \n");
	printf("il portale per tornare a casa,\n");
	printf("cogratulazioni la prossima volta ricordati il cellulare\033[0m\n");
}
