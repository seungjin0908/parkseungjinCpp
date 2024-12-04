﻿## .NET vs .NET Framework 의 차이

 1. 콘솔 앱 (.NET)
 2. 콘솔 앱 (.NET Framework)


 주로 사용하는건 .NET 이다.

 C++도 사실 버전이 있다.
 C++11
 C++14
 C++17
 C++20
 이런식으로 언어의 버전이 있다.

 C#도 언어의 버전이 있다.

 그 언어의 버전을
 C# 1
 C# 2
 가 아니라

 .NET Framework 1.0.0 이런식으로 이름을 부른거다.
 .NET Framework 4.8.x 에서 마지막을 봤다.
  => Unity에서 사용하는 버전이다.

여태까지 계속 .NET CORE라고만 말했지

## C# 언어의 히스토리

 C#은 Microsoft 사에서 언어를 개발한다.

 윈도우도 만든 회산데, 독자적인 언어를 만들어서 Window와 호환이 잘되는 언어를 만든다.

 처음 만들었을때, Linux나 Mac에서는 동작하지 않았다.
 (지금은 동작한다.)

 Java / Kotlin는 웹이나 안드로이드에서만 사용하고
 javascript는 웹에서 동작하고
 C#은 Window / 웹만 가능하다.

 갑자기 멀티플랫폼을 지원하게된 이유가 있다.

 Microsoft가 사업을 확장한다.

 Amazon WebService
 Google Cloud Platform
 Naver Cloud Platform
 Azure라는 이름으로 같은 클라우드 사업을 시작한다.

 OS를 같이 설치해주는 클라우드 사업을 하는데
 Linux를 판매하는 입장인데
 Microsoft가 만든 언어인 C#은 Linux를 지원하지 않으면
 모양새가 이상해진다.

 그래서 이제 멀티OS를 지원해야겠다고 하고 나온게
 .NET Core 이다.

 그 이전까지는 .NET Framework 였다가
 멀티 OS를 사용하기 시작하면서부터 .NET Core가 된다.


 클라우드 사업은
  - 서버를 만들면 서버를 올릴 PC가 필요한데,
  그거를 돈을 내면 임대해주는 사업이다.
  이거랑 같이 OS도 설치를 해준다.
	

## Unity에서의 .NET Framework

 .NET Framework는 방금듣기로는 Window밖에 지원을 안한다고 했는데...

 근데 우리가 아는 Unity는 C#으로 짜고
 모바일도 되고, 웹도 되고, 리눅스도 되고 다 되는데?

 왜 그러냐??
 C# 고인물들이 새로운 라이브러리를 만들어 낸다.
 Mono