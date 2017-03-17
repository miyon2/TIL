---
layout: post
title: jekyll로 gitblog 만들기
excerpt
categories: Tutorials
comments: true

---
##jekyll?
jekyll은 Markdown (또는 Textile), Liquid, HTML & CSS 로 구성된 페이지를 repository 에 push 하면 포스팅이 가능하게 해준다.

##시작하기
 blog를 생성하기위한 git계정의 repository가 필요하다.
`git계정.github.io`로 repository를 생성한다.

##jekyll사용하기
>  $ gem install jekyll
$ jekyll new git계정.github.io
$ cd git계정.github.io
~/git계정.github.io $ jekyll serve

이후 **http://localhost:4000**로 접속할 수 있으며
repository에 push할 경우 `git계정.github.io`에 접속할 수 있다.
최초 생성시 바로 접속 가능할 수도 있지만 몇분정도 더 걸릴 수 있다.

###참고
https://jekyllrb-ko.github.io/
