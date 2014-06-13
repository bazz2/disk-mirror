#include <linux/module.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>
#include <linux/version.h>

/**
 * A simple block device driver based on memery
 *
 * Sample for using
 *  Create device file (first time only)
 *    Note: if your system have udev, it can create device file for you in time
 *          of lsmode and fdisk automatically; otherwise you need to create them yourself by following steps.
 *    mknod /dev/mirrdev b 72
 *    mknod /dev/mirrdev1 b 72 1
 *    mknod /dev/mirrdev2 b 72 2
 *  Create dirs for test (first time only)
 *    mkdir /mnt/temp1
 *    mkdir /mnt/temp2
 * Run it:
 *   make
 *   insmod mirrdev.ko <size=numK/M/G/T>
 *   fdisk /dev/mirrdev # create 2 partitions
 *   mkfs.ext3 /dev/mirrdev1
 *   mkfs.ext3 /dev/mirrdev2
 *   mount /dev/mirrdev1 /mnt/temp1
 *   mount /dev/mirrdev2 /mnt/temp2
 *   # play in /mnt/temp1 & /mnt/temp2
 *   umount /dev/mirrdev1
 *   umount /dev/mirrdev2
 *   rmmod mirrdev.ko
 */
