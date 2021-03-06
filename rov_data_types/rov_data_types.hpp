//
// Created by zinjkov on 30.03.18.
//

#ifndef RC_ROV_SERVER_ROV_DATA_TYPES_HPP
#define RC_ROV_SERVER_ROV_DATA_TYPES_HPP

#include <stdint.h>
#include "serializable.hpp"

namespace rov_types {
    struct rov_telimetry : serializable {
        enum meta : uint8_t {
            packet_id = 0x1E,
            payload_size = 13,
            packet_size = 15
        };

        float yaw = 0;
        float pitch = 0;
        float roll = 0;

        void serialize(uint8_t *data, size_t *len);

        error_code deserialize(const uint8_t *input, size_t len);
    };

    struct rov_control : serializable {
        enum meta: uint8_t{
            packet_id = 0x2E,
            payload_size = 5,
            packet_size = 7
        };

        int8_t axis_x = 0;
        int8_t axis_y = 0;
        int8_t axis_z = 0;
        int8_t axis_w = 0;

        void serialize(uint8_t *data, size_t *len);

        error_code deserialize(const uint8_t *input, size_t len);
    };


    struct rov_hardware_control : serializable {
        enum meta: uint8_t{
            packet_id = 0x1A,
            payload_size = 9,
            packet_size = 11
        };

        int8_t horizontal_power[4];
        int8_t vertical_power[4];

		virtual void serialize(uint8_t *data, size_t *len);

		virtual error_code deserialize(const uint8_t *input, size_t len);
    };
};


#endif //RC_ROV_SERVER_ROV_DATA_TYPES_HPP
