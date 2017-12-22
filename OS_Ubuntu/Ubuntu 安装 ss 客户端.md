# UUbuntu 安装 ss 客户端
## gui方式

1. 添加PPA源： \
`sudo add-apt-repository ppa:hzwhuang/ss-qt5`
2. 更新软件列表： \
`sudo apt-get update`
3. 安装shadowsocks： \
`sudo apt-get install shadowsocks-qt5`
4. 配置shadowsocks帐号信息
    - dash中搜索shadow，然后打开shadowsocks-qt5软件
    - 在空白编辑区域点击鼠标右键，点击【添加】，然后填入正确的连接信息
    - 然后点击【连接】，状态显示为已连接。

## cmd方式

1. 安装 python-pip：\
`apt-get install python-pip`
2. 安装shadowsocks：\
`pip install shadowsocks`
3. 启动客户端 \
`sslocal -s server_ip -p server_port  -l 1080 -k password -t 600 -m aes-256-cfb`
-k 密码要加 "双引号"

## Firefox的设置

1. 安装代理插件 [Pan](https://addons.mozilla.org/zh-CN/firefox/addon/pan/?src=api)
2. 将默认代理改为SS