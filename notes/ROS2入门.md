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
+++

## 2.功能包(package)
### （1） 创建一个功能包

* ==C++ : ros2 pkg create --build-type ament_cmake + 名称==
eg : ros2 pkg create --build-type ament_cmake learning_pkg_c

* ==python : ros2 pkg create --build-type ament_python + 名称==
  eg : ros2 pkg create --build-type ament_python learning_pkg_python

  注：
  pkg : package
  create --build-type 后面加类型 ：ament_amake(cpp),  ament_python(py)
+++

# 五、节点：机器人的工作细胞

* ==执行具体任务的进程==
* ==独立运行的可执行文件==
* 可使用不同的编程语言
* 可分布式运行在不同主机
* ==通过节点名称进行管理==

## 1.第一个节点（面向过程编程）
* 编程接口初始化
* 创建节点并初始化
* 实现节点功能
* 销毁节点并关闭接口

## 2.优化一下代码（面向对象编程）
* 编程接口初始化
* 创建节点并初始化
* 实现节点功能（封装）
* 销毁节点并关闭接口

# 六、话题：节点间传递数据的桥梁

## 1.话题的特性
* 发布 / 订阅 模型
~ 举一个小例子：
   小明从A书店订阅《意林》，那么A书店就是发布者，小明就是订阅者

* 发布者或者订阅者可以不唯一
~ 同一个例子：
    小明可以从不同的地方订阅书籍，而A书店也不止小明一个订阅者，因此，发布者或者订阅者可能并不唯一

* 异步通信机制
~ 同一个例子：
    A书店发出书后，它并不知道小明什么时候能收到这本书，这就叫   异步通信机制
~ 异步的特性使话题更适用于一些周期发布的数据，比如：传感器的数据，运动控制的指令等

* .msg 文件定义通信的消息结构
~ 发布者和订阅者要有统一数据的描述格式 ： 消息 （消息是ros中一种接口定义的方式，与编程语言无关）

## 2.创建话题发布者的程序流程

* 编译接口初始化
* 创建节点并初始化
* 创建发布者对象
* 创建并填充话题消息
* 发布话题消息
* 销毁节点并关闭接口

```python
import rclpy  #引入ROS2的官方python库
from rclpy.node import Node    #从库中拿出创建节点Node的基础模板，后面发布者节点类要继承它
from std_msgs.msg import String   #导入字符串消息（ROS2收发数据必须规定消息格式；std_msgs => 标准消息包；String => 代表纯文本字符串消息）


 /*创建发布者节点类*/
class PublisherNode(Node):  #自定义一个发布者节点类，继承上面导入的基础Node

 /*构造函数（类初始化方法，创建节点时自动执行*/
	def __init__(self,name):  #类的初始方法，创建节点实例时自动运行（self代表类自身，name时自定义的节点名字 => ros2中要求每个节点必须有唯一的名字）
        super().__init__(name)  #调用父类Node的初始化，把节点名字传给底层ROS系统，完成节点注册
        self.pub = self.create_publisher(String, "chatter", 10)  #创建发布器Publisher(向外发送消息)；String => 发送的数据类型是字符串；chatter => 话题名，收发消息必须话题名完全一致才能通信；10 => 消息队列长度，缓存10条消息，消息来不及接收时暂存
        self.timer = self.create_timer(0.5, self.time_callback)  #创建定时器，定时执行发送消息的函数
        
 /*定时回调函数（到时间自动执行，发送文字，类内置功能函数）*/
	def timer_callback(self):  #定时器绑定的回调函数，每0.5秒自动运行一次
        msg = String()  #创建一条空的字符串消息载体，所有要发送的数据都存在这个msg对象里
        msg.data = "helloworld"  #ROS字符串消息固定用 .data 存文本，把要发送到文字赋值进去
        self.pub.publish(msg)  #调用前面创建的发布器，把这条msg消息发送到chatter这个话题上
        self.get_logger().info('Publishing: "%s"' % msg.data)  #日志打印，在终端输出你的发送内容，方便看程序运行状态， %s => 占位符，替换 msg.data 里的文字
	
    
 /*主函数：程序入口（运行代码时最先执行）*/
def main (args=None) :  #整个程序的入口函数，运行这个py文件会自动执行main
	rclpy.init(args=args)   #初始化ROS2环境（注意：所有ROS程序第一行必须执行这个，不初始化无法创建节点，接收消息）
	node = PublisherNode("topic_helloworld_pub")   #实例化我们写的发布节点，给节点命名topic_helloworld_pub，执行上面的 __int__ 初始化代码，创建发布器、定时器
	rclpy.spin(node)  #阻塞循环（死循环），让节点持续运行；一直监听定时器、持续发消息（没有这行，程序创建完节点会立刻直接退出）
	node.destroy_node()  #销毁我们创建的节点，释放资源
	rclpy.shutdown()  #彻底关闭整个ROS2运行环境
	
```
==提醒：==
1. self.pub = self.create_publisher(String, "chatter", 10)
~  self.  : 必须加，代表把把变量绑定到当前节点，整个类里面所有函数都能调用 ；不加 self 只写 pub ,则只能在初始化函数里用，定时回调函数拿不到（类内全局变量）
~ pub : 自定义变量名，在发布节点里一般写pub
~ create_publisher()  :  创建发布者，ROS2节点自带固定方法
2. self.timer = self.create_timer(0.5, self.time_callback)
~  self.  : 必须加，代表把把变量绑定到当前节点，整个类里面所有函数都能调用 ；不加 self 只写 timer ,则只能在初始化函数里用，定时回调函数拿不到（类内全局变量）
~ timer : 自定义变量名，在发布节点里一般写timer
~ create_timer()  :  创建定时器，ROS2节点自带固定方法
3. ROS2节点自带的固定方法（名字不能乱写）
~ create_subscription()  :  创建订阅者
~ create_timer()  :  创建定时器
~ create_service()  :  创建服务服务端
~ create_client()  :  创建服务客户端
~ create_publisher()  :  创建发布者

## 3.创建话题订阅者的程序流程

* 编译接口初始化
* 创建节点并初始化
* 创建发布者对象
* 创建并填充话题消息
* 发布话题消息
* 销毁节点并关闭接口
 