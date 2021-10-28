#include <stdio.h>

#define START_TIME (1) /* 始業時刻の登録 */
#define END_TIME (2) /* 退社時刻の登録 */

/* 就業状態 */
#define  ENGAGING 'e' /* 就業中 */
#define  NON_ENGAGING 'n' /* 非就業 */

int
main(void)
{
  int command; /* タイムレコーダへのコマンド */
  int employee; /* 従業員番号(管理者は0) */
  int status; /* 就業状態 */

//ユーザから従業員番号を入力しemployeeに設定
  printf("従業員番号(0-3): "); scanf("%d",&employee);

  switch(employee) {
  case 0:;//従業員0,2なら非就業に初期化
  case 2:employee = 'n';break;
  case 1:; // 従業員1,3なら就業に初期化
  case 3:employee = 'e';break;
  default:
    printf("エラー：正しい従業員を指定してください\n");
    return 0;
    break;
  }
  
  // ユーザからコマンドを入力しcommandに設定
  printf("コマンド(出社=1,退社=2): "); scanf("%d", &command);

  switch(command) {
  case START_TIME:
    if(employee == 'n') //非就業
      employee = 'e'; //この社員は就業中と記録する
    else {
      printf("エラー：従業員%dはすでに就業しています\n", employee);
      return 0;
    }
    break;
  case END_TIME:
    if(employee == 'e') //就業中
      employee = 'n'; //この社員は非就業と記録する
    else {
      printf("エラー：従業員%dはすでに退社しています\n", employee);
      return 0;
    }
    break;
  default:
    printf("エラー：正しい操作を指定してください\n");
    return 0;
    break;
  }

  printf("従業員%dは，", employee);
  if(employee == 'e')//就業中
    printf("業務中です\n");
  else
    printf("業務を終えました\n");

  return 0;
}
