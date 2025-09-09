#include <stdio.h>
#include <string.h>
#include <ctype.h>
# define SIZE 200 //입력 문자열 길이 제한


int main(void) {
	char plain[SIZE]; //평문
	char cipher[SIZE]; //암호문
	int len; //문자열 길이
	int key; //shift 키

	printf("Key: ");
	scanf_s("%d", &key); //key 입력받기
	getchar(); //\n 지우기

	printf("Input: ");
	fgets(plain, sizeof(plain), stdin); //평문 입력받기
	plain[strcspn(plain, "\n")] = '\0'; //끝을 null로 변경
	len = strlen(plain);

	for (int i = 0; i < len; i++) {
		if (isalpha(plain[i])) { //알파벳이면 shift
			if (islower(plain[i])) { //소문자를 대문자로 변경
				plain[i] = toupper(plain[i]);
			}
			cipher[i] = (plain[i] - 'A' + key) % 26 + 'A'; //shift 수행
		}
		else {
			cipher[i] = plain[i]; //알파벳이 아니면 유지
		}
	}
	cipher[len] = '\0'; //암호문마지막에 null 추가

	printf("Crypto: %s\n", cipher); //결과 출력

  return 0;
}
