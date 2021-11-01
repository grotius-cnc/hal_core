#include "rtapi.h"
#ifdef RTAPI
#include "rtapi_app.h"
#endif
#include "rtapi_string.h"
#include "rtapi_errno.h"
#include "hal.h"
#include "rtapi_math64.h"

static int comp_id;

#ifdef MODULE_INFO
MODULE_INFO(linuxcnc, "component:opencascade:opencascade component");
MODULE_INFO(linuxcnc, "descr:\nopencascade component\n\nPreprocess slogan examples :\n/opt/linuxcnc/bin/halcompile --preprocess /opt/linuxcnc/src/hal/components/opencascade.comp\n/opt/linuxcnc/bin/halcompile --preprocess /home/user/Desktop/Linux-Embedded/linux-hal/halcompile-opencascade/c-project/opencascade.comp\n\nUsage :\n\nThis file can only be used for --preprocess purposes. Direct --compile will fail.\nThe makefile uses the preproccesed .c and .o file to produce the .so library.\n\nThen in halview : loadrt opencascade\n\n");
MODULE_INFO(linuxcnc, "author:Skynet 2021");
MODULE_INFO(linuxcnc, "license:GPLv2 or greater");
MODULE_INFO(linuxcnc, "pin:init:bit:0:out:init values at component startup:None:None");
MODULE_INFO(linuxcnc, "pin:reset:bit:0:in:reset all values to initialisation values:None:None");
MODULE_INFO(linuxcnc, "param:interval:float:0:rw:calculation interval, 0ms=servo-thread, 2000ms=every 2sec, units ms:None:None");
MODULE_INFO(linuxcnc, "param:j0_x:float:0:rw:joint 0, x:None:None");
MODULE_INFO(linuxcnc, "param:j0_y:float:0:rw:joint 0, y:None:None");
MODULE_INFO(linuxcnc, "param:j0_z:float:0:rw:joint 0, z:None:None");
MODULE_INFO(linuxcnc, "param:j0_rotx:bit:0:rw:joint 0, x rotation flag:None:None");
MODULE_INFO(linuxcnc, "param:j0_roty:bit:0:rw:joint 0, y rotation flag:None:None");
MODULE_INFO(linuxcnc, "param:j0_rotz:bit:0:rw:joint 0, z rotation flag:None:None");
MODULE_INFO(linuxcnc, "param:j1_x:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j1_y:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j1_z:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j1_rotx:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j1_roty:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j1_rotz:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j2_x:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j2_y:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j2_z:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j2_rotx:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j2_roty:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j2_rotz:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j3_x:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j3_y:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j3_z:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j3_rotx:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j3_roty:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j3_rotz:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j4_x:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j4_y:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j4_z:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j4_rotx:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j4_roty:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j4_rotz:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j5_x:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j5_y:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j5_z:float:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j5_rotx:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j5_roty:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "param:j5_rotz:bit:0:rw::None:None");
MODULE_INFO(linuxcnc, "pin:pin_j0:float:0:in:pin in j0:None:None");
MODULE_INFO(linuxcnc, "pin:pin_j1:float:0:in:pin in j1:None:None");
MODULE_INFO(linuxcnc, "pin:pin_j2:float:0:in:pin in j2:None:None");
MODULE_INFO(linuxcnc, "pin:pin_j3:float:0:in:pin in j3:None:None");
MODULE_INFO(linuxcnc, "pin:pin_j4:float:0:in:pin in j4:None:None");
MODULE_INFO(linuxcnc, "pin:pin_j5:float:0:in:pin in j5:None:None");
MODULE_INFO(linuxcnc, "pin:pin_cartx:float:0:in:pin in cartx:None:None");
MODULE_INFO(linuxcnc, "pin:pin_carty:float:0:in:pin in carty:None:None");
MODULE_INFO(linuxcnc, "pin:pin_cartz:float:0:in:pin in cartz:None:None");
MODULE_INFO(linuxcnc, "pin:pin_eulerx:float:0:in:pin in eulerx:None:None");
MODULE_INFO(linuxcnc, "pin:pin_eulery:float:0:in:pin in eulery:None:None");
MODULE_INFO(linuxcnc, "pin:pin_eulerz:float:0:in:pin in eulerz:None:None");
MODULE_INFO(linuxcnc, "funct:_:1:");
MODULE_LICENSE("GPLv2 or greater");
#endif // MODULE_INFO


struct __comp_state {
    struct __comp_state *_next;
    hal_bit_t *init;
    hal_bit_t *reset;
    hal_float_t *pin_j0;
    hal_float_t *pin_j1;
    hal_float_t *pin_j2;
    hal_float_t *pin_j3;
    hal_float_t *pin_j4;
    hal_float_t *pin_j5;
    hal_float_t *pin_cartx;
    hal_float_t *pin_carty;
    hal_float_t *pin_cartz;
    hal_float_t *pin_eulerx;
    hal_float_t *pin_eulery;
    hal_float_t *pin_eulerz;
    hal_float_t interval;
    hal_float_t j0_x;
    hal_float_t j0_y;
    hal_float_t j0_z;
    hal_bit_t j0_rotx;
    hal_bit_t j0_roty;
    hal_bit_t j0_rotz;
    hal_float_t j1_x;
    hal_float_t j1_y;
    hal_float_t j1_z;
    hal_bit_t j1_rotx;
    hal_bit_t j1_roty;
    hal_bit_t j1_rotz;
    hal_float_t j2_x;
    hal_float_t j2_y;
    hal_float_t j2_z;
    hal_bit_t j2_rotx;
    hal_bit_t j2_roty;
    hal_bit_t j2_rotz;
    hal_float_t j3_x;
    hal_float_t j3_y;
    hal_float_t j3_z;
    hal_bit_t j3_rotx;
    hal_bit_t j3_roty;
    hal_bit_t j3_rotz;
    hal_float_t j4_x;
    hal_float_t j4_y;
    hal_float_t j4_z;
    hal_bit_t j4_rotx;
    hal_bit_t j4_roty;
    hal_bit_t j4_rotz;
    hal_float_t j5_x;
    hal_float_t j5_y;
    hal_float_t j5_z;
    hal_bit_t j5_rotx;
    hal_bit_t j5_roty;
    hal_bit_t j5_rotz;
    int myidx;

};
struct __comp_state *__comp_first_inst=0, *__comp_last_inst=0;

static void _(struct __comp_state *__comp_inst, long period);
static int __comp_get_data_size(void);
static int extra_setup(struct __comp_state *__comp_inst, char *prefix, long extra_arg);
#undef TRUE
#define TRUE (1)
#undef FALSE
#define FALSE (0)
#undef true
#define true (1)
#undef false
#define false (0)

static int export(char *prefix, long extra_arg) {
    char buf[HAL_NAME_LEN + 1];
    int r = 0;
    int sz = sizeof(struct __comp_state) + __comp_get_data_size();
    struct __comp_state *inst = hal_malloc(sz);
    memset(inst, 0, sz);
    r = extra_setup(inst, prefix, extra_arg);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_OUT, &(inst->init), comp_id,
        "%s.init", prefix);
    if(r != 0) return r;
    r = hal_pin_bit_newf(HAL_IN, &(inst->reset), comp_id,
        "%s.reset", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_j0), comp_id,
        "%s.pin-j0", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_j1), comp_id,
        "%s.pin-j1", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_j2), comp_id,
        "%s.pin-j2", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_j3), comp_id,
        "%s.pin-j3", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_j4), comp_id,
        "%s.pin-j4", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_j5), comp_id,
        "%s.pin-j5", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_cartx), comp_id,
        "%s.pin-cartx", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_carty), comp_id,
        "%s.pin-carty", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_cartz), comp_id,
        "%s.pin-cartz", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_eulerx), comp_id,
        "%s.pin-eulerx", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_eulery), comp_id,
        "%s.pin-eulery", prefix);
    if(r != 0) return r;
    r = hal_pin_float_newf(HAL_IN, &(inst->pin_eulerz), comp_id,
        "%s.pin-eulerz", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->interval), comp_id,
        "%s.interval", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j0_x), comp_id,
        "%s.j0-x", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j0_y), comp_id,
        "%s.j0-y", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j0_z), comp_id,
        "%s.j0-z", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j0_rotx), comp_id,
        "%s.j0-rotx", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j0_roty), comp_id,
        "%s.j0-roty", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j0_rotz), comp_id,
        "%s.j0-rotz", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j1_x), comp_id,
        "%s.j1-x", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j1_y), comp_id,
        "%s.j1-y", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j1_z), comp_id,
        "%s.j1-z", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j1_rotx), comp_id,
        "%s.j1-rotx", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j1_roty), comp_id,
        "%s.j1-roty", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j1_rotz), comp_id,
        "%s.j1-rotz", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j2_x), comp_id,
        "%s.j2-x", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j2_y), comp_id,
        "%s.j2-y", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j2_z), comp_id,
        "%s.j2-z", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j2_rotx), comp_id,
        "%s.j2-rotx", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j2_roty), comp_id,
        "%s.j2-roty", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j2_rotz), comp_id,
        "%s.j2-rotz", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j3_x), comp_id,
        "%s.j3-x", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j3_y), comp_id,
        "%s.j3-y", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j3_z), comp_id,
        "%s.j3-z", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j3_rotx), comp_id,
        "%s.j3-rotx", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j3_roty), comp_id,
        "%s.j3-roty", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j3_rotz), comp_id,
        "%s.j3-rotz", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j4_x), comp_id,
        "%s.j4-x", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j4_y), comp_id,
        "%s.j4-y", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j4_z), comp_id,
        "%s.j4-z", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j4_rotx), comp_id,
        "%s.j4-rotx", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j4_roty), comp_id,
        "%s.j4-roty", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j4_rotz), comp_id,
        "%s.j4-rotz", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j5_x), comp_id,
        "%s.j5-x", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j5_y), comp_id,
        "%s.j5-y", prefix);
    if(r != 0) return r;
    r = hal_param_float_newf(HAL_RW, &(inst->j5_z), comp_id,
        "%s.j5-z", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j5_rotx), comp_id,
        "%s.j5-rotx", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j5_roty), comp_id,
        "%s.j5-roty", prefix);
    if(r != 0) return r;
    r = hal_param_bit_newf(HAL_RW, &(inst->j5_rotz), comp_id,
        "%s.j5-rotz", prefix);
    if(r != 0) return r;
    rtapi_snprintf(buf, sizeof(buf), "%s", prefix);
    r = hal_export_funct(buf, (void(*)(void *inst, long))_, inst, 1, 0, comp_id);
    if(r != 0) return r;
    if(__comp_last_inst) __comp_last_inst->_next = inst;
    __comp_last_inst = inst;
    if(!__comp_first_inst) __comp_first_inst = inst;
    return 0;
}
int rtapi_app_main(void) {
    int r = 0;
    comp_id = hal_init("hal_opencascade");
    if(comp_id < 0) return comp_id;
    r = export("hal_opencascade", 0);
    if(r) {
        hal_exit(comp_id);
    } else {
        hal_ready(comp_id);
    }
    return r;
}

