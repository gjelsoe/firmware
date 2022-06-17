/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6 */

#ifndef PB_CONFIG_PB_H_INCLUDED
#define PB_CONFIG_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _Config_DeviceConfig_Role { 
    Config_DeviceConfig_Role_Client = 0, 
    Config_DeviceConfig_Role_ClientMute = 1, 
    Config_DeviceConfig_Role_Router = 2, 
    Config_DeviceConfig_Role_RouterClient = 3 
} Config_DeviceConfig_Role;

typedef enum _Config_PositionConfig_PositionFlags { 
    Config_PositionConfig_PositionFlags_POS_UNDEFINED = 0, 
    Config_PositionConfig_PositionFlags_POS_ALTITUDE = 1, 
    Config_PositionConfig_PositionFlags_POS_ALT_MSL = 2, 
    Config_PositionConfig_PositionFlags_POS_GEO_SEP = 4, 
    Config_PositionConfig_PositionFlags_POS_DOP = 8, 
    Config_PositionConfig_PositionFlags_POS_HVDOP = 16, 
    Config_PositionConfig_PositionFlags_POS_SATINVIEW = 32, 
    Config_PositionConfig_PositionFlags_POS_SEQ_NOS = 64, 
    Config_PositionConfig_PositionFlags_POS_TIMESTAMP = 128 
} Config_PositionConfig_PositionFlags;

typedef enum _Config_PowerConfig_ChargeCurrent { 
    Config_PowerConfig_ChargeCurrent_MAUnset = 0, 
    Config_PowerConfig_ChargeCurrent_MA100 = 1, 
    Config_PowerConfig_ChargeCurrent_MA190 = 2, 
    Config_PowerConfig_ChargeCurrent_MA280 = 3, 
    Config_PowerConfig_ChargeCurrent_MA360 = 4, 
    Config_PowerConfig_ChargeCurrent_MA450 = 5, 
    Config_PowerConfig_ChargeCurrent_MA550 = 6, 
    Config_PowerConfig_ChargeCurrent_MA630 = 7, 
    Config_PowerConfig_ChargeCurrent_MA700 = 8, 
    Config_PowerConfig_ChargeCurrent_MA780 = 9, 
    Config_PowerConfig_ChargeCurrent_MA880 = 10, 
    Config_PowerConfig_ChargeCurrent_MA960 = 11, 
    Config_PowerConfig_ChargeCurrent_MA1000 = 12, 
    Config_PowerConfig_ChargeCurrent_MA1080 = 13, 
    Config_PowerConfig_ChargeCurrent_MA1160 = 14, 
    Config_PowerConfig_ChargeCurrent_MA1240 = 15, 
    Config_PowerConfig_ChargeCurrent_MA1320 = 16 
} Config_PowerConfig_ChargeCurrent;

typedef enum _Config_DisplayConfig_GpsCoordinateFormat { 
    Config_DisplayConfig_GpsCoordinateFormat_GpsFormatDec = 0, 
    Config_DisplayConfig_GpsCoordinateFormat_GpsFormatDMS = 1, 
    Config_DisplayConfig_GpsCoordinateFormat_GpsFormatUTM = 2, 
    Config_DisplayConfig_GpsCoordinateFormat_GpsFormatMGRS = 3, 
    Config_DisplayConfig_GpsCoordinateFormat_GpsFormatOLC = 4, 
    Config_DisplayConfig_GpsCoordinateFormat_GpsFormatOSGR = 5 
} Config_DisplayConfig_GpsCoordinateFormat;

typedef enum _Config_LoRaConfig_RegionCode { 
    Config_LoRaConfig_RegionCode_Unset = 0, 
    Config_LoRaConfig_RegionCode_US = 1, 
    Config_LoRaConfig_RegionCode_EU433 = 2, 
    Config_LoRaConfig_RegionCode_EU868 = 3, 
    Config_LoRaConfig_RegionCode_CN = 4, 
    Config_LoRaConfig_RegionCode_JP = 5, 
    Config_LoRaConfig_RegionCode_ANZ = 6, 
    Config_LoRaConfig_RegionCode_KR = 7, 
    Config_LoRaConfig_RegionCode_TW = 8, 
    Config_LoRaConfig_RegionCode_RU = 9, 
    Config_LoRaConfig_RegionCode_IN = 10, 
    Config_LoRaConfig_RegionCode_NZ865 = 11, 
    Config_LoRaConfig_RegionCode_TH = 12 
} Config_LoRaConfig_RegionCode;

