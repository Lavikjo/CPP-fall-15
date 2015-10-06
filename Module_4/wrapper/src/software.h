#ifndef ELEC_AS_CPP_SOFTWARE_H
#define ELEC_AS_CPP_SOFTWARE_H

#include "bug.h"

/* DESCRIPTION:
 * ------------
 * A forward declaration of the Software_s structure. The implementation is in
 * the corresponding .c file.
 *
 * Each software has a name (char*), a revision number (int) and a list of bugs
 * (Bug**). The software is responsible of freeing the bugs in its list.
 */
struct Software_s;


/* DESCRIPTION:
 * ------------
 * Creates a new software structure according to the parameters.
 *
 * Initially a software has no bugs.
 *
 * RETURNS:
 * ------------
 * The function returns the new software structure on success.
 * On failure the function returns NULL.
 */
struct Software_s* software_construct(const char* name, int revision);


/* DESCRIPTION:
 * ------------
 * The function frees all the memory allocated for the parameter software,
 * effectively destroying it.
 *
 * The destructor also calls the bug_destruct for each of the bugs in the
 * software's bugs list.
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void software_destruct(struct Software_s* software);


/* DESCRIPTION:
 * ------------
 * The function returns the name of the software.
 *
 * RETURNS:
 * ------------
 * The name of the software.
 */
const char* software_get_name(const struct Software_s* software);


/* DESCRIPTION:
 * ------------
 * The function returns the revision number of the software.
 *
 * RETURNS:
 * ------------
 * The revision number of the software.
 */
int software_get_revision(const struct Software_s* software);


/* DESCRIPTION:
 * ------------
 * The function returns the number of bugs in the software's bugs list.
 *
 * RETURNS:
 * ------------
 * The number of bugs in the software's bugs list.
 */
int software_number_of_bugs(const struct Software_s* software);


/* DESCRIPTION:
 * ------------
 * The function reports a new bug to a software. The function takes a copy of
 * the parameter bug and appends it to the software's bugs list.
 *
 * RETURNS:
 * ------------
 * The function returns a pointer to the added bug structure on success.
 * On failure the function returns NULL.
 */
struct Bug_s* software_report_bug(struct Software_s* software, const struct Bug_s* bug);


/* DESCRIPTION:
 * ------------
 * The function sets the fixed status of a bug in the software's bugs list, 
 * according to the parameter bug id, as fixed. 
 *
 * The bug is not removed from the bug list even though its status is changed to
 * fixed.
 *
 * RETURNS:
 * ------------
 * The function returns a pointer to the fixed bug on success.
 * On failure the function returns NULL (e.g. bug not found).
 */
struct Bug_s* software_fix_bug(struct Software_s* software, const char* bug_id);


/* DESCRIPTION:
 * ------------
 * The function prints a complete report of all the different bugs of each
 * priority level, to the standard output.
 *
 * RETURNS:
 * ------------
 * Nothing.
 */
void software_print_bug_report(const struct Software_s* software);


/* DESCRIPTION:
 * ------------
 * The function creates a pirated copy of the software. The copied software is
 * in all other ways the same as the original, but it will have (Pirated) 
 * appended in its name. 
 *
 * The (Pirated) suffixes stack.
 *
 * RETURNS:
 * ------------
 * The function returns a pointer to the pirated copy of the software on
 * success. On failure the function returns NULL.
 */
struct Software_s* software_copy(const struct Software_s* software);

#endif
