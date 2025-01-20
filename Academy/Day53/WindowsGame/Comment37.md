## JSON 다루기
```
 C# 하면서 JSON이 무엇인지도 배웠습니다.
 그리고 어떻게 주로 사용하지는지도 배웠습니다.

 그런데, C++ 로는 JSON을 어떻게 사용하는지 모르는 상태입니다.
```

```
1. 
 기획자가 excel로 먼저 만듭니다.

2.
 그 이후에 내부 프로그래머가 excel을 custom 형식의 파일이나, 
 json 같은 형식으로 파싱해주는 툴을 만듭니다.

3.
 클라이언트 프로그래머는 전달된 json 데이터나 custom 형식의 파일을 게임에서 가져다 씁니다.
```

```
 그동안 데이터를 쓸일이 있을때는 다 하드코딩해서 썼습니다.

 왜 안좋냐? 
 기획자가 스스로 값을 변경할수없으면, 좋은 프로덕트가 안나옵니다.

 그리고 일이 프로그래머한테 과중돼요.
```

```
저희가 다루는 언어는
세상에서 제일 할게 많다는 
C++ 이에요.
그렇기때문에 JSON 또한 다루기 어렵습니다.

데이터를 다루는건 라이브러리르 만들어두면 되기때문에, 한번만 고생하면 되는 작업입니다.
```

### RapidJSON

```
이 라이브러리를 가져다 쓸겁니다.
C#에서 라이브러리 가져다쓰는거 Nuget 패키지 관리자를 써서 해봤었죠.

vcpkg라고 있긴 있습니다.
그래서 보통 안쓰고 직접 라이브러리를 붙입니다.
```


### 라이브러리 사용시 주의사항
```
 MIT 라이센스 - 무조건적인 무료.
 BSD 라이센스 - 무료.

 그 이외 라이센스는 
 꼭 안의 내용을 다 읽어보세요.
 제가 아는 한 상업적으로 무료인 라이센스는 저거 두개가 끝이었습니다.


 라이센스가 없다.
 절대 쓰지마세요.
```

### 라이브러리 붙일때 핵심내용
```
 (Solution)Project Include Path (헤더파일)
 (Solution)Project Libary Path (DLL)
```


### RapidJSON 라이브러리 적용하기

#### 1. 다운로드 받기
```
 1) git clone https://github.com/Tencent/rapidjson.git
 2) https://github.com/Tencent/rapidjson/archive/refs/heads/master.zip 경로로 다운로드
```

#### 2. 핵심 파일 복사
```
 (Solution)Project Include Path (헤더파일) 인 
 솔루션 폴더/ThirdParty/RapidJson/include를 만들어 주고
 include/rapidjson 내용 복사하기.
```

#### 3. (Solution)Project Include Path 지정하기
```
 프로젝트 우클릭 - 속성
 [VC++ 디렉토리]
 공용 포함 디렉토리 : (Solution Include Path 입니다.)

 [C/C++ - 일반]
 추가포함 디렉토리 : (Project Include Path 입니다.)
```




### JSON 사용처
```
데이터를 다룰때 사용합니다.
Windows API에서는 게임데이터를 JSON으로 많이 다루겠죠.
```

```
타워디펜스 게임

 1. 몬스터 데이터
 2. 타워 데이터
 3. 웨이브옵션 데이터
```

#### MonsterData
|ID|Name|Hp|MoveSpeed|ResourceName|
|--|--|--|--|--|
|1|Monster1| 1000| 20|FB_Enemy1|
|2|Monster2| 1500| 40|FB_Enemy2|