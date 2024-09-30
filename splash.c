#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 화면 지우기 (보너스 기능)
void clearScreen() {
    // ANSI escape code를 이용해 터미널 화면을 지움
    printf("\033[H\033[J");
}

// 3초 대기 함수
void waitForSeconds(int seconds) {
    time_t start = time(NULL);
    while (time(NULL) - start < seconds);
}

int main() {
    char name[100];  // 사용자 이름 저장
    char date[11];   // yyyy-mm-dd 형식의 날짜 저장 (10글자 + 널문자)

    // 사용자로부터 날짜를 입력 받기
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    fgets(date, sizeof(date), stdin);  // 날짜 입력받기
    date[strcspn(date, "\n")] = '\0';  // 문자열에서 '\n' 제거

    // 입력 버퍼에서 남은 줄바꿈 문자 제거
    getchar(); // 이전 입력에서 남아있는 newline 제거

    // 사용자로부터 이름을 입력 받기
    printf("[당신의 이름을 입력하세요]: ");
    fgets(name, sizeof(name), stdin);  // 이름 입력받기
    name[strcspn(name, "\n")] = '\0';  // 문자열에서 '\n' 제거

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기 후 화면 지우기
    waitForSeconds(3);
    clearScreen();

    // 스플래시 화면 출력
    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // 왼쪽 직삼각형 출력 및 스플래시 메시지
    for (int i = 1; i <= 5; i++) {
        // 왼쪽 삼각형
        for (int j = 0; j < i; j++) {
            printf("*");
        }

        // 스플래시 메시지 출력
        if (i == 1) {
            printf("                         [마그라테아 ver 0.1]                               ");
        }
        else if (i == 2) {
            printf("   풀 한 포기 없는 황무지에서 반짝이는 행성을 만들내는 곳 마그라테아,       ");
        }
        else if (i == 3) {
            printf("  사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빗는 곳,   ");
        }
        else if (i == 4) {
            printf("   마그라테아에 오신걸 환영합니다.\"                                         ");
        }
        else if (i == 5) {
            printf("                                                                            ");
        }

        // 오른쪽 역직삼각형 출력
        for (int j = 5; j >= i; j--) {
            printf("*");
        }

        printf("\n");
    }

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    // 사용자와 실행 시간을 출력하는 부분
    printf("[사용자]: %s                                   [실행 시간]: %s\n", name, date);
    printf("===========================================================================\n");

    return 0;
}
