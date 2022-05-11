1. Is the “safe sequence” order in Banker’s Algorithm and the “CPU scheduling”
   order the same or different? Explain why.

Banker Algorithm은 실제로 사용하지 않는 프로세스까지도 생각해야 하는 반면, 스케줄링 기법은 그 당시에 가장 최적인 프로세스를 선택하여 실행하게 된다. safe sequence는 가장 최악의 경우에도 해당 프로세스를 실행시킬 수 있는 상태인 것을 찾아 순서대로 release 하여 모든 프로세스가 안전하게 종료시킬 수 있는

2. In class, we discussed that “OS view of cache is same as main memory.”
   Explain what this means, and the reason why it is the same.

캐시 메모리는 컴퓨터 구조적으로 좀 더 빠른 속도 향상을 위해 만든 것이지 OS가 결정하는 부분이 아니다.

3. In class, we gave two reasons why paging is used: transparency, no external
   fragmentation. Explain each reason.

transparency는 유저가 메모리를 할당할 때, Logical address 만을 보고 할당하기 때문에 physical address로 갔을 때 기존의 메모리와 문제를 일으키지 않는다.

4. If TLB access time=1ns, Memory access time=200ns, TLB hit ratio=90%,
   then what is the EAT?

401 - 200a = 221;
