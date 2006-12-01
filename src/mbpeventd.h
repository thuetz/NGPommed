/*
 * $Id$
 */

#ifndef __MBPEVENTD_H__
#define __MBPEVENTD_H__


#define M_VERSION "0.3"


void
logmsg(int level, char *fmt, ...);

#ifdef DEBUG
# define logdebug(fmt, args...) printf(fmt, ##args);
# define debug 1
#else
# define logdebug(fmt, args...)
extern int debug;
#endif


struct machine_ops
{
  int type;
  int (*lcd_backlight_probe) (void);
  void (*lcd_backlight_step) (int dir);
};

extern struct machine_ops *mops;


#define PIDFILE                "/var/run/mbpeventd.pid"

#define USB_VENDOR_ID_APPLE           0x05ac
#define USB_PRODUCT_ID_GEYSER4_ISO    0x021b

#define MACHINE_MACBOOKPRO_22         1
#define MACHINE_MAC_UNKNOWN           0


#define K_LCD_BCK_DOWN          0xe0
#define K_LCD_BCK_UP            0xe1
#define K_AUDIO_MUTE            0x71
#define K_AUDIO_DOWN            0x72
#define K_AUDIO_UP              0x73
#define K_VIDEO_TOGGLE          0xe3
#define K_KBD_BCK_OFF           0xe4
#define K_KBD_BCK_DOWN          0xe5
#define K_KBD_BCK_UP            0xe6
#define K_CD_EJECT              0xa1

#define STEP_UP                 1
#define STEP_DOWN               -1

#define EVDEV_BASE              "/dev/input/event"
#define EVDEV_MAX               32

#define LOOP_TIMEOUT            200

#define LCD_BCK_STEP            10
#define LCD_BACKLIGHT_OFF       0
#define LCD_BACKLIGHT_MAX       255

#define KBD_BCK_STEP            10
#define KBD_BACKLIGHT           "/sys/class/leds/smc:kbd_backlight/brightness"
#define KBD_AMBIENT_SENSOR      "/sys/devices/platform/applesmc/light"
#define KBD_AMBIENT_THRESHOLD   20
#define KBD_BACKLIGHT_DEFAULT   100
#define KBD_BACKLIGHT_OFF       0
#define KBD_BACKLIGHT_MAX       255

#define CD_DVD_DEVICE           "/dev/dvd"
#define CD_CDROM_DEVICE         "/dev/cdrom"
#define CD_EJECT_CMD            "/usr/bin/eject"

#endif /* !__MBPEVENTD_H__ */
