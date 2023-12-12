/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:09:53 by nhayoun           #+#    #+#             */
/*   Updated: 2023/12/12 17:57:23 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
        printf("%p\n", &lst);
		del((lst)->content);
		free(lst);
		lst = NULL;
	}
}

/*void	free_content(void *content)
{
	free(content);
    content = NULL;
}
int main_(void)
{
    t_list *link;
    char text[] = "Node";
    int i = 0;
    char *ptr = (char *)malloc(sizeof(text));
    
    while (text[i])
    {
        ptr[i] = text[i];
        i++;
    }
    ptr[i] = '\0';
    
    link = ft_lstnew((void *)ptr);
    printf("-----%p\n", &link);
    if (link)
        printf("Before => %s\n", (char *)link->content);
    ft_lstdelone(link, free_content);
    //while (1);
    //if (link->content)
    //    printf("Deleted succesfully\n");
    //     printf("Before => %s\n", (char *)link->content);
    //printf("After => Node String deleted successfully\n");
    //the addresses being printed are different signifying that the lst point is passed by reference 
    // nothing gets printed after dereferencing the item content
    return (0);
}
int main()
{
    main_();
    //system("leaks -q a.out");
    //no leaks are found
    return 0;
}*/