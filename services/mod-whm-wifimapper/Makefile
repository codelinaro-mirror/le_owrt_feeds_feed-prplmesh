include $(TOPDIR)/rules.mk

PKG_NAME:=mod-whm-wifimapper
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/mod-whm-wifimapper
  SECTION:=prplmesh
  CATEGORY:=prplMesh
  TITLE:=WHM WiFi Mapper Module
  DEPENDS:=+pwhm
endef

define Package/mod-whm-wifimapper/description
  TR-181 WiFi mapper module for WHM
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	cp -r ./src $(PKG_BUILD_DIR)/
	cp -r ./include_priv $(PKG_BUILD_DIR)/
	cp -r ./odl $(PKG_BUILD_DIR)/
	cp ./makefile.inc $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR)/src \
		CC="$(TARGET_CC)" \
		STAGINGDIR="$(STAGING_DIR)" \
		COMPONENT=mod-whm-wifimapper
endef

define Package/mod-whm-wifimapper/install
	# Install .so into modules directory (FIX)
	$(INSTALL_DIR) $(1)/usr/lib/amx/wld/modules
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/mod-whm-wifimapper.so \
		$(1)/usr/lib/amx/wld/modules/

	# ODL files (already correct)
	$(INSTALL_DIR) $(1)/etc/amx/wld/modules/mod-whm-wifimapper
	$(CP) $(PKG_BUILD_DIR)/odl/* \
		$(1)/etc/amx/wld/modules/mod-whm-wifimapper/
endef

$(eval $(call BuildPackage,mod-whm-wifimapper))
