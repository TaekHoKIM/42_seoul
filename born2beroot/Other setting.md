
# hostname

- hostname (new_hostname) - 해당 세션에서만 사용하는  hostname으로 변경
- /etc/hostname 파일의 내용을 변경 - 영구적인 hostname을 변경
- hostnamectl set-hostname new_hostname - 영구적으로 hostname 변경


# SUDO 규칙 설정
visudo를 통해서 sudo의 규칙 설정이 가능

Defaults    authfail_message="Authentication attempt failed custom."
-> 권한 획득 실패 사용자 지정 메세지
Defaults    badpass_message="Wrong password custom."
-> 비밀번호 틀릴 시 사용자 지정 메세지
Defaults    log_input
-> sudo 입력 명령어를 log로 저장
Defaults    log_output
-> sudo 명령 실행 출력 결과를 log로 저장
Defaults    requiretty
-> sudo 명령시에 tty를 강제하는 설정 -> tty(teletypewriter) ==가상터미널의 표준 입출력 장치를 강제함==
=> ==이것을 설정하면 스크립트나 자동으로 sudo 명령어를 못씀== - 직접 대화형 인터페이스에서 sudo를 사용하는 것을 강제하는 것임 - ==보안적으로 좋음==
Defaults    iolog_dir="/var/log/sudo/"
-> sudo log를 해당 위치에 저장하는 설정
Defaults    passwd_tries=3
-> passwd 시도를 3회로 제한하는 설정

**Secure_path**
-> sudo 설정에 secure_path가 존재함 -> sudo 권한을 가진 사용자가 사용할 수 있는 명령어의 경로를 제한하기 위해 존재 -> secure_path에 존재하는 명령어만 사용이 가능함
[출처](https://woongtech.tistory.com/entry/42SEOUL-Born2Beroot#VM%20port%20forwarding-1) 

Defaults env_reset
-> 환경변수를 초기화하는 옵션 - 자신의 환경변수를 전달하는 것을 방지 설정 -> 자신의 환경변수대로 명령을 실행할 때 문제가 생길 수 있음
Defaults mail_badpass
-> 사용자가 비밀번호를 잘못 입력했을 대 관리자에게 알림메일을 보내는 설정

# Password 규칙 설정

passwd 관련 설정 파일 
1. /etc/login.defs <- 시스템 전반에 적용되는 로그인 정책 및 설정을 제어하는 파일
-> passwd age 관련해서 설정이 가능 
2. /etc/pam.d/common-password <- pam을 사용하여 사용자 암호 정책을 관리하는 파일
-> common-password를 보면 pam_unix.so, pam_deny.so 등의 socket모듈들이 존재  -> 이런 모듈들을  통해서 여러 인증을 통합할 수 있음
=> 여기에서 password의 quality를 확인할 수 있는 모듈이 pam_pwquality.so임 (pam_pwquality에는 minlen, difok, ucredit, lcredit, dcredit, reject_username, enforce_for_root, maxrepeat 등이 존재)
@PAM의 모듈들은 순서대로 작동함 ( ex, common-password)
@requisite의 경우 실패시 바로 실패로 반환, required의 경우 실패해도 다음 모듈로 진행하지만 결과는 실패로 반환
@difok

__PAM__
Pluggable Authentication Modules
-> 플러그 가능 모듈을 사용하여 기존 시스템으로 여러 인증메커니즘을 통합할 수 있게 하는 기능을 제공
-> 여러 인증 모듈을 통합하게 해주는 프레임워크


# monitoring.sh

## uname
현재 시스템의  정보를 출력하는 명령어
uname -a는 시스템의 모든 정보를 출력

## nproc
현재 사용가능한 프로세서(코어)의 수를 출력하는 명령어
nproc --all -> 설치되어 있는 프로세서(코어)의 수를 출력

## lscpu
현재 시스템에서 CPU와 관련된 정보를 상세하게 출력하는 명령어
-> 아키텍쳐, cpu모델, 소켓수, 코어수, 쓰레드수, 실제 cpu코어수 등 많은 정보를 담고 있음
다만, 가상화된 cpu( 즉, 쓰레드수의 경우 Thread per core와 같은 형식으로 나와서 모든 Thread의 수를 바로 알기가 어려움 - 예를 들어 socket이 2개일 경우에는 각 소켓의 cpu정보를 따로 계산해서 쓰레드를 구하고 더해야 함)

__/proc/cpuinfo__
cpu에 대한 정보를 담고 있는 파일
기준이 일반적으로 processor(Thread) 단위로 정보를 구성함
-> 

## free
메모리(ram)의 사용량 및 사용 가능량을 보여주는 명령어
Mem - 실제 메모리  Ram
Swap - 메모리 용량이 부족할 경우에 임시적으로 디스크의 Swap영역을 메모리처럼 사용 ( 가상메모리 영역 )

## df
파일 시스템의 디스크 사용현황을 보여주는 명령어
disk free의 약자
df를 사용하면 여러가지 Filesystem이 나옴
- udev - 하드웨어 장치를 관리하는 데 사용되는 가상파일시스템 (실제 디스크를 차지하지 않고 동적으로 제공됨)
- tmpfs - 메모리를 기반으로하는 가상파일시스템으로 일시적인 데티터를 저장하는 데 사용
-> 보통 디바이스 파일을 관리하는 데 쓰는 파일 시스템이 /dev/ 파일 시스템
-> 여기에서 실제로 우리가 쓰는 영역은 보통 /dev/mapper가 됨

## mpstat
multiprocessor statistics의 약자
다중 프로세서의 사용률 및 통계를 보여주는 시스템 모니터링 도구
@sysstat 패키지에서 지원함

## who
현재 시스템에서 로그인한 사용자의 정보를 나타내는 명령어
who -b - 시스템의 마지막 부팅시간을 나타내는 옵션

## lvdisplay, pvdisplay, vgdisplay
각각 lv, pv, vg의 정보를 표시하는 명령어
그 이외에  lvcreate, lvremove, lvextend 등의 lvm에 관련된 명령어들이 존재
-> lvm을 사용하는지를 보기 위해서 if lvdisplay &> /dev/null; 을 통해서 확인
-> &>는 redirection을 의미, /dev/null(파일)은 실행결과를 무시해서 표시를 하지 않는 것, 위의 조건에서 특이한 점은 lvdisplay의 결과만 보고 참/거짓을 판단  -> &> /dev/null은 단순히 실행결과를 무시하는 것으로 보면 됨
@ 다른 방법으로는  lsblk에서  type에 lvm이 있는 지를 통해서 확인 할 수도 있음

## ss
socket statistics의 약자
소켓의 정보를 확인하는 데 사용하는 명령어 (네트워크 연경에 대한 정보)
소켓 - 네트워크 통신을 위한 엔드포인트를 나타냄
ss -t -> tcp 소켓 정보 표시하는 옵션

## journalctl 
systemd의 로깅시스템에서 로그를 검색하는데 사용되는 명령어
여기에서 sudo 명령어의 로그를 확인할 수 있음
-> journalctl \_COMM=sudo 
\_COMM <- 특정 프로세스의 이름을 지정하여 로그를 확인하는데 사용

# crontab
주기적으로 반복되는 작업을 스케줄링 하기 위해 사용되는 명령어
\*/10 * * * * /root/monitoring.sh | wall
\* 이 순서에 따라 분, 시간, 일, 월, 년 이 됨
\*/10은 10단위로 작업하겠다는 것
| wall 은 접속한 유저 모두에게 전달한다는 것 -> 작업이 잘못될 경우에 그 작업을 올린 user에게 실패 메일을 전달함