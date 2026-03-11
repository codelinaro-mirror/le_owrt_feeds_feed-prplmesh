include $(TOPDIR)/rules.mk

PKG_NAME:=prplmesh-process-manager
PKG_VERSION:=v0.2.0
PKG_RELEASE:=1

PKG_SOURCE:=prplmesh-process-manager-v0.2.0.tar.gz
PKG_SOURCE_URL:=https://gitlab.com/prpl-foundation/prplmesh/prplmesh-process-manager/-/archive/v0.2.0
PKG_HASH:=2b50cb022136fda7f13a12d10a616948252c201491d2aace90392f8e34764563
PKG_BUILD_DIR:=$(BUILD_DIR)/prplmesh-process-manager-v0.2.0

PKG_LICENSE:=BSD-2-Clause-Patent
PKG_LICENSE_FILES:=LICENSE

COMPONENT:=prplmesh-process-manager

PKG_BUILD_PARALLEL:=1
TARGET_LDFLAGS += -L$(STAGING_DIR)/lib # libsahtrace is not in /usr/lib for some reason

CMAKE_BINARY_SUBDIR:=build
CMAKE_OPTIONS += -DINIT_SYSTEM=PROCD

CMAKE_OPTIONS += \
        -DPRPLMESH_PROCESS_MANAGER_START_ORDER=$(CONFIG_PRPLMESH_PROCESS_MANAGER_START_ORDER) \
        -DPRPLMESH_PROCESS_MANAGER_STOP_ORDER=$(CONFIG_PRPLMESH_PROCESS_MANAGER_STOP_ORDER) \
        -DPRPLMESH_DM_MAPPER=ON

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk


define Package/$(PKG_NAME)
	CATEGORY:=prpl Foundation
	TITLE:=prplmesh-process-manager
	MAINTAINER:=Inango <support@inango-systems.com>

	DEPENDS += +mod-amxb-ubus
	DEPENDS += +mod-amxb-usp
	DEPENDS += +libamxb
	DEPENDS += +libamxc
	DEPENDS += +libamxp
	DEPENDS += +libamxrt
	DEPENDS += +libamxd
	DEPENDS += +libamxo
	DEPENDS += +libsahtrace
endef

define Package/$(PKG_NAME)/description
	prplmesh-process-manager - process management from datamodel
endef

define Package/$(PKG_NAME)/install
	$(CP) $(PKG_INSTALL_DIR)/* $(1)/

	$(INSTALL_DIR) $(1)/usr/bin
	$(LN) amxrt $(1)/usr/bin/prplmesh-process-manager
endef

define Package/$(PKG_NAME)/config
        source "$(SOURCE)/Config.in"
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
