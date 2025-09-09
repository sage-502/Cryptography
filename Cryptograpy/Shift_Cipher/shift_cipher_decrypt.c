#include <stdio.h>
#include <string.h>
#include <ctype.h>
# define SIZE 200 //평문, 암호문 길이 제한

int main(void) {
	char plain[SIZE]; //평문
	char cipher[SIZE]; //암호문
	int len; //문자열 길이
	int key; //shift 키

	printf("Key: ");
	scanf_s("%d", &key); //key 입력받기
	getchar(); //\n 지우기

	printf("Input: ");
	fgets(cipher, sizeof(cipher), stdin); //암호문 입력받기
	cipher[strcspn(cipher, "\n")] = '\0'; //끝을 null로 변경
	len = strlen(cipher);

	for (int i = 0; i < len; i++) {
		if (isalpha(cipher[i])) { //알파벳이면 shift
				plain[i] = (cipher[i] - 'A' - key + 26) % 26 + 'A'; //shift 수행
		}
		else {
			plain[i] = cipher[i]; //알파벳이 아니면 유지
		}
	}
	plain[len] = '\0'; //평문 마지막에 null 추가

	printf("Message: %s\n", plain); //결과 출력

  return 0;
}
