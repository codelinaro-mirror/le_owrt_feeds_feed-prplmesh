# prplMesh v5.0

## Headline features

This release contains the following updates:

* [FEAT-26](https://prplfoundationcloud.atlassian.net/browse/FEAT-26) prplMesh configuration should happen through the data model
* [FEAT-31](https://prplfoundationcloud.atlassian.net/browse/FEAT-31) Easymesh R5 support (verified using the WFA Easymesh testbed)
* [FEAT-35](https://prplfoundationcloud.atlassian.net/browse/FEAT-35) Wi-Fi Sensing phase 2a
* [FEAT-36](https://prplfoundationcloud.atlassian.net/browse/FEAT-36) Basic MLO support
* [FEAT-55](https://prplfoundationcloud.atlassian.net/browse/FEAT-55) Airties EasymeshPlus Agent extensions

This release also prepares the groundwork for full Wi-Fi 7 & Easymesh R6 support later in 2025.

## Known issues

* [PPW-508](https://prplfoundationcloud.atlassian.net/browse/PPW-508) Intermittent crash on OSPv2
* [PPW-509](https://prplfoundationcloud.atlassian.net/browse/PPW-509) Direct socket connection between pWHM and prplMesh is not quite working yet
* [PPW-519](https://prplfoundationcloud.atlassian.net/browse/PPW-519) ACL issue affecting web UI
* [PPW-525](https://prplfoundationcloud.atlassian.net/browse/PPW-525) A crash is occasionally seen during stress testing on the MaxLinear platform
* [PPW-543](https://prplfoundationcloud.atlassian.net/browse/PPW-543) prplMesh is not yet working with the Bridging manager
* [PPW-546](https://prplfoundationcloud.atlassian.net/browse/PPW-546) Interoperability issue with retail extender

## Issues addressed since 4.3.0

* [PPW-114](https://prplfoundationcloud.atlassian.net/browse/PPW-114): Unassociated STA Link Metrics Response message shows invalid values for Time Delta and uplink RCPI
* [PPW-135](https://prplfoundationcloud.atlassian.net/browse/PPW-135): prplmesh agent sends all supported operating classes even if non-operating channel list of a supported operating class has all the channels that operating class has
* [PPW-182](https://prplfoundationcloud.atlassian.net/browse/PPW-182): Incorrect Neighbor AL MAC Address in Link Metric Response for wireless associated clients
* [PPW-184](https://prplfoundationcloud.atlassian.net/browse/PPW-184): Link Metric Response TLV Also Includes STA Devices
* [PPW-226](https://prplfoundationcloud.atlassian.net/browse/PPW-226): \[prplMesh\]\[OSPv2\] Wireless onboarding failed when Auto channel selection is enabled on the WiFi radio interfaces
* [PPW-288](https://prplfoundationcloud.atlassian.net/browse/PPW-288): Channel Utilization and BSS Load element is not present in Channel Scan Report
* [PPW-337](https://prplfoundationcloud.atlassian.net/browse/PPW-337): Operating channel report is not generated if there is no channel change
* [PPW-377](https://prplfoundationcloud.atlassian.net/browse/PPW-377): \[prplAgent\]\[pwhm\] Incorrect Utilization and Noise Reporting
* [PPW-389](https://prplfoundationcloud.atlassian.net/browse/PPW-389): \[CORE\_AIR\_0026\] Easymesh Plus: Agent Operating Class Reporting
* [PPW-393](https://prplfoundationcloud.atlassian.net/browse/PPW-393): Inconsistency in AP Metrics Response period with metric reporting policy
* [PPW-396](https://prplfoundationcloud.atlassian.net/browse/PPW-396): \[CORE\_AIR\_0034\] RSSI Value Reported as 0 in Receiver Link Metric TLV
* [PPW-532](https://prplfoundationcloud.atlassian.net/browse/PPW-532): \[prplMesh\] Failure to complete onboarding after WPS pairingDone

* [PPM-146](https://prplfoundationcloud.atlassian.net/browse/PPM-146): \[TASK\] Remove Windows code
* [PPM-341](https://prplfoundationcloud.atlassian.net/browse/PPM-341): Move Backhaul config and radio params to Agent DB
* [PPM-2579](https://prplfoundationcloud.atlassian.net/browse/PPM-2579): Update WBAPI  Ambiorix  infrastructure and relavant bwl code  to use a direct  connections  to the WHM(USP backend)
* [PPM-2602](https://prplfoundationcloud.atlassian.net/browse/PPM-2602): Investigate wifi 6 capabilities on OSP and Haze
* [PPM-2927](https://prplfoundationcloud.atlassian.net/browse/PPM-2927): \[tlvf\] \[R6\] Add TLV Available Spectrum Inquiry Response TLV
* [PPM-2974](https://prplfoundationcloud.atlassian.net/browse/PPM-2974): \[multi-vendor\]\[Tx\] Generic Approach to include multivendor TLV as part of 1905 TX messages
* [PPM-2997](https://prplfoundationcloud.atlassian.net/browse/PPM-2997): Add Freedom to prplMesh CI
* [PPM-2998](https://prplfoundationcloud.atlassian.net/browse/PPM-2998): Release prplMesh v4.3
* [PPM-3010](https://prplfoundationcloud.atlassian.net/browse/PPM-3010): Need to remove controller profile support update
* [PPM-3014](https://prplfoundationcloud.atlassian.net/browse/PPM-3014): Incorrect Media Type and Media-Specific Information in Device Information TLV for WNC Freedom Board
* [PPM-3016](https://prplfoundationcloud.atlassian.net/browse/PPM-3016): CI: boardfarm: boardfarm failure due to pyasn1 upstep
* [PPM-3017](https://prplfoundationcloud.atlassian.net/browse/PPM-3017): Add OSPv2 to prplMesh CI
* [PPM-3019](https://prplfoundationcloud.atlassian.net/browse/PPM-3019): \[OSP\] ebtables is not working for OSP Platform
* [PPM-3026](https://prplfoundationcloud.atlassian.net/browse/PPM-3026): NBAPI: Generated documentation should have the correct copyright declaration
* [PPM-3028](https://prplfoundationcloud.atlassian.net/browse/PPM-3028): Capability TLVs in AP Capability Report Message Show Zero Values.
* [PPM-3037](https://prplfoundationcloud.atlassian.net/browse/PPM-3037): Prepare UCC server for EasyMesh R6 certification
* [PPM-3038](https://prplfoundationcloud.atlassian.net/browse/PPM-3038): Invalid RF Band for 6Ghz
* [PPM-3044](https://prplfoundationcloud.atlassian.net/browse/PPM-3044): Update dev\_set\_config command for EasyMesh R6 certification
* [PPM-3046](https://prplfoundationcloud.atlassian.net/browse/PPM-3046): Eht Operations tlv param size fix
* [PPM-3047](https://prplfoundationcloud.atlassian.net/browse/PPM-3047): \[Agent\] Fill WiFi7 agent capabilities tlv
* [PPM-3048](https://prplfoundationcloud.atlassian.net/browse/PPM-3048): \[Agent\] Fill Eht Operations tlv
* [PPM-3051](https://prplfoundationcloud.atlassian.net/browse/PPM-3051): AL-MAC is global bridge MAC address instead of LAA MAC as per 1905 spec
* [PPM-3059](https://prplfoundationcloud.atlassian.net/browse/PPM-3059): \[RDKB\] Update prplmesh version to 4.2.6
* [PPM-3070](https://prplfoundationcloud.atlassian.net/browse/PPM-3070): \[CORE\_AIR\_0012\] EasyMeshPlus Agent Version Reporting
* [PPM-3077](https://prplfoundationcloud.atlassian.net/browse/PPM-3077): \[CORE\_AIR\_0023\] Handling 3rd party EM Controllers and EM Agents
* [PPM-3082](https://prplfoundationcloud.atlassian.net/browse/PPM-3082): \[FEATURE\_AIR\_0001\] Airties Device Metrics
* [PPM-3091](https://prplfoundationcloud.atlassian.net/browse/PPM-3091): \[CORE\_AIR\_0020\]   EasyMesh duplicate credential update
* [PPM-3094](https://prplfoundationcloud.atlassian.net/browse/PPM-3094): \[pwhm\] Add two new rpcs to get current tx power and max tx power as dbm
* [PPM-3095](https://prplfoundationcloud.atlassian.net/browse/PPM-3095): \[FEATURE\_AIR\_0009\] Reporting of Firmware Version and Serial Number
* [PPM-3097](https://prplfoundationcloud.atlassian.net/browse/PPM-3097): \[FEATURE\_AIR\_0011\] BSS Configuration: Hidden SSID
* [PPM-3099](https://prplfoundationcloud.atlassian.net/browse/PPM-3099): beerocks\_fronthaul: random: daemon crashes during shutdown procedure via SIGTERM signal 
* [PPM-3101](https://prplfoundationcloud.atlassian.net/browse/PPM-3101): \[CORE\_AIR\_0031\] Refined Failed Connection Message
* [PPM-3104](https://prplfoundationcloud.atlassian.net/browse/PPM-3104): Implement \[FEATURE\_AIR\_0002\] Device Information
* [PPM-3111](https://prplfoundationcloud.atlassian.net/browse/PPM-3111): random: beerocks\_agent: process crashes during CDRouter Wireless testing
* [PPM-3114](https://prplfoundationcloud.atlassian.net/browse/PPM-3114): Investigate moving configuration options to ODL
* [PPM-3115](https://prplfoundationcloud.atlassian.net/browse/PPM-3115): \[RDKB\] Update prplMesh version to 4.3
* [PPM-3119](https://prplfoundationcloud.atlassian.net/browse/PPM-3119): \[Agent\] unused parameters in send\_channel\_preference\_report
* [PPM-3120](https://prplfoundationcloud.atlassian.net/browse/PPM-3120): \[Agent\]\[R6\] Eht supported handling
* [PPM-3121](https://prplfoundationcloud.atlassian.net/browse/PPM-3121): \[Agent\]\[R6\] early ap capability message
* [PPM-3129](https://prplfoundationcloud.atlassian.net/browse/PPM-3129): prplMesh/prplOS integration: restart process using process monitor
* [PPM-3130](https://prplfoundationcloud.atlassian.net/browse/PPM-3130): EasyMeshPlus \[RX Approach\] \[FEATURE\_AIR\_0005\] Airties Reboot/FactoryReset Feature 
* [PPM-3135](https://prplfoundationcloud.atlassian.net/browse/PPM-3135): beerocks\_controller and beerocks\_agent processes are crashing after triggering the Client Steering command
* [PPM-3138](https://prplfoundationcloud.atlassian.net/browse/PPM-3138): EasyMeshPlus \[CORE\_AIR\_0008\] IEEE 1905.1 Interface Identification
* [PPM-3140](https://prplfoundationcloud.atlassian.net/browse/PPM-3140): \[FEATURE\_AIR\_0003\] Airties Ethernet Stats
* [PPM-3147](https://prplfoundationcloud.atlassian.net/browse/PPM-3147): EasyMesh Plus \[FEATURE\_AIR\_0012\] Switching Wi-Fi On/Off on EM+ Agents
* [PPM-3150](https://prplfoundationcloud.atlassian.net/browse/PPM-3150): \[prplAgent\]\[CORE\_AIR\_0030\] Minimum Duration Between Consecutive Scans
* [PPM-3151](https://prplfoundationcloud.atlassian.net/browse/PPM-3151): prplmesh controller fail to access ambiorix bus
* [PPM-3152](https://prplfoundationcloud.atlassian.net/browse/PPM-3152): Moving configuration options to ODL
* [PPM-3153](https://prplfoundationcloud.atlassian.net/browse/PPM-3153): \[CORE\_0036\] Interpretation of multi-channel 802.11k beacon report measurement request
* [PPM-3155](https://prplfoundationcloud.atlassian.net/browse/PPM-3155): \[RDK-B\] heaptrack undefined reference to dl lib.
* [PPM-3163](https://prplfoundationcloud.atlassian.net/browse/PPM-3163): \[R6\]\[Controller\] WiFi7 Agent Capabilities TLV handling
* [PPM-3164](https://prplfoundationcloud.atlassian.net/browse/PPM-3164): \[R6\]\[Controller\] EHT Operations TLV handling
* [PPM-3165](https://prplfoundationcloud.atlassian.net/browse/PPM-3165): \[R6\]\[Controller\] early ap capability handling
* [PPM-3166](https://prplfoundationcloud.atlassian.net/browse/PPM-3166): \[Slave\]\[R6\] Handle WSC M8 TLV
* [PPM-3168](https://prplfoundationcloud.atlassian.net/browse/PPM-3168): \[Master\]\[R6\] Send WSC M8 TLV
* [PPM-3169](https://prplfoundationcloud.atlassian.net/browse/PPM-3169): CI: upstep prplOS to release version (v3.2.0)
* [PPM-3170](https://prplfoundationcloud.atlassian.net/browse/PPM-3170): RDKB: prevent DHCP/CcspPandMSsp console log spamming
* [PPM-3174](https://prplfoundationcloud.atlassian.net/browse/PPM-3174): Add 320MHz bandwidth support for WiFi 7
* [PPM-3176](https://prplfoundationcloud.atlassian.net/browse/PPM-3176): Non-1905.1 neighbor device list report
* [PPM-3192](https://prplfoundationcloud.atlassian.net/browse/PPM-3192): \[prplMesh/framework\] Improvement based on query type in handling Link Metric Query
* [PPM-3201](https://prplfoundationcloud.atlassian.net/browse/PPM-3201): Coverity: uninitialized variables
* [PPM-3203](https://prplfoundationcloud.atlassian.net/browse/PPM-3203): socket file descriptors close on exec
* [PPM-3205](https://prplfoundationcloud.atlassian.net/browse/PPM-3205): prplMesh must be able to connect to any bus
* [PPM-3208](https://prplfoundationcloud.atlassian.net/browse/PPM-3208): Handle CI issues regarding MR failure
* [PPM-3209](https://prplfoundationcloud.atlassian.net/browse/PPM-3209): \[prplAgent\]\[Steering Policy\] Implement BTM Steering Disallowed STA List
* [PPM-3210](https://prplfoundationcloud.atlassian.net/browse/PPM-3210): HW acceleration broken by prplMesh beerocks agent
* [PPM-3218](https://prplfoundationcloud.atlassian.net/browse/PPM-3218): beerocks\_agent crash
* [PPM-3239](https://prplfoundationcloud.atlassian.net/browse/PPM-3239): OSPv2: mainline-23.05: invalid hostapd configuration
* [PPM-3244](https://prplfoundationcloud.atlassian.net/browse/PPM-3244): beerocks\_vendor\_message: high cpu usage 
* [PPM-3245](https://prplfoundationcloud.atlassian.net/browse/PPM-3245): Detecting LAN Interfaces dynamically
* [PPM-3246](https://prplfoundationcloud.atlassian.net/browse/PPM-3246): CI: all targets: upstep prplOS version
* [PPM-3248](https://prplfoundationcloud.atlassian.net/browse/PPM-3248): Boardfarm tests are broken
* [PPM-3249](https://prplfoundationcloud.atlassian.net/browse/PPM-3249): Fix agent and controller crash on 5.0 rc1
* [PPM-3258](https://prplfoundationcloud.atlassian.net/browse/PPM-3258): Fix prplmesh agent process disappearing in some cases
* [PPM-3260](https://prplfoundationcloud.atlassian.net/browse/PPM-3260): odl: refactor to have agent and controller folders
* [PPM-3261](https://prplfoundationcloud.atlassian.net/browse/PPM-3261): Fix certification tests
* [PPM-3264](https://prplfoundationcloud.atlassian.net/browse/PPM-3264): CI: onboarding with zero bssid
* [PPM-3274](https://prplfoundationcloud.atlassian.net/browse/PPM-3274): Certification: Agent1 does not forward autoconfig responses to locally administrated MAC of DUT
* [PPM-3279](https://prplfoundationcloud.atlassian.net/browse/PPM-3279): controller: configuration: dcs\_channel\_pool
* [PPM-3285](https://prplfoundationcloud.atlassian.net/browse/PPM-3285): beerocks\_agent crash with reason SIGABRT
* [PPM-3287](https://prplfoundationcloud.atlassian.net/browse/PPM-3287): Onboarding WFA QCA controller fails
* [PPM-3295](https://prplfoundationcloud.atlassian.net/browse/PPM-3295): MFPConfig bit not set correctly
* [PPM-3298](https://prplfoundationcloud.atlassian.net/browse/PPM-3298): STA is added or not removed from Blacklist
