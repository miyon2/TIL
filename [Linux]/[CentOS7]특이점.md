## /etc/inittab
해당 파일은 centos7에서는 더이상 존재하지 않기때문에 몇가지 명령어로 런레벨을 확인하거나 수정할 수 있다.
```
$ systemctl get-default						//현재 런레벨
$ systemctl set-default multi-user.target	//level 3으로 변경
$ systemctl set-default graphical.target	//level 5로 변경
```