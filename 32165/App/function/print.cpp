#include "../App.h"
#include "Enclave_u.h"

/* OCall functions */
void ocall_print_string(const char *str)
{
    printf("==in ocall_print:%s", str);
}

