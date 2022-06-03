# Rootkit
## Version
The code for this assignment should be developed and tested using a Linux Virtual machine based on Ubuntu 20.04
Select following image: Ubuntu 20.04 VM Kernel version: Linux 5.4.0-104-generic (You can see your kernel version using “uname -r”)
## File Description
Makefile – A makefile that will compile “sneaky_process.c” into “sneaky_process”, and will compile “sneaky_mod.c” into “sneaky_mod.ko”. In most cases, this will simply be the example Makefile provided with the skeleton module example code.
## Result
When you run  sudo ./sneaky_process. Using another machine to see the result
1. It will hide the “sneaky_process” executable file from both the ‘ls’ and ‘find’ UNIX commands.
  a. “ls /home/userid/hw5” should show all files in that directory except for “sneaky_process”.
  b. “cd /home/userid/hw5; ls” should show all files in that directory except for “sneaky_process”
  c. “find /home/userid -name sneaky_process” should not return any results
2. In a UNIX environment, every executing process will have a directory under /proc that is named with its process ID (e.g /proc/1480).
3.  It will do this by opening the saved “/tmp/passwd” when a request to open the “/etc/passwd” is seen. For example: a. “cat /etc/passwd” should return contents of the original password file without the modifications the sneaky process made to /etc/passwd.
4.  It will hide the fact that the sneaky_module itself is an installed kernel module. The list of active kernel modules is stored in the /proc/modules file. Thus, when the contents of that file are read, the sneaky_module will remove the contents of the line for “sneaky_mod” from the buffer of read data being returned. For example: 
   a. “lsmod” should return a listing of all modules except for the “sneaky_mod”
