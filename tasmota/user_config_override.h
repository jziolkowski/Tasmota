#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#ifdef ESP32
	#include "sdkconfig.h"
	#undef  APP_SLEEP
	#define APP_SLEEP              0                // Sleep does not work good with ESP32. Laggy!!
#endif


#undef OTA_URL
#define OTA_URL " "

#undef  MQTT_HOST
#define MQTT_HOST         "mqtt.iot"

#ifdef LOCATION_PB
	#define CODE_IMAGE_STR "pb"
	#undef  STA_SSID1
	#define STA_SSID1         "Przyborowo"             // [Ssid1] Wifi SSID
	#undef  STA_PASS1
	#define STA_PASS1         "wz7595wz"     // [Password1] Wifi password
	
	#define INFLUXDB_BUCKET    "iot_pb"

#elif LOCATION_OS
	#define CODE_IMAGE_STR "os"
	#define INFLUXDB_BUCKET    "iot_os"

#else
	#define CODE_IMAGE_STR "oz"
	#undef  STA_SSID1
	#define STA_SSID1         "NznCoDk3McKgMzgy"             // [Ssid1] Wifi SSID
	#undef  STA_PASS1
	#define STA_PASS1         "42.iot.i"     // [Password1] Wifi password

	#undef  STA_SSID2
	#define STA_SSID2         "Recovery"             // [Ssid1] Wifi SSID
	#undef  STA_PASS2
	#define STA_PASS2         "a1b2c3d4"     // [Password1] Wifi password
	#define INFLUXDB_BUCKET    "iot_oz"
#endif


#ifndef USE_INFLUXDB
#define USE_INFLUXDB
#define INFLUXDB_STATE     1
#define INFLUXDB_HOST      "grafana.pub.oz"
#endif

#ifdef CUSTOM_CONFIG_REMOVALS  // ******************************************************************


#undef USER_TEMPLATE
#undef CODE_IMAGE_STR
#define CODE_IMAGE_STR " "

#undef USE_ARDUINO_OTA                          // Disable support for Arduino OTA (+13k code)
#undef USE_DOMOTICZ                             // Disable Domoticz (+6k code, +0.3k mem)
#undef USE_HOME_ASSISTANT                       // Disable Home Assistant Discovery Support (+7k code)

//#undef MQTT_TELE_RETAIN                         // Tele messages may send retain flag (0 = off, 1 = on)
//#undef MQTT_CLEAN_SESSION                       // Mqtt clean session connection (0 = No clean session, 1 = Clean session (default))
#undef USE_TLS
#undef USE_ZBBRIDGE_TLS
#undef USE_MQTT_TLS                             // Use TLS for MQTT connection (+34.5k code, +7.0k mem and +4.8k additional during connection handshake)
  #undef USE_MQTT_TLS_CA_CERT                   // Force full CA validation instead of fingerprints, slower, but simpler to use (+2.2k code, +1.9k mem during connection handshake)
  #undef USE_MQTT_TLS_FORCE_EC_CIPHER           // Force Elliptic Curve cipher (higher security) required by some servers (automatically enabled with USE_MQTT_AWS_IOT) (+11.4k code, +0.4k mem)
  #undef USE_MQTT_AWS_IOT                       // Enable MQTT for AWS IoT - requires a private key (+11.9k code, +0.4k mem)

#define UPGRADE_V8_MIN                           // do not support upgrading from version below 8.0.0
#define UPGRADE_V8_MIN_KEEP_WIFI
#define UPGRADE_V8_MIN_KEEP_MQTT

#undef USE_KNX                                  // Disable KNX IP Protocol Support (+9.4k code, +3k7 mem)
#undef USE_WEBSERVER
#undef USE_JAVASCRIPT_ES6                       // Disable ECMAScript6 syntax using less JavaScript code bytes (fails on IE11)
#undef USE_WEBSEND_RESPONSE                     // DIsable command WebSend response message (+1k code)
#undef USE_EMULATION_HUE                        // Disable Hue Bridge emulation for Alexa (+18k code, +2k mem)
#undef USE_EMULATION_WEMO                       // Disable Belkin WeMo emulation for Alexa (+18k code, +2k mem)
#undef USE_DISCOVERY                            // Disable mDNS for the following services (+8k code, +0.3k mem)
#undef USE_TIMERS                               // Disable support for up to 16 timers (+2k2 code)
#undef USE_TIMERS_WEB                           // Disable timer webpage support (+4k5 code)

