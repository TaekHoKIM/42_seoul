인터넷을 통해 이메일을 전송하는 에이전트 (MTA - Mail Transfer Agent)

sendmail-cf 패키지 -> sendmail의 구성을 수정하고 변경할 수 있음
/etc/mail/sendmail.mc 파일을 수정하여 sendmail의 구성을 변경할 수 있음

@ ".mc" 파일은 마크업 파일로 사람이 읽기쉬운 형식으로 구성 -> ==".mc" 을 ".cf" 파일로 변경해서 사용==해야 함 ( 변경하는 데 필요한 것인 ==m4 매크로 프로세서==임)

SMTP(Simple Mail Transfer Protocol) 포트는 25번 포트
### SMTP 명령 형식
__==helo localhost==__                                                   
helo는 메일 서버에 연결하기 위해 클라이언트의 도메인 이름을 알려주는 명령어 

__==mail from: <현재 접속한 유저 이름>@localhost==__
발신자 

__==rcpt to: <이메일 주소>==__
수신자 

__==data==__
메일 시작 

__==subject: <메일 제목>==__
__==메일 본문==__
__==.==__ 
메일 본문 종료 

__==quit==__
메일 발송 및 종료
# Telnet
네트워크를 통해서 다른 컴퓨터에 원격으로 접속할 수 있게 하는 프로토콜
- 문제는 보안적으로 안전하지 않음 - ssh가 보안이 더욱 좋음

@연결은 ==telnet host_name port_num== 로 접속 (ex, telnet example.com 80 / telnet localhost 25)