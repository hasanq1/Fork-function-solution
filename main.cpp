//
//  main.cpp
//  fork
//
//  Created by Hasan Qureshi on 9/22/19.
//  Copyright © 2019 Hasan Qureshi. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main()
{


   for(int i =0; i<4;i++){
        pid_t pid = fork();
        
        if (pid == 0)   // Code of the child process
        {
          if ((i%2)!=0){
              pid=fork();
                if (pid != 0)       // wait for the child processes with children
                {
                    for (int j = 0; j <4 - i; j++)
                        wait(0);
                }
                        if (pid == 0)       // code of the grandchild processes
                        {
                            pid=fork();
                         cout << "I am a grandchild process" << endl;
                         _exit(0);
                        }
            }
            sleep(1);
            cout << "I am a child process" << endl;
            _exit(0);
        }
    }
    // code of the parent process
    for (int i = 0; i < 4; i++)
        wait(0);
    cout << "I am the parent process" << endl;
    return 0;
}

