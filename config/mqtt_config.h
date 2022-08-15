#ifndef MQTT_CONFIG_H_
#define MQTT_CONFIG_H_

#include "wifi_config.h"

namespace mqtt
{
constexpr auto server_ip = "255.0.0.0";
constexpr auto server_port = 1883;

constexpr auto username = "MQTT Username";
constexpr auto password = "MQTT Password";

constexpr auto client_id = wifi::hostname;
}  // namespace mqtt

#endif /* MQTT_CONFIG_H_ */