typedef enum _Config_LoRaConfig_ModemPreset { 
    Config_LoRaConfig_ModemPreset_LongFast = 0, 
    Config_LoRaConfig_ModemPreset_LongSlow = 1, 
    Config_LoRaConfig_ModemPreset_VLongSlow = 2, 
    Config_LoRaConfig_ModemPreset_MidSlow = 3, 
    Config_LoRaConfig_ModemPreset_MidFast = 4, 
    Config_LoRaConfig_ModemPreset_ShortSlow = 5, 
    Config_LoRaConfig_ModemPreset_ShortFast = 6 
} Config_LoRaConfig_ModemPreset;

/* Struct definitions */
typedef struct _Config_DeviceConfig { 
    Config_DeviceConfig_Role role;
    bool serial_disabled;
    bool factory_reset;
    bool debug_log_enabled;
    char ntp_server[33];
} Config_DeviceConfig;

typedef struct _Config_DisplayConfig { 
    uint32_t screen_on_secs;
    Config_DisplayConfig_GpsCoordinateFormat gps_format;
    uint32_t auto_screen_carousel_secs;
} Config_DisplayConfig;

typedef struct _Config_LoRaConfig { 
    int32_t tx_power;
    Config_LoRaConfig_ModemPreset modem_preset;
    uint32_t bandwidth;
    uint32_t spread_factor;
    uint32_t coding_rate;
    float frequency_offset;
    Config_LoRaConfig_RegionCode region;
    uint32_t hop_limit;
    bool tx_disabled;
    pb_size_t ignore_incoming_count;
    uint32_t ignore_incoming[3];
} Config_LoRaConfig;

typedef struct _Config_PositionConfig { 
    uint32_t position_broadcast_secs;
    bool position_broadcast_smart_disabled;
    bool fixed_position;
    bool gps_disabled;
    uint32_t gps_update_interval;
    uint32_t gps_attempt_time;
    uint32_t position_flags;
} Config_PositionConfig;

typedef struct _Config_PowerConfig { 
    Config_PowerConfig_ChargeCurrent charge_current;
    bool is_power_saving;
    bool is_always_powered;
    uint32_t on_battery_shutdown_after_secs;
    float adc_multiplier_override;
    uint32_t wait_bluetooth_secs;
    uint32_t mesh_sds_timeout_secs;
    uint32_t sds_secs;
    uint32_t ls_secs;
    uint32_t min_wake_secs;
} Config_PowerConfig;

typedef struct _Config_WiFiConfig { 
    char ssid[33];
    char psk[64];
    bool ap_mode;
    bool ap_hidden;
} Config_WiFiConfig;

typedef struct _Config { 
    pb_size_t which_payloadVariant;
    union {
        /* TODO: REPLACE */
        Config_DeviceConfig device;
        /* TODO: REPLACE */
        Config_PositionConfig position;
        /* TODO: REPLACE */
        Config_PowerConfig power;
        /* TODO: REPLACE */
        Config_WiFiConfig wifi;
        /* TODO: REPLACE */
        Config_DisplayConfig display;
        /* TODO: REPLACE */
        Config_LoRaConfig lora;
    } payloadVariant;
} Config;


/* Helper constants for enums */
#define _Config_DeviceConfig_Role_MIN Config_DeviceConfig_Role_Client
#define _Config_DeviceConfig_Role_MAX Config_DeviceConfig_Role_RouterClient
#define _Config_DeviceConfig_Role_ARRAYSIZE ((Config_DeviceConfig_Role)(Config_DeviceConfig_Role_RouterClient+1))

#define _Config_PositionConfig_PositionFlags_MIN Config_PositionConfig_PositionFlags_POS_UNDEFINED
#define _Config_PositionConfig_PositionFlags_MAX Config_PositionConfig_PositionFlags_POS_TIMESTAMP
#define _Config_PositionConfig_PositionFlags_ARRAYSIZE ((Config_PositionConfig_PositionFlags)(Config_PositionConfig_PositionFlags_POS_TIMESTAMP+1))

