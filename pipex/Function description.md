# open()
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
- return value :  ==없음== (실패가 없는 함수);
- parameter : ptr -> 해제할 메모리 블록의 포인터

# fd
- File Descriptor #fd
- 파일이나 소켓 등의 입출력 장치를 식별하기 위한 정수값
- stdin (0) : 표준입력 - 표준입력 (키보드 등) ( fd 0으로 사용자의 표준입력(키보드 등)을 읽을 수 있음)
- stdout (1) : 표준출력 - 표준출력 (모니터 등) ( \* 일반적으로 표준출력을 읽는 것을 허용하지 않음  - read에서는 fd 1을 잘 사용하지 않음 / 출력함수에서 사용을 함)
- stderr (2) : 표준에러 - 표준에러 (에러 메시지, 디버깅 정보) - (\* 표준에러도 read에서는 잘 사용하지 않음, 주로 오류메시지 출력에 사용됨)