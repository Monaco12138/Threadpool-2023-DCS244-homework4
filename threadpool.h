#ifndef __POOL__
#define __POOL__

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>
#include <semaphore.h>
#include <limits.h>
typedef void* (*function_t)(void* arg);
#define gettid() syscall(__NR_gettid)

// 任务节点，每个任务用函数指针和对应的参数表示
// 执行任务时用 pf(arg) 即可，pf表示对应的函数，arg为对应的传入参数
typedef struct Jobnode{
	function_t pf;
	void* arg;
}Jobnode;

// 任务队列，用一个队列表示
typedef struct threadjob{
	Jobnode data;
	struct threadjob* next;
}threadjob;

// 线程池
typedef struct threadpool{
	threadjob* poolhead; //任务队列的头节点
	int jobnum;			 // 任务队列中的任务节点数目
	int Maxthread;		// 线程池中可容纳的最大线程数目
	pthread_t* threads; // 线程池中维护的线程句柄
	sem_t sem;			// 线程池中的同步管理，可以用信号量或互斥锁
	int flag;           // 线程池结束标志，为0时回收所有挂起的线程
	......				// 其它你实现过程中可能需要的参数，自行添加
}threadpool;

//operation of threadpool

//构造函数
threadpool* Pool_init(int Maxthread);				

//删除线程池
// 回收创建线程池所开辟的空间，注意要回收任务队列中的空间
int Delete_pool(threadpool* pool);					

// 主线程添加任务到线程池中
int Add_job(threadpool* pool , function_t pf , void* arg); 

// 线程池中的每个线程执行此函数
// 如果任务队列非空，取出一个任务节点执行
// 如果任务队列为空，挂起等待
// 涉及多个线程从任务队列中取任务节点，注意考虑同步的问题
void Job_running(threadpool* pool);


// 任务队列的操作，push, pop相应的任务节点
// 这里只是给一个示例，实际实现可以进行相应的更改
Jobnode Pop(threadpool* pool);

int Push(threadpool* pool , Jobnode data );

//

#endif