#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>


    struct process{
        char *proc_name;
        int proc_st;
        int priority;
        int pid;
    };

    struct par_process{
        char *par_proc;
        int par_pid;
    };

int main(){
    long int ret_status = syscall(548);

    if(ret_status == 0)
         printf("Success\n");
    else
         printf("Fail\n");

    int a,c,e,f;
    char b[1];
    char d[1];

    printf("PID: ");
    scanf("%d\n", &a);
    printf("Process name: ");
    scanf("%s\n", b);
    printf("Parent PID: ");
    scanf("%d\n", &c);
    printf("Parent name: ");
    scanf("%s\n", d);
    printf("Process state: ");
    scanf("%d\n", &e);
    printf("Process priority: ");
    scanf("%d\n", &f);

    struct process sec = {b,e,f,a};
    struct par_process sec1 = {d,c};

    struct process first={"abc",1,2,3};
    struct par_process first1={"bc",1};

    printf("%d%s%d%s%d%d\n",a,b,c,d,e,f);

    printf("  PID |    PN    |  PP  |    PaP    |  PS  | Prior\n");
    printf("------+----------+------+-----------+------+------\n");
    printf("%5d |%10s| %5d|%-10s |%-5d |%-5d\n", first.pid, first.proc_name, first1.par_pid, first1.par_proc, first.proc_st, first.priority);
    printf("%5d |%10s| %5d|%-10s |%-5d |%-5d\n", sec.pid, sec.proc_name, sec1.par_pid, sec1.par_proc, sec.proc_st, sec.priority);
     return 0;
}
