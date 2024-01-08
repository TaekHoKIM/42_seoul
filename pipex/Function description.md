
# open
- 파일을 열때 사용하는 함수 #open
- header : <fcntl.h>
- form : int open ( __const char__ \*FILENAME, __int__ FLAGS );
	      int open ( __const char__ \*FILENAME, __int__ FLAGS, __mode_t__ mode);
- return value : 파일 열기 성공 -> ==파일 디스크립터의 양의 정수값 반환 (int 0 이상)==
/ 파일 열기 실패 -> ==-1== 반환
- parameter : FILENAME -> 대상파일 이름 / FLAGS -> 열기 옵션 / mode -> 파일 생성시 파일 접근 권한 설정 (FLAGS에서 O_CREAT 옵션을 사용할 때)

# close()
- 파일을 닫을 때 사용하는 함수 #close
- header : <unistd.h>
- form : int close ( __int__ fd );
- return value : 파일 닫기 성공 -> ==0== / 파일 닫기 실패  -> ==-1== (==+'errno' 변수에 오류코드를 저장함== - perror 함수나 strerror 함수를 이용해서 볼수 있음)
- parameter : fd -> 파일 디스크립터

# read()
- 파일이나 소켓의 데이터를 읽는 데 사용하는 함수 #read
- header : <unistd.h>
- form : ssize_t read( __int__ fd, __void__ \*buf, __size_t__ count );
- return value : 읽기 성공 -> ==읽은 바이트 수== or ==0==(EOF 도달시) / 읽기 실패  -> ==-1== (==+'errno' 변수에 오류코드를 저장함== - perror 함수나 strerror 함수를 이용해서 볼수 있음)
- parameter : fd -> 파일 디스크립터 / buf -> 읽은 데이터를 저장할 버퍼 / count -> 읽을 바이트 수

# write()
- 파일이나 소켓의 데이터를 쓰는 데 사용하는 함수 #write
- header : <unistd.h>
- form : ssize_t write( __int__ fd, __const void__ \*buf, __size_t__ count );
- return value : 쓰기 성공 -> ==쓴 바이트 수== / 파일 닫기 실패  -> ==-1== (==+'errno' 변수에 오류코드를 저장함== - perror 함수나 strerror 함수를 이용해서 볼수 있음)
- parametre : fd -> 파일 디스크립터 / buf -> 쓸 데이터가 저장된 버퍼 / count -> 쓸 바이트 수

# malloc()
- 동적으로 메모리를 할당하는 데 사용하는 함수 #malloc
- header : <stdlib.h>
- form : void \*malloc (__size_t__ size);
- return value : 할당 성공 -> ==시작주소 포인터== / 할당 실패 -> ==NULL==  (반환형 ==\*void== )
- parameter : size -> 할당할 메모리 바이트 수
- additional
	- malloc으로 할당되는 데이터는 heap 영역에 할당됨

# free()
- 동적으로 할당한 메모리를 해제하는 데 사용하는 함수 #free
- header : <stdlib.h>
- form : void free ( __void__ \*ptr );
- return value :  ==없음== (실패가 없는 함수)
- parameter : ptr -> 해제할 메모리 블록의 포인터

# fd
- File Descriptor #fd
- 파일이나 소켓 등의 ==입출력 장치==를 식별하기 위한 정수값
- stdin (0) : 표준입력 - 표준입력 (키보드 등) ( fd 0으로 사용자의 표준입력(키보드 등)을 읽을 수 있음)
- stdout (1) : 표준출력 - 표준출력 (모니터 등) ( \* 일반적으로 표준출력을 읽는 것을 허용하지 않음  - read에서는 fd 1을 잘 사용하지 않음 / 출력함수에서 사용을 함)
- stderr (2) : 표준에러 - 표준에러 (에러 메시지, 디버깅 정보) - (\* 표준에러도 read에서는 잘 사용하지 않음, 주로 오류메시지 출력에 사용됨)

# perror
- 오류 메세지(errno에 대한 메세지)를 출력하는 함수 #perror
- print error의 약자
- header : <stdio.h>
- form : void perror (__const char__ \*string);
- return value : ==없음== (항상 실행됨)
- parameter : string -> 오류 출력 전에 출력할 문자열 ( ex, perror("hello")일 경우에 error가 있을때 "hello: (errno 문구)"로 출력이 됨 __/__ ": "는 항상 붙음 -> "<사용자 제공 문자열>: <오류 메시지>" 이렇게 출력이 됨 )
- additional
	- 시스템 호출이 있을 경우에 errno이 변경이 됨 (성공시 0 / 실패시 오류코드) -> 여기에서 0일 경우에는 출력을 안함(string도 출력을 안함)

