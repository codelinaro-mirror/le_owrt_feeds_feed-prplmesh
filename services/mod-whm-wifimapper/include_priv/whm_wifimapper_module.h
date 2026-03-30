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
#ifndef __WHM_SAH_MODULE_H__
#define __WHM_SAH_MODULE_H__

#include "wld/wld_vendorModule.h"

#define EXTENSION_VENDOR_NAME "SoftAtHome"

#define EXTENSION_MODULE_NAME "whm-wifimapper"

/**
 * @brief path of vendor module main odl file
 * eg: modules/mod-<vendorName>/mod-<vendorName>.odl
 */
#define VENDOR_MODULE_TOKEN WLD_VENDOR_MODULE_PREFIX EXTENSION_MODULE_NAME
#define ODL_DIR "modules/" VENDOR_MODULE_TOKEN
#define ODL_MAIN_FILE ODL_DIR "/" VENDOR_MODULE_TOKEN ".odl"
#define ODL_DEFAULTS_DIR ODL_DIR "/" VENDOR_MODULE_TOKEN "_defaults/"

bool whm_wifimapper_module_init();
bool whm_wifimapper_module_destroy();
bool whm_wifimapper_module_loadDefaults();

#endif // __WHM_SAH_MODULE_H__
