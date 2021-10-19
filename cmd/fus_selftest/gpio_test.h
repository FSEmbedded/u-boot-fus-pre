#ifndef CMD_FUS_SELFTEST_GPIO_TEST_H_
#define CMD_FUS_SELFTEST_GPIO_TEST_H_

//---Functions for selftest---//

int test_gpio(int uclass, char *szStrBuffer);
int test_gpio_dev(struct udevice *dev, u32 *failmask); // return count of gpio pairs

#endif // CMD_FUS_SELFTEST_GPIO_TEST_H_