#undef USE_GPIO_VIEWER

#undef USE_UFILESYS
#undef GUI_TRASH_FILE
#undef GUI_EDIT_FILE
#undef USE_PING
#undef USE_AUTOCONF
#undef USE_BERRY
#undef USE_WEBCLIENT
#undef USE_WEBCLIENT_HTTPS

#undef USE_SUNRISE                              // Disable support for Sunrise and sunset tools (+16k)

#undef USE_UNISHOX_COMPRESSION                  // Disable support for string compression in Rules or Scripts

#undef USE_RULES                                // Disable support for rules (+4k4 code)
  #undef USE_RULES_COMPRESSION                  // Disable Compresses rules in Flash at about ~50% (+3.8k code)
  #undef USE_EXPRESSION                         // Disable support for expression evaluation in rules (+3k2 code, +64 bytes mem)
    #undef SUPPORT_IF_STATEMENT                 // Disable support for IF statement in rules (+4k2 code, -332 bytes mem)
  #undef SUPPORT_MQTT_EVENT                     // Support trigger event with MQTT subscriptions (+3k5 code)

#undef USE_SCRIPT                               // Disable support for script
#undef USE_SML_M                                // Disable SML support optional using script
  #undef USE_SCRIPT_FATFS                       // Disable support for script storage on SD card (+12k code, +4k mem)

#undef ROTARY_V1                                // Disable support for Rotary Encoder as used in MI Desk Lamp (+0k8 code)
#undef ROTARY_MAX_STEPS                         // Rotary step boundary

#undef USE_SONOFF_RF                            // Add support for Sonoff Rf Bridge
  #undef USE_RF_FLASH                           // Add support for flashing the EFM8BB1 chip on the Sonoff RF Bridge. C2CK must be connected to GPIO4, C2D to GPIO5 on the PCB (+3k code)
#undef USE_SONOFF_SC                            // Disable support for Sonoff Sc (+1k1 code)
#undef USE_TUYA_MCU                             // Disable support for Tuya Serial Dimmer
#undef USE_ARMTRONIX_DIMMERS                    // Disable support for Armtronix Dimmers (+1k4 code)
#undef USE_AC_ZERO_CROSS_DIMMER
#undef USE_PS_16_DZ                             // Disable support for PS-16-DZ Dimmer (+2k code)
#undef USE_SONOFF_IFAN                          // Disable support for Sonoff iFan02 and iFan03 (+2k code)
#undef USE_BUZZER                               // Disable support for a buzzer (+0k6 code)
#undef USE_ARILUX_RF                            // Disable support for Arilux RF remote controller (+0k8 code, 252 iram (non 2.3.0))
#undef USE_SHUTTER                              // Disable Shutter support for up to 4 shutter with different motortypes (+6k code)
#undef USE_DEEPSLEEP                            // Add support for deepsleep (+1k code)
#undef USE_EXS_DIMMER                           // Add support for ES-Store WiFi Dimmer (+2k6 code)
#undef USE_HOTPLUG                              // Add support for HotPlug
#undef USE_DEVICE_GROUPS                        // Add support for device groups (+4k code)
#undef USE_PWM_DIMMER                           // Add support for MJ-SD01/acenx/NTONPOWER PWM dimmers (+4k5 code)
  #undef USE_PWM_DIMMER_REMOTE                  // Add support for remote switches to PWM Dimmer, also adds device groups support (+0k7 code, also includes device groups)
