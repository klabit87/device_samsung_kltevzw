#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    "/sys/class/graphics/fb0",
    "/sys/class/misc/android_adb",
    "/sys/class/android_usb/android0/f_adb",
    "/sys/class/tty/ptmx",
    "/sys/class/misc/uinput",

    // storage devices
    "/sys/dev/block*",
    "/sys/block/mmcblk0",
    "/sys/module/mmc_core",
    "/sys/module/mmcblk",

    // Input
    "/sys/class/input/input1",
    "/sys/class/input/input1/*",
    "/sys/class/input/input2",
    "/sys/class/input/input2/*",

    "/sys/bus*",
    "/sys/devices*",

    NULL
};
