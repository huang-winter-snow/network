#include "unp.h"

Sigfunc * Signal(int signo, Sigfunc *func)
{
	struct sigaction act, oact;
	act.sa_handler = func;
	sigemptyset(&act.sa_mask);
	act.sa_flag = 0;
	if (signo == SIGALRM) {
		#ifdef SA_INTERRUPT
			act.sa_flag |= SA_INTERRUPT;
		#endif	
	} else {
		#ifdef SA_RESTART
			act.sa_flag |= SA_RESTART;
		#endif	
	}

	if (sigaction(signo, &act, &oact) < 0) {
		return (SIG_ERR);
	}

	return ocat.sa_handler;
}