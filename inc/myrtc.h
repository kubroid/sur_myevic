#ifndef __MERTC_H__
#define __MERTC_H__

#include <time.h>
#include "M451Series.h"

//=========================================================================
// REAL-TIME CLOCK
//=========================================================================

#define IS_RTC_OPENED() ((RTC->INIT & RTC_INIT_ACTIVE_Msk) != 0)

//=========================================================================
// LIRC correction ratio
//-------------------------------------------------------------------------
// On boards without a 32k Xtal, we use the LIRC to drive the RTC. Since
// its frequency is way off, a corrective ratio is necessary to compute the
// real time. Since it may vary from box to box, it is adjustable by the
// "Clk Speed" configuration menu.
// This value is unused if a X32 is soldered on the board.

#define RTC_DEF_CLK_RATIO 33425

#define RTC_MIN_CLOCK_RATIO 30000
#define RTC_MAX_CLOCK_RATIO 35000

//-------------------------------------------------------------------------
// Spare registers usage
//-------------------------------------------------------------------------

#define RTCSPARE_REF_DATE 0
#define RTCSPARE_MIDNIGHT 1
//#define RTCSPARE_VV_BASE	1 //not used
//#define RTCSPARE_VV_MJOULES	2
//#define RTCSPARE_VV_MJOULESDAY	3

//=========================================================================
// When the RTC is driven by the LIRC, a "second" of the RTC is approx
// 3.3 real seconds, but we'd like the clock to display with a correct
// second tick. The correction value is driven by the 1kHZ TMR2 and reset
// by the RTC tick.
// This value is unused if a X32 is soldered on the board.

extern volatile int32_t ClockCorrection;
// extern volatile uint8_t IsRTCAlarmINT;

//=========================================================================
// Functions

extern void RTCStart(S_RTC_TIME_DATA_T *d);
extern void GetRTC(S_RTC_TIME_DATA_T *rtd);
extern void SetRTC(S_RTC_TIME_DATA_T *rtd);

extern void RTCWriteRegister(uint32_t r, uint32_t v);
extern uint32_t RTCReadRegister(uint32_t r);

extern void RTCTimeToEpoch(time_t *t, const S_RTC_TIME_DATA_T *d);
extern void RTCEpochToTime(S_RTC_TIME_DATA_T *d, const time_t *t);

extern void RTCSetClockSpeed(const unsigned int cs);
extern unsigned int RTCGetClockSpeed();
extern void RTCAdjustClock(int seconds);

extern void RTCSleep();
extern void RTCWakeUp();

extern time_t RTCGetEpoch(time_t *t);

// extern time_t RTCGetReferenceDate();
// extern void RTCSetReferenceDate( time_t *t );
extern void   RTCWriteNextMidnight();
extern time_t RTCGetMidnightDate();

extern void ResetMJDay();

//=========================================================================

#endif /* __MERTC_H__ */
