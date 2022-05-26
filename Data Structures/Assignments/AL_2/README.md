# AL_2 - TimeLine

## 0524

```
work_1 HeapSort
  int 타입 정수에 대하여 내림차순, 오름차순 모두 정상적으로 구현
  수행결과 시간은 time.h 을 사용해 ms 단위로 작업시간 체크 가능
  double 타입과 String 타입에 대하여 확장 필요
  DATA_SIZE를 조정하여 데이터 개수 변경가능
```

```
work_2 else...
QuickSort와 Insertion, Selection, Bubble은 주석보고 수정하면 사용가능
```

## 0526

```
QuickSort 완성

-> MakeInputFile.c 를 실행하면 unSorted.dat 파일이 나온다. 이 파일은 규칙에 따라 랜덤하게 생성된 숫자들을 비 정렬 상태로 저장한 파일이다. 그냥 랜덤 배열이라고 생각하면 된다. 이 배열을 가지고 QuickSort.c를 실행시키면 수행 결과로 몇 ms가 걸렸는지도 체크되고, 정렬된 데이터는 Sorted.dat에 들어가게 된다.

> 주의해야할 사항은, MakeInputFile.c와 정렬함수의 `#define DATA_SIZE` 값을 동일하게 맞춰주어야 하고, `typedef (datatype) dataType` 의 경우에도 int와 double을 동시에 변경해주어야 하고 변경할 때 기타 print함수의 출력형식을 반드시 변경해 주어야 한다.
```
