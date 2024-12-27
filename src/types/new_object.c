#include "../../include/types/types.h"

static int current_id = 0;

object_t *new_integer(int value)
{
    object_t *obj;

    obj = malloc(sizeof(object_t));
    if (!obj)
        return (NULL);

    obj->type = TYPE_INTEGER;
    obj->value.integer = value;
    obj->id = ++current_id;

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
    obj->id = ++current_id;

    return (obj);
}

object_t *new_string(const char *value)
{
    object_t *obj;

    if (!value)
        return (NULL);

    obj = malloc(sizeof(object_t));
    if (!obj)
        return (NULL);

    obj->type = TYPE_STRING;
    obj->value.string.value = strdup(value);
    obj->value.string.length = strlen(value);
    obj->id = ++current_id;

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
    obj->id = ++current_id;

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
    obj->id = ++current_id;

    return (obj);
}
