# 路由器ART参数提取

**[English](/README.md)**

从编程器固件或Openwrt系统中提取ART参数

# 使用方法 

### 注意: 只支持高通或Atheros的芯片.请勿在联发科和博通芯片上使用!

版本 : V1.0 目前只测试支持了TP-LINK fast路由器(从编程器固件获取ART) 

或者从一个基于Openwrt系统的路由上获取ART参数.


## 从编程器固件获取ART

1. 从release页面下载 SPI-ART-extract-

2. 选择编程器固件所在路径

在命令行下使用./SPI-ART-extract ./XXX.bin 或者 打开可执行文件再输入BIN文件路径，两种方法均可。

3. 在执行目录下你会得到ART_OUTPUT.BIN

## 从Openwrt路由器中获取ART参数

1. 下载release页面下的 OPENWRT_ART_extract.sh

2. 上传脚本至路由 SCP FTP方式等

3. 执行`chmod +x OPENWRT_ART_extract.sh && ./OPENWRT_ART_extract.sh`

## 自行编译

1. git 克隆

2. 执行`gcc SPI-ART-extract.c -o SPI-ART-extract -std=gnu99`
