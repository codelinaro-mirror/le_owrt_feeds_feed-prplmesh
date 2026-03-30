/****************************************************************************
**
** Copyright (c)  2026 SoftAtHome
**
** The information and source code contained herein is the exclusive
** property of SoftAtHome and may not be disclosed, examined, or
** reproduced in whole or in part without explicit written authorization
** of the copyright owner.
**
****************************************************************************/

#include "../include_priv/whm_wifimapper_module.h"

#include <debug/sahtrace.h>

#include "wld/wld.h"
#include "wld/wld_radio.h"
#include "wld/wld_nl80211_api.h"

#define ME "mapMod"
							       
typedef struct {
    bool init;
    uint32_t moduleId;
} whm_wifimapper_module_t;

static whm_wifimapper_module_t s_self = {
    .init = false,
    .moduleId = 0,
};

bool whm_wifimapper_module_init(void) {
    ASSERT_FALSE(s_self.init, false, ME, "already initialized");

    s_self.moduleId = wld_extMod_register(EXTENSION_VENDOR_NAME, EXTENSION_MODULE_NAME);
    SAH_TRACEZ_WARNING(ME, "wifiMapper module init : id %u", s_self.moduleId);
    ASSERT_TRUE(s_self.moduleId > 0, false, ME, "Failure to register module");

    /* load private vendor datamodel extension and config options*/
    swl_rc_ne ret = wld_vendorModule_parseOdl(ODL_MAIN_FILE);
    ASSERT_EQUALS(ret, SWL_RC_OK, false, ME, "Fail to load vendor odl file");

    /* register private trace zones to pwhm */
    wld_vendorModule_loadPrivTraceZones(amxo_parser_get_config(get_wld_plugin_parser(), "mod-trace-zones"));

    SAH_TRACEZ_WARNING(ME, "WiFiMapper module init");
    s_self.init = true;

    return true;
}

bool whm_wifimapper_module_destroy(void) {
    ASSERTS_TRUE(s_self.init, false, ME, "Not initialized");

    wld_extMod_unregister(s_self.moduleId);

    s_self.moduleId = 0;
    s_self.init = false;
    return true;
}

bool whm_wifimapper_module_loadDefaults(void) {
    ASSERTS_TRUE(s_self.init, false, ME, "Not initialized");
    swl_rc_ne ret = wld_vendorModule_loadOdls(ODL_DEFAULTS_DIR);
    ASSERT_EQUALS(ret, SWL_RC_OK, false, ME, "Fail to load vendor odl defaults");
    return true;
}

