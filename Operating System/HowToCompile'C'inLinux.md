# Compile

```
gcc [소스파일] -o [실행파일 이름]

ex)
gcc test.c -o test
```

만약 sqrt 함수, math.h 를 사용중이라면
gcc test.c -o test -lm

뒤에 -lm을 붙여준다.

# Execute

```
./[실행파일 이름]

ex)
./test
```
