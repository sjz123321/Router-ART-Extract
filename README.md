# Router-ART-Extract

**[中文](/README-ZH-CN.md)**

Extract ART Parameter from SPI flash or Openwrt system

# Usage 

### Notice: Just support Atheros or Qualcomm Chip. DO NOT USE IT ON MTK OR BCM devices!

Version : V1.0 Just support TP-LINK Devices(Extract ART from SPI flash) 

Or a Router based on Openwrt(Extract ART from system).


## Extract ART from SPI flash

1. Download release program SPI-ART-extract-

2. Specify the path for the file location（THE BIN files read from SPI flash)

like ./SPI-ART-extract ./XXX.bin Or open it and type the BIN file PATH.

3. You will get ART_OUTPUT.BIN where the executable file is located.

## Extract ART from Openwrt

1. Download release program OPENWRT_ART_extract.sh

2. upload file to your router by SCP FTP ...

3.  `chmod +x OPENWRT_ART_extract.sh && ./OPENWRT_ART_extract.sh`

## Compile by yourself

1. clone this repo

2. `gcc SPI-ART-extract.c -o SPI-ART-extract -std=gnu99`
