# [Docker 教程](http://www.runoob.com/docker/docker-tutorial.html)

## 运行交互式的容器
`docker run -i -t ubuntu:15.10 /bin/bash`
### 各个参数解析：

- `-t`: 在新容器内指定一个伪终端或终端。

- `-i`: 允许你对容器内的标准输入 (STDIN) 进行交互。

## 启动容器（后台模式）
`docker run -d ubuntu:15.10 /bin/sh -c "while true; do echo hello world; sleep 1; done"`

## 确认容器有在运行，可以通过 `docker ps` 来查看

## 查看容器内的标准输出
`docker logs 2b1b7a428627`

## 停止容器
`docker stop 2b1b7a428627`

## 移除应用容器
`docker rm 2b1b7a428627`













