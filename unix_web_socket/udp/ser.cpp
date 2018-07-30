/*
 *************************************************************************
 *    File Name:  ser.cpp
 *       Author: Thomas Beijing,Inc.
 *         Mail: 982737593@qq.com
 * Created Time: 2018年07月19日 星期四 10时32分35秒
 * 
 *  Description: ...
 * 
 *************************************************************************
*/
#include<iostream>
#include <sys/socket.h>
#include <sys/types.h> 
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main()
{
    struct sockaddr_in servaddr, cliaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(9001);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
    if(sockfd < 0)
        std::cout << "sockfd < 0" << sockfd << std::endl;
    int ret = bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    if(ret < 0)
        std::cout << "123213" << std::endl;

    socklen_t len = sizeof(cliaddr);
    char buff[10];
    while(1)
    {
        int length = recvfrom(sockfd, buff, 10, 0, (struct sockaddr *)&cliaddr, &len);
        std::cout << "length:"   << length << std::endl;
        std::cout << "recvfrom:" << buff << std::endl;
    }
    
    return 0;
}