#undef USE_KEELOQ                               // Add support for controling Jarolift rollers by Keeloq algorithm
#undef USE_SONOFF_D1                            // Add support for Sonoff D1 Dimmer
#undef USE_THERMOSTAT                           // Add support for Thermostat (+9k code)
#undef USE_SHELLY_DIMMER                        // Add support for Shelly Dimmer (+2k2 code)
  #undef SHELLY_CMDS                            // Add command to send co-processor commands (+0k4 code)
  #undef SHELLY_FW_UPGRADE                      // Add firmware upgrade option for co-processor (+30k code, +5k mem)
  #undef SHELLY_VOLTAGE_MON                     // Add support for reading voltage and current measurment (+?? code)

// -- Optional light modules ---------------------
//#undef USE_LIGHT                                // Disable all light
#undef USE_WS2812                               // Disable WS2812 Led string using library NeoPixelBus (+5k code, +1k mem, 232 iram) - Disable by //
  #undef USE_WS2812_DMA                         // Disable DMA supports only GPIO03 (= Serial RXD) (+1k mem). When USE_WS2812_DMA is enabled expect Exceptions on Pow
  #undef USE_WS2812_INVERTED                    // Disable inverted data signal
  #undef USE_WS2812_HARDWARE                    // Hardware type (NEO_HW_WS2812, NEO_HW_WS2812X, NEO_HW_WS2813, NEO_HW_SK6812, NEO_HW_LC8812, NEO_HW_APA106)
  #undef USE_WS2812_CTYPE                       // WS2812 Color type (NEO_RGB, NEO_GRB, NEO_BRG, NEO_RBG, NEO_RGBW, NEO_GRBW)
#undef USE_MY92X1                               // Add support for MY92X1 RGBCW led controller as used in Sonoff B1 and Ailight
#undef USE_SM16716                              // Add support for SM16716 RGB LED controller (+0k7 code)
#undef USE_SM2135                               // Add support for SM2135 RGBCW led control as used in Action LSC (+0k6 code)
#undef USE_SONOFF_L1                            // Add support for Sonoff L1 led control
#undef USE_ELECTRIQ_MOODL                       // Add support for ElectriQ iQ-wifiMOODL RGBW LED controller
#undef USE_LIGHT_PALETTE                        // Add support for color palette (+0k9 code)

#undef USE_COUNTER                              // Disable counters
#undef USE_ADC_VCC

#undef USE_DS18x20                              // Disable support for DS18x20 sensors with id sort, single scan and read retry (+2k6 code)
  #undef W1_PARASITE_POWER                      // If using USE_DS18x20 then optimize for parasite powered sensors

#undef USE_I2C                                  // Disable I2C using library wire (+10k code, 0k2 mem, 124 iram)
#undef USE_SHT                                  // Disable SHT1X sensor (+1k4 code)
#undef USE_HTU                                  // Disable HTU21/SI7013/SI7020/SI7021 sensor (I2C address 0x40) (+1k5 code)
#undef USE_BMP                                  // Disable BMP085/BMP180/BMP280/BME280 sensor (I2C address 0x76 or 0x77) (+4k code)
  #undef USE_BME680                             // Disable support for BME680 sensor using Bosch BME680 library (+4k code)
