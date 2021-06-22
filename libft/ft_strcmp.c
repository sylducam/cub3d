/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sylducam <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/08/06 10:40:23 by sylducam     #+#   ##    ##    #+#       */
/*   Updated: 2021/04/29 16:01:53 by sylducam         ###   ########lyon.fr   */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_simplify(int result)
{
	if (result > 0)
		return (1);
	else if (result < 0)
		return (-1);
	else
		return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		index;
	int		result;

	index = 0;
	result = 0;
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] != s2[index])
		{
			result += (s1[index] - s2[index]);
			return (ft_simplify(result));
		}
		index++;
	}
	return (result);
}
