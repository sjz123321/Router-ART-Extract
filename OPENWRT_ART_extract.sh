#!/bin/sh
mtd_flag=`ls /dev/mtdblock4 | wc -l`
lrzsz_flag=`opkg list-installed | grep lrzsz | wc -l`
case $mtd_flag in
	0)
		echo "Error, not found ART block!"
		;;
	1)
		cat /dev/mtdblock4 > /tmp/ART.BIN
		echo "ART extract successfully"
		echo "save file to /tmp/ART.BIN"
		case $lrzsz_flag in
			0)
				echo "you can download it by SCP"
				;;
			1)
				echo "detect lrzsz!"
				echo "send file with Zmodem"
				sz /tmp/ART.BIN
				echo "File send successfully!"
				;;
		esac
		;;
esac
