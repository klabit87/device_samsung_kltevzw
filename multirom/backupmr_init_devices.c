
#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
	//"/sys/devices/virtual/mem/null",
	//"/sys/devices/virtual/misc/fuse",

	// Framebuffer
	"/sys/class/graphics/fb0",

	// Storage Devices
	"/sys/block/mmcblk0",
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0",
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001",
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p15", //boot
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p23", //system
	//"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p24", //cache
	//"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p2",  //modem
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p26", //userdata
	//"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p21", //persist
	//"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1",  //apnhlos
	
    /*
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p2",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p8",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0rpmb",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p11",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p12",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p13",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p14",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p15",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p20",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p21",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p22",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p23",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p24",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p25",
    "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p26",
    "/dev/block/bootdevice/by-name/*",
    */
    


	"/sys/bus/mmc",
	"/sys/bus/mmc/drivers/mmcblk",
	"/sys/bus/sdio/drivers/bcmsdh_sdmmc",
	"/sys/module/mmcblk",
    "/sys/module/mmc_core",

	// Input
	"/sys/class/input/input1",
	"/sys/class/input/input1/*",
	"/sys/class/input/input2",
	"/sys/class/input/input2/*",
    "/sys/class/misc/uinput",
    "/sys/devices/virtual/input*",


	// for adb
	"/sys/class/tty/ptmx",
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p23", //system
	"/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p26", //cache
	"/sys/class/misc/android_adb",
	"/sys/class/android_usb/android0/f_adb",
	"/sys/bus/usb",
/*
	"/sys/devices/system/cpu",
    "/sys/devices/system/cpu/cpu0/cpufreq/scaling_governor",
    "/sys/devices/system/cpu/cpu0/cpufreq/scaling_available_governors",
    "/sys/devices/system/cpu/cpu1/online",
    "/sys/devices/system/cpu/cpu2/online",
    "/sys/devices/system/cpu/cpu3/online",
    "/sys/devices/system/cpu/cpu1/cpufreq/scaling_governor",
    "/sys/devices/system/cpu/cpu2/cpufreq/scaling_governor",
    "/sys/devices/system/cpu/cpu3/cpufreq/scaling_governor",
    "/sys/devices/system/cpu/cpufreq/ondemand/up_threshold",
    "/sys/devices/system/cpu/cpufreq/ondemand/sampling_rate",
    "/sys/devices/system/cpu/cpufreq/ondemand/io_is_busy",
    "/sys/devices/system/cpu/cpufreq/ondemand/sampling_down_factor",
    "/sys/devices/system/cpu/cpufreq/ondemand/down_differential",
    "/sys/devices/system/cpu/cpufreq/ondemand/up_threshold_multi_core",
    "/sys/devices/system/cpu/cpufreq/ondemand/down_differential_multi_core",
    "/sys/devices/system/cpu/cpufreq/ondemand/optimal_freq",
    "/sys/devices/system/cpu/cpufreq/ondemand/sync_freq",
    "/sys/devices/system/cpu/cpufreq/ondemand/up_threshold_any_cpu_load",
    "/sys/devices/system/cpu/cpu0/cpufreq/scaling_min_freq",
    "/sys/devices/system/cpu/cpu1/cpufreq/scaling_min_freq",
    "/sys/devices/system/cpu/cpu2/cpufreq/scaling_min_freq",
    "/sys/devices/system/cpu/cpu3/cpufreq/scaling_min_freq",

    "/sys/module/lpm_levels/enable_low_power/l2",
    "/sys/module/lpm_levels/enable_low_power/pxo",
    "/sys/module/lpm_levels/enable_low_power/vdd_dig",
    "/sys/module/lpm_levels/enable_low_power/vdd_mem",
    "/sys/module/msm_pm/modes/cpu0/power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu1/power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu2/power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu3/power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu0/power_collapse/idle_enabled",
    "/sys/module/msm_pm/modes/cpu0/standalone_power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu1/standalone_power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu2/standalone_power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu3/standalone_power_collapse/suspend_enabled",
    "/sys/module/msm_pm/modes/cpu0/standalone_power_collapse/idle_enabled",
    "/sys/module/msm_pm/modes/cpu1/standalone_power_collapse/idle_enabled",
    "/sys/module/msm_pm/modes/cpu2/standalone_power_collapse/idle_enabled",
    "/sys/module/msm_pm/modes/cpu3/standalone_power_collapse/idle_enabled",
    "/sys/module/msm_pm/modes/cpu0/retention/idle_enabled",
    "/sys/module/msm_pm/modes/cpu1/retention/idle_enabled",
    "/sys/module/msm_pm/modes/cpu2/retention/idle_enabled",
    "/sys/module/msm_pm/modes/cpu3/retention/idle_enabled",
*/
	// Mount persist
	// "/sys/devices/msm_sdcc.1/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p21", //persist

	// For Qualcomm overlay - /dev/ion
	"/sys/devices/virtual/misc/ion",

	NULL
};