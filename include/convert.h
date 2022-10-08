#ifndef INCLUDE_CONVERT_H
#define INCLUDE_CONVERT_H

#include "interface.h"

char *shape_to_string(const generated_shape_option_t shape);
char *size_to_string(const option_size_t size);
int size_to_integer(const option_size_t size);

#endif