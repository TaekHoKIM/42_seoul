
[SELinux 관련링크](https://lesstif.gitbook.io/web-service-hardening/selinux)
# 접근통제
접근 통제 : 디렉토리, 파일, 네트워크 소켓 등 ==시스템자원==을 적절한 권한을 가진 사용자나 그룹이 접근하고 사용할 수 있도록 통제하는 것

객체 ( object ) : 시스템 자원
주제  ( subject ) : 자원에 접근하는 사용자나 그룹

2가지 방식이 존재
## DAC (Discretionary Access Control)

**시스템 객체에 대한 접근은 사용자와 그룹의 신분을 기준으로 통제하는 방식**
- 객체의 소유자가 접근권한을 부여하는 방식
- 유닉스나 윈도우등에서 기본적인 접근 통제방식으로 사용
- 소유자 권한을 탈취당하면 모든 객체의 권한을 가지게 됨
- 특히 root를 탈취당하면 모든 권한을 가짐 (생기는 문제점은 다음과 같음)
	1. setuid / setgid 문제 -> setuid,setgid는 사용자가 사용자가 속한 그룹이나 소유자의 권한으로 동작하게 하는 비트임 -> DAC 방식은 setuid 보안을 해결할 수 없음 ( setuid는 필요한 비트 )
	2. well-known port daemon 문제 -> 특정한 쓰임새에 따라 미리 지정해둔 1024 미만의 포트번호로 루트만 사용할 수 있는 포트번호임 -> 데몬 서비스는 루트의 권한으로 작동함 -> 데몬 서비스를 이용해서 루트의 권한을 가져올 수 도 있음

## MAC ( Mandatory Access Control )

__미리 정해진 정책에 따라 주체의 허용권한과 객체의 허용권한을 비교하여 접근하는 통제 모델__
- 소유자라고 할 지라도 정책에 어긋나면 객체에 접근 할 수 없음
- well-known port daemon 문제에서 해당 포트의 권한을 탈취해도 그 포트의 권한만으로 모든 객체에 접근 할 수 없음 -> 접근이 허용된 일부 객체에만 접근이 가능함 ( 2차 피해를 줄일 수 있음 )
- 단, 구현이 복잡하고 설정이 까다로움, 시스템 관리자가 모델에 대해서 이해가 깊어야 함


# SELinux
__SELinux : Security-Enhanced Linux__

==MAC== 기반의 보안 커널을 사용한 리눅스 ( 커널 레벨의 보안 모듈임 )
- RHEL 기반의 배포판에서 포함되어 있음 ( Red Hat 계열 Linux 커널에 포함되었다고 보면 됨 )
- 기존 접근 통제 방식 ( DAC )보다 먼저 동작함 -> 소유자여도 자신 소유 폴더나 파일에 접근이 안될 수 있음

## SELinux 의 장점
- 사전 정의된 접근 통제 정책을 사용 - 기본적으로 정의된 접근 통제방식으로 DAC에서의 문제점인 setuid나 well-known port daemon 문제를 걱정하지 않아도 됨
- 기본적으로 ==Deny ALL, Permit Some== 정책이어서 잘못된 설정을 최소화함 - 필요한 것들을 허용하는 방식이어서 잘못된 접근이 나올 수 없음
- 권한 상승 공격으로 인한 취약점 감소 - DAC와 반대로 높은 권한을 가져도 접근 할 수 있는 적기 때문에 보안에 더욱 좋음
- 잘못된 설정과 버그로부터 시스템 보호 - 예를 들어, 버퍼오버플로 공격의 경우 어플리케이션이 메모리에 이있는 코드를 실행할 수 없도록 통제함 -> 쉘을 얻을 수 없음

## SELinux 의 한계
- SELinux의 주 목표는 2차 피해를 막는 것
- 침입차단 시스템 (IPS : Intrusion Protection System), 침입탐지 시스템 ( IDS : Intrusion Detection System) 과는 다름

## SELinux 동작
![](https://cloud.githubusercontent.com/assets/404534/12506805/d187db34-c134-11e5-85e3-76a71fd3ea9a.png)

-> 커널에서 처리를 함 - 속도를 위해 정책의 내용은 커널 내부의 AVC( Access Vector Cache )라는 이름으로 캐싱함

### 3가지 모드가 존재
1. enforce : 기본 설정이고, 보안 정책에 위반되는 모든 액션을 차단함
2. permissive : 정책에 위반되는 액션에 대한 경고를 하고 차단을 하지는 않음, 로그를 기록함
3. disable : SELinux 자체를 사용하지 않는 모드
-> enforce , permissive는 setenforce 0, setenforce 1 명령어로 변경 가능
-> disable은 /etc/selinux/config에서 SELINUX = disabled로 설정하고 재부팅 하면됨
=> 다시 활성화 할 때는 부팅 시간이 오래걸림 ( 모든 리소스에 보안 레이블을 추가해야 돼서 )

# AppArmor
