include $(TOPDIR)/rules.mk

PKG_NAME:=mod-whm-wifimapper
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  CATEGORY:=prpl Foundation
  SUBMENU:=prplMesh
  TITLE:=WHM WiFi Mapper (TR181 + legacy sync)
  DEPENDS += +pwhm +libamxm +libsahtrace +libswlc +libamxc +libamxd +libamxo +libamxp +libamxb +libamxs +amxrt
endef

define Package/$(PKG_NAME)/description
 WHM WiFi mapper module with TR-181 and legacy mapping
endef

# TEMP: local source until mod_whm_legacy_mapper is merged
define Build/Prepare
	rm -rf $(PKG_BUILD_DIR)
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) $(CURDIR)/src/* $(PKG_BUILD_DIR)/
	$(CP) $(CURDIR)/include_priv $(PKG_BUILD_DIR)/
	$(CP) $(CURDIR)/makefile.inc $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		CC="$(TARGET_CC)" \
		STAGINGDIR="$(STAGING_DIR)" \
		CFLAGS="$(TARGET_CFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)" \
		V=1
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/lib/amx/wld/modules

	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/mod-whm-wifimapper.so \
		$(1)/usr/lib/amx/wld/modules/

	# copy ODL/config
	if [ -d $(CURDIR)/files ]; then \
		$(CP) $(CURDIR)/files/* $(1)/; \
	fi

	# cleanup
	find $(1) -name '*.a' -delete
	find $(1) -name '*.h' -delete
	find $(1) -name '*.pc' -delete
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
