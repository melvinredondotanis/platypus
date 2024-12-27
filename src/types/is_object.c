#include "../../include/types/types.h"

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
