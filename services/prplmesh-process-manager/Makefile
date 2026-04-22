include $(TOPDIR)/rules.mk

PKG_NAME:=prplmesh-process-manager
PKG_VERSION:=v0.2.0
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=3eec5cb324389d7134e99fb36889b23494358177
PKG_SOURCE_URL:=https://gitlab.com/prpl-foundation/prplmesh/prplmesh-process-manager.git
PKG_HASH:=skip
PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)

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
