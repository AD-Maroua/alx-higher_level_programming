#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

/**
 * print_python_bytes - Prints bytes information
 *
 * @p: A Python list Object
 * Return: no return
 */
void print_python_bytes(PyObject *p)
{
	int size, alloc, i;
	char *string;
	PyListObject *list = (PyListObject *)p;
	PyVarObject *var = (PyVarObject *)p;

	size = var->ob_size;
	alloc = list->allocated;

	printf("[*] Python list info bytes\n");
	printf("[*] Sizeof the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", alloc);

	for (i = 0; i < size; i++)
	{
		type = list->ob_item[i]->ob_type->tp_name;
		printf("Element %d: %s\n", i, type);
		if (strcmp(type, "bytes") ==0)
			print_python_bytes(list->ob_item[i]);
	}
}

/**
 * print_python_bytes - Prints basic info about Python byte objects.
 * @p: A Python byte Object.
 */
void print_python_bytes(PyObject *p)
{
	unsigned char i, size;
	PyBytesObject *bytes = (PyBytesObject *)p;

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes") != 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	printf(" size: %ld\n",  ((PyVarObject *)p)->ob_size);
	printf(" trying string: %s\n", bytes->ob_aval);
	
	if (((PyVarObject *)p)->ob_size > 10)
		size = 10;
	else
		size = ((PyVarObject *)p)->ob_size +1;

	printf("  first %d bytes: ", size);
	for (i = 0; i < size; i++)
	{
		printf("%02hhx", bytes->ob_sval[i]);
		if (i == (size -1))
			printf("\n");
		else
			printf(" ");
	
	}
}
