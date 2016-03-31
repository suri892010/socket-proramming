#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <iostream>
#include <string>
using namespace std;
#define PORT 8888

int main(int argc, char const *argv[])
{
    if(argc==6)
    {
        int sockfd ,no_clients=3,client_socket[3];
        string password=argv[3],length=argv[4],bits=argv[5];
        struct sockaddr_in my_addr;
        sockfd=socket(PF_INET,SOCK_STREAM,0);
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(PORT);//htons(atoi(argv[2]))
        my_addr.sin_addr.s_addr = INADDR_ANY;//atoi(argv[1])

        if(sockfd==0)
        {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }
        if (connect(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))<0)
        {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        /*char buffer[1025];
        buffer[0]='x';
        buffer[1]='y';*/
        //cout<<"x\n";
        password = password + length + bits;
        send(sockfd,&password,password.length(),0);
        read(sockfd,&password,atoi(argv[3]));
        cout<<"Your password is "<<password;
        close(sockfd);
        /* code */
        return 0;
    }
    else
    {
        puts("correct arguments needed");
        return -1;
    }
}
