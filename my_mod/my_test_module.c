#include <ngx_config.h>
#include <ngx_core.h>

struct test_conf_context {
    size_t size;
    int length;
};

static struct test_conf_context test_conf;

static void *create_test_mod_conf(ngx_cycle_t *cycle) {
    ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno, "create_test_mod_conf");
    // return ngx_pnalloc(cycle->pool, sizeof(struct test_conf_context));
    return &test_conf;
}

static char *init_test_conf(ngx_cycle_t *cycle, void *conf) {
    ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno, "init_test_conf");

    struct test_conf_context *c = conf;
    c->size = 0;
    c->length = 0;
    return NGX_OK;
}

static ngx_core_module_t test_context = {
        ngx_string("my_core_test_modules"),
        create_test_mod_conf,
        init_test_conf
};

static ngx_int_t do_init_master(ngx_log_t *log) {
    ngx_log_error(NGX_LOG_ALERT, log, ngx_errno, "do_init_master");
}

static ngx_int_t do_init_modules(ngx_cycle_t *cycle) {
    ngx_log_error(NGX_LOG_ALERT, cycle->log, ngx_errno, "do_init_modules");
}

static ngx_int_t do_init_process(ngx_cycle_t *cycle) {
    ngx_log_error(NGX_LOG_STDERR, cycle->log, ngx_errno, "do_init_process,log_level=%d", cycle->log->log_level);
}

static void do_exit_process(ngx_cycle_t *cycle) {
    ngx_log_error(NGX_LOG_STDERR, cycle->log, ngx_errno, "do_exit_process,log_level=%d", cycle->log->log_level);
}

static void do_exit_master(ngx_cycle_t *cycle) {
    ngx_log_error(NGX_LOG_STDERR, cycle->log, ngx_errno, "do_exit_master,log_level=%d", cycle->log->log_level);
}

ngx_module_t my_test_mod = {
        NGX_MODULE_UNSET_INDEX,
        NGX_MODULE_UNSET_INDEX,
        NULL,
        0,
        0,
        nginx_version,
        NGX_MODULE_SIGNATURE,
        &test_context,
        NULL,
        NGX_CORE_MODULE,
        do_init_master, // 这个属性是没有用的
        do_init_modules,
        do_init_process,
        NULL,
        NULL,
        do_exit_process,
        do_exit_master,
        NGX_MODULE_V1_PADDING // 6个0
};
