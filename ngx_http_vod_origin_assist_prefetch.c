#include "ngx_http_vod_origin_assist_prefetch.h"
#include "ngx_http_vod_utils.h"

static ngx_str_t origin_assist_prefetch_enabled_key = ngx_string("CDN-Origin-Assist-Prefetch-Enabled");
static ngx_str_t origin_assist_prefetch_request_key = ngx_string("CDN-Origin-Assist-Prefetch-Request");
static ngx_str_t origin_assist_prefetch_path_key = ngx_string("CDN-Origin-Assist-Prefetch-Path");

bool_t
ngx_http_vod_is_origin_assist_prefetch_enabled(ngx_http_request_t *r)
{
	ngx_str_t origin_assist_prefetch_enabled_value = ngx_null_string;
	ngx_http_vod_read_header(r, &origin_assist_prefetch_enabled_key, &origin_assist_prefetch_enabled_value);

	if (!origin_assist_prefetch_enabled_value.data)
	{
		return FALSE;
	}

	return ngx_strcmp(origin_assist_prefetch_enabled_value.data, "1") == 0;
}

bool_t
ngx_http_vod_is_origin_assist_prefetch_request(ngx_http_request_t *r)
{
	ngx_str_t origin_assist_prefetch_request_value = ngx_null_string;
	ngx_http_vod_read_header(r, &origin_assist_prefetch_request_key, &origin_assist_prefetch_request_value);

	if (!origin_assist_prefetch_request_value.data)
	{
		return FALSE;
	}

	return ngx_strcmp(origin_assist_prefetch_request_value.data, "1") == 0;
}

ngx_int_t
ngx_http_vod_set_origin_assist_prefetch_path(ngx_http_request_t *r, ngx_str_t path)
{
	ngx_table_elt_t *origin_assist_prefetch = ngx_list_push(&r->headers_out.headers);

	if (origin_assist_prefetch == NULL)
	{
		return NGX_ERROR;
	}

	origin_assist_prefetch->hash = 1;
	origin_assist_prefetch->key = origin_assist_prefetch_path_key;
	origin_assist_prefetch->value = path;

	return NGX_OK;
}
