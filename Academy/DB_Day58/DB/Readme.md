## Migration 사용법
1. 시작프로젝트를 이 DB로 설정한다.
2. 도구 - Nuget 패키지 관리자 - **패키지 관리자 콘솔** 실행
3. 기본프로젝트를 이 DB로 바꿔준다.
4. 아래 명령어를 입력한다.

```
Add-Migration "[마이그레이션 이름]"
```
5. Migrations 내용을 확인한다. (정상 적용이 되었는지.)
6. DB에 실제로 적용시키려면 아래 내용을 입력한다.
```
Update-Database
```

**만약에 Migrations 내용이 마음에 들지 않는다면**
```
Remove-Migration
명령어 입력
```
