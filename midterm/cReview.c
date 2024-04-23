/*
git config --global user.name "user1"
git config --global user.email "email"

git init
git remote add origin repoURL

git clone repoURL

git add file
git commit -m "message"
git commit -am "message"


untracked file 삭제
git rm <file>  // 로컬 git 모두 삭제
git rm --cached <file> //git에서만 삭제 로컬은 남음

현재 파일 상태 확인
git status

commit history 보기
git log

워킹 디렉토리와 staging area 비교
git diff
commit 내용과 staging area비교
git diff --cached / --staged
커밋끼리 비교
git diff commit1_checksum commit2_checksum

커밋 수정
git commit -m "message"
git add file
git commit --amend

수정된 파일 수정전 상태로 변경
git checkout file

git revert 커밋 이력 삭제 x

파일 보존 후 staged로 이동
git reset --soft HEAD~

파일 보존 / unstaged
git reset --mixed HEAD~

파일 변경사항 삭제
git reset --hard HEAD~

git push origin main

git pull origin main

git fetch

pull = fetch + merge

임시저장 / wd에서 수정한 파일만 저장 / modified면서 tracked 상태 / staging
area에 있는 git stash save/list/apply <stashName>/ pop / drop / clear

Merge
커밋 생성x
git merge --ff (default)

커밋생성 o
git merge --no-ff

별도 커밋
git merge --squash




*/

#include <stdio.h>
#include <stdlib.h>  // file, rand()
#include <string.h>
#include <time.h>

int main() {
  srand(time(NULL));
  printf("%d\n", rand() % 5 + 1);

  FILE *file;
  file = fopen("test.txt", "w");
  printf("%d", feof(file));
  fprintf(file, "asdfsdfa%d", 1);
  printf("%d\n", feof(file));
  fclose(file);

  char a[100] = "sldkfjasdf asldkfasd";
  char b[100];
  strcpy(b, a);
  printf("%s", b);

  return 0;
}