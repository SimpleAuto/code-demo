/*
 *************************************************************************
 *    File Name:  thread_test_3.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年04月05日 星期四 15时45分04秒
 * 
 *  Description: 存在内存泄露的demo 
 * 
 *************************************************************************
*/
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

pthread_key_t key;
pthread_once_t once = PTHREAD_ONCE_INIT; 

static void destructor(void *ptr)
{
	free(ptr);
}  

void init_once(void)
{
	pthread_key_create(&key, destructor);
} 

static void *get_buf(void)
{
    pthread_once(&once, init_once); 
    void *ptr = NULL;

    if ((ptr = pthread_getspecific(key)) == NULL)
    {
        ptr = malloc(1024);
        pthread_setspecific(key, ptr);
    }

    return (ptr);
} 

static void *thread_fn(void *arg)
{
    char *ptr = (char*) get_buf(); 
    sprintf(ptr, "hello world");
    printf(">>%s\n", ptr);
    return (NULL);
} 

static void *thread_fn_2(void *arg)
{
    char *ptr = (char*) get_buf(); 
    sprintf(ptr, "good afternoon");
    printf(">>%s\n", ptr);
    return (NULL);
} 

void test(void)
{
    int i, n = 10;
    pthread_t tids[10]; 

    for (i = 0; i < n/2; i++)
    {
        pthread_create(&tids[i], NULL, thread_fn, NULL);
    } 

    for (i = n/2; i < n; i++)
    {
        pthread_create(&tids[i], NULL, thread_fn_2, NULL);
    }

    for (i = 0; i < n; i++)
    {
        pthread_join(tids[i], NULL);
    }
}

int main()
{
    int ret = pthread_key_create(&key, &destructor);
    while(1)
    {
        test();
        sleep(5);
    }
	return 0;
}
