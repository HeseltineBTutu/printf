#include <stdio.h>
#include <stdlib.h>
#include <printf.h>

typedef struct
{
	char *name;
}
Binary;

int print_binary (FILE *stream,
		  const struct printf_info *info,
		  const void *const *args)
{
	const Binary *b;
	char *buffer;
	int len;
	w = *((const Binary **) (args[0]));
	len = asprintf (&buffer, "Binary %p; %s>", b, b->name);
	if (len == -1)
		return (-1);

	len = fprintf (stream, "%*s",
			(info->left ? -info->width: info->width),
			buffer);

	free (buffer);
	return len;
}

int print_binary_arginfo (const struct printf_info *info, size_t n,
		int *argtypes)
{
	if (n > 0)
		argtypes[0] = PA_POINTER;
	return 1;
}
int main (void)
{
	binary mybinary;
	mybinary.name = "mybinary";

	register_printf_function ('b', print_binary, print_binary_arginfo);
	printf ("|%w|\n", &mybinary);

	return (0);
}
