# AL_2 - TimeLine

발표 두번째

## 0524

```
work_1 HeapSort
  int 타입 정수에 대하여 내림차순, 오름차순 모두 정상적으로 구현
  수행결과 시간은 time.h 을 사용해 ms 단위로 작업시간 체크 가능
  double 타입과 String 타입에 대하여 확장 필요
  DATA_SIZE를 조정하여 데이터 개수 변경가능
```

## 0526

```
QuickSort 완성

-> MakeInputFile.c 를 실행하면 unSorted.dat 파일이 나온다. 이 파일은 규칙에 따라 랜덤하게 생성된 숫자들을 비 정렬 상태로 저장한 파일이다. 그냥 랜덤 배열이라고 생각하면 된다. 이 배열을 가지고 QuickSort.c를 실행시키면 수행 결과로 몇 ms가 걸렸는지도 체크되고, 정렬된 데이터는 Sorted.dat에 들어가게 된다.
```

~~주의해야할 사항은, MakeInputFile.c와 정렬함수의 `#define DATA_SIZE` 값을 동일하게 맞춰주어야 하고, `typedef (datatype) dataType` 의 경우에도 int와 double을 동시에 변경해주어야 하고 변경할 때 기타 print함수의 출력형식을 반드시 변경해 주어야 한다.~~
--->> 0527 해결
common.h 파일로 한번에 관리할 수 있다.

### Running Time

MakeInputFile.c 내부 함수를 살짝 변경하면, 세가지 형태의 배열을 만들 수 있다.내림차순, 오름차순, 랜덤.

이때, QuickSort의 경우 랜덤 배열인 상황에서는 HeapSort보다 더 나은 성능을 보여주지만, 내림차순 혹은 오름차순일 경우 최악의 성능을 보여준다.

1. 내림차순 배열일 경우

QuickSort가 200배 이상 느리다

```
QuickSort
Random Based Array - QuickSort (size: 50000) Running Time: 2531880 ms
Sorted Well! :)

HeapSort
Random Based Array - HeapSort (size: 50000) Running time: 10488 ms
Sorted Well! :)
```

2. 오름차순 배열일 경우

QuickSort가 300배 이상 느리다

```
QuickSort
Random Based Array - QuickSort (size: 50000) Running Time: 2426996 ms
Sorted Well! :)

HeapSort
Random Based Array - HeapSort (size: 50000) Running time: 7455 ms
Sorted Well! :)
```

3. 랜덤 배열일 경우

QuickSort가 약간 빠르다.

```
QuickSort
Random Based Array - QuickSort (size: 50000) Running Time: 6067 ms
Sorted Well! :)

HeapSort
Random Based Array - HeapSort (size: 50000) Running time: 11937 ms
Sorted Well! :)
```

이는 QuickSort의 방식이 분할정복 방식이기 때문인데, 한쪽으로 정렬될 경우 분할이 되지 않으니 10번 하면 되는 것을 1000번 해야 한다. 그러나 HeapSort의 경우 모든 경우에도 평균적인 속도를 보여준다.

## 0527

common.h 파일로 전체 정렬함수 관리

```
// 여기만 int, double로 변경
typedef double dataType;
```

저거 하나만 바꿔주면 자동으로 데이터타입이 전부 바뀌게 만들어놓았다.

그래프 그리기 성공
[GeoGebra_graph](https://www.geogebra.org/calculator/uqv7qsu9)
