# C Test For Embedded Linux Course

Author: Nguyen Luong Dinh Hoang\
Contact: fb.com/nguyenluongdinhhoang

# How to build

Make sure you are runnning cmake version >= 2.8

```
mkdir build && cd build
cmake ..
make
./test
```

# Read data from file

Accept reading from this format only, read sample on data_test.txt
```
fullname:salary
```
Run with file name argument
```
./test ${FILE_NAME}
```
Example
```
./test ../data_test.txt
```
# Exercise 2 Watchdog Solution

```
/* Địa chỉ cơ bản của watchdog */
#define WDT_BASE_ADDR         0x44E35000
/* Offsets */
#define WDT_EN_OFFSET         0x48        //WDT_WSPR Register
#define WDT_PING_OFFSET       0x30        //WDT_WTGR Register
#define WDT_STATUS_OFFSET     0x34        //WDT_WWPS Register
/*
* bbb_wdt_enable sẽ có thực hiện enable watchdog
*/
void bbb_wdt_enable(void)
{
  uint32_t *wdt_en_res = (WDT_BASE_ADDR + WDT_EN_OFFSET);
  uint32_t *wdt_status_res = (WDT_BASE_ADDR + WDT_STATUS_OFFSET);
  /* Enable Watchdog */
  /* To enable the timer, follow this sequence:
  1. Write XXXX BBBBh in WDT_WSPR.
  2. Poll for posted write to complete using WDT_WWPS.W_PEND_WSPR.
  3. Write XXXX 4444h in WDT_WSPR.
  4. Poll for posted write to complete using WDT_WWPS.W_PEND_WSPR */
  *wdt_en_res = 0x0000BBBB;
  while((*wdt_status_res)&(1UL << 4));
  *wdt_en_res = 0x00004444;
  while((*wdt_status_res)&(1UL << 4));

}
/*
* bbb_wdt_ping sẽ thực hiện trigger(reload thanh ghi
đếm ngược) watchdog
*/
void bbb_wdt_ping(void) {
  uint32_t *wdt_ping_res = (WDT_BASE_ADDR + WDT_PING_OFFSET);
  /* Ping watchdog */
  /* The specific reload sequence is performed
   * whenever the written value on the WDT_WTGR register
   * differs from its previous value */
  *wdt_ping_res = 0x99999999;
}
int main(void) {
  /* Kích hoạt watchdog */
  bbb_wdt_enable();
  /* Ping watchdog theo chu kì 2 phút */
  while (true) {
    bbb_wdt_ping();
    /* Sleep 2 minutes */
    sleep(120);
  };
  return 0;
}
```
