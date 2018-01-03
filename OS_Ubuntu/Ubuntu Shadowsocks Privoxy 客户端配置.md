# Ubuntu Shadowsocks Privoxy 客户端配置

干啥的不说了,ubuntu下Shadowsocks不能正常使用,需通过Privoxy中转
 
## 安装Privoxy

(python-pip python-m2crypto用来安装shadowsocks)
 
`sudo apt-get update`  
`sudo apt-get install python-pip python-m2crypto privoxy`
## 安装 shadowsocks
`sudo pip install shadowsocks`  

## 配置shadowsocks

`sudo mkdir -p /etc/shadowsocks`  
`sudo vi /etc/shadowsocks/config.json`  
```
{  
  
"server":"你所申请服务器ip安装了Shadowsocks server",  
  
"server_port":443,  
  
"local_port":1080,  
  
"password":"password",  
  
"timeout":600,  
  
"method":"aes-256-cfb"  
  
}  
``` 
## 配置privoxy

`sudo vi /etc/privoxy/config`  
 
最后追加
```
listen-address 127.0.0.1:8118
forward-socks5 / 127.0.0.1:1080 .  
```
## 启动 shadowsocks
`sslocal -c /etc/shadowsocks/config.json`  
或者
`sudo nohup sslocal -c ~/shadowsocks.conf >/dev/null 2>%1 &`

## 配置生效：
`systemctl enable /etc/systemd/system/shadowsocks.service`

## 查看进程
`sudo ps aux |grep sslocal |grep -v "grep"`
## 启动privoxy,修改后重启服务

`sudo service privoxy start`
`sudo service privoxy restart`
`systemctl restart privoxy`
`systemctl enable privoxy`  
`systemctl status privoxy.service`
 
## 配置系统proxy

`vi /etc/profile`  

``` 
export http_proxy=http://localhost:8118
export https_proxy=http://localhost:8118 
export HTTP_PROXY=http://localhost:8118 
export HTTPS_PROXY=http://localhost:8118  
``` 
使起效，也可以把这几个命令加入到 `.bashrc` 中，以后就需要每次都设置了
`source /etc/profile`

 