#include<stdio.h>
#include <fcntl.h>
#include<sys/stat.h>
#include <mqueue.h>
#include<sys/types.h>
struct mq_attr cdacmq_attr;
mqd_t cdacmqd;
int main()
{
cdacmq_attr.mq_flags= 0;
cdacmq_attr.mq_maxmsg=4;
cdacmq_attr.mq_msgsize=128;
cdacmq_attr.mq_curmsgs=0;
cdacmqd= mq_open("/cdacmq", O)

}
