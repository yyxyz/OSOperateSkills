## 使用SSH命令行传输文件到远程服务器

以前一直在windows下用SSH Secure Shell连接远程服务器，它自带了一个可视化的文件传输工具，跟ftp差不多
但是它也存在一个缺陷，不支持编码的选择，遇到utf8就自动乱码了，另外mac下也没有这个工具

在mac下我用终端登录上去之后，想传个文件上去就犯愁了，难不成要开个ftp？
搜了一下，果然有直接的命令行工具，名字叫SCP

使用方式如下：

## 1、上传本地文件到服务器
> scp /path/filename username@servername:/path/

例如
> scp /var/www/test.php root@192.168.0.101:/var/www/ 

把本机/var/www/目录下的test.php文件上传到192.168.0.101这台服务器上的/var/www/目录中

## 2、从服务器上下载文件
下载文件我们经常使用wget，但是如果没有http服务，如何从服务器上下载文件呢？
> scp username@servername:/path/filename /var/www/local_dir（本地目录）

例如:
> scp root@192.168.0.101:/var/www/test.txt 

把192.168.0.101上的/var/www/test.txt 的文件下载到/var/www/local_dir（本地目录）

## 3、从服务器下载整个目录
> scp -r username@servername:/var/www/remote_dir/（远程目录） /var/www/local_dir（本地目录）

例如:
> scp -r root@192.168.0.101:/var/www/test /var/www/

## 4、上传目录到服务器
> scp -r local_dir username@servername:remote_dir

例如：
> scp -r test root@192.168.0.101:/var/www/ 

把当前目录下的test目录上传到服务器的/var/www/ 目录