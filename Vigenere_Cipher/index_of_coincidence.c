#include <stdio.h>
#include <string.h>


int main(void) {
	char msg[200]; //입력받을 문자열
	int len; //문자열 길이
	int alpha[26] = { 0, }; //알파벳 빈도수
	float IC = 0; //index of coincidence
	int expt = 0; //알파벳 외의 문자
	int N; //글자 수

	printf("Input: ");
	fgets(msg, sizeof(msg), stdin); //입력받기
	msg[strcspn(msg, "\n")] = '\0'; // 줄바꿈 제거
	len = strlen(msg);

	//알파벳 빈도수 세기
	for (int i = 0; i < len; i++) {
		if (msg[i] >= 'A' && msg[i] <= 'Z') {
			alpha[msg[i] - 'A']++;
		}
		else if (msg[i] >= 'a' && msg[i] <= 'z') {
			alpha[msg[i] - 'a']++;
		}
		else
			expt++;
	}

	
	//IC 구하기 : 합산{각 알파벳 빈도*(각 알파벳 빈도-1)}/{총 알파벳 수*(총 알파벳 수-1)}
	N = len - expt;
	for (int i = 0; i < 26; i++) {
		IC += alpha[i] * (alpha[i] - 1);
	}
	IC /= (float)N * (N - 1);

	printf("IC : %.4f\n", IC); //결과 출력
}
