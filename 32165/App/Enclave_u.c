#include "Enclave_u.h"
#include <errno.h>

typedef struct ms_encall_print_t {
	char** ms_fmt;
} ms_encall_print_t;

typedef struct ms_ocall_print_string_t {
	char* ms_str;
} ms_ocall_print_string_t;

static sgx_status_t SGX_CDECL Enclave_ocall_print_string(void* pms)
{
	ms_ocall_print_string_t* ms = SGX_CAST(ms_ocall_print_string_t*, pms);
	ocall_print_string((const char*)ms->ms_str);

	return SGX_SUCCESS;
}

static const struct {
	size_t nr_ocall;
	void * table[1];
} ocall_table_Enclave = {
	1,
	{
		(void*)Enclave_ocall_print_string,
	}
};
sgx_status_t encall_print(sgx_enclave_id_t eid, char** fmt)
{
	sgx_status_t status;
	ms_encall_print_t ms;
	ms.ms_fmt = fmt;
	status = sgx_ecall(eid, 0, &ocall_table_Enclave, &ms);
	return status;
}

