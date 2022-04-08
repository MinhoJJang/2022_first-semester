# R-B TREE

[R-B Tree](https://zeddios.tistory.com/237)

# R-B Tree Rules

1. Root Property : 루트노드의 색깔은 검정(Black)이다.
2. External Property : 모든 external node들은 검정(Black)이다.
3. Internal Property : 빨강(Red)노드의 자식은 검정(Black)이다.
   == No Double Red(빨간색 노드가 연속으로 나올 수 없다.)
4. Depth Property : 모든 리프노드에서 Black Depth는 같다.