#define _Config_PowerConfig_ChargeCurrent_MIN Config_PowerConfig_ChargeCurrent_MAUnset
#define _Config_PowerConfig_ChargeCurrent_MAX Config_PowerConfig_ChargeCurrent_MA1320
#define _Config_PowerConfig_ChargeCurrent_ARRAYSIZE ((Config_PowerConfig_ChargeCurrent)(Config_PowerConfig_ChargeCurrent_MA1320+1))

#define _Config_DisplayConfig_GpsCoordinateFormat_MIN Config_DisplayConfig_GpsCoordinateFormat_GpsFormatDec
#define _Config_DisplayConfig_GpsCoordinateFormat_MAX Config_DisplayConfig_GpsCoordinateFormat_GpsFormatOSGR
#define _Config_DisplayConfig_GpsCoordinateFormat_ARRAYSIZE ((Config_DisplayConfig_GpsCoordinateFormat)(Config_DisplayConfig_GpsCoordinateFormat_GpsFormatOSGR+1))

#define _Config_LoRaConfig_RegionCode_MIN Config_LoRaConfig_RegionCode_Unset
#define _Config_LoRaConfig_RegionCode_MAX Config_LoRaConfig_RegionCode_TH
#define _Config_LoRaConfig_RegionCode_ARRAYSIZE ((Config_LoRaConfig_RegionCode)(Config_LoRaConfig_RegionCode_TH+1))

#define _Config_LoRaConfig_ModemPreset_MIN Config_LoRaConfig_ModemPreset_LongFast
#define _Config_LoRaConfig_ModemPreset_MAX Config_LoRaConfig_ModemPreset_ShortFast
#define _Config_LoRaConfig_ModemPreset_ARRAYSIZE ((Config_LoRaConfig_ModemPreset)(Config_LoRaConfig_ModemPreset_ShortFast+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define Config_init_default                      {0, {Config_DeviceConfig_init_default}}
#define Config_DeviceConfig_init_default         {_Config_DeviceConfig_Role_MIN, 0, 0, 0, ""}
#define Config_PositionConfig_init_default       {0, 0, 0, 0, 0, 0, 0}
#define Config_PowerConfig_init_default          {_Config_PowerConfig_ChargeCurrent_MIN, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define Config_WiFiConfig_init_default           {"", "", 0, 0}
#define Config_DisplayConfig_init_default        {0, _Config_DisplayConfig_GpsCoordinateFormat_MIN, 0}
#define Config_LoRaConfig_init_default           {0, _Config_LoRaConfig_ModemPreset_MIN, 0, 0, 0, 0, _Config_LoRaConfig_RegionCode_MIN, 0, 0, 0, {0, 0, 0}}
#define Config_init_zero                         {0, {Config_DeviceConfig_init_zero}}
#define Config_DeviceConfig_init_zero            {_Config_DeviceConfig_Role_MIN, 0, 0, 0, ""}
#define Config_PositionConfig_init_zero          {0, 0, 0, 0, 0, 0, 0}
#define Config_PowerConfig_init_zero             {_Config_PowerConfig_ChargeCurrent_MIN, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define Config_WiFiConfig_init_zero              {"", "", 0, 0}
#define Config_DisplayConfig_init_zero           {0, _Config_DisplayConfig_GpsCoordinateFormat_MIN, 0}
#define Config_LoRaConfig_init_zero              {0, _Config_LoRaConfig_ModemPreset_MIN, 0, 0, 0, 0, _Config_LoRaConfig_RegionCode_MIN, 0, 0, 0, {0, 0, 0}}