#undef USE_BH1750                               // Disable BH1750 sensor (I2C address 0x23 or 0x5C) (+0k5 code)
#undef USE_VEML6070                             // Disable VEML6070 sensor (I2C addresses 0x38 and 0x39) (+0k5 code)
#undef USE_ADS1115                              // Disable ADS1115 16 bit A/D converter (I2C address 0x48, 0x49, 0x4A or 0x4B) based on Adafruit ADS1x15 library (no library needed) (+0k7 code)
#undef USE_INA219                               // Disable INA219 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+1k code)
#undef USE_INA226                               // Disable INA226 (I2C address 0x40, 0x41 0x44 or 0x45) Low voltage and current sensor (+2k3 code)
#undef USE_SHT3X                                // Disable SHT3x (I2C address 0x44 or 0x45) or SHTC3 (I2C address 0x70) sensor (+0k7 code)
#undef USE_TSL2561                              // Disable TSL2561 sensor (I2C address 0x29, 0x39 or 0x49) using library Joba_Tsl2561 (+2k3 code)
#undef USE_TSL2591                              // Disable TSL2591 sensor (I2C address 0x29, 0x39 or 0x49) using library Adafruit_TSL2591 (+2k3 code)
#undef USE_MGS                                  // Disable Xadow and Grove Mutichannel Gas sensor using library Multichannel_Gas_Sensor (+10k code)
#undef USE_SGP30                                // Disable SGP30 sensor (I2C address 0x58) (+1k1 code)
#undef USE_SI1145                               // Disable SI1145/46/47 sensor (I2C address 0x60) (+1k code)
#undef USE_LM75AD                               // Disable LM75AD sensor (I2C addresses 0x48 - 0x4F) (+0k5 code)
#undef USE_APDS9960                             // Disable APDS9960 Proximity Sensor (I2C address 0x39). Disables SHT and VEML6070 (+4k7 code)
#undef USE_MCP230xx                             // Disable MCP23008/MCP23017 for GP INPUT ONLY (I2C addresses 0x20 - 0x27) providing command Sensor29 for configuration (+2k2 code)
#undef USE_PCA9685                              // Disable PCA9685 I2C HW PWM Driver - Must define I2C Address in #define USE_PCA9685_ADDR below - range 0x40 - 0x47 (+1k4 code)
#undef USE_MPR121                               // Disable MPR121 controller (I2C addresses 0x5A, 0x5B, 0x5C and 0x5D) in input mode for touch buttons (+1k3 code)
#undef USE_CCS811                               // Disable CCS811 sensor (I2C address 0x5A) (+2k2 code)
#undef USE_CCS811_V2                            // Disable CCS811 sensor (I2C addresses 0x5A and 0x5B) (+2k8 code)
#undef USE_MPU6050                              // Disable MPU6050 sensor (I2C address 0x68 AD0 low or 0x69 AD0 high) (+2k6 code)
#undef USE_DS3231                               // Disable DS3231 external RTC in case no Wifi is avaliable. See docs in the source file (+1k2 code)
//  #undef USE_RTC_ADDR  0x68                     // Default I2C address 0x68
#undef USE_MGC3130                              // Disable MGC3130 Electric Field Effect Sensor (I2C address 0x42) (+2k7 code, 0k3 mem)
#undef USE_MAX44009                             // Disable MAX44009 Ambient Light sensor (I2C addresses 0x4A and 0x4B) (+0k8 code)
#undef USE_SCD30                                // Disable Sensiron SCd30 CO2 sensor (I2C address 0x61) (+3k3 code)
#undef USE_SPS30                                // Disable Sensiron SPS30 particle sensor (I2C address 0x69) (+1.7 code)
#undef USE_ADE7953                              // Disable ADE7953 Energy monitor as used on Shelly 2.5 (I2C address 0x38) (+1k5)
#undef USE_VL53L0X                              // Disable VL53L0x time of flight sensor (I2C address 0x29) (+4k code)
#undef USE_VL53L1X                              // Disable support for VL53L1X sensor (I2C address 0x29) using Pololu VL53L1X library (+2k9 code)
#undef USE_MLX90614                             // Disable MLX90614 ir temp sensor (I2C address 0x5a) (+0.6k code)
#undef USE_CHIRP                                // Disable CHIRP soil moisture sensor (variable I2C address, default 0x20)
#undef USE_PAJ7620                              // Disable PAJ7620 gesture sensor (I2C address 0x73) (+2.5k code)
#undef USE_PCF8574                              // Disable PCF8574 I/O Expander (I2C addresses 0x20 - 0x27 and 0x38 - 0x3F) (+1k9 code)
#undef USE_HIH6                                 // Disable Honeywell HIH Humidity and Temperature sensor (I2C address 0x27) (+0k6)
#undef USE_DHT12                                // Disable DHT12 humidity and temperature sensor (I2C address 0x5C) (+0k7 code)
#undef USE_DS1624                               // Disable DS1624, DS1621 temperature sensor (I2C addresses 0x48 - 0x4F)
#undef USE_AHT1x                                // Disable AHT10/15 humidity and temperature sensor (I2C address 0x38) (+0k8 code)
#undef USE_WEMOS_MOTOR_V1                       // Disable Wemos motor driver V1 ()
#undef USE_HDC1080                              // Disable HDC1080 temperature/humidity sensor (I2C address 0x40) (+1k5 code)
#undef USE_IAQ                                  // Disable iAQ-core air quality sensor (I2C address 0x5a) (+0k6 code)
#undef USE_AS3935                               // Disable AS3935 Franklin Lightning Sensor (I2C address 0x03) (+5k4 code)
#undef USE_VEML6075                             // Disable VEML6075 UVA/UVB/UVINDEX Sensor (I2C address 0x10) (+2k1 code)
#undef USE_VEML7700                             // Disable VEML7700 Ambient Light sensor (I2C addresses 0x10) (+4k5 code)
#undef USE_MCP9808                              // Disable MCP9808 temperature sensor (I2C addresses 0x18 - 0x1F) (+0k9 code)
#undef USE_HP303B                               // Disable HP303B temperature and pressure sensor (I2C address 0x76 or 0x77) (+6k2 code)
#undef USE_MLX90640                             // Disable MLX90640 IR array temperature sensor (I2C address 0x33) (+4k9 code)
#undef USE_EZOPH                                // Disable support for EZO's pH sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
#undef USE_EZOORP                               // Disable support for EZO's ORP sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
#undef USE_EZORTD                               // Disable support for EZO's RTD sensor (+0k2 code) - Shared EZO code required for any EZO device (+1k2 code)
#undef USE_EZOHUM                               // Disable support for EZO's HUM sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
#undef USE_EZOEC                                // Disable support for EZO's EC sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)
#undef USE_EZOCO2                               // Disable support for EZO's CO2 sensor (+0k3 code) - Shared EZO code required for any EZO device (+1k2 code)