void rtapi_app_exit(void) {
    hal_exit(comp_id);
}

#undef FUNCTION
#define FUNCTION(name) static void name(struct __comp_state *__comp_inst, long period)
#undef EXTRA_SETUP
#define EXTRA_SETUP() static int extra_setup(struct __comp_state *__comp_inst, char *prefix, long extra_arg)
#undef EXTRA_CLEANUP
#define EXTRA_CLEANUP() static void extra_cleanup(void)
#undef fperiod
#define fperiod (period * 1e-9)
#undef init
#define init (*__comp_inst->init)
#undef reset
#define reset (0+*__comp_inst->reset)
#undef pin_j0
#define pin_j0 (0+*__comp_inst->pin_j0)
#undef pin_j1
#define pin_j1 (0+*__comp_inst->pin_j1)
#undef pin_j2
#define pin_j2 (0+*__comp_inst->pin_j2)
#undef pin_j3
#define pin_j3 (0+*__comp_inst->pin_j3)
#undef pin_j4
#define pin_j4 (0+*__comp_inst->pin_j4)
#undef pin_j5
#define pin_j5 (0+*__comp_inst->pin_j5)
#undef pin_cartx
#define pin_cartx (0+*__comp_inst->pin_cartx)
#undef pin_carty
#define pin_carty (0+*__comp_inst->pin_carty)
#undef pin_cartz
#define pin_cartz (0+*__comp_inst->pin_cartz)
#undef pin_eulerx
#define pin_eulerx (0+*__comp_inst->pin_eulerx)
#undef pin_eulery
#define pin_eulery (0+*__comp_inst->pin_eulery)
#undef pin_eulerz
#define pin_eulerz (0+*__comp_inst->pin_eulerz)
#undef interval
#define interval (__comp_inst->interval)
#undef j0_x
#define j0_x (__comp_inst->j0_x)
#undef j0_y
#define j0_y (__comp_inst->j0_y)
#undef j0_z
#define j0_z (__comp_inst->j0_z)
#undef j0_rotx
#define j0_rotx (__comp_inst->j0_rotx)
#undef j0_roty
#define j0_roty (__comp_inst->j0_roty)
#undef j0_rotz
#define j0_rotz (__comp_inst->j0_rotz)
#undef j1_x
#define j1_x (__comp_inst->j1_x)
#undef j1_y
#define j1_y (__comp_inst->j1_y)
#undef j1_z
#define j1_z (__comp_inst->j1_z)
#undef j1_rotx
#define j1_rotx (__comp_inst->j1_rotx)
#undef j1_roty
#define j1_roty (__comp_inst->j1_roty)
#undef j1_rotz
#define j1_rotz (__comp_inst->j1_rotz)
#undef j2_x
#define j2_x (__comp_inst->j2_x)
#undef j2_y
#define j2_y (__comp_inst->j2_y)
#undef j2_z
#define j2_z (__comp_inst->j2_z)
#undef j2_rotx
#define j2_rotx (__comp_inst->j2_rotx)
#undef j2_roty
#define j2_roty (__comp_inst->j2_roty)
#undef j2_rotz
#define j2_rotz (__comp_inst->j2_rotz)
#undef j3_x
#define j3_x (__comp_inst->j3_x)
#undef j3_y
#define j3_y (__comp_inst->j3_y)
#undef j3_z
#define j3_z (__comp_inst->j3_z)
#undef j3_rotx
#define j3_rotx (__comp_inst->j3_rotx)
#undef j3_roty
#define j3_roty (__comp_inst->j3_roty)
#undef j3_rotz
#define j3_rotz (__comp_inst->j3_rotz)
#undef j4_x
#define j4_x (__comp_inst->j4_x)
#undef j4_y
#define j4_y (__comp_inst->j4_y)
#undef j4_z
#define j4_z (__comp_inst->j4_z)
#undef j4_rotx
#define j4_rotx (__comp_inst->j4_rotx)
#undef j4_roty
#define j4_roty (__comp_inst->j4_roty)
#undef j4_rotz
#define j4_rotz (__comp_inst->j4_rotz)
#undef j5_x
#define j5_x (__comp_inst->j5_x)
#undef j5_y
#define j5_y (__comp_inst->j5_y)
#undef j5_z
#define j5_z (__comp_inst->j5_z)
#undef j5_rotx
#define j5_rotx (__comp_inst->j5_rotx)
#undef j5_roty
#define j5_roty (__comp_inst->j5_roty)
#undef j5_rotz
#define j5_rotz (__comp_inst->j5_rotz)
#undef myidx
#define myidx (__comp_inst->myidx)

