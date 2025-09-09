#include <stdio.h>
#include <string.h>
#include <ctype.h>
# define SIZE 200 //평문, 암호문 길이 제한

int isCoprime(int a) { //a와 26이 서로소인지 판단
	int temp;
	int b = 26;
	// gcd 구하기 : gcd 1이면 서로소
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	if (temp == 1) return 1; //서로소임
	else return 0; //서로소 아님
}

int main(void) {
	char plain[SIZE]; //평문
	char cipher[SIZE]; //암호문
	int len; //문자열 길이
	int key[2]; //키 pair key = (a, b)

	//key 입력받기
	printf("Key1: ");
	scanf_s("%d", &key[0]); //key(a) 입력받기
	while (!isCoprime(key[0])) { //a와 26이 서로소가 아니면 다시 입력받기
		printf("> key1 should be coprime to 26.\n");
		printf("Key1: ");
		scanf_s("%d", &key[0]); //key(a) 입력받기
	}
	printf("Key2: ");
	scanf_s("%d", &key[1]); //key(b) 입력받기
	getchar(); //\n 지우기

	printf("Input: ");
	fgets(plain, sizeof(plain), stdin); //평문 입력받기
	plain[strcspn(plain, "\n")] = '\0'; //끝을 null로 변경
	len = strlen(plain);

	for (int i = 0; i < len; i++) {
		if (isalpha(plain[i])) { //알파벳이면 치환
			if (islower(plain[i])) { //소문자를 대문자로 변경
				plain[i] = toupper(plain[i]);
			}
			cipher[i] = ((plain[i] - 'A')* key[0] + key[1]) % 26 + 'A'; //M*a+b (mod 26)
		}
		else {
			cipher[i] = plain[i]; //알파벳이 아니면 유지
		}
	}
	cipher[len] = '\0'; //암호문 마지막에 null 추가

	printf("Crypto: %s\n", cipher); //결과 출력

	return 0;
}
