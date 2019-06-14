#include <stdio.h>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <clocale>
#include <chrono>

void* FirstOfPlayer(void* NULLdata);
void* SecondOfPlayer(void* NULLdata);

int FirstPlayer, SecondPlayer;

enum states{WaitConnectPlayer, Win, Lose, Combat, WaitTheEndPlayer};

struct StateForClient
{	
	int16_t type = static_cast<int16_t>(state_for_client);
	int16_t state;
};

states StateFirstPlayer, StateSecondPlayer;

int main()
{
	setlocale(LC_ALL, "Russian");

	int16_t StateFP, StateSP;

	int ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(ServerSocket < 0)
	{
		perror("socket");
		exit(1);
	}

	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(2048);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(ServerSocket, (struct sockaddr*)(&addr), sizeof(addr));

	listen(ServerSocket, 2);

	FirstPlayer = accept(ServerSocket, 0, 0);
	
	if(FirstPlayer > 0)
	{
		std::cout << "Первый игрок подключился." << std::endl;

		StateFirstPlayer = WaitConnectPlayer;

		int16_t StateForFP = static_cast<int16_t>(StateFirstPlayer);

		send(ServerSocket, StateForFP, sizeof(int16_t), MSG_NOSIGNAL);
	}

	SecondPlayer = accept(ServerSocket, 0, 0);

	if(SecondPlayer > 0)
	{
		std::cout << "Второй игрок подключился." << std::endl;
	}

	pthread_t FPlayer;
	pthread_t SPlayer;

	void* NULLdata = NULL;
	pthread_create(&FPlayer, NULL, FirstOfPlayer, NULLdata);
	pthread_create(&SPlayer, NULL, SecondOfPlayer, NULLdata);

	pthread_join(FPlayer, NULL);
	pthread_join(SPlayer, NULL);

	return 0;
}

void* FirstOfPlayer(void* NULLdata)
{
	bool goal = true;
	bool not_goal = false;

	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			if(goal)
			{

			}

			if(not_goal)
			{

			}
		}
	}
}

void* SecondOfPlayer(void* NULLdata)
{
	bool goal = true;
	bool not_goal = false;

	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			if(goal)
			{

			}

			if(not_goal)
			{

			}
		}
	}
}
