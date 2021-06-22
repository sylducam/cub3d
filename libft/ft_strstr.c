/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/08 16:44:22 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2021/04/12 12:24:18 by sylducam         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	track;

	i = 0;
	j = 0;
	if (to_find == 0)
		return (str);
	while (str[i] != '\0')
	{
		track = i;
		while (str[i] == to_find[j] && str[i] != '\0' && to_find[j] != '\0')
		{
			if (to_find[j + 1] == '\0')
				return (&str[track]);
			i++;
			j++;
		}
		i = track;
		i++;
		j = 0;
	}
	return (0);
}
