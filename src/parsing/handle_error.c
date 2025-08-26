#include "../../include/parsing.h"

// #include "errors.h"

static void putstr_fd(const char *s, int fd)
{
    if (!s)
        return;
    while (*s)
        write(fd, s++, 1);
    write(fd, "\n", 1);
}

void print_error(const char *msg)
{
    putstr_fd(msg, 2);
}

void print_error2(const char *msg, const char *detail)
{
    putstr_fd(msg, 2);
    putstr_fd(detail, 2);
}

int	display_error_direction(int code)
{
	if (code == ERR_DUPLICATE_NO)
		print_error("Error: Duplicate NO\n");
	else if (code == ERR_DUPLICATE_SO)
		print_error("Error: Duplicate SO\n");
	else if (code == ERR_DUPLICATE_WE)
		print_error("Error: Duplicate WE\n");
	else if (code == ERR_DUPLICATE_EA)
		print_error("Error: Duplicate EA\n");
	else if (code == ERR_INVALID_ID)
		print_error("Error: invalid texture identifier\n");
	else
		return (0);
	return (1);
}

int	display_error_color(int code)
{
	if (code == ERR_DUPLICATE_FLOOR_COLOR)
		print_error("Error: Duplicate Floor Color\n");
	else if (code == ERR_INVALID_FLOOR_COLOR)
		print_error("Error: Invalid Floor Color\n");
	else if (code == ERR_DUPLICATE_CEIL_COLOR)
		print_error("Error: Duplicate Ceiling Color\n");
	else if (code == ERR_INVALID_CEIL_COLOR)
		print_error("Error: Invalid Ceiling Color\n");
	else
		return (0);
	return (1);
}

int	display_error_input_malloc(int code, const char *target)
{
	if (code == ERR_MALLOC_FAILED)
		print_error("Error: malloc failed\n");
	else if (code == ERR_STRDUP_FAILED)
		print_error("Error: strdup failed\n");
	else if (code == ERR_NULL_INPUT)
		print_error("Error: null input provided\n");
	else
		return (0);
	(void)target;
	return (1);
}


int	display_error_arg(int code)
{
	if (code == ERR_EXPECTED_ONE_ARG)
		print_error("Error: expected exactly one argument\n");
	else if (code == ERR_INVALID_ARGUMENT)
		print_error("Error: invalid argument\n");
	else
		return (0);
	return (1);
}

int	display_error_file(int code, const char *target)
{
	if (code == ERR_CANNOT_OPEN_FILE)
		print_error2( "Error: cannot open file '%s'\n", target);
	else if (code == ERR_FILE_OPEN_FAILED)
		print_error2( "Error: cannot open texture file '%s'\n", target);
	else if (code == ERR_NULL_MAP_NAME)
		print_error( "Error: null map name\n");
	else if (code == ERR_INVALID_MAP_SIZE)
		print_error( "Error: invalid map size\n");
	else if (code == ERR_INVALID_MAP_CONFIG)
		print_error( "Error: invalid map configuration\n");
	else if (code == ERR_PROCESSING_MAP)
		print_error( "Error: processing map failed\n");
	else
		return (0);
	return (1);
}
