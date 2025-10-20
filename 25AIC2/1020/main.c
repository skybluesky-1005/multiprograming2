#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>;

struct Fish
{
	char* name;
	
	char* talk;
	int answer;

	char* talk_O;
	char* talk_X;
};

int main()
{
	struct Fish fish[5];

	fish[0].name = "붕어";
	fish[1].name = "연어";
	fish[2].name = "메기";
	fish[3].name = "쏘가리";
	fish[4].name = "가물치";
	fish[0].talk = "문제1";
	fish[1].talk = "문제2";
	fish[2].talk = "문제3";
	fish[3].talk = "문제4";
	fish[4].talk = "문제5";
	fish[0].answer = 3;
	fish[1].answer = 2;
	fish[2].answer = 4;
	fish[3].answer = 5;
	fish[4].answer = 1;
	fish[0].talk_O = "붕어를 잡았다";
	fish[1].talk_O = "연어를 잡았다";
	fish[2].talk_O = "메기를 잡았다";
	fish[3].talk_O = "쏘가리를 잡았다";
	fish[4].talk_O = "가물치를 잡았다";
	fish[0].talk_X = "붕어를 놓쳤다";
	fish[1].talk_X = "연어를 놓쳤다";
	fish[2].talk_X = "메기를 놓쳤다";
	fish[3].talk_X = "쏘가리를 놓쳤다";
	fish[4].talk_X = "가물치를 놓쳤다";

	char yn;
	int answer = 0;
	int random = 0;
	
	// 찌 던지기 입력 받는 부분
	while (1)
	{
		printf("찌를 던진다(Y/N): ");
		if (scanf(" %c", &yn) != 1) 
		{
			// 입력 실패 처리
			while (getchar() != '\n'); // 버퍼 비우기
			continue;
		}
		if (yn == 'Y' || yn == 'y') 
		{
			break;
		}
		else if (yn == 'N' || yn == 'n') 
		{
			return 0;
		}
		else 
		{
			printf("잘못된 입력입니다. Y 또는 N을 입력하세요.\n");
		}
		while (getchar() != '\n'); // 버퍼 비우기
	}

	srand(time(NULL));
	random = rand() % 5;
	int n = random;

	printf(".....\n"); //500마다 찍힘

	printf("%s : %s\n", fish[n].name, fish[n].talk); //물고기 이름 ,질문

	scanf("%d", &answer);
	while (getchar() != '\n'); // 버퍼 비우기
	printf("입력한 숫자: %d\n", answer);

	if (fish[n].answer == answer) printf("%s\n", fish[n].talk_O);
	if (fish[n].answer != answer) printf("%s\n", fish[n].talk_X);
	return 0;
}