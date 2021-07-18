//
// Created by dear on 2021/7/17.
//


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_http.h>
#include <ngx_http_config.h>
#include <so_http_bind.h>

static ngx_int_t so_http_module_init(ngx_conf_t *cf);

static char *in_bind_init(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);


ngx_command_t nhttp_cmds[] = {
        {ngx_string("in_bind"),
         NGX_HTTP_MAIN_CONF | NGX_CONF_BLOCK | NGX_CONF_NOARGS,
         in_bind_init,
         0,
         0,
         NULL},
        ngx_null_command
};


ngx_http_module_t so_http_ctx = {
        NULL,                                  /* preconfiguration */
        so_http_module_init,                   /* postconfiguration */

        NULL,                                  /* create main configuration */
        NULL,                                  /* init main configuration */

        NULL,                                  /* create server configuration */
        NULL,                                  /* merge server configuration */

        NULL,        /* create location configuration */
        NULL          /* merge location configuration */
};


ngx_module_t so_http_bind_module = {
        NGX_MODULE_V1,
        &so_http_ctx,           /* module context */
        nhttp_cmds,              /* module directives */
        NGX_HTTP_MODULE,                       /* module type */
        NULL,                                  /* init master */
        NULL,                                  /* init module */
        NULL,                                  /* init process */
        NULL,                                  /* init thread */
        NULL,                                  /* exit thread */
        NULL,                                  /* exit process */
        NULL,                                  /* exit master */
        NGX_MODULE_V1_PADDING
};

static char *in_bind_init(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {

    char *rv = ngx_conf_parse(cf, NULL);


    return NGX_CONF_OK;
}

static ngx_int_t so_http_module_init(ngx_conf_t *cf) {

    return NGX_OK;
}