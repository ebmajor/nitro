#ifndef NITRO_OPT_H
#define NITRO_OPT_H

#include "common.h"

typedef struct nitro_sockopt_t {
    int hwm_in;
    int hwm_out_general;
    int hwm_out_private;
    double close_linger;
    double reconnect_interval;
    uint32_t max_message_size;

    int has_ident;
    uint8_t ident[SOCKET_IDENT_LENGTH];
    uint8_t pkey[crypto_box_SECRETKEYBYTES];

    int secure;

    int has_remote_ident;
    uint8_t required_remote_ident[SOCKET_IDENT_LENGTH];

} nitro_sockopt_t;

nitro_sockopt_t *nitro_sockopt_new();
void nitro_sockopt_set_hwm(nitro_sockopt_t *opt, int hwm);
void nitro_sockopt_set_hwm_detail(nitro_sockopt_t *opt, int hwm_in,
    int hwm_out_general, int hwm_out_private);
void nitro_sockopt_set_close_linger(nitro_sockopt_t *opt,
    double close_linger);
void nitro_sockopt_set_reconnect_interval(nitro_sockopt_t *opt,
    double reconnect_interval);
void nitro_sockopt_set_max_message_size(nitro_sockopt_t *opt,
    uint32_t max_message_size);
void nitro_sockopt_set_secure_identity(nitro_sockopt_t *opt,
    uint8_t *ident, size_t ident_length,
    uint8_t *pkey, size_t pkey_length);
void nitro_sockopt_set_secure(nitro_sockopt_t *opt, int enabled);
void nitro_sockopt_set_required_remote_ident(nitro_sockopt_t *opt,
    uint8_t *ident, size_t ident_length);

#endif /* NITRO_OPT_H */
