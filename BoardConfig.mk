# Copyright (C) 2016 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common klte
-include device/samsung/klte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := kltevzw,klte

# Kernel
TARGET_KERNEL_VARIANT_CONFIG := msm8974pro_sec_klte_vzw_defconfig

# Init
TARGET_INIT_VENDOR_LIB := libinit_msm
TARGET_LIBINIT_DEFINES_FILE := device/samsung/kltevzw/init/init_klte.cpp
TARGET_UNIFIED_DEVICE := true

# NFC
BOARD_NFC_CHIPSET := pn547

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 13631488
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 15728640
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 3145728000
BOARD_USERDATAIMAGE_PARTITION_SIZE := 11334040576

# inherit from the proprietary version
-include vendor/samsung/kltevzw/BoardConfigVendor.mk

# Recovery
TARGET_RECOVERY_IS_MULTIROM := true
TW_THEME := portrait_hdpi


# MultiRom config. MultiROM also uses parts of TWRP config
MR_INPUT_TYPE := type_b
MR_INIT_DEVICES := device/samsung/kltevzw/multirom/mr_init_devices.c
MR_DEVICE_HOOKS := device/samsung/kltevzw/multirom/mr_hooks.c
MR_DEVICE_HOOKS_VER := 4
MR_DPI := hdpi
MR_DPI_FONT := 340
MR_FSTAB := device/samsung/kltevzw/twrp.fstab
MR_KEXEC_MEM_MIN := 0x02c00000
MR_USE_MROM_FSTAB := true
MR_PIXEL_FORMAT := "RGBX_8888"
MR_USE_QCOM_OVERLAY := true
MR_QCOM_OVERLAY_HEADER := device/samsung/kltevzw/multirom/overlay/mr_qcom_overlay.h
MR_QCOM_OVERLAY_CUSTOM_PIXEL_FORMAT := MDP_RGBX_8888
RECOVERY_GRAPHICS_USE_LINELENGTH := true
MR_DPI_MUL := 2.0
# MR_KEXEC_DTB := true
MR_CONTINUOUS_FB_UPDATE := true
MR_ALLOW_NKK71_NOKEXEC_WORKAROUND := true