# 기본 변수 설정
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -O2
LDFLAGS =

# 빌드 출력 파일
TARGET = test_vectors

# 소스 파일 목록
SRC = test_vectors.c chacha20.c
OBJ = $(SRC:.c=.o)

# 기본 빌드 규칙 (mingw32-make 명령으로 빌드 가능)
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

test: all

# 객체 파일 생성 규칙
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 실행 규칙 (mingw32-make run 명령으로 실행 가능)
run: $(TARGET)
ifeq ($(OS),Windows_NT)
	.\$(TARGET)$(EXEEXT)
else
	./$(TARGET)
endif

# 정리 규칙
clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all test run clean