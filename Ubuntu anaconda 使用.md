# 
## 出现 command not found: conda  时，输入下面的语句
 ` export PATH="/home/cad/anaconda3/bin:$PATH" `

## 创建一个PY3.5版本的名为tensorflow的环境
 ` conda create -n tensorflow python=3.5 `

## 切换到指定的环境
 ` source activate tensorflow`

## 查看你现在所在的版本分支: 
  ` conda info -e`

## 切换回 root 分支
  ` source deactivate`

## 查看环境下的包列表
 ` conda list`

## 删除一个环境

如果你不想要这个名为flowers的环境，就按照如下方法移除该环境：

 `conda remove -n flowers --all`
