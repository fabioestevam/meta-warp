FILESEXTRAPATHS_prepend := "${THISDIR}/files/common:${THISDIR}/files/${MACHINE}:${THISDIR}/files:"
RPROVIDES_${PN} = "virtual/bootloader"

DEPENDS_append_warp = "u-boot-mainline-tools-native"
