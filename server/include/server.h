/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuch <mbuch@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 21:10:32 by mbuch             #+#    #+#             */
/*   Updated: 2020/01/02 21:10:32 by mbuch            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <arpa/inet.h>
# define OPTIONS_STR	"pxynct"
# define USAGE_MSG		"Usage: ./serveur -p <port> -x <width> -y <height> -n <team> [<team>] [<team>] ... -c <nb> -t <t>"

# define MAX_CMD_BUF	10

typedef struct	s_sock
{
	int					fd;
	struct sockaddr		addr;
	struct sockaddr_in	*in_addr;
}				t_sock;

typedef struct		s_cmd
{
	char			*name;
	void			*(*func)(void*, void*);
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_obj
{
	int				x;
	int				y;
	char			name[32];
}					t_obj;

typedef struct		s_inventory
{
	int				nourriture;
	int				linemate;
	int				deraumere;
	int				sibur;
	int				mendiane;
	int				phiras;
	int				thystame;
}					t_inventory;

typedef struct		s_drone
{
	t_obj			obj;
	t_sock			sock;
	t_inventory		inv;
	t_cmd			*cmd;
}					t_drone;

typedef struct		s_world
{
	int				time_factor;
	long int		current_time;
	int				width;
	int				height;
}					t_world;

typedef struct		s_team
{
	char			*name;
	int				player_nbr;
	int				player_max;
	t_drone			players;
}					t_team;

typedef struct		s_option
{
	char			c;
	int				(*func)(t_server*, int*, int, char**);
}					t_option;

typedef struct		s_server
{
	t_sock			gate;
	t_world			world;
	t_team			teams;
	int				opt_nbr;
	t_option		options[6];
}					t_server;

void			usage_error();


#endif
