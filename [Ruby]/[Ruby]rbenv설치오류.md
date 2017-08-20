# Rails 및 Rbenv 설치 오류
```
$ export PATH="$HOME/.rbenv/bin:$PATH"
$ eval "$(rbenv init -)"
```
이후 터미널을 reboot하면 PATH설정이 안되어있다.
이 경우에
```
$ echo 'export PATH="$HOME/.rbenv/bin:$PATH"' >> ~/.bash_profile
$ echo 'eval "$(rbenv init -)"' >> ~/.bash_profile
```
를 입력할 경우 terminal을 reboot해도 PATH설정이 고정되어있다.

# RVM 제거
```
$rvm implode
```	
이후에도 PATH설정에 .rvm/bin 경로가 남아있는 경우가 있다.
```
~/.bashrc 
~/.bash_profile 
~/.profile 
~/.zshrc
~/.zlogin
```
이때 위의 다섯가지 경로에서 rvm폴더를 참조하는 부분을 지워준 뒤 터미널을 reboot하면 정상적으로 제거된다.