#include "rtapi_math.h"
#include "halmodule.h"

double ms;
double seconds;
double totalnsec;
struct data d; // Component wide data bucket

// http://linuxcnc.org/docs/2.8/html/man/man3/RTAPI_MP_ARRAY_STRING.3rtapi.html
char *stepfilepath;
RTAPI_MP_STRING(stepfilepath,"");

int display_hz;
RTAPI_MP_INT(display_hz,"");

// Example of array
char *joint0[6] = {0,0,0,0,0,0};
RTAPI_MP_ARRAY_STRING(joint0, 6, "");

FUNCTION(_) {
        totalnsec = totalnsec + period;
        ms = totalnsec * 0.000001;          // rtapi_print_msg(RTAPI_MSG_ERR,"totalms: %f \n", totalms);
        seconds = totalnsec * 0.000000001;  // rtapi_print_msg(RTAPI_MSG_ERR,"totalseconds: %f \n", totalseconds);
        
        if(!init && totalnsec>5){ // Startup delay of the opencascade init to prevent realtime startup errors
            init_opencascade(stepfilepath,display_hz);
            init=1;
            totalnsec=0;
        }

        if(init){
            d.J0=pin_j0; // Copy hal parameter values to the shared (parallel) c++ program data bucket.
            d.J1=pin_j1;
            d.J2=pin_j2;
            d.J3=pin_j3;
            d.J4=pin_j4;
            d.J5=pin_j5;
            d.Cartx=pin_cartx;
            d.Carty=pin_carty;
            d.Cartz=pin_cartz;
            d.Eulerx=pin_eulerx;
            d.Eulery=pin_eulery;
            d.Eulerz=pin_eulerz;
            
            d.J0x=j0_x;
            d.J0y=j0_y;
            d.J0z=j0_z;
            d.J0_rotx=j0_rotx;
            d.J0_roty=j0_roty;
            d.J0_rotz=j0_rotz;

            d.J1x=j1_x;
            d.J1y=j1_y;
            d.J1z=j1_z;
            d.J1_rotx=j1_rotx;
            d.J1_roty=j1_roty;
            d.J1_rotz=j1_rotz;

            d.J2x=j2_x;
            d.J2y=j2_y;
            d.J2z=j2_z;
            d.J2_rotx=j2_rotx;
            d.J2_roty=j2_roty;
            d.J2_rotz=j2_rotz;

            d.J3x=j3_x;
            d.J3y=j3_y;
            d.J3z=j3_z;
            d.J3_rotx=j3_rotx;
            d.J3_roty=j3_roty;
            d.J3_rotz=j3_rotz;

            d.J4x=j4_x;
            d.J4y=j4_y;
            d.J4z=j4_z;
            d.J4_rotx=j4_rotx;
            d.J4_roty=j4_roty;
            d.J4_rotz=j4_rotz;

            d.J5x=j5_x;
            d.J5y=j5_y;
            d.J5z=j5_z;
            d.J5_rotx=j5_rotx;
            d.J5_roty=j5_roty;
            d.J5_rotz=j5_rotz;
                    
            meat(d); // Give meat the values.
        }
}

