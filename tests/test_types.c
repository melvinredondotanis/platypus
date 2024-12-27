#include <stdio.h>
#include <assert.h>
#include "../include/types/types.h"

static int tests_run = 0;
static int tests_failed = 0;

void test_integer(void)
{
    object_t *obj;

    obj = new_integer(42);
    assert(obj != NULL);
    assert(obj->type == TYPE_INTEGER);
    assert(obj->value.integer == 42);
    assert(obj->id > 0);
    free(obj);
    tests_run++;
    printf("test_integer: OK\n");
}

void test_floating(void)
{
    object_t *obj;

    obj = new_floating(3.14f);
    assert(obj != NULL);
    assert(obj->type == TYPE_FLOATING);
    assert(obj->value.floating == 3.14f);
    assert(obj->id > 0);
    free(obj);
    tests_run++;
    printf("test_floating: OK\n");
}

void test_string(void)
{
    object_t *obj;

    obj = new_string("test");
    assert(obj != NULL);
    assert(obj->type == TYPE_STRING);
    assert(strcmp(obj->value.string.value, "test") == 0);
    assert(obj->value.string.length == 4);
    assert(obj->id > 0);
    free(obj->value.string.value);
    free(obj);
    tests_run++;
    printf("test_string: OK\n");
}

void test_boolean(void)
{
    object_t *obj;

    obj = new_boolean(1);
    assert(obj != NULL);
    assert(obj->type == TYPE_BOOLEAN);
    assert(obj->value.boolean == 1);
    assert(obj->id > 0);
    free(obj);
    tests_run++;
    printf("test_boolean: OK\n");
}

void test_null(void)
{
    object_t *obj;

    obj = new_null();
    assert(obj != NULL);
    assert(obj->type == TYPE_NULL);
    assert(obj->id > 0);
    free(obj);
    tests_run++;
    printf("test_null: OK\n");
}

int run_tests(void)
{
    printf("Running tests...\n");
    test_integer();
    test_floating();
    test_string();
    test_boolean();
    test_null();
    printf("\nTests run: %d\nTests failed: %d\n", tests_run, tests_failed);
    return (tests_failed);
}

int main(void)
{
    return (run_tests());
}
