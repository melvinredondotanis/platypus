#include "../../include/types/types.h"

object_t *new_integer(int value)
{
    object_t *obj;

    obj = malloc(sizeof(object_t));
    if (!obj)
        return (NULL);
    obj->type = TYPE_INTEGER;
    obj->value.integer = value;
    return (obj);
}

object_t *new_floating(float value)
{
    object_t *obj;

    obj = malloc(sizeof(object_t));
    if (!obj)
        return (NULL);
    obj->type = TYPE_FLOATING;
    obj->value.floating = value;
    return (obj);
}

object_t *new_string(char *value)
{
    object_t *obj;

    obj = malloc(sizeof(object_t));
    if (!obj)
        return (NULL);
    obj->type = TYPE_STRING;
    obj->value.string.value = strdup(value);
    obj->value.string.length = strlen(value);
    return (obj);
}

object_t *new_boolean(bool value)
{
    object_t *obj;

    obj = malloc(sizeof(object_t));
    if (!obj)
        return (NULL);
    obj->type = TYPE_BOOLEAN;
    obj->value.boolean = value;
    return (obj);
}

object_t *new_null(void)
{
    object_t *obj;

    obj = malloc(sizeof(object_t));
    if (!obj)
        return (NULL);
    obj->type = TYPE_NULL;
    obj->value.null = NULL;
    return (obj);
}

bool is_integer(object_t obj)
{
    return (obj.type == TYPE_INTEGER);
}

bool is_floating(object_t obj)
{
    return (obj.type == TYPE_FLOATING);
}

bool is_string(object_t obj)
{
    return (obj.type == TYPE_STRING);
}

bool is_boolean(object_t obj)
{
    return (obj.type == TYPE_BOOLEAN);
}

bool is_null(object_t obj)
{
    return (obj.type == TYPE_NULL);
}

void free_object(object_t *obj)
{
    if (!obj)
        return;
    if (obj->type == TYPE_STRING)
        free(obj->value.string.value);
    free(obj);
}
