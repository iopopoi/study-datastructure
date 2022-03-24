# StudyForDataStructure
Repository for DataStructureStudy

## Git & Github?
### Git  _  [공식한글메뉴얼](https://git-scm.com/book/ko/v2)
<br>

버전 관리란?
- 버전 관리 시스템(VCS - Version Control System)은 파일 변화를 시간에 따라 기록했다가 나중에 특정 시점의 버전을 다시 꺼내올 수 있는 시스템이다.
- VCS를 사용하면 파일과 프로젝트를 이전 상태로 되돌릴 수 있고 시간에 따라 수정 내용을 비교할 수 있습니다. 또한, 문제의 원인을 추적하고 문제 이전의 상태로 쉽게 복구할 수 있다.

Git?
- 형상 관리 도구(버전 관리 시스템) 중 하나로 소스코드를 효과적으로 관리하게 해주는 무료, 공개 소프트웨어이다.
- 분산형 관리 시스템으로 소스 코드를 여러 개발 PC와 저장소에 분산하여 저장한다. <br>
- 소스코드를 주고 받을 필요 없이, 같은 파일을 여러 명이 동시에 작업하는 병렬 개발이 가능하다. branch를 통해 개발한 뒤, 본 프로그램에 Merge(합치는) 방식으로 작업을 진행할 수 있다.

Github?
- 형상 관리 도구(버전 관리) 웹호스팅 서비스로 협업하고 있는 코드를 저장할 서버
- 버전 관리 시스템을 지원하는 서비스로 push, pull request등 을 통해 작업을 할 수 있다.

용어들...
- Repository: 저장소, branch에 따라 소스코드, 히스토리를 저장한다. 
- Commit: 저장소에 저장하는 작업
- Branch: 가지 또는 분기점, 작업을 할때, 현재 상태를 복사하여 Branch에서 작업한다. 작업과 검증을 완전히 마친 후에 Merge하여 작업을 한다. 
- Merge: 다른 Branch의 내용을 현재 Branch로 가져와 합치는 작업을 의미한다.
<br><br>
## How to install git & set Github
1. [install Git](http://git-scm.com/download/win) 

2. 사용자 이름/ 이메일 등록
    ```
    git config --global user.name "사용자이름"
    git config --global user.email "이메일@abc.com"

    git config --list
    ```

3. [Github 가입하기](https://github.com/)

4. git bash 실행 및 ssh키 생성하기_[참고자료](https://www.lainyzine.com/ko/article/creating-ssh-key-for-github/)
    ```
    $ cd ~/.ssh
    $ ls
    ```
    ls를 통해 id_ed25519와 id_ed25519.pub 또는 id_rsa와 id_rsa.pub 파일 쌍이 있는지 확인한다.
    이 파일이 없는 경우
    ```
    $ ssh-keygen -t ed25519 -C "your_email@example.com"
    ```
    위의 명령어를 통해 ssh키를 생성한다. 저장위치와 ssh키의 비밀번호 설정을 물으면 원하는 설정을 해줍니다. (편한건 default, 그냥 "enter"를 눌러주면 됩니다.)
    ```
    cat id_rsa.pub
    ```
    위의 명령어를 통해 key를 확인하고 결과를 모두 복사한다.<br>

5. Github에 ssh키를 등록한다.
    - Github 로그인 후 오른쪽 상당의 프로필을 클릭하소, Setting 메뉴로 이동한다.
    - 사이드 바에서 SSH and GPU keys 메뉴를 선택하고 New SSH key를 클릭한다.
    - Title: 등록하여는 키의 이름, 본인이 구분하기 편하도록 이름을 정한다.
    - Key: 앞서 복사한 키를 입력한다.
    - Add SSH key
    

## How to use Git & Github

### Clone Repository
1. 원하는 Repository를 clone받기 해당 Repo의 clone code를 복사한다.
    ![clone code](./images/clone_http.png)
2. terminal에서 clone 받고 싶은 위치로 이동한다.

    ``` 
    git clone https://github.com/iopopoi/StudyForDataStructure.git
    ```


## How to use Repository

## How to use Branch

## How to use Issue
