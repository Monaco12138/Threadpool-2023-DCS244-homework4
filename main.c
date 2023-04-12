#include "threadpool.h"

void task1(void)
{
	long sum = 0, i;
	for( i=0; i<1000; i++ ){
		sum = ( sum + rand() ) % INT_MAX;
	}
	printf("this is the task1 running in <%ld>, the answer = %ld\n", gettid(), sum );
}

void task2(void)
{
	long sum = 0, i;
	for(i=0; i<1000; i++){
		sum = ( sum + i * rand() ) % INT_MAX;
	}
	printf("this is the task2 running in <%ld>, the answer = %ld\n", gettid(), sum );
}

int main()
{
	// 初始化一个线程池
	threadpool* pool = Pool_init(10);

	// 主线程添加相应的任务到线程池中
	int i=0;
	for(; i<100; i++){
		Add_job(pool ,(void*)task1 , NULL );
		Add_job(pool , (void*)task2 , NULL);
	}

	// 等待任务的运行
	sleep(10);

	// 删除线程池
    Delete_pool(pool);

	return 0;
}