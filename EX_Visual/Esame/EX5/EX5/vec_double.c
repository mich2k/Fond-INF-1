#include "vec_double.h"

struct vec_double* read_vec_double(const char* filename) {
	FILE* f = fopen(filename, "rb");
	if (f == NULL) {
		//fclose(f);
		return NULL;
	}
	uint32_t x, ret;
	struct vec_double* r = malloc(sizeof(struct vec_double));
	ret=fread(&x, sizeof(uint32_t), 1, f); // RICORDARSI DI UTILIZZARE IL RET
	if (ferror(f) || ret != 1) {			// PER IL CONTROLLO DELL FREAD/FWRITE
		free(r);
		fclose(f);
		return NULL;
	}
	r->size = x;
	r->data = malloc(r->size * sizeof(double));
	//fseek(f, sizeof(uint32_t) , 0);
	if (r->data) {
		ret = fread(r->data, sizeof(double), r->size, f);
		if (ferror(f) || ret != x){
			free(r->data);
			free(r);
			fclose(f);
			return NULL;
		}
		fclose(f);
		return r;
	}
	else
		return NULL;
}