# errno
- 오류 발생시 오류 번호를 저장하는 ==전역변수== #errno
- error number의 약자
- errno을 직접적으로 활용하기 위해서는 <errno.h>를 사용하면 됨
- EINVAL, ENOMEM, ENODEV 등 다양한 에러 코드들이 존재함
- ==오류가 없으면 errno은 0으로 리셋됨==
- ==시스템 호출이 실패할 경우에만 errno이 변경이 됨==
	-> 시스템 호출 : 커널에 요청하는 호출들 -open, close, fork 등 시스템에 관한 것들이 시스템 호출이 됨 (if, 변수 선언, 할당과 같은것들은 시스템 호출이 아님)

# strerror
- 오류 번호에 대해서 매핑된 메세지를 반환하는 함수 #strerror
- header : <string.h>
- form : char \*strerror (__int__ errnum);
- return value : 함수 성공 -> errnum에 해당하는 문자열 반환 / 함수 실패 -> NULL 반환
- parameter : errnum -> errno에 저장된 에러 코드 번호


# access
- 지정한 파일이 존재하는지, 읽기/쓰기/실행이 가능한지를 확인하는 함수 #access
- header : <unistd.h>
- form : int access (__const char__ \*path, __int__ mode);
- return value : 성공 -> ==0== / 실패 -> ==-1 ( errno에 오류코드 저장 )==
- parameter : path -> 접근 권한을 확이하는 파일이나 디렉토리의 경로 / mode -> 확인할 종류를 나타내는 ==정수== ( F_OK, R_OK, W_OK, X_OK )가 존재 ( 각각 파일존재, 읽기가능, 쓰기가능, 실행가능 )
- additional
	- 사용 예시 : access (filepath, F_OK | R_OK) <- | 로 모드를 구분함 ( ==|== 를 쓰는 이유는 '|' 는 or 비트연산자여서 권한을 비트마스크를 하면 됨 - 그래서 mode가 정수인 이유임)

# dup
- 열려져 있는 파일 디스크립터를 복제하는 함수 #dup
- ==같은 파일이나 소켓==에 다른 fd를 할당해서 길을 2개를 여는 방식 (단, 들어가는 방향이 같음)
	-> 이로 인해 oldfd에서나 newfd에서 변경하는 것을이 다 파일에 적용됨
- header : <unistd.h>
- form : int dup (__int__ oldfd);
- return value : 성공 -> ==새로운 fd값 (oldfd와 다른 값이지만 같은 파일이나 소켓을 가르킴)== / 실패 ->  ==-1 ( errno에 오류코드 저장 )==
- parameter : oldfd -> 기존에 파일에 열려있는 fd 값
- addtional
	- 결론은 oldfd와 새로 할당되는 newfd는 서로 값은 다르지만 같은 파일이나 소켓을 가르키고 있음 <- 그래서 ==하나의 fd가 닫히면 다른 fd에서 접근할 수 없음==

# dup2
- 열려져 있는 파일 디스크립터를 원하는 fd로 복제하는 함수 #dup2
- dup과 같다고 보면 됨 -> 단, ==newfd를 지정할 수 있다==는 것이 다름
- header : <unistd.h>
- form : int dup2 (__int__ oldfd, __int__ newfd);
- return value : 성공 -> ==newfd== (중요! 기존에 newfd가 열려 있다면 닫고나서 newfd로 복제함 ) / 실패 -> ==-1 ( errno에 오류코드 저장 )==
- parameter : oldfd -> 복제하고 싶은 기존 fd / newfd -> 복제될 fd 값

# execve
- 기존의 프로세스 이미지를 종료하고 새로운 프로세스 이미지를 실행하는 함수(시스템 콜) #execve
- 프로세스를 종료하고 새로운 프로세스로 대체되는 게 아니라 정확히는 ==프로세스는 그대로 실행되면서 모든 이미지가 변경되는 것== -> 그래서 pid나 이런 것들은 변경이 안됨, ==안의 내용물이 변경되는 것==
- header : <unistd.h>
- form : int execve (__const char__ \*filename, __char \*const__ argv\[], __char \*const__ envp\[]);
- return value : 성공 -> ==없음== ( 새로운 프로세스로 대체되기 때문에 반환이 안됨) / 실패 ->  ==-1 ( errno에 오류코드 저장 )==
- parameter :  __filename__ -> 실행할 프로그램의 경로를 나타내는 문자열 / __argv\[]__ ->프로그램에 전달되는 명령행 인수들의 배열 ( ==첫 번째 요소는 프로그램의 이름==이어야 함, ==마지막은 NULL==로 끝나야 함 -> 마지막에 NULL이 있어야 하는 이유는 argc가 따로 존재하지 않기 때문 ) / __envp\[]__ -> 환경 변수들의 배열 ( 환경변수 문자열의 배열리스트를 전달, ==마지막은 NULL==로 끝나야 함 + NULL만 전달하면 기존의 환경변수를 그대로 씀, 1개 이상의 환경변수가 있고 NULL이 되면 기존의 환경변수는 사라짐 )