#undef USE_SPI                                  // Disable SPI using GPIO12(MISO), GPIO13(MOSI) and GPIO14(CLK) in addition to two user selectable GPIOs(CS and DC)
#undef USE_SPI_LORA                             // Disable support for LoRaSend and LoRaCommand (+4k code)
#undef USE_RC522                                // Disable support for MFRC522 13.56Mhz Rfid reader (+6k code)
  #undef USE_RC522_DATA_FUNCTION                // Disable support for reading data block content (+0k4 code)
  #undef USE_RC522_TYPE_INFORMATION             // Disable support for showing card type (+0k4 code)

#undef USE_DISPLAY                              // Disable displays
#undef USE_DISPLAY_MODES1TO5                    // Disable display mode 1 to 5 in addition to mode 0

#undef USE_MHZ19                                // Disable support for MH-Z19 CO2 sensor (+2k code)
#undef USE_SENSEAIR                             // Disable support for SenseAir K30, K70 and S8 CO2 sensor (+2k3 code)
#undef USE_PMS5003                              // Disable support for PMS5003 and PMS7003 particle concentration sensor (+1k3 code)
#undef USE_NOVA_SDS                             // Disable support for SDS011 and SDS021 particle concentration sensor (+0k7 code)
#undef USE_HPMA                                 // Disable support for Honeywell HPMA115S0 particle concentration sensor (+1k4)
#undef USE_SR04                                 // Disable support for HC-SR04 ultrasonic devices (+1k code)
#undef USE_DYP                                  // Disable support for DYP ME-007 ultrasonic distance sensor, serial port version (+0k5 code)
#undef USE_SERIAL_BRIDGE                        // Disable support for software Serial Bridge (+0k8 code)
#undef USE_MP3_PLAYER                           // Disable Use of the DFPlayer Mini MP3 Player RB-DFR-562 commands: play, volume and stop
#undef USE_AZ7798                               // Disable support for AZ-Instrument 7798 CO2 datalogger (+1k6 code)
#undef USE_PN532_HSU                            // Disable support for PN532 using HSU (Serial) interface (+1k8 code, 140 bytes mem)
  #undef USE_PN532_DATA_FUNCTION                // Disable sensor40 command support for erase, setting data block content (+1k7 code, 388 bytes mem)
  #undef USE_PN532_DATA_RAW                     // Allow DATA block to be used by non-alpha-numberic data (+ 80 bytes code, 48 bytes ram)
