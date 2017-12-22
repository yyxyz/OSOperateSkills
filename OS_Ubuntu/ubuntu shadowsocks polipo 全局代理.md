# [ubuntu shadowsocks polipo 全局代理](http://dearmadman.com/2015/08/30/use-shadowsocks-in-ubuntu/)

## 安装shadowsocks

```
sudo apt-get install python-pip
sudo pip install shadowsocks
```

## 启动方式
```
sslocal -s 222.22.2.2 -p 222 -b 127.0.0.1 -l 1080 -k pass -t 600 -m aes-256-cfb
# or
sslocal -c shadowsocks.json
```
如果用配置文件的方式进行配置 需要编辑配置文件

```
touch shadowsocks.json
```
copy:
```
{
"server" : "222.22.2.2",
"local_address": "127.0.0.1",
"server_port" : 222,
"local_port" : 1080,
"password" : "pass",
"timeout" : 600,
"method" : "aes-256-cfb",
"fast_open":false
}
```
OK,

shadowsocks 是走的socks5协议，需要搭配浏览器插件使用，如果想要在系统全局使用，需要使用polipo进行二次转发

## 安装polipo
```
sudo apt-get install polipo
```
## 配置

```
vi /etc/polipo/config
```
copy:
```
# This file only needs to list configuration variables that deviate
# from the default values.  See /usr/share/doc/polipo/examples/config.sample
# and "polipo -v" for variables you can tweak and further information.

logSyslog = true
logFile = /var/log/polipo/polipo.log

proxyAddress = "0.0.0.0"

socksParentProxy = "127.0.0.1:1080"
socksProxyType = socks5

chunkHighMark = 50331648
objectHighMark = 16384

serverMaxSlots = 64
serverSlots = 16
serverSlots1 = 32
```
## 重启polipo服务

```
sudo /etc/init.d/polipo restart
```
## 验证以及使用
polipo默认是运行在8123端口的，sslocal运行shadowsocks后，我们可以通过以下方式测试 shadowsocks是否连接成功
```
export http_proxy="http://127.0.0.1:8123/" curl ifconfig.me
```
如果返回正常的话，应该是可以看到shadowsocks服务器ip的

## 设置别名

bash中有一个很好的东西，就是别名alias. Linux用户修改~/.bashrc，Mac用户修改~/.bash_profile文件，增加如下设置

```
alias hp="http_proxy=http://localhost:8123"
```
然后Linux用户执行source ~/.bashrc，Mac用户执行source ~/.bash_profile

测试使用
```
20:39:39-androidyue~$ curl ip.gs
当前 IP：125.39.112.14 来自：中国天津天津 联通
20:39:44-androidyue~$ hp curl ip.gs
当前 IP：210.140.193.128 来自：日本日本 
20:39:48-androidyue~$ 
```

## 当前会话全局设置

如果嫌每次为每一个命令设置代理比较麻烦，可以为当前会话设置全局的代理。即使用
`export http_proxy=http://localhost:8123` 即可。 如果想撤销当前会话的http_proxy代理，使用 `unset http_proxy` 即可。 示例效果如下

```
21:29:49-androidyue~$ curl ip.gs
当前 IP：125.39.112.14 来自：中国天津天津 联通
21:29:52-androidyue~$ export http_proxy=http://localhost:8123
21:30:07-androidyue~$ curl ip.gs
当前 IP：210.140.193.128 来自：日本日本 
21:30:12-androidyue~$ unset http_proxy
21:30:37-androidyue~$ curl ip.gs
当前 IP：125.39.112.14 来自：中国天津天津 联通
```
如果想要更长久的设置代理，可以将
`export http_proxy=http://localhost:8123` 加入.bashrc或者.bash_profile文件

## 设置全局代理

System Settings => Network => Network proxy

Method=>Manual,Socks Host=>127.0.0.1 1080

这样就启用系统全局代理了，一般我们都是配合浏览器使用 Chrome:Proxy SwitchyOmega

## 开机启动

编译一个 shadowsocks.sh

```
vi shadowsocks.sh
```
copy:
```
#!/bin/sh

nohup sslocal -c /home/wang/conf/shadowsocks.json &
```
修改 rc.local文件做开启执行：
```
sudo vi /etc/rc.local
```
添加：
```
sudo sh /home/wang/sh/shadowsocks.sh
```
下次重启就会自启动了，如果没有自启动，排查下执行路径及权限是否正确，还有1080端口是否被占用,最好是自己配置一个指定端口，默认的1080可能会与其他程序冲突，比如xware,
如果与xware冲突，重新配置端口即可解决