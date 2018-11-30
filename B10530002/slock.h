#ifndef _SCOPED_LOCK_
#define _SCOPED_LOCK_

#include <pthread.h>
#include "verify.h"
struct ScopedLock {
	private:
		pthread_mutex_t *m_;
	public:
		ScopedLock(pthread_mutex_t *m): m_(m) {
			VERIFY(pthread_mutex_lock(m_)==0);
		}
		~ScopedLock() {
			VERIFY(pthread_mutex_unlock(m_)==0);
		}
};
#endif  /*_SCOPED_LOCK_*/