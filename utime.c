#include "defs.h"
#include <utime.h>

typedef struct utimbuf utimbuf_t;

SYS_FUNC(utime)
{
	if (entering(tcp)) {
		utimbuf_t u;

		printpath(tcp, tcp->u_arg[0]);
		tprints(", ");

		if (!tcp->u_arg[1])
			tprints("NULL");
		else if (!verbose(tcp) || umove(tcp, tcp->u_arg[1], &u) < 0)
			tprintf("%#lx", tcp->u_arg[1]);
		else {
			tprintf("[%s,", sprinttime(u.actime));
			tprintf(" %s]", sprinttime(u.modtime));
		}
	}
	return 0;
}
