#include "music.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	List *h = music_init(argv[1]);
	Node *p = h->first;
	int status;
	int b;
	while(1)
	{
		char a[1024] = {0};
		scanf("%d",&b);
		if(b == 1)       //播放
		{
			//b = 0;
			sprintf(a,"madplay %s",p->data);
			system(a);
		}
		if(b == 2)		//继续播放
		{
			system("killall -CONT madplayer &");
		}
		if(b == 3)		//暂停
		{
			system("killall -STOP madplay &");	
		}
		if(b == 4)		//播放下一首
		{
			system("killall -9 madplay");
			p = p->next;
			sprintf(a,"madplay %s",p->data);
			system(a);
		}
		if(b == 5)		//播放上一首
		{
			system("killall -9 madplay");
			p = p->pre;
			sprintf(a,"madplay %s",p->data);
			system(a);
		}
		if(b == 6)		//退出
		{
			system("killall -9 madplay");
			break;
		}
	}
		
	return 0;
}
