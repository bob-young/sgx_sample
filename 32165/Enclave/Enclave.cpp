#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */
#include "Enclave.h"
#include "Enclave_t.h"  /* print_string */
# include <unistd.h>
#include <string.h>

void encall_print(char **fmt)
{
	char buf[BUFSIZ] = {'\0'};
	char* a="\tnow is in encall\n";
	strncat(buf,fmt[0],100);
	strncat(buf,(fmt[1]),100);
	strncat(buf,(fmt[2]),100);
	strncat(buf,a,100);
	ocall_print_string(buf);
}
