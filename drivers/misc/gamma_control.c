/*
 * Copyright 2013 Illes Pal Zoltan
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/device.h>
#include <linux/miscdevice.h>

#define GAMMACONTROL_VERSION 1

/*
 * Update function callback into the display driver
 */
extern void update_vals(
    unsigned int red_linear_max,
    unsigned int green_linear_max,
    unsigned int blue_linear_max,

    unsigned int red_curve_max,
    unsigned int gree_curve_max,
    unsigned int blue_curve_max,

    unsigned int red_curve_ratio,
    unsigned int green_curve_ratio,
    unsigned int blue_curve_ratio
    );

/*
 *  for RED, GREEN and BLUE
 */

// where's the linear maximum of the components
unsigned int red_linear_max = 100;
unsigned int green_linear_max = 100;
unsigned int blue_linear_max = 100;

// where's the additional curve's maximum
unsigned int red_curve_max = 50;
unsigned int green_curve_max = 50;
unsigned int blue_curve_max = 50;

// curve height - 50 is no curve, 0 is max concave curve, 100 is max convex curve
unsigned int red_curve_ratio = 50;
unsigned int green_curve_ratio = 50;
unsigned int blue_curve_ratio = 50;

static void upd(void)
{
		update_vals(
			red_linear_max, green_linear_max, blue_linear_max,
			red_curve_max, green_curve_max, blue_curve_max,
			red_curve_ratio, green_curve_ratio, blue_curve_ratio);
}

/*
 * Sysfs get/set entries
 */

static ssize_t red_linear_max_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", red_linear_max);
}

static ssize_t red_linear_max_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != red_linear_max) {
		pr_info("New RED lin max: %d\n", new_val);
		red_linear_max = new_val;
		upd();
	}
	return size;
}
static ssize_t green_linear_max_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", green_linear_max);
}

static ssize_t green_linear_max_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != green_linear_max) {
		pr_info("New GREEN lin max: %d\n", new_val);
		green_linear_max = new_val;
		upd();
	}
	return size;
}

static ssize_t blue_linear_max_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", blue_linear_max);
}

static ssize_t blue_linear_max_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != blue_linear_max) {
		pr_info("New BLUE lin max: %d\n", new_val);
		blue_linear_max = new_val;
		upd();
	}
	return size;
}


static ssize_t red_curve_max_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", red_curve_max);
}

static ssize_t red_curve_max_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != red_curve_max) {
		pr_info("New RED curve max: %d\n", new_val);
		red_curve_max = new_val;
		upd();
	}
	return size;
}
static ssize_t green_curve_max_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", green_curve_max);
}

static ssize_t green_curve_max_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != green_curve_max) {
		pr_info("New GREEN curve max: %d\n", new_val);
		green_curve_max = new_val;
		upd();
	}
	return size;
}

static ssize_t blue_curve_max_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", blue_curve_max);
}

static ssize_t blue_curve_max_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != blue_curve_max) {
		pr_info("New BLUE curve max: %d\n", new_val);
		blue_curve_max = new_val;
		upd();
	}
	return size;
}


static ssize_t red_curve_ratio_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", red_curve_ratio);
}

static ssize_t red_curve_ratio_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != red_curve_ratio) {
		pr_info("New RED ratio max: %d\n", new_val);
		red_curve_ratio = new_val;
		upd();
	}
	return size;
}
static ssize_t green_curve_ratio_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", green_curve_ratio);
}

static ssize_t green_curve_ratio_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != green_curve_ratio) {
		pr_info("New GREEN ratio max: %d\n", new_val);
		green_curve_ratio = new_val;
		upd();
	}
	return size;
}

static ssize_t blue_curve_ratio_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return sprintf(buf, "%d\n", blue_curve_ratio);
}

static ssize_t blue_curve_ratio_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t size)
{
	int new_val;
	sscanf(buf, "%d", &new_val);
	if (new_val != blue_curve_ratio) {
		pr_info("New BLUE ratio max: %d\n", new_val);
		blue_curve_ratio = new_val;
		upd();
	}
	return size;
}


static ssize_t gammacontrol_version(struct device * dev, struct device_attribute * attr, char * buf)
{
    return sprintf(buf, "%u\n", GAMMACONTROL_VERSION);
}

static DEVICE_ATTR(red_linear_max, 0777, red_linear_max_show, red_linear_max_store);
static DEVICE_ATTR(green_linear_max, 0777, green_linear_max_show, green_linear_max_store);
static DEVICE_ATTR(blue_linear_max, 0777, blue_linear_max_show, blue_linear_max_store);

static DEVICE_ATTR(red_curve_max, 0777, red_curve_max_show, red_curve_max_store);
static DEVICE_ATTR(green_curve_max, 0777, green_curve_max_show, green_curve_max_store);
static DEVICE_ATTR(blue_curve_max, 0777, blue_curve_max_show, blue_curve_max_store);

static DEVICE_ATTR(red_curve_ratio, 0777, red_curve_ratio_show, red_curve_ratio_store);
static DEVICE_ATTR(green_curve_ratio, 0777, green_curve_ratio_show, green_curve_ratio_store);
static DEVICE_ATTR(blue_curve_ratio, 0777, blue_curve_ratio_show, blue_curve_ratio_store);

static DEVICE_ATTR(version, 0777 , gammacontrol_version, NULL);

static struct attribute *gammacontrol_attributes[] = 
{
	&dev_attr_red_linear_max.attr,
	&dev_attr_green_linear_max.attr,
	&dev_attr_blue_linear_max.attr,

	&dev_attr_red_curve_max.attr,
	&dev_attr_green_curve_max.attr,
	&dev_attr_blue_curve_max.attr,

	&dev_attr_red_curve_ratio.attr,
	&dev_attr_green_curve_ratio.attr,
	&dev_attr_blue_curve_ratio.attr,

	&dev_attr_version.attr,
	NULL
};

static struct attribute_group gammacontrol_group = 
{
	.attrs  = gammacontrol_attributes,
};

static struct miscdevice gammacontrol_device = 
{
	.minor = MISC_DYNAMIC_MINOR,
	.name = "gammacontrol",
};

static int __init gammacontrol_init(void)
{
    int ret;

    pr_info("%s misc_register(%s)\n", __FUNCTION__, gammacontrol_device.name);

    ret = misc_register(&gammacontrol_device);

    if (ret) {
	    pr_err("%s misc_register(%s) fail\n", __FUNCTION__, gammacontrol_device.name);
	    return 1;
	}

    if (sysfs_create_group(&gammacontrol_device.this_device->kobj, &gammacontrol_group) < 0) {
	    pr_err("%s sysfs_create_group fail\n", __FUNCTION__);
	    pr_err("Failed to create sysfs group for device (%s)!\n", gammacontrol_device.name);
	}

    return 0;
}
late_initcall(gammacontrol_init);
