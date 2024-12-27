#include "../../include/types/types.h"

void free_object(object_t *obj)
{
    if (!obj)
        return;

    if (obj->type == TYPE_STRING)
        free(obj->value.string.value);

    free(obj);
}
