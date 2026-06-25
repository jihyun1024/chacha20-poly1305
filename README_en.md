# chacha20-poly1305
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