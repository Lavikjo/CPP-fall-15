#ifndef ELEC_AS_CPP_BUG_H
#define ELEC_AS_CPP_BUG_H

/* Enumerations for the priorities of different bugs. */
typedef enum PRIORITY {
    TRIVIAL,
    MINOR,
    MAJOR,
    CRITICAL,
    BLOCKER
} Priority;


/* DESCRIPTION:
 * ------------
 *
 * Forward declaration of the Bug_s structure. Implementation is in the .c file.
 *
 * Each bug has a unique id (char*), description (char*), priority, and a fixed
 * status (int). A bug is always either fixed (1) or not fixed (0). Since the
 * id of a bug is unique, the id is alone enough to identify a bug.
 */
struct Bug_s;


/* DESCRIPTION:
 * ------------
 * Creates a new bug according to the parameters. When a bug is created it is
 * initially unfixed.
 *
 * RETURNS:
 * -----------
 * The function returns a pointer to the created bug structure on success.
 * The function returns NULL on failure.
 */
struct Bug_s* bug_construct(const char* id, const char* description, Priority priority);


/* DESCRIPTION:
 * ------------
 * Frees all the memory reserved for a bug, effectively destroying it.
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void bug_destruct(struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function returns the id of the bug.
 *
 * RETURNS:
 * ------------
 * The id of the bug.
 */
const char* bug_get_id(const struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function returns the description of the bug.
 *
 * RETURNS:
 * ------------
 * The description of the bug.
 */
const char* bug_get_description(const struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function returns the priority of the bug.
 *
 * RETURNS:
 * ------------
 * The priority of the bug.
 */
Priority bug_get_priority(const struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function returns the fixed status of the bug.
 *
 * RETURNS:
 * ------------
 * The fixed status of the bug.
 */
int bug_is_fixed(const struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function sets the bug's fixed status as fixed (1).
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void bug_fix(struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function prints information about the bug to the standard output.
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void bug_print(const struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function creates an exact copy of the parameter bug structure.
 *
 * RETURNS:
 * ------------
 * The function returns a copy of the parameter bug structure on success.
 * On failure the function returns NULL.
 */
struct Bug_s* bug_copy(const struct Bug_s* bug);

#endif
