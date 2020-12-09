#ifndef NGINX_VOD_MODULE_NGX_HTTP_VOD_ORIGIN_ASSIST_PREFETCH_H
#define NGINX_VOD_MODULE_NGX_HTTP_VOD_ORIGIN_ASSIST_PREFETCH_H

#include <ngx_http.h>
#include "vod/common.h"

bool_t ngx_http_vod_is_origin_assist_prefetch_enabled(ngx_http_request_t *r);
bool_t ngx_http_vod_is_origin_assist_prefetch_request(ngx_http_request_t *r);
ngx_int_t ngx_http_vod_set_origin_assist_prefetch_path(ngx_http_request_t *r, ngx_str_t path);

#endif //NGINX_VOD_MODULE_NGX_HTTP_VOD_ORIGIN_ASSIST_PREFETCH_H

