include $(TOPDIR)/rules.mk

PKG_NAME:=prplmesh
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=6903054fccc7a558d5c7b9a3e1caf23199a7c5bc
PKG_SOURCE_URL:=https://gitlab.com/prpl-foundation/prplmesh/prplMesh.git
PKG_MIRROR_HASH:=0c3304cd9c47ff670787c8915774fcae65df51aab5bbaadb5010ebdfa9dedcb1
PKG_SOURCE_DATE:=2025-07-25
PKG_MAINTAINER:=Frederik Van Bogaert <frederik.vanbogaert@prplfoundation.org>
PKG_LICENSE:=BSD-2-Clause-Patent
PKG_LICENSE_FILES:=LICENSE

PRPLMESH_VERSION:=$(subst -,.,$(PKG_SOURCE_DATE))
PRPLMESH_REVISION:=$(PKG_SOURCE_VERSION)

PKG_BUILD_PARALLEL:=1
PKG_CONFIG_DEPENDS:= \
	CONFIG_WIRELESS_STA \
	CONFIG_TARGET_brcmbca \
	CONFIG_USE_PRPLMESH_WHM \
	CONFIG_PRPLMESH_ENABLE_UNIT_TESTS \
	CONFIG_PRPLMESH_ENABLE_AMBIORIX_UBUS_BACKEND

CMAKE_BINARY_SUBDIR:=build

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/prplmesh/default
	SECTION:=net
	CATEGORY:=prpl Foundation
	SUBMENU:=prplMesh
	TITLE:=prplmesh
	URL:=https://gitlab.com/prpl-foundation/prplmesh/prplMesh/-/blob/master/README.md
	MAINTAINER:=prplfoundation
endef

define Package/prplmesh
	$(Package/prplmesh/default)
	DEPENDS:= \
		+libstdcpp \
		+libpthread \
		+librt \
		+libjson-c \
		+libopenssl \
		+libnl \
		+uci \
		+ubus \
		+ubox \
		+ebtables

	DEPENDS+= \
		+kmod-sched-act-vlan \
		+kmod-sched-core \
		+kmod-sched-flower \
		+kmod-sched-prio
	DEPENDS+= \
		+hostapd-openssl \
		+wpa-supplicant-openssl

	DEPENDS+= \
		+PRPLMESH_ENABLE_AMBIORIX_UBUS_BACKEND:libamxb \
		+PRPLMESH_ENABLE_AMBIORIX_UBUS_BACKEND:libamxrt \
		+PRPLMESH_ENABLE_AMBIORIX_UBUS_BACKEND:mod-pcm-svc \
		+PRPLMESH_ENABLE_AMBIORIX_UBUS_BACKEND:pcm-manager \
		+PRPLMESH_ENABLE_AMBIORIX_UBUS_BACKEND:mod-amxb-ubus
#	pwhm dependency:
	DEPENDS+= +USE_PRPLMESH_WHM:pwhm
endef

define Package/prplmesh-unit-tests
	$(Package/prplmesh/default)
	TITLE+= - unit tests
	DEPENDS:=+prplmesh +@PRPLMESH_ENABLE_UNIT_TESTS
endef

define Package/prplmesh/config
	source "$(SOURCE)/Config.in"
endef

CMAKE_OPTIONS+= \
	-DTARGET_PLATFORM=openwrt \
	-DCMAKE_INSTALL_PREFIX=/opt/prplmesh \
	-DPLATFORM_BUILD_DIR=$(BUILD_DIR) \
	-DPLATFORM_STAGING_DIR=$(STAGING_DIR) \
	-DPLATFORM_INCLUDE_DIR=$(STAGING_DIR)/usr/include \
	-DCMAKE_CXX_FLAGS="-Wno-error=deprecated-declarations"

ifeq ($(wildcard $(PKG_BUILD_DIR)/.source_dir),)
	CMAKE_OPTIONS += -DPRPLMESH_REVISION=$(PRPLMESH_REVISION)
	CMAKE_OPTIONS += -DPRPLMESH_VERSION=$(PRPLMESH_VERSION)
endif

CMAKE_OPTIONS+=-DPython3_EXECUTABLE=$(STAGING_DIR_HOST)/bin/python3
$(eval $(call TestHostCommand,python3-yaml, \
	Please install the Python3 YAML module, \
	$(STAGING_DIR_HOST)/bin/python3 -c 'import yaml'))

DATAELEMENTS_ROOT_DM:=$(CONFIG_PRPL_CONTROLLER_ROOT_PATH)

ifeq ($(CONFIG_PRPLMESH_ENABLE_AMBIORIX_UBUS_BACKEND),y)
	CMAKE_OPTIONS += -DENABLE_NBAPI=ON
	CMAKE_OPTIONS += -DDATAELEMENTS_ROOT_DM="$(DATAELEMENTS_ROOT_DM)"
	CMAKE_OPTIONS += -DUBUS_SOCK="-DAMBIORIX_BACKEND_PATH=\\\"/usr/bin/mods/amxb/mod-amxb-ubus.so\\\" -DAMBIORIX_BUS_URI=\\\"ubus:/var/run/ubus/ubus.sock\\\""
ifeq ($(CONFIG_USE_PRPLMESH_WHM),y)
	CMAKE_OPTIONS += -DUSE_PRPLMESH_WHM=ON
	CMAKE_OPTIONS += -DWBAPI_SOCK="-DAMBIORIX_WBAPI_BACKEND_PATH=\\\"/usr/bin/mods/amxb/mod-amxb-ubus.so\\\" -DAMBIORIX_WBAPI_BUS_URI=\\\"ubus:/var/run/ubus/ubus.sock\\\""
endif
endif

CMAKE_OPTIONS+= -DBWL_TYPE=NL80211 \
	-DTARGET_PLATFORM_TYPE=turris-omnia

ifeq ($(CONFIG_PRPLMESH_ENABLE_UNIT_TESTS),y)
	CMAKE_OPTIONS += -DBUILD_TESTS=ON
endif

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/lib/libbml* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/include/beerocks/bml $(1)/usr/include/
endef

define Package/prplmesh/install
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/etc/uci-defaults
	$(INSTALL_DIR) $(1)/opt/prplmesh
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/etc/acl/admin
	$(INSTALL_DIR) $(1)/etc/amx/tr181-device/extensions
	$(INSTALL_BIN) ./files/etc/init.d/* $(1)/etc/init.d/
	$(INSTALL_BIN) ./files/etc/uci-defaults/* $(1)/etc/uci-defaults/
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/bin $(1)/opt/prplmesh/
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/scripts $(1)/opt/prplmesh/
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/lib/*.so* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/share $(1)/opt/prplmesh/
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/config $(1)/opt/prplmesh/
	$(CP) $(PKG_INSTALL_DIR)/etc/acl/admin/prplmesh.json $(1)/etc/acl/admin/
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/config/controller/odl/01_device-wifi_prplmesh_mapping.odl $(1)/etc/amx/tr181-device/extensions/
endef

define Package/prplmesh-unit-tests/install
	$(INSTALL_DIR) $(1)/opt/prplmesh/tests
	$(CP) $(PKG_INSTALL_DIR)/opt/prplmesh/tests $(1)/opt/prplmesh/
endef

$(eval $(call BuildPackage,prplmesh))
$(eval $(call BuildPackage,prplmesh-unit-tests))
