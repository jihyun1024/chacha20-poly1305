[English](#english) | [한국어](#korean)

# English
This library is portable implementation of ChaCha20-Poly1305:
- ChaCha20: Stream cipher
- Poly1305: Universal hash family designed by Daniel J.Bernstein in 2002

It's much faster and more efficient than AES-GCM in the following environments:
- Low-power CPUs
- Lightweight environments like mobile or embedded systems
- Environments where you can't directly use the host's hardware AES acceleration, like Docker containers or virtual machines

# Description
ChaCha20-Poly1305 algorithm takes as input a 256-bit key and a 96-bit nonce to encrypt a plaintext, with a ciphertext expansion of 128-bit(tag size).

ChaCha20 is used to derive a key stream that is XORed with the plaintext. The ciphertext and the associated data is then authenticated using a variant of Poly1305 that first encodes the two strings into one. 

# Use 
This algorithm can be used in IPsec, SSH, TLS 1.2, DTLS 1.2, TLS 1.3, WireGuard, S/MIME 4.0, OTRv4 and multiple other protocols and implemented in OpenSSL and libsodium. 

# License
Apache License Version 2.0, January 2004, http://www.apache.org/licenses/

# Korean
이 라이브러리는 ChaCha20-Poly1305의 구현입니다:
- ChaCha20: 스트림 암호
- Poly1305: 2002년에 Daniel J. Bernstein이 설계한 범용 해시 계열

다음 환경에서 AES-GCM보다 훨씬 빠르고 효율적입니다:
- 저전력 CPU
- 모바일 환경, 임베디드 시스템 등 가벼워야 되는 환경
- Docker 컨테이너나 가상 머신 등 호스트의 하드웨어 AES 가속 기능을 직접 쓰지 못하는 환경

# 간략한 설명
ChaCha20-Poly1305 알고리즘은 평문을 암호화하기 위해 256비트 키와 96비트 논스(Nonce)를 입력으로 사용하며, 암호문은 128비트(태그 크기)만큼 확장됩니다.

ChaCha20는 평문과 XOR 연산을 수행할 키 스트림을 생성하는 데 사용됩니다. 그 후 암호문과 연관 데이터는 먼저 두 문자열을 하나로 인코딩하는 Poly1305의 변형을 사용하여 인증됩니다.

# 이 알고리즘을 사용하는 프로토콜
이 알고리즘은 IPsec, SSH, TLS 1.2, DTLS 1.2, TLS 1.3, WireGuard, S/MIME 4.0, OTRv4 및 여러 다른 프로토콜에서 사용할 수 있으며, OpenSSL과 libsodium에 구현되어 있습니다.

# 라이선스
Apache License Version 2.0, January 2004, http://www.apache.org/licenses/