/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: safuente <safuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:03 by safuente          #+#    #+#             */
/*   Updated: 2024/12/30 11:56:32 by safuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = (t_list *) malloc (sizeof(t_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