# exit
- 프로그램을 종료하는 데 사용하는 함수 #exit
- header : <stdlib.h>
- form : void exit (__int__ status);
- return value : 없음 ( 단, 프로그램을 실행한 곳에 status를 반환함 -> 운영체제나 부모 프로세스에 status를 반환함 )
- parameter : status -> 일반적으로 status = 0 ( 정상 종료 ) / status = 1 ( 비정상 종료 ) / 그 외 ( 시그널에 의한 종료 )로 나타냄
- additional
	- exit를 작동 -> __atexit()__ 에 등록된 모든 함수를 역순으로 호출함( ==__atexit__ 는 프로그램이 종료될때 호출할 함수를 등록하는 함수 ( 프로그램 종료에 필요한 함수들이 등록되어 있음== , 마지막에 호출하는 함수가 첫번째 등록된 함수가 됨 - stack 구조라고 보면 편함 ) -> 모든 열린 파일 닫힘, 입력 버퍼 지워짐 -> 종료상태 전달

# fork
- 실행중인 프로세스를 복제해서 새로운 프로세스를 생성하는 함수( 시스템 콜 ) #fork
- 현재 실행중인 프로세스를 복제하여 child process를 생성함, 현재 프로세스가 parent process가 됨 - ==복제이기 때문에 독립적으로 변수가 돌아감==
- header : <unistd.h>
- form : pid_t fork (__void__);
- return value : 성공 -> ==parent process한테는 child process의 pid를 반환, child process에게는 0을 반환 ==/ 실패 -> ==-1 반환==
	- 여기에서 child process랑 parent process에 다른 값을 반환한다는 의미는 다음과 같음
	-> 일반적으로 pid = fork(); 로 실행을 함 -> 이때 fork()로 parent process의 복제본으로 child process가 생성됨( 이때 ==프로세스가 실행되는 위치는 같음==, 즉 child process도 fork()의 결과물을 pid에 저장하고 다음 줄을 실행함) -> 이렇게 되면 ==parent process의 pid 변수에는 child process의 pid==가 들어가고, ==child process의 pid 변수에는 0==이 들어가고 각자 실행되는 것
- parameter : void
- additional
	- 상수, 전역변수 등은 자식과 부모 프로세스에서 공유해서 사용함

# pipe
- 두 프로세스 간에 양방향(반이중) 통신을 제공하는 파이프를 생성하는 함수 (시스템 콜) #pipe
- 서로 다른 프로세스 간에 데이터를 전송하는 데 사용함
- header : <unistd.h>
- form : int pipe (__int__ filedes\[2]);
- return value : 성공 -> ==0== / 실패 -> ==-1==
- parameter : filedes\[2] -> fd를 지정해서 넣는 것이 아니라 pipe() 함수에서 fd\[2]에 fd 2개를 할당해서 넣어줌 ( ==fd\[0]은 무조건 읽기용==, ==fd\[1]은 무조건 쓰기용== <- 거꾸로 하면 컴파일에서 문제가 발생할 수 있음)
- additional
	- 양방향으로 서로에게 보낼수는 있는데 반이중으로 한쪽에서 보내고 반대쪽에서 받는 방식으로 파이프가 작동됨 ( 동시에 보내고 받기는 불가능 )
	- 실제 작동 방식 -> 원형 버퍼를 이용해서 읽기와 쓰기를 버퍼를 쓰고 읽으면서 데이터를 전달하는 방식
	- fd\[0]와 fd\[1]이 ==같은 파이프를 가르키지만 다른 방향에서 파이프를 가르키는 fd==라고 보는 게 편함 -> 그래서 한쪽이 닫혀도 다른 fd에서 파이프에 접근이 가능함 ( dup에서는 한쪽이 닫히면 다른 쪽에서 접근이 안됨 )

# unlink
- 파일시스템에서 특정 파일의 디렉토리 엔트리를 삭제하는 명령어 ( 디렉토리는 아님 ) #unlink
- 파일시스템에서 링크 계수를 1 줄이는 함수
- header : <unistd.h>
- form : int unlink (__const char__ \*pathname);
- return value : 성공 -> ==0== / 실패 -> ==-1==
- parameter : pathname -> unlink 할 파일의 경로
- additional 
	- 우선 파일시스템에서는 ==데이터 블록과 파일을 링크로 연결함== -> 여기에서 실제 데이터는 데이터 블록에 저장이 됨 -> unlink는 여기에서 ==데이터 블록과 파일의 링크를 끊는 역할==을 함
	- ==링크계수== - 특정파일이나 디렉토리에 대한 ==하드링크의 수== ( 실제 데이터가 있는 데이터 블록에 연결된 링크의 수라고 보면 됨 <- 그래서 소프트링크는 안됨 ) -> 소프트링크는 데이터 블록과 연결된 링크를 빌려서 쓰는 개념임, 반면 하드링크는 데이터블록에 새로운 링크를 연결하는 것
	- 링크계수는 Inode라는 메타데이터에 저장되어 있음 ( ==모든 하드링크가 동일한 Inode를 가르킴== )
	- Inode의 링크계수가 0이 되면 엔트리에서 삭제하고 ==추가적으로 파일이 열려 있지 않고 파일을 참조하고 있지 않을때== Inode와 데이터 블록을 해제함 
	- ==파일이 열려있는 경우== ( fd가 유지되는 경우 ) -> 해당 fd로 연결을 하고 있어서 바로 자원을 해제하지 않음 -> fd가 닫히면 자원을 해제하고 데이터를 삭제함

# wait
- parent process가 child process의 종료를 기다리는 데 사용하는 함수 ( 시스템 콜 ) #wait
- header : <sys/types.h> - pid_t / <sys/wait.h> -wait
- form : pid_t wait (__int__ \*status);
- return value : 성공 -> ==child process의 pid== / 실패 -> ==-1==
- parameter : status -> 자식 프로세스의 종료 상태를 저장함 ( 자식 프로세스에서 exit (10) 이런식으로 보내면 10이 status에 저장됨 )
- additional
	- wait 함수와 관련된 매크로는 WIFEXITED, WEXITSTATUS, WIFSIGNALED 등 다양하게 있음
	- wait 함수는 child process가 정상적이든, signal을 보내고 비정상적으로 종료되든지 계속해서 기다림 ( ==종료가 될때까지 기다림 - signal만 보내고 종료가 안되는 경우에는 계속해서 기다림== )
	- wait(NULL)은 자식의 종료상태가 상관없을 때 사용
	- wait는 자식프로세스의 종료를 무조건적으로 기다리기 때문에 다른 일을 할 수 없음 -> 이럴때 SIGCHLD 등을 사용해서 이용함
	- child process는 프로세스가 종료되고 자원을 바로 반환하지 않음 - ==좀비 프로세스 상태==로 기다리고 있다가 parent process가 child process의 상태를 확인하고 child process가 종료 됨

# waitpid
- 특정 자식의 프로세스의 종료를 기다리거나 모든 자식 프로세스의 종료를 기다릴 때 사용하는 함수 ( 시스템 콜 ) #waitpid
- header : <sys/wait.h>
- form : pid_t waitpid(__pid_t__ pid, __int__ \*status, __int__ option);
- return value : 성공 -> ==child process의 pid== / 실패 -> ==-1==
- parameter : pid -> 기다릴 child process의 pid / status -> 종료 상태를 저장할 변수의 주소 / option -> 다양한 옵션을 지정 ( 주로 0을 사용)
- additional
	- parameter pid의 경우
		1. pid > 0 : 특정 pid의 child process를 기다림
		2. pid == 0 : ==현재 프로세스 그룹==의 모든 자식프로세서를 기다림
		3. pid == -1 : ==모든 자식프로세스==를 기다림
		4. pid < -1 : ==지정된 프로세스 그룹==내의 모든 자식프로세서를 기다림
	-> ==프로세스 그룹 (PGID)는 프로세스를 그룹으로 묶은 것==을 이야기함 -> setpgid 등의 시스템 콜을 이용해서 프로세스 그룹을 만들 수 있음 - pgid는 보통 양수인데 -pgid와 같은 형태로 특정 프로세스 그룹을 지정할 수 있음
	
# zombie process (not function)
- ==이미 종료된 프로세스 이지만 해당 프로세스의 종료 상태를 수집하지 않은 상태의 프로세스==
- 부모 프로세스에서 자식 프로세스의 종료상태를 수집하지 않으면 발생 -> ==수집하면 리소스가 해제되고 시스템에서 제거됨==
- 종료가 되었지만 프로세스 테이블에는 남아서 좀비상태로 유지 - 그래도 일부 리소스(프로세스 테이블, PCB, status 등)를 계속해서 차지함 -> 그래서 부모 프로세스에서 wait나 waitpid로 종료상태를 수집해서 리소스를 없애야 함