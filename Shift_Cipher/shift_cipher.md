# Shift cipher
황제 Julius Caesar가 갈리아 전쟁 중 로마군과 소통하기 위해 사용했던 암호이며, 카이사르 암호라고도 부름.

키 값만큼 알파벳을 이동(shift)시켜 치환하는 고전 암호 방식.

암호키와 복호화키가 동일한 대칭키 암호화 방식(Symmetric Encryption).

- 암호화 : $$C=M+K (mod 26)$$
- 복호화 : $$M=C-K (mod 26)$$
- C(암호문), M(평문), K(키)

여기서 (mod 26) 은 알파벳의 개수(A~Z). 이동시키면서 뒤로 넘어가는 것들을 앞으로 옮기기 위함.

## 예시
키 값이 4라고 하면 다음과 같이 치환된다.
```
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
W X Y Z A B C D E F G H I J K L M N O P Q R S T U V
```
따라서 CRYPTO 는 GVCTXS가 된다.
