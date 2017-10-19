# Ubuntu修改hosts方法

以下是Ubuntu修改hosts方法。
## 1、修改hosts
sudo gedit /etc/hosts

如果您不喜欢使用gedit命令，而且当前帐户为非root帐户，那么可把/etc/hosts复制到桌面上，然后手动编辑后保存，再使用命令copy覆盖过去即可，示例如下：

sudo cp hosts /etc/

## 2、如何添加解析记录
把网上的公开的解析记录只需复制粘贴到hosts文件后面即可，每行一条，

示例：127.0.0.1 localhost

## 3、保存并重启网络

sudo /etc/init.d/networking restart

也可以直接点击右上角的网络连接图标，选择断开，然后再选中连接即可。