# threadpool

## 描述
线程池 (thread pool)：是一种线程的使用模式。在实际系统中，频繁的创建销毁线程会带来
过多的调度开销，从而影响整体性能。线程池维护着多个线程，等待着监督管理者分配可并发执
行的任务。这避免了在处理短时间任务时创建与销毁线程的代价。线程池不仅能够保证内核的充
分利用，还能防止过分调度。

在本习题中，我们采用任务队列的模式来实现一个线程池：主线程负责将相应的任务放入任
务队列中，工作线程负责从任务队列中取出相应的任务进行处理，如果任务队列为空，则取不到
任务的工作线程将进入挂起状态。

## 实验环境
  1. Ubuntu 14.0+

  2. ```shell
      sudo apt-get update
      sudo apt-get install build-essential
      ```
## 数据结构
```c
// 任务节点，每个任务用函数指针和对应的参数表示
// 执行任务时用 pf(arg) 即可，pf表示对应的函数，arg为对应的传入参数
typedef void* (*function_t)(void* arg);
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
```
## 具体任务
代码框架已经给出，请根据要求填充完成空缺的部分，实现一个简单的线程池

## 代码运行
  1. you should first __make__ the Makefile to build exce.o
  2. then just run ./exce.o you can get the answer
