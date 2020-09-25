#include <iostream>
#include <cstdio> // for perror()
#include <sys/wait.h> // for wait()
#include <unistd.h> // for execvp()

void printArgs(int argc, char* argv[]) { // reusable print function
  for (int i = 0; i < argc; i++) {
	   std::cout << argv[i] << ' '; // needs spacing between args
  }
}

// new parameter for main(): int argc, char* argv
// argc is number of args, argv is the actual args
int main(int argc, char* argv[])
{
	printArgs(argc, argv); // print args

	pid_t process; // get process identification object

	process = fork(); // fork the process we made

 	if (process < 0) {  // if fork == -1
		 perror(argv[0]); // perror with command used in args
     exit(1);
  }

	// child process is 0
	if (process == 0) {
		int pid = getpid(); //getpid returns pid number
		std::cout << "Child process pid is " << pid << std::endl; // output
		execvp(argv[1], &argv[1]); // execute args
    if ((execvp(argv[1], &argv[1])) < 0) {  // if execvp == -1
		    perror(argv[0]);
        exit(1);
    }
	} else {  // parent process > 0
		wait(NULL);  // wait for child process to stop
		int pid = getpid();
		std::cout << "Parent process pid is " << pid << std::endl;
	}

	return 0;
}
