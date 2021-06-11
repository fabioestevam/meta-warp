FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

BPV := "${@'.'.join(d.getVar('PV').split('.')[0:2])}"
KBRANCH_warp ?= "linux-${BPV}.y"
KMACHINE_warp ?= "warp"
COMPATIBLE_MACHINE = "(warp)"

SRC_URI_append_warp = " \
	file://${BPV}/warp;type=kmeta;destsuffix=${BPV}/warp \
	file://common/warp;type=kmeta;destsuffix=common/warp \
	"
KERNEL_FEATURES_warp = " warp-standard.scc "
