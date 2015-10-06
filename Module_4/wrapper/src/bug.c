#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "bug.h"

struct Bug_s {
    char* id;
    char* description;
    Priority priority;
    int fixed;
};

struct Bug_s* bug_construct(const char* id, const char* description, Priority priority) {
    assert(id && description);

    struct Bug_s* new_bug = (struct Bug_s*)malloc(sizeof(struct Bug_s));
    if (!new_bug)
        goto CLEANUP_C;

    new_bug->id = (char*)malloc(strlen(id) + 1);
    if (!new_bug->id)
        goto CLEANUP_B;

    strcpy(new_bug->id, id);
    
    new_bug->description = (char*)malloc(strlen(description) + 1);
    if (!new_bug->description)
        goto CLEANUP_A;

    strcpy(new_bug->description, description);
    
    new_bug->priority = priority;
    new_bug->fixed = 0;
    
    return new_bug;

    // Error handling
    CLEANUP_A:
        free(new_bug->description);
    CLEANUP_B:
        free(new_bug->id);
    CLEANUP_C:
        free(new_bug);
    return NULL;
}

void bug_destruct(struct Bug_s* bug) {
    assert(bug); 
    free(bug->id);
    free(bug->description);
    free(bug);
}

const char* bug_get_id(const struct Bug_s* bug) {
    assert(bug);
    return bug->id;
}

const char* bug_get_description(const struct Bug_s* bug) {
    assert(bug);
    return bug->description;
}

Priority bug_get_priority(const struct Bug_s* bug) {
    assert(bug);
    return bug->priority;
}

int bug_is_fixed(const struct Bug_s* bug) {
    assert(bug);
    return bug->fixed;
}

void bug_fix(struct Bug_s* bug) {
    assert(bug);
    bug->fixed = 1;
}

void bug_print(const struct Bug_s* bug) {
    assert(bug);
    printf("Id: %s, Desc: %s, Fixed: %s\n", bug->id, bug->description, bug->fixed ? "Yes" : "No");
}

struct Bug_s* bug_copy(const struct Bug_s* bug) {
    assert(bug);

    struct Bug_s* copy = bug_construct(bug->id, bug->description, bug->priority);
    if (!copy)
        return NULL;

    copy->fixed = bug->fixed;
    return copy;
}