/* Field tags (for use in manual encoding/decoding) */
#define Config_DeviceConfig_role_tag             1
#define Config_DeviceConfig_serial_disabled_tag  2
#define Config_DeviceConfig_factory_reset_tag    3
#define Config_DeviceConfig_debug_log_enabled_tag 4
#define Config_DeviceConfig_ntp_server_tag       5
#define Config_DisplayConfig_screen_on_secs_tag  1
#define Config_DisplayConfig_gps_format_tag      2
#define Config_DisplayConfig_auto_screen_carousel_secs_tag 3
#define Config_LoRaConfig_tx_power_tag           1
#define Config_LoRaConfig_modem_preset_tag       2
#define Config_LoRaConfig_bandwidth_tag          3
#define Config_LoRaConfig_spread_factor_tag      4
#define Config_LoRaConfig_coding_rate_tag        5
#define Config_LoRaConfig_frequency_offset_tag   6
#define Config_LoRaConfig_region_tag             7
#define Config_LoRaConfig_hop_limit_tag          8
#define Config_LoRaConfig_tx_disabled_tag        9
#define Config_LoRaConfig_ignore_incoming_tag    103
#define Config_PositionConfig_position_broadcast_secs_tag 1
#define Config_PositionConfig_position_broadcast_smart_disabled_tag 2
#define Config_PositionConfig_fixed_position_tag 3
#define Config_PositionConfig_gps_disabled_tag   5
#define Config_PositionConfig_gps_update_interval_tag 6
#define Config_PositionConfig_gps_attempt_time_tag 7
#define Config_PositionConfig_position_flags_tag 10
#define Config_PowerConfig_charge_current_tag    1
#define Config_PowerConfig_is_power_saving_tag   2
#define Config_PowerConfig_is_always_powered_tag 3
#define Config_PowerConfig_on_battery_shutdown_after_secs_tag 4
#define Config_PowerConfig_adc_multiplier_override_tag 6
#define Config_PowerConfig_wait_bluetooth_secs_tag 7
#define Config_PowerConfig_mesh_sds_timeout_secs_tag 9
#define Config_PowerConfig_sds_secs_tag          10
#define Config_PowerConfig_ls_secs_tag           11
#define Config_PowerConfig_min_wake_secs_tag     12
#define Config_WiFiConfig_ssid_tag               1
#define Config_WiFiConfig_psk_tag                2
#define Config_WiFiConfig_ap_mode_tag            3
#define Config_WiFiConfig_ap_hidden_tag          4
#define Config_device_tag                        1
#define Config_position_tag                      2
#define Config_power_tag                         3
#define Config_wifi_tag                          4
#define Config_display_tag                       5
#define Config_lora_tag                          6

/* Struct field encoding specification for nanopb */
#define Config_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,device,payloadVariant.device),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,position,payloadVariant.position),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,power,payloadVariant.power),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,wifi,payloadVariant.wifi),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,display,payloadVariant.display),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,lora,payloadVariant.lora),   6)
#define Config_CALLBACK NULL
#define Config_DEFAULT NULL
#define Config_payloadVariant_device_MSGTYPE Config_DeviceConfig
#define Config_payloadVariant_position_MSGTYPE Config_PositionConfig
#define Config_payloadVariant_power_MSGTYPE Config_PowerConfig
#define Config_payloadVariant_wifi_MSGTYPE Config_WiFiConfig
#define Config_payloadVariant_display_MSGTYPE Config_DisplayConfig
#define Config_payloadVariant_lora_MSGTYPE Config_LoRaConfig

#define Config_DeviceConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    role,              1) \
X(a, STATIC,   SINGULAR, BOOL,     serial_disabled,   2) \
X(a, STATIC,   SINGULAR, BOOL,     factory_reset,     3) \
X(a, STATIC,   SINGULAR, BOOL,     debug_log_enabled,   4) \
X(a, STATIC,   SINGULAR, STRING,   ntp_server,        5)
#define Config_DeviceConfig_CALLBACK NULL
#define Config_DeviceConfig_DEFAULT NULL

#define Config_PositionConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   position_broadcast_secs,   1) \
X(a, STATIC,   SINGULAR, BOOL,     position_broadcast_smart_disabled,   2) \
X(a, STATIC,   SINGULAR, BOOL,     fixed_position,    3) \
X(a, STATIC,   SINGULAR, BOOL,     gps_disabled,      5) \
X(a, STATIC,   SINGULAR, UINT32,   gps_update_interval,   6) \
X(a, STATIC,   SINGULAR, UINT32,   gps_attempt_time,   7) \
X(a, STATIC,   SINGULAR, UINT32,   position_flags,   10)
#define Config_PositionConfig_CALLBACK NULL
#define Config_PositionConfig_DEFAULT NULL

