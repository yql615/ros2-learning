# 一、ROS和ROS2是什么
ROS: Robot Operating System,机器人操作系统 
                                   
 ROS2（全新的ROS）：

1. 多机器人系统
2. 跨平台
3. 实时性
4. 网络连接
5. 产品化
6. 项目管理
+++

# 二、ROS1和ROS2对比

### 1.架构的颠覆
*  ROS1的架构下，所有节点需要使用 Master (节点管理器 ) 下进行管理
*  ROS2使用基于DDS的Discovery机制，和Master说拜拜 

 具体体现：
(1)OS
·ROS1：Linux
·ROS2:   Linux,Windows,MAC,RTOS
(2)通讯
·ROS1:  TCPROS/UDPROS
·ROS2:  DDS
(3)节点类型
·ROS1:  publish/subscribe
·ROS2:  discovery
(4)进程
·ROS1:  Nodelet
·ROS2:  Inra-process

### 2.API的重新设计
*  当前路径下面有哪些文件以及文件夹ROS1中的大部分代码都基于2009年2月设计的API
*  ROS2重新设计了用户API，但 使用方法类似
### 3.编译系统的升级
*  ROS1使用rosbuild,catkin管理项目     		
*  ROS2使用升级版的ament,colcon
+++

# 三、ROS2命令行操作

## 1. Linux中的命令行

1. pwd : 当前终端所在路径

2. ls : 当前路径下面有哪些文件以及文件夹

3. ls -a : 当前路径下面有哪些文件以及文件夹(包括隐藏文件---以点开头)

4. mkdir + 文件夹的名字（eg: mkdir text）： 在当前路径下面创建一个新的文件夹

5. cd + 文件夹的一个路径的一个目标的名称（eg: cd text/）: 在终端里面跳转 到目标文件夹（例如：text）

6. touch + 文件名称 .txt/cpp/py（eg: touch read.txt---txt为文本文件）: 创建一个新的文件

7. rm + 文件名称 .txt/cpp/py（eg : rm read.txt）: 删除文件

8. cd .. : 退回到上一级目录

9. rm -R + 文件夹名称（eg: rm -R text/）: 删除文件夹

10. sudo apt install + 应用的库的名称（eg : sudo apt install libopencv --- 安装opencv）

   【注】sudo : 提升当前用户的权限             apt : application,应用
## 2.ROS2中的命令行
* ros2 node == rosnode（对节点的的操作）
  ·  list
  ·  Info
  ·  ······
* ros2 topic == rostopic（对话题的操作===对机器人控制的接口 ）
  · list
  · pub
  ·  echo
  ·  ······
* ros2 bag 
  ·  record
  ·  info
  ·  play
  ·  list
  ·  ······
* ······
+++

# 四、工作空间与功能包：开发过程的大本营

## 1.什么是工作空间
* 工作空间：是一个存放项目开发相关的文件夹；是开发过程的大本营。
·  src: 代码空间（Source Space） 
· install：安装空间（Instal Spacel）
· build: 编译空间（Build Space）
· log: 日志空间（Log Space）
* 创建&编译工作空间
1. 创建工作空间
$ mkdir -p ~/dev_ws/src
$ cd ~/dev_ws/src
$ git clone https://gitee.com/guyuhome/ros2_21_tutorials.git （guyuhome课程资源）
2. 自动安装依赖
$ sudo apt install -y phthon3-pip
$ sudo pip3 install rosdepc（新版Ubuntu: sudo apt pipx）
$ sudo rosdepc init & rosdepc update
$ cd ..
$ rosdepc install -i --from-path src --rosdistro humble -y
3. 编译工作空间
$ sudo apt install python3-colcon-ros
$ cd ~/dev_ws/
$ colcon build
4. 设置环境变量
$ source install/local_setup.sh
$ echo "source ~/dev_ws/install/local_setup.sh">>~/.bashrc