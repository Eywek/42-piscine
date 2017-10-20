/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtouffet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:02:26 by vtouffet          #+#    #+#             */
/*   Updated: 2017/07/14 09:12:21 by vtouffet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# include <string.h>

# define SAVE_AUSTIN_POWERS "Save"

typedef struct s_perso	t_perso;

struct	s_perso {
	char	*name;
	float	life;
	int		age;
	char	*profession;
};

#endif