#define Config_PowerConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    charge_current,    1) \
X(a, STATIC,   SINGULAR, BOOL,     is_power_saving,   2) \
X(a, STATIC,   SINGULAR, BOOL,     is_always_powered,   3) \
X(a, STATIC,   SINGULAR, UINT32,   on_battery_shutdown_after_secs,   4) \
X(a, STATIC,   SINGULAR, FLOAT,    adc_multiplier_override,   6) \
X(a, STATIC,   SINGULAR, UINT32,   wait_bluetooth_secs,   7) \
X(a, STATIC,   SINGULAR, UINT32,   mesh_sds_timeout_secs,   9) \
X(a, STATIC,   SINGULAR, UINT32,   sds_secs,         10) \
X(a, STATIC,   SINGULAR, UINT32,   ls_secs,          11) \
X(a, STATIC,   SINGULAR, UINT32,   min_wake_secs,    12)
#define Config_PowerConfig_CALLBACK NULL
#define Config_PowerConfig_DEFAULT NULL

#define Config_WiFiConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   ssid,              1) \
X(a, STATIC,   SINGULAR, STRING,   psk,               2) \
X(a, STATIC,   SINGULAR, BOOL,     ap_mode,           3) \
X(a, STATIC,   SINGULAR, BOOL,     ap_hidden,         4)
#define Config_WiFiConfig_CALLBACK NULL
#define Config_WiFiConfig_DEFAULT NULL

#define Config_DisplayConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   screen_on_secs,    1) \
X(a, STATIC,   SINGULAR, UENUM,    gps_format,        2) \
X(a, STATIC,   SINGULAR, UINT32,   auto_screen_carousel_secs,   3)
#define Config_DisplayConfig_CALLBACK NULL
#define Config_DisplayConfig_DEFAULT NULL

#define Config_LoRaConfig_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    tx_power,          1) \
X(a, STATIC,   SINGULAR, UENUM,    modem_preset,      2) \
X(a, STATIC,   SINGULAR, UINT32,   bandwidth,         3) \
X(a, STATIC,   SINGULAR, UINT32,   spread_factor,     4) \
X(a, STATIC,   SINGULAR, UINT32,   coding_rate,       5) \
X(a, STATIC,   SINGULAR, FLOAT,    frequency_offset,   6) \
X(a, STATIC,   SINGULAR, UENUM,    region,            7) \
X(a, STATIC,   SINGULAR, UINT32,   hop_limit,         8) \
X(a, STATIC,   SINGULAR, BOOL,     tx_disabled,       9) \
X(a, STATIC,   REPEATED, UINT32,   ignore_incoming, 103)
#define Config_LoRaConfig_CALLBACK NULL
#define Config_LoRaConfig_DEFAULT NULL

extern const pb_msgdesc_t Config_msg;
extern const pb_msgdesc_t Config_DeviceConfig_msg;
extern const pb_msgdesc_t Config_PositionConfig_msg;
extern const pb_msgdesc_t Config_PowerConfig_msg;
extern const pb_msgdesc_t Config_WiFiConfig_msg;
extern const pb_msgdesc_t Config_DisplayConfig_msg;
extern const pb_msgdesc_t Config_LoRaConfig_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Config_fields &Config_msg
#define Config_DeviceConfig_fields &Config_DeviceConfig_msg
#define Config_PositionConfig_fields &Config_PositionConfig_msg
#define Config_PowerConfig_fields &Config_PowerConfig_msg
#define Config_WiFiConfig_fields &Config_WiFiConfig_msg
#define Config_DisplayConfig_fields &Config_DisplayConfig_msg
#define Config_LoRaConfig_fields &Config_LoRaConfig_msg

/* Maximum encoded size of messages (where known) */
#define Config_DeviceConfig_size                 42
#define Config_DisplayConfig_size                14
#define Config_LoRaConfig_size                   67
#define Config_PositionConfig_size               30
#define Config_PowerConfig_size                  47
#define Config_WiFiConfig_size                   103
#define Config_size                              105

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
