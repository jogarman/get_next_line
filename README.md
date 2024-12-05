# Get_next_line

## A 42´s project.
Get_next_line is apparently a simple function in C which read a line each time that is called. 
The target of the project is about the understanding of static variables. 


## External functs
• read()

• malloc() 

• free()

## Compilation
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.


## Example of main()
We will read 4 lines from file "text.txt"

int	 main()
{
	char	*line = NULL;
	int	fd;
	int	i = 0;

	fd = open("./text", O_RDONLY);
	while (i != 5)
	{
		line = get_next_line(fd);
		printf("|---|%s", line);
		if (line == NULL)
			return (EXIT_SUCCESS);
		free(line);
		i++;
	}
	close(fd);
}
