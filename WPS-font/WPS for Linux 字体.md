
# WPS for Linux字体配置（Ubuntu 16.04） 

1、解压

```
sudo unzip wps_symbol_fonts.zip -d /usr/share/fonts/wps-office
```

解压完成后再次打开WPS就不会看到以上错误。

2、注意：一定要以wps-office的文件夹进行保存，如果没有以这样命名，那么可以按照以下方法进行：

```
#生成字体的索引信息
sudo mkfontscale
sudo mkfontdir
#运行fc-cache命令更新字体缓存
sudo fc-cache
```

重启WPS即可。

3、这种方式是直接双击字体进行安装，进入到解压出的文件，双击即可。