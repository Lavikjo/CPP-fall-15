#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "bug.h"
#include "software.h"

struct Software_s {
    char* name;             // The name of the software
    int revision;           // Revision number of the software
    struct Bug_s** bugs;    // List of the software's reported bugs
};

struct Software_s* software_construct(const char* name, int revision) {
    assert(name);

    struct Software_s* new_software = (struct Software_s*)malloc(sizeof(struct Software_s));
    if (!new_software)
        goto CLEANUP_C;

    new_software->name = (char*)malloc(strlen(name) + 1);
    if (!new_software->name)
        goto CLEANUP_B;
    strcpy(new_software->name, name);
    
    new_software->revision = revision;

    new_software->bugs = (struct Bug_s**)calloc(1, sizeof(struct Bug_s*));
    if (!new_software->bugs)
        goto CLEANUP_A;

    return new_software;

    // Error handling
    CLEANUP_A:
        free(new_software->bugs);
    CLEANUP_B:
        free(new_software->name);
    CLEANUP_C:
        free(new_software);
    return NULL;
}

void software_destruct(struct Software_s* software) {
    assert(software);
    
    free(software->name);
    for (int i = 0; software->bugs[i] != NULL; i++)
        bug_destruct(software->bugs[i]);
    free(software->bugs);
    free(software);
}

const char* software_get_name(const struct Software_s* software) {
    assert(software);
    return software->name;
}

int software_get_revision(const struct Software_s* software) {
    assert(software);
    return software->revision;
}

int software_number_of_bugs(const struct Software_s* software) {
    assert(software);
    int i;
    for (i = 0; software->bugs[i] != NULL; i++);
    return i;
}

struct Bug_s* software_report_bug(struct Software_s* software, const struct Bug_s* bug) {
    assert(software && bug);
    
    struct Bug_s* copy = bug_copy(bug);
    if (!copy)
        return NULL;

    int num_of_bugs = software_number_of_bugs(software);
    struct Bug_s** bugs = (struct Bug_s**)realloc(software->bugs, (num_of_bugs+2) * sizeof(struct Bug_s*));
    if (!bugs) {
        bug_destruct(copy);
        return NULL;
    }

    software->bugs = bugs;
    software->bugs[num_of_bugs] = copy;
    software->bugs[num_of_bugs + 1] = NULL;
    return software->bugs[num_of_bugs];
}

struct Bug_s* software_fix_bug(struct Software_s* software, const char* bug_id) {
    assert(software && bug_id);

    for (int i = 0; software->bugs[i] != NULL; i++) {
        if (strcmp(bug_get_id(software->bugs[i]), bug_id) == 0) {
            bug_fix(software->bugs[i]);
            return software->bugs[i];
        }
    }
    return NULL;
}

void software_print_bug_report(const struct Software_s* software) {
    assert(software);
    printf("%s, revision: %d\n", software->name, software->revision);
    
    const char* priorities[] = {"Trivial", "Minor", "Major", "Critical", "Blocker"};
    int count = 0, fixed = 0, total = 0;
    
    for (int i = 0; i <= BLOCKER; i++, count = 0) {
        printf("Priority: %s\n", priorities[i]);
        for (int j = 0; software->bugs[j] != NULL; j++) {
            if (bug_get_priority(software->bugs[j]) == i) {
                if (bug_is_fixed(software->bugs[j])) fixed++;
                bug_print(software->bugs[j]);
                count++;
                total++;
            }
        }
        if (count == 0)
            printf("None\n");
    }
    printf("Bugs in report: %d, Bugs fixed: %d/%d\n", total, fixed, total);
}

struct Software_s* software_copy(const struct Software_s* software) {
    assert(software);
    
    char* copy_name = (strlen(software->name) > strlen(" (Pirated)")) && 
                        strcmp(software->name + (strlen(software->name) - strlen(" (Pirated)")), " (Pirated)") == 0 ? 
                        strcpy((char*)malloc(strlen(software->name) + 1), software->name) : 
                        strcat(strcpy((char*)malloc(strlen(software->name) + strlen(" (Pirated)") + 1), software->name), " (Pirated)");

    if (!copy_name)
        return NULL;
    
    struct Software_s* copy = software_construct(copy_name, software->revision);
    free(copy_name);

    if (!copy)
        return NULL;

    for (int i = 0; software->bugs[i] != NULL; i++) {
        struct Bug_s* ret = software_report_bug(copy, software->bugs[i]);   // Copy the bugs
        if (!ret) {
            software_destruct(copy);
            return NULL;
        }
    }
    return copy;
}
