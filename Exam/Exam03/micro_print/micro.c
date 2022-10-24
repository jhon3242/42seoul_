#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_zone
{
	int hight;
	int width;
	char background;
}	t_zone;

typedef struct s_list
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}	t_list;

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int print_err(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int check_zone(t_zone *zone)
{
	if (zone->width <= 0 || zone->width > 300)
		return (1);
	if (zone->hight <= 0 || zone->hight > 300)
		return (1);
	return (0);
}

char *get_zone(FILE *file, t_zone *zone)
{
	int count;
	char *arr;
	int i = -1;

	if (!(count = fscanf(file, "%d %d %c\n", &zone->width, &zone->hight, &zone->background)))
		return (NULL);
	if (count == -1)
		return (NULL);
	if (check_zone(zone))
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (zone->width * zone->hight));
	if (!arr)
		return (NULL);
	while (++i < zone->width * zone->hight)
		arr[i] = zone->background;
	return (arr);
}

int free_all(FILE *file, char *str)
{
	fclose(file);
	if (str)
		free(str);
	return (1);
}

int check_info(t_list *info)
{
	return (info->height > 0.00000000 && info->width > 0.000000000 && (info->type == 'r' || info->type == 'R'));
}

int is_rec(float x, float y, t_list *info)
{
	float check = 1.00000000;
	if (x < info->x || info->x + info->height < x || y < info->y || info->y + info->width < y)
		return (0);
	if (x - info->x < check || (info->x + info->height) - x < check || y - info->y < check || (info->y + info->width) - y < check)
		return (2);
	return (1);
}

void print_draw(char *draw, t_zone *zone)
{
	int i = -1;
	while (++i < zone->hight)
	{
		write(1, draw + (i * zone->hight), zone->width);
		write(1, "\n", 1);
	}
}

void	get_draw(char **draw, t_list *info, t_zone *zone)
{
	int x, y;
	int rec;

	x = -1;
	while (++x < zone->hight)
	{
		y = -1;
		while (++y < zone->width)
		{
			rec = is_rec(x, y, info);
			if ((info->type == 'r' && rec == 2) || (info->type == 'R' && rec)){
				(*draw)[(x * zone->width) + y] = info->color;
			}
		}
	}
}

int drawing(FILE *file, char **draw, t_zone *zone)
{
	t_list	info;
	int count;

	while ((count = fscanf(file, "%c %f %f %f %f %c\n", &info.type, &info.x, &info.y, &info.width, &info.height, &info.color)) == 6)
	{
		if (!check_info(&info))
			return (1);
		get_draw(draw, &info, zone);
	}
	if (count == -1)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	FILE *file;
	t_zone zone;
	char	*draw;

	if (ac == 1)
		return (print_err("Error: argument\n"));
	if (!(file = fopen(av[1], "r")))
		return (print_err("Error: Operation file corrupted\n"));
	if (!(draw = get_zone(file, &zone)))
		return (free_all(file, NULL) && print_err("Error: Operation file corrupted\n"));
	if (!drawing(file, &draw, &zone))
		return (free_all(file, draw) && print_err("Error: Operation file corrupted\n"));
	print_draw(draw, &zone);
	free_all(file, draw);
	return (0);
}