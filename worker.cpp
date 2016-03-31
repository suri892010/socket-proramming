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
#include <stdio.h>
#include <time.h>
#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define PORT 8888
   char *password;
   string x;
  //char salt[] = "$1$........";

int permute(char set[],int n,int size,char *str)
{
 
   if(n==0){
    cout<<str<<endl;
        string y=crypt(str,"aa");
        //cout<<y<<endl;
    if(x==y){cout<<str<<endl;
      return 0;}
      return -1;
   }
   else
   {
 
           for(int j=0;j<size;j++)
           {
            str[n-1]=set[j];
            if(permute(set,n-1,size,str)==0){
              return 0;
            }
           }
 
   }
 
}
int main(int argc, char const *argv[])
{
    if(argc==3)
    {
        int sockfd ,no_clients=3,client_socket[3],valread;
        string password,length,bits;
        int n,bit;
    	char * str;
        struct sockaddr_in my_addr;
        sockfd=socket(PF_INET,SOCK_STREAM,0);
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(PORT);//htons(atoi(argv[2]))
        my_addr.sin_addr.s_addr = INADDR_ANY;//atoi(argv[1])
        int addrlen = sizeof(my_addr);

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
        char buff[1];
        buff[0]='x';
        //*/
        //cout<<"x\n";
        //password = password + length + bits;
        //send(sockfd,&password,password.length(),0);
        //read(sockfd,&password,atoi(argv[3]));
        //cout<<"Your password is "<<password;
        send(sockfd,buff,1,0);

        char buffer[1025];
        while(true)
        {
            if ((valread = read( sockfd , buffer, 1024)) == 0)
            {
                getpeername(sockfd , (struct sockaddr*)&my_addr , (socklen_t*)&addrlen);
                printf("Server disconnected , ip %s , port %d \n" , inet_ntoa(my_addr.sin_addr) , ntohs(my_addr.sin_port));

                close( sockfd );
                break;
            }
            else
            {
                if(buffer[0]=='x')
                {
                    read( sockfd , &password, password.length());
                    bits=password.substr(password.length()-3,password.length()-1);
                    length=password.substr(password.length()-4,password.length()-4);
                    x=password.substr(0,password.length()-5);
                    string::size_type sz;
                    n=atoi(length.c_str());
                    bit=atoi(bits.c_str());
    				str=(char *)malloc(sizeof(char)*n);
  char set1[]={'1','2','3','4','5','6','7','8','9','0'};
  char set2[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char set3[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      char set4[]={'1', '2','3','4','5','6','7','8','9','0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char set5[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','1', '2','3','4','5','6','7','8','9','0'};
    char set6[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char set7[]={'1', '2','3','4','5','6','7','8','9','0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  switch(bit){
    case 001 :
      permute(set1,n,(sizeof(set1)/sizeof(char)),str);
      break;
    case 010 :
    permute(set2,n,(sizeof(set2)/sizeof(char)),str);
      break;
    case 100 :
     permute(set3,n,(sizeof(set3)/sizeof(char)),str);
      break;
    case 011 :
    permute(set4,n,(sizeof(set4)/sizeof(char)),str);
    break;
    case 101 :
    permute(set5,n,(sizeof(set5)/sizeof(char)),str);
    break;
    case 110 :
    permute(set6,n,(sizeof(set6)/sizeof(char)),str);
    break;
    default :
    permute(set7,n,(sizeof(set7)/sizeof(char)),str);
  }//*/
                }
            }
        };
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