#undef USE_RDM6300                              // Disable support for RDM6300 125kHz RFID Reader (+0k8)
#undef USE_IBEACON                              // Disable support for bluetooth LE passive scan of ibeacon devices (uses HM17 module)
#undef USE_GPS                                  // Disable support for GPS and NTP Server for becoming Stratus 1 Time Source (+ 3.1kb flash, +132 bytes RAM)
  #undef USE_FLOG                               // Disable support for GPS logging in OTA's Flash (Experimental) (+ 2.9kb flash, +8 bytes RAM)
#undef USE_HM10                                 // (ESP8266 only) Disable support for HM-10 as a BLE-bridge for the LYWSD03 (+5k1 code)
#undef USE_HRXL                                 // (ESP32 only) Disable support for MaxBotix HRXL-MaxSonar ultrasonic range finders (+0k7)
#undef USE_MI_ESP32                             // Disable support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)
#undef USE_TASMOTA_CLIENT                       // Disable support for Arduino Uno/Pro Mini via serial interface including flashing (+2k3 code, 44 mem)
#undef USE_OPENTHERM                            // Disable support for OpenTherm (+15k code)
#undef USE_MIEL_HVAC                            // Disable support for Mitsubishi Electric HVAC (+5k code)
#undef USE_AS608                                // Disable support for AS608 optical and R503 capacitive fingerprint sensor (+3k code)
  #undef USE_AS608_MESSAGES                     // Disable verbose error messages (+0k4 code)

// Power monitoring sensors ----------------------
#undef USE_ENERGY_SENSOR                        // Disable energy sensors (+14k code)
#undef USE_HLW8012
#undef USE_CSE7766
#undef USE_ENERGY_MARGIN_DETECTION              // Disable support for Energy Margin detection (+1k6 code)
  #undef USE_ENERGY_POWER_LIMIT                 // Disable additional support for Energy Power Limit detection (+1k2 code)
#undef USE_PZEM004T                             // Disable support for PZEM004T Energy monitor (+2k code)
#undef USE_PZEM_AC                              // Disable support for PZEM014,016 Energy monitor (+1k1 code)
#undef USE_PZEM_DC                              // Disable support for PZEM003,017 Energy monitor (+1k1 code)
#undef USE_MCP39F501                            // Disable support for MCP39F501 Energy monitor as used in Shelly 2 (+3k1 code)
#undef USE_SDM120                               // Disable support for Eastron SDM120-Modbus energy monitor (+1k1 code)
#undef USE_SDM630                               // Disable support for Eastron SDM630-Modbus energy monitor (+0k6 code)
#undef USE_DDS2382                              // Disable support for Hiking DDS2382 Modbus energy monitor (+0k6 code)
#undef USE_DDSU666                              // Disable support for Chint DDSU666 Modbus energy monitor (+0k6 code)
#undef USE_SOLAX_X1                             // Disable support for Solax X1 series Modbus log info (+4k1 code)
#undef USE_LE01MR                               // Disable support for F&F LE-01MR modbus energy meter
#undef USE_BL0940                               // Disable support for BL0940 Energy monitor as used in Blitzwolf SHP-10 (+1k6 code)
#undef USE_TELEINFO                             // Disable support for Teleinfo via serial RX interface (+5k2 code, +168 RAM + SmartMeter LinkedList Values RAM)
#undef USE_IEM3000                              // Disable support for Schneider Electric iEM3000-Modbus series energy monitor (+0k8 code)
#undef USE_SDM72
#undef SDM72_SPEED
#undef SDM120_SPEED
#undef SDM630_SPEED
#undef DDS2382_SPEED
#undef DDSU666_SPEED
#undef SOLAXX1_SPEED
#undef SOLAXX1_PV2
#undef USE_BL09XX
#undef USE_LE01MR
#undef LE01MR_SPEED
#undef LE01MR_ADDR
#undef IEM3000_SPEED
#undef IEM3000_ADDR
#undef IEM3000_IEM3155
#undef USE_WE517

