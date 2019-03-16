#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include "ProcessInfo.h"


asmlinkage long sys_ProcessInfo(void) {
  
    struct task_struct *proces;
 
    for_each_process(proces) {
 
    printk(
      "Process: %s\n \
       PID: %ld\n \
       Process State: %ld\n \
       Priority: %ld\n", \
       proces->comm, \
       (long)task_pid_nr(proces), \
       (long)proces->state, \
       (long)proces->prio \
    );
  
  
   if(proces->parent) 
      printk(
        "Parent process: %s, \
         PID: %ld", \ 
         proces->parent->comm, \
         (long)task_pid_nr(proces->parent) \
      );
  
   printk("\n\n");
  
  }
  
  return 0;
}
