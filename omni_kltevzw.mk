$(call inherit-product, vendor/omni/config/common_full_phone.mk)

$(call inherit-product, vendor/omni/config/nfc_enhanced.mk)

$(call inherit-product, vendor/omni/config/common.mk)

$(call inherit-product, device/samsung/kltevzw/full_kltevzw.mk)

PRODUCT_NAME := omni_kltevzw
PRODUCT_DEVICE := kltevzw
PRODUCT_BRAND := samsung
PRODUCT_MANUFACTURER := Samsung
PRODUCT_MODEL := SM-G900V

PRODUCT_BUILD_PROP_OVERRIDES += \
	PRODUCT_NAME=klte \
	TARGET_DEVICE=kltevzw \
	PRIVATE_BUILD_DESC="Verizon/kltevzw/kltevzw:5.0/LRX21T/G900VVRU2BPB1:user/release-keys" \
	BUILD_FINGERPRINT="samsung/klte/kltevzw:5.0/LRX21T/G900VVRU2BPB1:user/release-keys"
