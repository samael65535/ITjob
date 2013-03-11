#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 测试内存区域 使用  gdb 调试 使用ulimit -a 查看系统分配的大小
本机 ubuntu 12.04 LTS
core file size          (blocks, -c) 0
data seg size           (kbytes, -d) unlimited
scheduling priority             (-e) 0
file size               (blocks, -f) unlimited
pending signals                 (-i) 15129
max locked memory       (kbytes, -l) 64
max memory size         (kbytes, -m) unlimited
open files                      (-n) 1024
pipe size            (512 bytes, -p) 8
POSIX message queues     (bytes, -q) 819200
real-time priority              (-r) 0
stack size              (kbytes, -s) 8192 (这里)
cpu time               (seconds, -t) unlimited
max user processes              (-u) 15129
virtual memory          (kbytes, -v) unlimited
file locks                      (-x) unlimited
 */
int a = 1;
void main()
{
	const float PI = 3.14159f;
	static int b = 2;
	int c = 3;
	char *d = "Hello";
	char **e = &d;		//指针的指针
	char *f = (char *)malloc(3);
	strcpy(f, "AB");

	printf("main 代码区 0x%08x\n\n", &main);

	printf("文字 常量区 0x%08x\t%s\n\n", (void *)"Hello", "Hello");

	printf("a    全局区 0x%08x\t%d\n", &a, a);
	printf("b    静态区 0x%08x\t%d\n\n", &b, b);

	printf("PI   栈  区 0x%08x\t%f\n", &PI, PI);
	printf("c    栈  区 0x%08x\t%d\n", &c, c);
	printf("d    栈  区 0x%08x\t0x%08x\t%s\n", &d, (void *)d, d);
	printf("e    栈  区 0x%08x\t0x%08x\t0x%08x\t%s\n\n", &e, (void *)e, (void *)*e, *e);

	printf("f    堆  区 0x%x\t0x%08x\t%s\n\n", &f, (void *)f, f);

	free(f);
}
