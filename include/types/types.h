#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

typedef enum object_type
{
    TYPE_INTEGER,
    TYPE_FLOATING,
    TYPE_BOOLEAN,
    TYPE_STRING,
    TYPE_NULL
} object_type_t;

typedef struct object
{
    object_type_t type;
    union
    {
        int integer;
        float floating;
        struct
        {
            char *value;
            size_t length;
        } string;
        bool boolean;
        void *null;
    } value;
} object_t;

object_t *new_integer(int value);
object_t *new_floating(float value);
object_t *new_string(char *value);
object_t *new_boolean(bool value);
object_t *new_null(void);

bool is_integer(object_t obj);
bool is_floating(object_t obj);
bool is_string(object_t obj);
bool is_boolean(object_t obj);
bool is_null(object_t obj);

void free_object(object_t *obj);

#endif