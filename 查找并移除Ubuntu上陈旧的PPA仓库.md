# Linux教程：如何查找并移除Ubuntu上陈旧的PPA仓库
 - 首先，找出那些引起“404 无法找到”错误的PPA。

 `sudo apt-get update | grep "Failed"`

![](https://github.com/yyxyz/OSOperateSkills/blob/master/resource/2017111701.jpg)

在本例中，Ubuntu Trusty不再支持的PPA仓库是“ppa:finalterm/daily”。

 - 去移除PPA仓库吧。

 `sudo add-apt-repository --remove ppa:finalterm/daily`

你得去重复重复再重复，把上面找到的所有过时的PPA仓库一个一个地移除。

![](https://github.com/yyxyz/OSOperateSkills/blob/master/resource/2017111702.jpg)


