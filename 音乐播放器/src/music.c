#include "music.h"

/*
	音乐初始化
	@pathname:音乐的目录名
	返回值:
		返回成功添加结点的音乐头文件
*/

List *music_init(char *pathname)
{
	List *h = creat_list();
	DIR *music = opendir(pathname);
	if(music == NULL)
	{
		perror("music open faild");
	}
	struct dirent *st;
	char str[1024] = {0};
	while(1)
	{
		st = readdir(music);
		if(st == NULL)
		{
			break;
		}
		if(strcmp(".mp3",(st->d_name) + strlen(st->d_name) - 4) == 0)
		{
			sprintf(str,"%s/%s",pathname,st->d_name);
			add_a_node(h,str);
		}
	}
	int a = closedir(music);
	if(a == -1)
	{
		perror("close faild");
	}
	return h;
}