EXTRA_SETUP(){
if (stepfilepath == 0) {
rtapi_print_msg(RTAPI_MSG_ERR,"stepfilepath string missing\n");
return -EINVAL;
}
rtapi_print_msg(RTAPI_MSG_ERR,"stepfilepath: %s\n",stepfilepath);

if (display_hz == 0) {
rtapi_print_msg(RTAPI_MSG_ERR,"display_hz string missing\n");
return -EINVAL;
}
rtapi_print_msg(RTAPI_MSG_ERR,"display_hz: %d\n",display_hz);
return(0);

// Example of array
//myidx = extra_arg;
//if(myidx<0 || myidx >2)
//{
//    rtapi_print_msg(RTAPI_MSG_ERR,"arg is outside the allowable range 0..2\n");
//    return -EINVAL;
//}
//if(arg[myidx] == 0)
//{
//    rtapi_print_msg(RTAPI_MSG_ERR,"arg string for index %d missing\n", myidx);
//    return -EINVAL;
//}
//rtapi_print_msg(RTAPI_MSG_ERR,"stepfilepath : %s\n",arg[0]);
//rtapi_print_msg(RTAPI_MSG_ERR,"opencascade screen hz : %s\n",arg[1]);
//return(0);
}

static int __comp_get_data_size(void) { return 0; }
