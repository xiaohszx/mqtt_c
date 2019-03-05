//
// Created by xzl on 2019/2/26.
//

#ifndef MQTT_IOT_PROTO_H
#define MQTT_IOT_PROTO_H

#include <stdint.h>
#include "iot_type.h"
#include "buffer.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


int pack_iot_bool_packet(int with_head,
                         int req_flag,
                         uint32_t req_id,
                         uint32_t tag_id,
                         uint8_t bool_flag,
                         unsigned char *data_out,
                         int out_len);

int pack_iot_enum_packet(int with_head,
                         int req_flag,
                         uint32_t req_id,
                         uint32_t tag_id,
                         const char *enum_str,
                         unsigned char *data_out,
                         int out_len);

int pack_iot_string_packet(int with_head,
                           int req_flag,
                           uint32_t req_id,
                           uint32_t tag_id,
                           const char *str,
                           unsigned char *data_out,
                           int out_len);

int pack_iot_double_packet(int with_head,
                           int req_flag,
                           uint32_t req_id,
                           uint32_t tag_id,
                           double double_num,
                           unsigned char *data_out,
                           int out_len);

int unpack_iot_packet(uint8_t *req_flag,
                      uint32_t *req_id,
                      uint32_t *tag_id,
                      iot_data_type *type,
                      const unsigned char *data_in,
                      int in_len,
                      const unsigned char **content);

double to_double(const unsigned char *data_in);

void dump_iot_pack(const uint8_t *in,int size);

void test_iot_packet();


int iot_buffer_header(buffer *buffer, int req_flag, uint32_t req_id);
int iot_buffer_bool(buffer *buffer, uint32_t tag_id , uint8_t bool_flag);
int iot_buffer_enum(buffer *buffer, uint32_t tag_id, const char *enum_str);
int iot_buffer_string(buffer *buffer, uint32_t tag_id, const char *str);
int iot_buffer_double(buffer *buffer, uint32_t tag_id , double double_num);



#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif //MQTT_IOT_PROTO_H