#include <unistd.h>
#include <sys/syscall.h>

int
main(void)
{
#ifdef __NR_readlink
	char buf[31];

	if (syscall(__NR_readlink, "readlink.link", buf, sizeof(buf)) != 10)
		return 77;

	return 0;
#else
	return 77;
#endif
}