SOC_FAMILY ?= "imx7"

MACHINEOVERRIDES =. "mx7:mx7d:"

ARM_INSTRUCTION_SET = "thumb"

require conf/machine/include/tune-cortexa7.inc
require conf/machine/include/soc-family.inc

MACHINE_FEATURES ?= "apm ext2 serial usbgadget usbhost"

SERIAL_CONSOLE = "115200 ttymxc0"

# U-Boot bootloader
UBOOT_ENTRYPOINT := "0x80800000"
UBOOT_MAKE_TARGET := "u-boot-dtb.imx"
UBOOT_BINARY := "u-boot-dtb.imx"
UBOOT_SUFFIX ?= "imx"
UBOOT_MACHINE = "warp7_defconfig"
UBOOT_DTB_LOADADDRESS = "0x83000000"

PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot-mainline"
PREFERRED_PROVIDER_u-boot ?= "u-boot-mainline"
PREFERRED_PROVIDER_u-boot-native ?= "u-boot-mainline"
PREFERRED_PROVIDER_u-boot-fw-utils ?= "u-boot-mainline-fw-utils"
PREFERRED_PROVIDER_u-boot-fw-utils-native ?= "u-boot-mainline-fw-utils-native"
PREFERRED_PROVIDER_u-boot-tools ?= "u-boot-mainline-tools"
PREFERRED_PROVIDER_u-boot-tools-native ?= "u-boot-mainline-tools-native"
PREFERRED_VERSION_u-boot ?= "2021.01%"
PREFERRED_VERSION_u-boot-native ?= "2021.01%"
PREFERRED_VERSION_u-boot-fw-utils ?= "2021.01%"
PREFERRED_VERSION_u-boot-fw-utils-native ?= "2021.01%"
PREFERRED_VERSION_u-boot-mainline-tools ?= "2021.01%"
PREFERRED_VERSION_u-boot-mainline-tools-native ?= "2021.01%"

# Linux kernel
PREFERRED_PROVIDER_virtual/kernel ?= "linux-stable"
PREFERRED_VERSION_linux-stable ?= "5.10%"
PREFERRED_VERSION_linux-yocto ?= "5.10%"

# WPE (from meta-webkit)
PREFERRED_RPROVIDER_virtual/wpebackend ?= "wpebackend-fdo"

# Ship kernel modules
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += " \
	kernel-modules kernel-devicetree \
	firmware-imx-sdma-imx6q u-boot-default-env \
	"

# List of images to be built
IMAGE_FSTYPES ?= "tar.xz wic.xz wic.gz"
INITRAMFS_FSTYPES ?= "cpio.xz"

EXTRA_IMAGEDEPENDS += "virtual/bootloader"
WKS_FILE = "sdimage-imx.wks"
IMAGE_BOOT_FILES ?= "${KERNEL_IMAGETYPE}"
IMAGE_INSTALL_append = " kernel-devicetree virtual/bootloader "
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot virtual/bootloader:do_deploy"

# Add any optional config files that might be present e.g. in other layers
include conf/machine/include/warp-common-extra.inc
include conf/machine/${MACHINE}-extra.conf
