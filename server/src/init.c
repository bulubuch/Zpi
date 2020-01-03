/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 22:07:28 by mbuch             #+#    #+#             */
/*   Updated: 2020/01/02 22:07:28 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			get_options(t_server *srv, int *ai, int ac, char **av)
{
	int			i;
	int			j;
	char		*arg;
	t_option	*opts;

	arg = av[*ai];
	if (*arg == '-')
	{
		arg++;
		i = 0;
		while (i < 6)
		{
			if (*arg == opts[i].c)
				opts[i].func(srv, ai, ac, av);
			i++;
		}
	}
	else
		*ai = *ai + 1;	
}

void			init_options(t_server *srv)
{
	t_option	*opts;

	srv->opt_nbr = 0;
	opts = &srv->options[0];
	opts[0].c = 'p';
	opts[0].func = &set_port;
	opts[1].c = 'w';
	opts[1].func = &set_width;
	opts[2].c = 'h';
	opts[2].func = &set_height;
	opts[3].c = 'n';
	opts[3].func = &set_team;
	opts[4].c = 'c';
	opts[4].func = &set_nb;
	opts[5].c = 't';
	opts[5].func = &set_time;
}

int				init_srv(t_server *srv, int ac, char **av)
{
	int			i;

	if (ac < 13)
		usage_error();
	i = 0;
	init_options(srv);
	while (i < ac)
		get_options(srv, &i, ac, av);
}