# 패키지
package - 소프트웨어를 실행하는데 필요한 파일들(실행 파일, 설정 파일, 라이브러리 등)이 담겨 있는 설치 파일 묶음
-> 윈도우에서는 zip이나 .msi로 지원을 함 / Linux에서는 package라는 것으로 지원

__이전 문제점__
-> A파일을 설치하기 위해 tar, gzip으로 파일을 가져와서 컴파일해서 실행
-> A를 위해 B가 필요하면 B를 설치하고 A를 설치해야됨 (의존성 문제)

__패키지 종류
1. source package -> source 파일들을 묶어 놓은 package - 컴파일 과정이 필요함
2. binary package -> 이미 컴파일 된 binary 파일들을 묶어 놓은 package - 컴파일 필요 X
	=> 컴파일 된 환경과 실제 환경이 다를 때 문제가 발생할 수 있음
	ex) 특정 라이브러리가 필요한데 없으면 실행이 안됨 or 다른 파일들이 필요한데 없으면 실행이 안됨
		-> 이 문제를 ==패키지 의존성== 문제라고 함
=> 대부분이 binary package로 지원함 - 수정이 필요할 때는 source package도 사용

__패키징 방식
- Debian 계열 -  ".deb"
- Red Hat 계열 - ".rpm"

@여기에서 사용하는 패키지 관리 시스템
- Low-level Package Tool -> Debian = dpkg / Red Hat = rpm -> 의존성 확인 X
- High-level Package Tool -> Debian = apt-get, apt, aptitude / Red Hat = yum, dnf -> 의존성 확인 O

__패키지 설치 과정__
sudo apt install python3 - 이런 식으로 명령어를 실행
-> _etc/apt/source.list_ 에 원격 repository에 있는 package를 받아옴
-> package에 의존성을 확인하고 필요한 파일들을 설치함
=> package에 대하 메타 정보들은 로컬 cache에 존재 - 이를 통해서 원격 repository에서 다운받아서 설치
-> 모든 package가 존재하는 것은 아님
@ 단, dpkg와 rpm은 그런 방식이 아니라 로컬에서 가지고 있는 패키지를 설치,삭제 하는 것임
# sudo
Super User DO / Substitute User DO의 약자
=> 유닉스 및 리눅스 계열에서 다른 유저의 권한을 가지고 작업을 할 수 있게 하는 명령어

@ etc/sudoers파일에 지정된 사용자만 sudo명령어를 사용 가능

@ su 명령어는 유저를 바꾸는 것임

__#쓰는 이유__
root는 시스템의 모든 권한을 가지고 있음
1.  root에서 무엇인가를 작업하면 보안 부분에서 굉장히 위험함
-> sudo를 이용하면 해당 권한만 이용해서 작업이 가능함
-> su를 이용해서 root에서 작업을 할 때 한순간에 실수로 시스템이 날라갈 수도 있음 ( ex, rm -rf all) 과 같은 문제
=> ==sudo rm -rf all 도 전체가 다 삭제됨 ( 주의해야 됨 )== 그래도 명령어를 sudo라고 해야 되니까 조금이라도 생각할 수 있음
2. sudo로 한 명령어는 log가 남음
-> 보안적으로 확인이 가능함



# dpkg
Debian 계열 패키지 관리의 기본이 되는 소프트웨어
".deb" 파일의 설치, 삭제, 정보 제공을 수행하는 소프트웨어

@가장 저레벨의 패키지 관리 소프트웨어
-> ==의존성 문제를 해결 못함== -> 그냥 패키지를 설치, 삭제만 함
=> 이러한 문제로 apt, apt-get, aptitude 등을 사용해서 의존성 문제를 해결하는 것임
# APT
APT = Advanced Package Tool
-> ==Dedian== 계열의 LINUX에서 사용되는 패키지 관리 시스템 (사용자 친화적 - 대화형)
-> apt-get, apt-cache, dpkg -l 에서 자주 쓰는 부분들을 합쳤다고 보면 편함
- apt-get : 패키지 설치, 업데이트 및 제거
- apt-cache : 패키지 조회
- dpkg -l : 시스템에 설치된 패키지 조회 => dpkg는 apt보다 낮은 단계의 패키지 관리 시스템임

@ apt가 apt-get보다 상위 레벨의 시스템임 - apt가 보다 사용자 친화적임( apt-get이 먼저 나옴 )
=> apt가 사용자 친화적인 만큼 사용자에게 물어보는 게 많음

@ apt-get과 apt-cache에서 필요한 부분들을 합쳐서 apt를 만듦
__apt-get이 low-level과 script 작성 측에서는 더 많은 옵션을 줄 수 있음__
=> ==script 작성에서는 apt-get, apt-cache를 쓰는 게 더 좋음== ( 설치 과정에서 문제나 메세지가 나타날 수 있는데 apt-get의 경우에는 -y옵션으로 자동적으로 넘길 수 있음, 근데 apt는 그게 안됨 )

@apt를 실행하기 위해서는 sudo 권한을 가져야함 - package 설치 관련해서 권한들이 필요함

@dpkg와 rpm을 제외하고는 인터넷 연결이 있어야 함 -> 애초에 외부 레포지토리에서 패키지를 다운받아서 설치함

# Aptitude
Apt의 프론트엔드 프로그램으로 볼 수 있음
apt보다 상위레벨의 패키지 매니저라고도 할 수 있음

__Apt랑 Aptitude의 차이점__
1. Aptitude가 보다 유저 친화적인 인터페이스를 가짐
2. apt보다 효율적으로 의존성 해결책을 제시함 (보다 효율적으로 의존성 관련 문제를 해결함)
	=> 권장 패키지의 경우에 상황에 따라 aptitude가 더욱 효율적으로 설치하고 삭제함
	
3. 문제발생 시 apt는 "할 수 없음"을 띄운다면, aptitude는 해결책을 제시함


# RPM
RPM - Red Hat package manager
Red Hat에서 개발한 패키지 관리 소프트웨어

rpm 패키지는 규칙성 있는 패키지명을 가져야 함
[name]-[version]-[release].[arch].rpm 와 같은 패키지명을 가짐

==dpkg와 같이 의존성 문제를 해결해주지 않음==
=> 이러한 문제를 yum, dnf 등에서 해결해줌


# YUM
YUM = yellowdog updater modified

Red Hat 계열에서 사용되는 패키지 관리 시스템
rpm의 의존성 문제를 해결한 시스템
=> 대신에 인터넷 연결이 필요함

apt와 비슷하다고 보면 됨 - 단, Red Hat 계열이라는 것만 차이가 있음

dpkg == rpm
apt == yum