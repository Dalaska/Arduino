# Arduino Projects for Auto Electrnoics
This project is for AUE 835 Automotive Electronic Class I took at Clemson University in 2013

## Objective
The goal of this project to prototype some applications in automotive electronics system

## Usage 
1. wire the compnent to the Arduino Uno board
2. load the source code into Arudino using the laugage Processing

## Hardware and Software requirement:
Hardware: [Arduino Uno starter kit](https://www.adafruit.com/)    
Programing lauguage: [Processing](https://processing.org/)

*树莓派*

配置：1.4GHz 64-bit 4-core ARM Cortex-A53 CPU，1G LPDDR2，2.4/5GHz无线网卡，4.2蓝牙，300Mbps以太网口，4个USB2.0，全尺寸HDMI，MIPI显示及相机接口，40针GPIO，SD卡存储，5V DC micro USB及PoE供电，能够运行Linux。

- 部署HTTP服务器，测试和运行web系统；
- 媒体服务器、文件服务器或电视机顶盒；
- ssh远程访问;

*内网穿透*

内网穿透方式有几种:
- 申请固定IP专线。稳定且速度有保障，缺点是费用高。

- 云方案。把业务主机都搬到云上，直接通过云主机来访问。

- 云主机+内网穿透方案。通过云主机做跳板来实现内网穿透，既可以复用现有的业务系统，又解决了公网IP的问题。


没有公网IP的解决方案，分为两个步骤：

-  本地局域网和云主机之间搭建虚拟局域网。

- 在云主机上配置内网穿透的防火墙规则。具体步骤如下：

1. 搭建虚拟局域网, 首先要在云主机上安装虚拟局域网软件，配置ca证书等。 然后是客户端配置。在WSG的客户端中，配置上云主机的IP和端口、用户名密码等信息。即可成功组网。

2. 内网穿透的防火墙规则, 组建虚拟局域网后，本地局域网就和云主机处于同一个局域网内。
我们再通过iptables配置一些防火墙规则，就可以把外网访问重定向到局域网内部；原理和端口映射是一样的。[link](https://blog.csdn.net/Mrqiang9001/article/details/100030694)
[link](https://service.oray.com/question/1669.html)