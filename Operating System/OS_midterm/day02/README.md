# day02

03/07 Mon

## 과제1

[https://computer.howstuffworks.com/computer-memory1.htm](https://computer.howstuffworks.com/computer-memory1.htm)
이곳에서 아래 4가지 질문에 답할 수 있게 공부해올 것..

### Why do we need RAM to store data, when we already have hard disk?

메모리는 빠르지만 너무 비싸고, 하드디스크는 느리지만 용량이 크다. 현재 CPU의 데이터 처리 속도를 메모리로만 따라잡으려면 어마어마한 양의 메모리가 필요한데, 이는 비용적으로 합리적이지 않다. 따라서 메모리로 속도를 챙기고, 하드디스크로 용량을 챙겨야 하기 때문에 램과 하드디스크 등등이 모두 필요하다.

### What happens when you turn your computer on until you shut down?

<번역본 참고>

컴퓨터는 읽기 전용 메모리(ROM)에서 데이터를 로드하고 전원 투입 시 자가 테스트(POST)를 수행하여 모든 주요 구성 요소가 제대로 작동하는지 확인합니다. 이 테스트의 일환으로 메모리 컨트롤러는 빠른 읽기/쓰기 작업으로 모든 메모리 주소를 검사하여 메모리 칩에 오류가 없는지 확인합니다. 읽기/쓰기는 데이터가 비트에 쓰인 다음 해당 비트에서 읽히는 것을 의미합니다.

컴퓨터는 ROM에서 기본 입출력 시스템(BIOS)을 로드합니다. BIOS는 스토리지 장치, 부팅 순서, 보안, 플러그 앤 플레이(자동 장치 인식) 기능 및 기타 몇 가지 항목에 대한 가장 기본적인 정보를 제공합니다.

컴퓨터는 운영 체제(OS)를 하드 드라이브에서 시스템의 RAM으로 로드합니다. 일반적으로 운영 체제의 중요한 부분은 컴퓨터가 켜져 있는 한 RAM에 유지됩니다. 이를 통해 CPU는 운영 체제에 즉시 액세스할 수 있으므로 전체 시스템의 성능과 기능이 향상됩니다.

응용 프로그램을 열면 RAM에 로드됩니다. RAM 사용량을 절약하기 위해 많은 응용 프로그램은 처음에는 프로그램의 필수 부분만 로드한 다음 필요에 따라 다른 부분만 로드합니다.

응용 프로그램이 로드되면 해당 응용 프로그램에서 사용하기 위해 열려 있는 모든 파일이 RAM에 로드됩니다.

파일을 저장하고 응용 프로그램을 닫으면 파일이 지정된 저장 장치에 기록된 다음 RAM에서 해당 파일과 응용 프로그램이 삭제됩니다.

### Why are there so many memory systems?

속도가 빠를수록 비싸기 때문에, 가격의 합리성을 위해 적절한 크기의 메모리, 캐시, 하드디스크 등을 사용해서 저장 공간과 속도를 모두 확보하기 위해서이다.

### What are cache and Registers?

레지스터는 CPU에 직접 내장된 메모리 셀이다. CPU에 필요한 특정 데이터, 특히 ALU(산술 및 논리 유닛)이 포함되어 있다. 캐시는 CPU 근처에 있는 메모리 카드에 위치하며 레벨2 캐시는 CPU에 직접 연결된다. 이는 CPU에서 가장 자주 사용하는 데이터를 즉시 사용할 수 있도록 해 준다.

## 과제2

Linux vim(vi)에서 C언어로 Hello World 출력하고 제출하기

-> vim 다루는 법 공부하기