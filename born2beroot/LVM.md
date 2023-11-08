
LVM - Logical Volume Manager
-> 리눅스에서 저장공간을 유연하고 효율적을 관리하기 위한 도구 및 라이브러리 (커널의 부분은 아님)

- 기존 방식
-> 파일시스템이 블록장치에 직접 읽고 쓰기를 수행
- LVM
-> 파일시스템이 LVM이 만든 가상블록에 읽고 쓰기를 수행 -> 이후에  LVM이 블록장치에 읽고 쓰기를 수행

@ 장점
1. 유연한 용량조절 - 가상블록의 크기를 조절가능
2. 크기 조절이 가능한 storage pool - 실제 디스크의 분할된 공간을 가상으로 합쳐서 사용할 수 있음
3. 편의에 따른 장치 이름 지정 - 이름 지정으로 편리하게 관리가 가능
4. disk striping, mirror volume등을 제공 - disk striping은 데이터를 여러 물리적 장치에 분리해서 저장해서 읽고 쓰기를 병렬로 처리할 수 있음, 안정성이 높아짐, 여러 디스크를 논리적으로 하나로 보아서 용량을 확장할 수 있음 / mirror volume은 디스크의 백업을 만들수 있음

# 주요 용어
PV - Physical Volume
-> 실제 하드웨어의 블록장치를 사용하기 위해 LVM에서 사용할 수 있게 변화하는 것 - PE들로 구성됨

PE - Physical Extent
-> PV를 구성하는 일정 크기의 블록 ( 일반적으로는 4MB ) - PE와  LE는 1 : 1 로 대응됨

VG - Volume Group
-> PV들의 집합으로 LV를 할당할 수 있는 공간 - 이 공간을 LV로 할당해서 사용함
![](http://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/11/LVM-03.png)

LV - Logical Volume
-> 사용자가 최종적으로 사용하는 단위 - VG에서 할당받아서 사용함
**#3가지 유형이 존재**
1. 선형 LV ( Linear LV )
![](http://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/11/LVM-05-600x229.png)
=> 하나의 LV에 모든 VG를 모으는 방법

2. Striped LV
![](http://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/11/LVM-06.png)
=> LV에 데이터를 기록하면 LVM에서 PV가 다른 곳들로 분산해서 저장 -> 읽기랑 쓰기 속도가 빨라짐 - 병렬 처리가 가능해짐
=> 번갈아 가면서 쓰는 크기를 스트라이프 크기 라고 함 -> 이 크기는 PE, LE의 크기를 초과할 수 없음

3. Mirrored LV
![](http://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/11/LVM-07.png)
=> 데이터를 저장할 때 복사본은 다른 PV에 저장하는 방식 -> 데이터 보호가 가능

LE - Logical Extent
![](http://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/11/LVM-04.png)

-> LV를 이루는 일정한 단위 - PE와 LE는 1 : 1 로 대응됨

# 쓰는 이유

**기존 방식**
![](http://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/11/LVM-08-600x277.png)

-> 물리디스크를 파티션으로 나누고 이를 OS에 마운트함 -> 근데 특정 디렉토리에 파티션을 마운트 해야됨
=> 문제는 새로운 파티션을 추가할때 새롭게 PV를 만들고 거기에 복사 or 이동 한 다음에 다시 마운트를 진행해야됨 -> 전체적으로 하나로 통째로 마운트 하는 것도 아님

**LVM 방식**
![](http://tech.cloud.nongshim.co.kr/wp-content/uploads/2018/11/LVM-09-600x568.png)

-> 물리디스크를 따로 마운트 하는 게 아니라 하나의 그룹으로 만들어서 거기에서 재할당
=> 기존에는 다시 마운트해야 되는 것이 PV를 VG에 묶으면 끝남