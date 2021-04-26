/* Copyright (c) 2010-2011, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef __QPNP_CHARGER_H__
#define __QPNP_CHARGER_H__

#include <linux/power_supply.h>

struct qpnp_battery_gauge {
	int (*get_battery_mvolts) (void);
	int (*get_battery_temperature) (void);
	int (*is_battery_present) (void);
	int (*is_battery_temp_within_range) (void);
	int (*is_battery_id_valid) (void);
	int (*get_battery_status)(void);
	int (*get_batt_remaining_capacity) (void);
	int (*monitor_for_recharging) (void);
	int (*get_battery_soc) (void);
	int (*get_average_current) (void);
	int (*is_battery_authenticated) (void);//wangjc add for authentication
	//lfc add for fastchg
	int	(*fast_chg_started) (void);
	int (*fast_switch_to_normal) (void);
	int (*set_switch_to_noraml_false) (void);
	int (*set_fast_chg_allow) (int enable);
	int (*get_fast_chg_allow) (void);
	int (*fast_normal_to_warm)	(void);	
	int (*set_normal_to_warm_false)	(void);
	int	(*get_fast_chg_ing)	(void);
	int	(*get_fast_low_temp_full)	(void);
	int	(*set_low_temp_full_false)	(void);
	int (*set_i2c_read_allow)	(bool enable);
	//lfc add for fastchg end
};

struct qpnp_external_charger {
	int (*chg_vddmax_set) (int mV);
	int (*chg_vbatdet_set) (int mV);
	int (*chg_iusbmax_set) (int mA);
	int (*chg_ibatmax_set) (int mA);
	int (*chg_ibatterm_set) (int mA);
	int (*chg_vinmin_set)(int mV);
	int (*chg_charge_en) (int enable);
	int (*check_charge_timeout) (int hours);
	int (*chg_get_system_status) (void);
	int (*chg_get_charge_en) (void);
	int (*chg_usb_suspend_enable) (int enable);
	int (*chg_otg_current_set) (int mA);
	int (*chg_wdt_set) (int seconds);
	int (*chg_regs_reset) (int reset);
};

#define BATTERY_1800MAH_MM		0
#define BATTERY_1800MAH_XWD		1
#define BATTERY_2020MAH_SONY	2
#define BATTERY_2020MAH_ATL		3
#define BATTERY_2420MAH_SONY	4
#define BATTERY_2420MAH_ATL		5
#define BATTERY_2420MAH_SDI		6
#define BATTERY_2420MAH_LG		7
#define BATTERY_2550MAH_SONY	8
#define BATTERY_2550MAH_ATL		9
#define BATTERY_2550MAH_SDI		10
#define BATTERY_2550MAH_LG		11
extern int opchg_get_bq2022_manufacture_id(void);


#endif /* __QPNP_CHARGER_H__ */
