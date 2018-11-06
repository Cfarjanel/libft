#include "../includes/libft.h"

void        free_double_tab(void **tab, int x)
{
    int i;

    i = 0;
    while (tab && i < x)
    {
        ft_memdel(&(tab[i]));
        i++;
    }
    free(tab);
    tab = NULL;
}