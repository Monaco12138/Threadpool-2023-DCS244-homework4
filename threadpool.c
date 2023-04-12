#include "threadpool.h"

threadpool* Pool_init(int Maxthread)
{

	threadpool* pool;
	pool = (threadpool*)malloc(sizeof(threadpool));

	pool->flag = 1;

	/*******************************************************************/

    	//PLEASE ADD YOURs CODES


   	/******************************************************************/
	
	return pool;
}

void Job_running(threadpool* pool)
{
	while(pool->flag){
	/*******************************************************************/

    	//PLEASE ADD YOURs CODES


   	/******************************************************************/
	}
	pthread_exit(0);
}


int Add_job(threadpool* pool , function_t pf , void* arg)
{
	/*******************************************************************/

    	//PLEASE ADD YOURs CODES


   	/******************************************************************/
}

int Push(threadpool* pool , Jobnode data )
{
	/*******************************************************************/

    	//PLEASE ADD YOURs CODES


   	/******************************************************************/
}

Jobnode Pop(threadpool* pool)
{
	/*******************************************************************/

    	//PLEASE ADD YOURs CODES


   	/******************************************************************/
}

int Delete_pool(threadpool* pool)
{
	
	pool->flag = 0;
	/*******************************************************************/

    	//PLEASE ADD YOURs CODES


   	/******************************************************************/
	
}
