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
#include <string.h>
#include <stdlib.h>
#include <debug/sahtrace.h>
#include <errno.h>

#include "../include_priv/whm_wifimapper_module.h"
#include "wld/wld.h"
#include "wld/wld_vendorModule.h"

#define ME "mapMain"

static bool s_initCb(wld_vendorModule_initInfo_t* pInitInfo _UNUSED) {
    SAH_TRACEZ_IN(ME);
    SAH_TRACEZ_WARNING(ME, "Start wifiMapper vendor module");
    whm_wifimapper_module_init();
    SAH_TRACEZ_OUT(ME);
    return true;
}

static bool s_destroyCb() {
    SAH_TRACEZ_IN(ME);
    SAH_TRACEZ_WARNING(ME, "Stop wifiMapper vendor module");
    whm_wifimapper_module_destroy();
    SAH_TRACEZ_OUT(ME);
    return true;
}

static bool s_loadDefaultsCb() {
    SAH_TRACEZ_IN(ME);
    SAH_TRACEZ_WARNING(ME, "Loading default dm configs of wifiMapper vendor module");
    whm_wifimapper_module_loadDefaults();
    SAH_TRACEZ_OUT(ME);
    return true;
}

static const wld_vendorModule_handlers_cb s_Cbs = {
    .fInitCb = s_initCb,
    .fDeinitCb = s_destroyCb,
    .fLoadDefaultsCb = s_loadDefaultsCb,
};

/**
 * @brief: Global amxm vendor module call handler.
 * This function is called for all apis invoked by wld plugin side.
 * No processing is done here (only display) ,
 * but the vendor module asks lib_wld to forward call (and convert args/ret)
 * to wld vendor module internal handler.
 *
 * @return 0 for success, < 0 when error occurs
 */
static int s_globalCb(const char* const funcName, amxc_var_t* args, amxc_var_t* ret _UNUSED) {
    SAH_TRACEZ_INFO(ME, "function %s called", funcName);
    return wld_vendorModule_forwardCall(funcName, args, ret, &s_Cbs);
}

static AMXM_CONSTRUCTOR s_onLoad(void) {
    SAH_TRACEZ_IN(ME);
    SAH_TRACEZ_WARNING(ME, "Load vendor module");
    wld_vendorModule_config_t config = {
        .fGlobalCb = s_globalCb,
    };
    wld_vendorModule_register(EXTENSION_MODULE_NAME, &config);
    SAH_TRACEZ_OUT(ME);
    return 0;
}

static AMXM_DESTRUCTOR s_onUnload(void) {
    SAH_TRACEZ_IN(ME);
    SAH_TRACEZ_WARNING(ME, "UnLoad vendor module");
    whm_wifimapper_module_destroy();
    wld_vendorModule_unregister(EXTENSION_MODULE_NAME);
    SAH_TRACEZ_OUT(ME);
    return 0;
}

