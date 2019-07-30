/*
 *************************************************************************
 *    File Name:  timed_wait.h
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2019年07月30日 星期二 21时36分16秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#ifndef _TIMED_WAIT_H_
#define _TIMED_WAIT_H_

#include <pthread.h>
#include <time.h>
#include <iostram>

class TimedWaiter {
public:
    TimedWaiter() {
        pthread_mutex_init(&lock_, NULL);
        pthread_cond_init(&cond_, NULL);
    }
    ~TimedWaiter() {
        pthread_mutex_destory(&lock_);
        pthread_cond_destory(&cond_);
    }

    bool timedWait(const int timed) const {
        bool wait_ret = false;
        struct timespec ts;
        pthread_mutex_lock(&lock_);
        if (clock_gettime(CLOCK_REALTIME, &ts) == 0 ) {
            wait_ret = true;
            ts.tv_sec += timed;
            int ret = pthread_cond_timedwait(&cond_, &lock_, &ts);
            if (ret == ETIMEDOUT) {
                std::cout << "timed out" << std::endl;
            }
        }

        pthread_mutex_unlock(&lock_);
        return wait_ret;
    }

    void signal() const {
        pthread_mutex_lock(&lock_);
        pthread_cond_signal(&cond_);
        pthread_mutex_unlock(&lock_);
    }
private:
    mutable pthread_mutex_t lock_;
    mutable pthread_cond_t cond_;
};

#endif // _TIMED_WAIT_H_
