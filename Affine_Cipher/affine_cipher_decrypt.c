#include <stdio.h>
#include <string.h>
#include <ctype.h>
# define SIZE 200 //평문, 암호문 길이 제한

int isCoprime(int a) { //a와 26이 서로소인지 판단
	int temp;
	int m = 26;
	// gcd 구하기 : gcd 1이면 서로소
	while (m != 0) {
		temp = m;
		m = a % m;
		a = temp;
	}
	if (temp == 1) return 1; //서로소임
	else return 0; //서로소 아님
}

/* 역원 존재 : gcd(a, m) == 1
없으면 -1 반환, 있으면 [0, m-1] 범위의 역원 반환
정수론과 친하지 않은 관계로 이 부분은 gpt한테 SOS 쳤음 */
int modinv_iter(int a) {
	const int m = 26;   // 알파벳 개수 (고정된 모듈러스)

	int r0, r1, r2; // 나머지들
	int t0, t1, t2; // a의 계수 추적용 (베주 계수)
	int q; // 나눗셈 몫

	// 초기화
	r0 = m;
	r1 = a % m; // r1 = a mod m
	if (r1 < 0) r1 += m; // 음수라면 양수로 보정

	t0 = 0; // r0 = m*1 + a*0  -> a의 계수는 0
	t1 = 1; // r1 = m*0 + a*1  -> a의 계수는 1

	// 유클리드 호제법 반복
	while (r1 != 0) {
		q = r0 / r1; // 몫 q

		r2 = r0 - q * r1; // 다음 나머지 r2 = r0 - q*r1
		r0 = r1; // 값 갱신
		r1 = r2;

		t2 = t0 - q * t1; // a의 계수도 같은 방식으로 갱신
		t0 = t1;
		t1 = t2;
	}

	// 반복 끝났을 때 r0 = gcd(a, m)
	if (r0 != 1) return -1;     // gcd가 1이 아니면 역원 없음

	// t0가 a의 역원 (베주 계수)
	if (t0 < 0) t0 += m;        // 음수면 양수로 보정
	return t0;
}

int main(void) {
	char plain[SIZE]; //평문
	char cipher[SIZE]; //암호문
	int len; //문자열 길이
	int key[2]; //키 pair key = (a, b)
	int ainv; //모듈로 역원

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
	fgets(cipher, sizeof(plain), stdin); //암호문 입력받기
	cipher[strcspn(cipher, "\n")] = '\0'; //끝을 null로 변경
	len = strlen(cipher);

	ainv = modinv_iter(key[0]);
	if (ainv == -1) {
		fprintf(stderr, "Error: modular inverse not found\n");
		return 1;
	}

	for (int i = 0; i < len; i++) {
		if (isalpha(cipher[i])) { //알파벳이면 치환
			if (islower(cipher[i])) { //소문자를 대문자로 변경
				cipher[i] = toupper(cipher[i]);
			}
			plain[i] = (char)(((ainv * ((cipher[i] - 'A') - key[1] + 26)) % 26) + 'A'); //a^-1 * (C-b) (mod 26)
		}
		else {
			plain[i] = cipher[i]; //알파벳이 아니면 유지
		}
	}
	plain[len] = '\0'; //암호문 마지막에 null 추가

	printf("Message: %s\n", plain); //결과 출력

	return 0;
}