// -- Low level interface devices -----------------
#undef USE_DHT                                  // Disable support for DHT11, AM2301 (DHT21, DHT22, AM2302, AM2321) and SI7021 Temperature and Humidity sensor

#undef USE_MAX31855                             // Disable MAX31855 K-Type thermocouple sensor using softSPI
#undef USE_MAX31865                             // Disable support for MAX31865 RTD sensors using softSPI
#undef USE_LMT01                                // Disable support for TI LMT01 temperature sensor, count pulses on single GPIO (+0k5 code)

// -- IR Remote features --------------------------
#undef USE_IR_REMOTE_FULL                       // Activate all protocols from IRremoteESP8266 - activating this option will ignore all other USE_IR_REMOTE_* options and set them all to active
#undef USE_IR_REMOTE                            // Send IR remote commands using library IRremoteESP8266 and ArduinoJson (+4k3 code, 0k3 mem, 48 iram)
  #undef USE_IR_SEND_NEC                        // Support IRsend NEC protocol
  #undef USE_IR_SEND_RC5                        // Support IRsend Philips RC5 protocol
  #undef USE_IR_SEND_RC6                        // Support IRsend Philips RC6 protocol

  #undef USE_IR_RECEIVE                         // Support for IR receiver (+7k2 code, 264 iram)

// -- Zigbee interface ----------------------------
#undef USE_ZIGBEE                               // Disable serial communication with Zigbee CC2530 flashed with ZNP
  #undef USE_ZIGBEE_ZNP                         // Disable ZNP protocol, needed for CC2530 based devices
  #undef USE_ZIGBEE_EZSP                        // Disable EZSP protocol, needed for EFR32 EmberZNet based devices, like Sonoff Zigbee bridge

// ------------------------------------------------

#undef USE_TM1638                               // Disable support for TM1638 switches copying Switch1 .. Switch8 (+1k code)
#undef USE_HX711                                // Disable support for HX711 load cell (+1k5 code)
  #undef USE_HX711_GUI                          // Disable optional web GUI to HX711 as scale (+1k8 code)

#undef USE_TX20_WIND_SENSOR                     // Disable support for La Crosse TX20 anemometer (+2k6/0k8 code)
#undef USE_TX23_WIND_SENSOR                     // Disable support for La Crosse TX23 anemometer (+2k7/1k code)

#undef USE_WINDMETER                            // Add support for analog anemometer

#undef USE_FTC532                               // Add support for FTC532 touch controller (+0k6 code)

#undef USE_RC_SWITCH                            // Disable support for RF transceiver using library RcSwitch (+2k7 code, 460 iram)

#undef USE_RF_SENSOR                            // Disable support for RF sensor receiver (434MHz or 868MHz) (+0k8 code)
  #undef USE_THEO_V2                            // Disable support for decoding Theo V2 sensors as documented on https://sidweb.nl using 434MHz RF sensor receiver (+1k4 code)
  #undef USE_ALECTO_V2                          // Disable support for decoding Alecto V2 sensors like ACH2010, WS3000 and DKW2012 weather stations using 868MHz RF sensor receiver (+1k7 code)

#undef USE_HRE                                  // Disable support for Badger HR-E Water Meter (+1k4 code)
#undef USE_A4988_STEPPER                        // Disable support for A4988 stepper-motor-driver-circuit (+10k5 code)

#undef USE_PROMETHEUS                           // Disable support for https://prometheus.io/ metrics exporting over HTTP /metrics endpoint


//#undef DEBUG_TASMOTA_CORE                       // Disable core debug messages
//#undef DEBUG_TASMOTA_DRIVER                     // Disable driver debug messages
//#undef DEBUG_TASMOTA_SENSOR                     // DIsable sensor debug messages
//#undef DEBUG_TASMOTA_TRACE                      // Disable trace debug messages

#endif  // CUSTOM_CONFIG_REMOVALS *******************************************************************



#endif  // _USER_CONFIG_OVERRIDE_H_
