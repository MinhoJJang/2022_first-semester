# Error

sqrt 오류 이유는 모르겠음 gcc 문제인듯

[https://codingcoding.tistory.com/990](https://codingcoding.tistory.com/990)

```
prime.c:(.text+0x1c): undefined reference to `sqrt'
```

compile error occurs

-> plus -lm!
gcc test.c -o test -lm

정상적으로 작동함
