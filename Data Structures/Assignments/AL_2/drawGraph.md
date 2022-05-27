# Graph그리기 위한 데이터 저장

각 n에 대하여, 각 Sort 함수를 100번 실행한 시간의 평균이다.

## level_1: postive numbers

| n / ms | BubbleSort | InsertionSort | SelectionSort | HeapSort | QuickSort |
| ------ | ---------- | ------------- | ------------- | -------- | --------- |
| 10     | 0          | 0             | 0             | 0        | 0         |
| 100    | 17         | 6             | 10            | 5        | 3         |
| 1000   | 1459       | 577           | 1022          | 119      | 39        |
| 3000   | 12705      | 4925          | 8811          |          |           |
| 5000   | 36636      | 13161         | 24699         |          |           |
| 7000   | 75581      | 25732         | 46764         |          |           |
| 10000  | 169184     | 59141         | 94234         | 1462     | 1001      |
| 100000 | 30157122   | 5240318       | 9325306       | 17654    | 12424     |
| 600000 | timeOut    | timeOut       | timeOut       | 134480   | 84603     |

SpLine({(10, 0), (100, 17), (1000, 1459), (3000, 12705), (5000, 36636),(7000, 75581), (10000, 169184)})
SpLine({(10, 0), (100, 6), (1000, 577), (3000, 4925), (5000, 13161),(7000, 25732),(10000, 59141)})
SpLine({(10, 0), (100, 10), (1000, 1022), (3000, 8811), (5000, 24699),(7000, 46764),(10000, 94234)})
SpLine({(10, 0), (100, 5), (1000, 119), (10000, 1462), (100000, 17654), (600000, 134480)})
SpLine({(10, 0), (100, 3), (1000, 39), (10000, 1001), (100000, 12424), (600000, 84603)})

## level_2: integers

| n / ms | BubbleSort | InsertionSort | SelectionSort | HeapSort | QuickSort |
| ------ | ---------- | ------------- | ------------- | -------- | --------- |
| 10     | 0          | 0             | 0             | 0        | 0         |
| 100    | 13         | 6             | 10            | 5        | 3         |
| 1000   | 1558       | 566           | 1037          | 89       | 38        |
| 10000  | 169184     | 59141         | 94234         | 1462     | 1001      |
| 100000 | 30157122   | 5240318       | 9325306       | 17654    | 12424     |
| 600000 | timeOut    | timeOut       | timeOut       | 134480   | 84603     |