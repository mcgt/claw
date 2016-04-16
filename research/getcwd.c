#include <stdio.h>
/* For "free". */
#include <stdlib.h>
/* For "getcwd". */
#include <unistd.h>
/* For "strerror". */
#include <string.h>
/* For "errno". */
#include <errno.h>

static void
call_getcwd ()
{
    char * cwd;
    cwd = getcwd (0, 0);
    if (! cwd) {
	fprintf (stderr, "getcwd failed: %s\n", strerror (errno));
    } else {
	printf ("%s\n", cwd);
	free (cwd);
    }
}

int
main (int argc, char ** argv)
{
    call_getcwd ();
    return 0;
}
